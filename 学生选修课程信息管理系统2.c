#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#define N1 100
#define N2 100
HANDLE hOut;
struct Course//课程
{ int num;//课程编号
  char name[50];//课程名称
  char nature[50];//课程性质
  int toperiod;//课程总学时
  int giperiod;//课程授课学时
  int experiod;//课程上机或实验学时
  float credit;//课程学分
  int term;//课程学期
};
struct Student//学生
{   int num;//学生学号
	char name[50];//学生姓名
	int course[10];//学生所学课程的编号
};
  
int main()
{
    int color(int c);
	void gotoxy(int x, int y);
    void title();
    void welcome();
    void coursemod();
    void studentmod();
	void classcheck();
	void stucheck();
	title();
	welcome();
}

int color(int c) //控制文字颜色
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
	return 0; 
}

void gotoxy(int x, int y) //控制文字位置
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void title() //标题输出
{ 
	color(10);
	gotoxy(24, 5);
	printf("学生选课信息管理系统\n");

}

void welcome() //菜单选项
{
	int i,j, n;
	color(13);
	for (i=6; i<=30; i++)
	{
		for (j=15; j<=60; j++)
		{
			gotoxy(j, i);
			if(i==6||i==30)
			{
				printf("=");
			}
			else if(j==15||j==60)
			{
				printf("||");
			}
		}

	}
	color(12);
	gotoxy(30, 10);
	printf("1.选课信息查询");
	gotoxy(30, 13);
	printf("2.学生信息查询");
	gotoxy(30, 16);
	printf("3.选课信息修改");
	gotoxy(30, 19);
	printf("4.学生信息修改");
	gotoxy(30, 22);
	printf("5.退出");
	gotoxy(21,25);
	color(3);
	printf("请选择[1 2 3 4 5]:[ ]\b\b");
	color(14);
	scanf("%d", &n);
	switch(n)
	{ 
	case 1: system("cls");classcheck();break;
	case 2: system("cls");stucheck();break;
	case 3:system("cls");coursemod();break;
	case 4: system("cls");studentmod();break;
	case 5: exit(0);break;
	}
}

void coursemod() //选课信息修改
{   int n, i=0, n1, s; 
    FILE *fp, *fp1, *fp2, *fp3;
	struct Course temp, cour[N1];
	color(15);
	gotoxy(26, 5);
    printf("*****选课信息修改模块*****\n");
    gotoxy(26, 6);
    printf("  查询前请先刷新系统 \n");
    gotoxy(26, 7);
    printf(" ********************* \n");
    gotoxy(26, 8);
    printf("  * 1.添加课程数据 *\n");
    gotoxy(26, 9);
    printf(" ********************* \n"); 
    gotoxy(26, 10);
    printf("  * 2.修改课程数据 *\n");
    gotoxy(26, 11);
    printf(" ********************* \n");
    gotoxy(26, 12);
    printf("  * 3.删除课程数据 *\n");
    gotoxy(26, 13);
    printf(" ********************* \n");
    gotoxy(26,14);
    printf("  * 4.恢复数据 *\n");
    gotoxy(26,15);
    printf(" ********************* \n");
    gotoxy(26, 16);
    printf("  * 5.返回上一级   *\n");
    gotoxy(26, 17);
    printf(" ********************* \n");
    gotoxy(26, 18);
    printf("  * 6.退出         * \n");
    gotoxy(26, 19);
    printf(" ********************* \n");
    gotoxy(26, 20);
    printf("请选择[1 2 3 4 5 6]:[ ]\b\b");
    color(14);
	scanf("%d", &n);
	switch(n)
	{ 
	case 1: 
		color(10);
		printf("请依次输入课程编号、名称、性质、总学时、授课学时、实验或上机学时、学分、开课学期\n");
		color(14);
		scanf("%d%s%s%d%d%d%f%d", &temp.num, temp.name, temp.nature, &temp.toperiod, &temp.giperiod, &temp.experiod, &temp.credit, &temp.term);
	    if((fp=fopen("d:\\course.txt", "a+"))==NULL){printf("无法打开此文件\n");exit(0);}
		fprintf(fp, "%d %s %s %d %d %d %.2f %d\n",temp.num, temp.name, temp.nature, temp.toperiod, temp.giperiod, temp.experiod, temp.credit, temp.term);
		fclose(fp);break;


	case 2: 
		color(10);
		printf("请输入需要修改的课程编号\n");
		color(14);
		scanf("%d", &temp.num);
        if((fp1=fopen("d:\\course.txt", "r+"))==NULL) {printf("无法打开此文件\n");exit(0);}
        while(!feof(fp1)){
		 fscanf(fp1, "%d%s%s%d%d%d%f%d\n", &cour[i].num, cour[i].name, cour[i].nature, &cour[i].toperiod, &cour[i].giperiod, &cour[i].experiod, &cour[i].credit, &cour[i].term);
        i++;}
	    for(s=0;s<i;s++)
	    if(cour[s].num==temp.num) {temp=cour[s];break;}
	    if(s==i) {printf("所输入的课程编号不存在\n");exit(0);}//Q1判断课程是否在其中
        printf("请输入需要修改项目的序号：1.名称2.性质3.总学时4.授课学时5.实验或上机学时6.学分7.开课学期\n");
		scanf("%d", &n1);
		switch(n1){		
		case 1: printf("请输入新的数据\n"); scanf("%s", temp.name);break;
		case 2: printf("请输入新的数据\n");scanf("%s", temp.nature); break;
		case 3: printf("请输入新的数据\n");scanf("%d", &temp.toperiod);break;
		case 4: printf("请输入新的数据\n");scanf("%d", &temp.giperiod);break;
		case 5:  printf("请输入新的数据\n");scanf("%d", &temp.experiod);break;
		case 6:  printf("请输入新的数据\n");scanf("%f", &temp.credit);break;
		case 7:  printf("请输入新的数据\n");scanf("%d", &temp.term);break;}	
		cour[s]=temp;
        color(10);
		fp2=fopen("d:\\course.txt", "w+");
		for(s=0;s<i;s++)
        fprintf(fp2, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
		fclose(fp1);
		fclose(fp2);
		break;
		
		
	case 3:
		color(10); 
		printf("请输入需要删除的课程编号\n");
		color(14);
		scanf("%d", &temp.num); 
		if((fp=fopen("d:\\course.txt", "r+"))==NULL){printf("无法打开此文件\n");exit(0);}
		while(!feof(fp)){
		            fscanf(fp, "%d%s%s%d%d%d%f%d\n", &cour[i].num, cour[i].name, cour[i].nature, &cour[i].toperiod, &cour[i].giperiod, &cour[i].experiod, &cour[i].credit, &cour[i].term);
		            i++;}//Q2\n必须存在
		fp1=fopen("d:\\course.txt", "w+");
		color(10);
		printf("请选择删除类型\n1.物理删除2.逻辑删除\n");
		color(14);
		scanf("%d",&n1);

		switch(n1){
		case 1:	
			for(s=0;s<i;s++)		
				if(cour[s].num!=temp.num)
             	fprintf(fp1, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
				fclose(fp1);fclose(fp);break;
		case 2:
			if((fp3=fopen("d:\\courserecycle.txt", "a+"))==NULL){printf("无法打开此文件\n");exit(0);}
			for(s=0;s<i;s++)		
				if(cour[s].num!=temp.num)
			     	fprintf(fp1, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
				else
					fprintf(fp3, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
				fclose(fp3);fclose(fp1);fclose(fp);break;}
		break;


	case 4: color(10);
		printf("请输入需要恢复的课程编号:\n");
		color(14);
		scanf("%d",&temp.num);

		if((fp=fopen("d:\\course.txt", "a+"))==NULL){printf("无法打开此文件\n");exit(0);}
	    if((fp1=fopen("d:\\courserecycle.txt", "r+"))==NULL){printf("无法打开此文件\n");exit(0);}
		while(!feof(fp1)){
			fscanf(fp1, "%d%s%s%d%d%d%f%d\n", &cour[i].num, cour[i].name, cour[i].nature, &cour[i].toperiod, &cour[i].giperiod, &cour[i].experiod, &cour[i].credit, &cour[i].term);
			i++;
		}
		for(s=0;s<i;s++){
			if(temp.num==cour[s].num)
			fprintf(fp, "%d %s %s %d %d %d %.2f %d\n",cour[s].num, cour[s].name, cour[s].nature, cour[s].toperiod, cour[s].giperiod, cour[s].experiod, cour[s].credit, cour[s].term);
		}fclose(fp1);fclose(fp);break;


	case 5: system("cls");welcome();break;
	case 6: exit(0);break;
	}
	color(10);
	printf("请选择1.返回上一级 2.返回主界面3.退出\n");
	scanf("%d",&n1);
	switch(n1){
	case 1:system("cls");coursemod();break;
	case 2:system("cls");welcome();break;
	case 3:exit(0);break;}
}
void studentmod() //学生信息修改
{   int n, i=0, n1, s, k; 
    FILE *fp, *fp1, *fp2, *fp3;
	struct Student temp, stu[N2];
	color(15);
	gotoxy(26, 5);
    printf("*****学生信息修改模块*****\n");
    gotoxy(26, 6);
    printf("  查询前请先刷新系统 \n");
    gotoxy(26, 7);
    printf(" ********************* \n");
    gotoxy(26, 8);
    printf("  * 1.添加学生数据 *\n");
    gotoxy(26, 9);
    printf(" ********************* \n"); 
    gotoxy(26, 10);
    printf("  * 2.修改学生数据 *\n");
    gotoxy(26, 11);
    printf(" ********************* \n");
    gotoxy(26, 12);
    printf("  * 3.删除学生数据 *\n");
    gotoxy(26, 13);
    printf(" ********************* \n");
    gotoxy(26, 14);
    printf("  * 4.恢复数据     *\n");
    gotoxy(26, 15);
    printf(" ********************* \n");
    gotoxy(26, 16);
    printf("  * 5.返回上一级   *\n");
    gotoxy(26, 17);
    printf(" ********************* \n");
    gotoxy(26, 18);
    printf("  * 6.退出         * \n");
    gotoxy(26, 19);
    printf(" ********************* \n");
    gotoxy(26, 20);
    printf("请选择[1 2 3 4 5 6]:[ ]\b\b");
    color(14);
	scanf("%d", &n);
	switch(n){ 
	case 1:
		color(10);
		printf("请依次输入学号、姓名、选课的课程编号（10个）\n");
		color(14);
		scanf("%d%s%d%d%d%d%d%d%d%d%d%d", &temp.num, temp.name, &temp.course[0], &temp.course[1], &temp.course[2], &temp.course[3],&temp.course[4], &temp.course[5], &temp.course[6], &temp.course[7],&temp.course[8], &temp.course[9]);
	    if((fp=fopen("d:\\student.txt", "a+"))==NULL){printf("无法打开此文件\n");exit(0);}
		fprintf(fp, "%d %s %d %d %d %d %d %d %d %d %d %d\n", temp.num, temp.name, temp.course[0], temp.course[1], temp.course[2], temp.course[3], temp.course[4], temp.course[5], temp.course[6], temp.course[7], temp.course[8], temp.course[9]);
		fclose(fp);break;


	case 2: 
		color(10);
		printf("请输入需要修改的学生学号\n");
		color(14);
		scanf("%d", &temp.num);
		if((fp1=fopen("d:\\student.txt", "r+"))==NULL){printf("无法打开此文件\n");exit(0);}
        while(!feof(fp1)){
		fscanf(fp1, "%d%s%d%d%d%d%d%d%d%d%d%d\n", &stu[i].num, stu[i].name, &stu[i].course[0], &stu[i].course[1], &stu[i].course[2], &stu[i].course[3],&stu[i].course[4], &stu[i].course[5], &stu[i].course[6], &stu[i].course[7],&stu[i].course[8], &stu[i].course[9]);
        i++;}
	    for(s=0;s<i;s++)
	    if(stu[s].num==temp.num) {temp=stu[s];break;}
	    if(s==i) {printf("所输入的学号不存在\n");exit(0);}
        printf("请输入需要修改项目的序号：1.名字2.课程编号（十个）\n");
		scanf("%d", &n1);
		switch(n1){		
		case 1: printf("请输入新的数据\n"); scanf("%s", temp.name);break;
		case 2: printf("请输入新的数据\n");
			for(k=0; k<10; k++)
			scanf("%d", &temp.course[k]);}
		stu[s]=temp;
        color(10);
		for(s=0;s<i;s++){
	    fp2=fopen("d:\\student.txt", "w+");
	    fprintf(fp2, "%d %s %d %d %d %d %d %d %d %d %d %d\n", temp.num, temp.name, temp.course[0], temp.course[1], temp.course[2], temp.course[3], temp.course[4], temp.course[5], temp.course[6], temp.course[7], temp.course[8], temp.course[9]);}
		fclose(fp1);fclose(fp2);break;
		break;
		

	case 3: 
		color(10);
		printf("请输入需要删除的学生学号\n");
		color(14);
		scanf("%d", &temp.num);
		color(10);
	    printf("请选择删除类型\n1.物理删除2.逻辑删除\n");
		color(14);
		scanf("%d",&n1);
        if((fp=fopen("d:\\student.txt", "r+"))==NULL){printf("无法打开此文件\n");exit(0);}
		while(!feof(fp)){
				fscanf(fp, "%d%s%d%d%d%d%d%d%d%d%d%d\n", &stu[i].num, stu[i].name, &stu[i].course[0], &stu[i].course[1], &stu[i].course[2], &stu[i].course[3],&stu[i].course[4], &stu[i].course[5], &stu[i].course[6], &stu[i].course[7],&stu[i].course[8], &stu[i].course[9]);
				i++;}
		fp1=fopen("d:\\student.txt", "w+");
		switch(n1){
		case 1:
			
			for(s=0;s<i;s++)	
				if(stu[s].num!=temp.num)
					fprintf(fp1, "%d %s %d %d %d %d %d %d %d %d %d %d\n",stu[s].num, stu[s].name, stu[s].course[0], stu[s].course[1], stu[s].course[2], stu[s].course[3],stu[s].course[4], stu[s].course[5], stu[s].course[6], stu[s].course[7], stu[s].course[8], stu[s].course[9]);
                    fclose(fp1);fclose(fp);break;
		case 2:
			if((fp3=fopen("d:\\studentrecycle.txt", "a+"))==NULL){printf("无法打开此文件\n");exit(0);}
			for(s=0;s<i;s++)		
				if(stu[s].num!=temp.num)
					fprintf(fp1, "%d %s %d %d %d %d %d %d %d %d %d %d\n",stu[s].num, stu[s].name, stu[s].course[0], stu[s].course[1], stu[s].course[2], stu[s].course[3],stu[s].course[4], stu[s].course[5], stu[s].course[6], stu[s].course[7], stu[s].course[8], stu[s].course[9]);
				else
					fprintf(fp3, "%d %s %d %d %d %d %d %d %d %d %d %d\n",stu[s].num, stu[s].name, stu[s].course[0], stu[s].course[1], stu[s].course[2], stu[s].course[3],stu[s].course[4], stu[s].course[5], stu[s].course[6], stu[s].course[7], stu[s].course[8], stu[s].course[9]);	
			        fclose(fp3);fclose(fp1);fclose(fp);break;}
		break;


	case 4: 
		color(10);
		printf("请输入需要恢复数据的学生学号:\n");
		color(14);
		scanf("%d",&temp.num);
		if((fp=fopen("d:\\student.txt", "a+"))==NULL){printf("无法打开此文件\n");exit(0);}
	    if((fp1=fopen("d:\\studentrecycle.txt", "r+"))==NULL){printf("无法打开此文件\n");exit(0);}
		while(!feof(fp1)){
			fscanf(fp1, "%d%s%d%d%d%d%d%d%d%d%d%d\n", &stu[i].num, stu[i].name, &stu[i].course[0], &stu[i].course[1], &stu[i].course[2], &stu[i].course[3],&stu[i].course[4], &stu[i].course[5], &stu[i].course[6], &stu[i].course[7],&stu[i].course[8], &stu[i].course[9]);
			i++;
		}
		for(s=0;s<i;s++){
			if(temp.num==stu[s].num)
			fprintf(fp, "%d %s %d %d %d %d %d %d %d %d %d %d\n",stu[s].num, stu[s].name, stu[s].course[0], stu[s].course[1], stu[s].course[2], stu[s].course[3],stu[s].course[4], stu[s].course[5], stu[s].course[6], stu[s].course[7], stu[s].course[8], stu[s].course[9]);
		}fclose(fp1);fclose(fp);break;


	case 5: system("cls");welcome();break;
	case 6: exit(0);break;
		}
	color(10);
	printf("请选择1.返回上一级 2.返回主界面3.退出\n");
	scanf("%d",&n1);
	switch(n1){
	case 1:system("cls");studentmod();break;
	case 2:system("cls");welcome();break;
	case 3:exit(0);break;}

}
void classcheck()//选课信息查询
{	
	int num=0,i,j=0,n;
	char nam[50]="0";
	FILE *fp;
	struct Course cla[N1];
	color(15);
	gotoxy(26,4);
	printf("*************************\n");
	gotoxy(26,5);
    printf("*****课程信息查询模块*****\n");
    gotoxy(26, 6);
    printf("  查询前请先刷新系统 \n");
    gotoxy(26, 7);
    printf(" ********************* \n");
    gotoxy(26, 8);
    printf("  * 1.按课程编号查询 *\n");
    gotoxy(26, 9);
    printf(" ********************* \n"); 
    gotoxy(26, 10);
    printf("  * 2.按课程名称查询 *\n");
    gotoxy(26, 11);
    printf(" ********************* \n");
    gotoxy(26, 12);
    printf("  * 3.返回上一级 *\n");
    gotoxy(26, 13);
    printf(" ********************* \n");
    gotoxy(26, 14);
    printf("请选择[1 2 3]:[ ]\b\b");
	scanf("%d",&n);
	switch(n){
	case 1:
		color(10);
		printf("输入课程编号:\n");
		color(14);
		scanf("%d",&num);
		break;


	case 2:
		color(10);
		printf("输入课程名称\n");
		color(14);
		scanf("%s",nam);
		break;


	case 3:system("cls");welcome();break;
	}
	if((fp=fopen("d:\\course.txt", "r"))==NULL)	{printf("无法打开此文件\n");exit(0);}
	for(i=0;!(feof(fp));i++){
		fscanf(fp,"%d%s%s%d%d%d%f%d",&cla[i].num,cla[i].name,cla[i].nature,&cla[i].toperiod,&cla[i].giperiod,&cla[i].experiod,&cla[i].credit,&cla[i].term);
		if(num==cla[i].num||strcmp(nam,cla[i].name)==0)
			printf("课程编号:%07d 名称:%s 性质:%s 总学时:%d 授课学时:%d 实验或上机学时:%d 学分:%.2f 上课学期:%d\n",cla[i].num,cla[i].name,cla[i].nature,cla[i].toperiod,cla[i].giperiod,cla[i].experiod,cla[i].credit,cla[i].term);
		else j++;
	}
	if(i==j){
		color(10);
		printf("查询不到该条选课信息\n");
	}
	fclose(fp);
    color(10);
	printf("请选择1.返回上一级 2.返回主界面3.退出\n");
	scanf("%d",&n);
	switch(n){
	case 1:system("cls");classcheck();break;
	case 2:system("cls");welcome();break;
	case 3:exit(0);break;}

}
void stucheck()//学生信息查询
{	
	int num=0,i,j,k,n,g, l=0, m, n1;
	char nam[20]="0";
	FILE *fp1,*fp2;
	struct Course cla[N1];
	struct Student stu[N2];
    color(15);
	gotoxy(26,4);
	printf("*************************\n");
	gotoxy(26,5);
    printf("*****学生信息查询模块*****\n");
    gotoxy(26, 6);
    printf("  查询前请先刷新系统 \n");
    gotoxy(26, 7);
    printf(" ********************* \n");
    gotoxy(26, 8);
    printf("  * 1.按学号查询  *\n");
    gotoxy(26, 9);
    printf(" ********************* \n"); 
    gotoxy(26, 10);
    printf("  * 2.按名字查询  *\n");
    gotoxy(26, 11);
    printf(" ********************* \n");
    gotoxy(26, 12);
    printf("  * 3.返回上一级  *\n");
    gotoxy(26, 13);
    printf(" ********************* \n");
    gotoxy(26, 14);
    printf("请选择[1 2 3]:[ ]\b\b");
	scanf("%d",&n);
	switch(n){
	case 1:
		color(10);
		printf("输入学号\n");
		color(14);
		scanf("%d",&num);
		break;


	case 2:
		color(10);
		printf("输入姓名\n");
		color(14);
		scanf("%s",nam);
		break;


	case 3:system("cls");welcome();break;
	}
	
    if((fp2=fopen("d:\\course.txt", "r"))==NULL){printf("无法打开此文件\n");exit(0);}
	for(j=0;!(feof(fp2));j++)
	fscanf(fp2,"%d%s%s%d%d%d%f%d",&cla[j].num,cla[j].name,cla[j].nature,&cla[j].toperiod,&cla[j].giperiod,&cla[j].experiod,&cla[j].credit,&cla[j].term);
	
	
	if((fp1=fopen("d:\\student.txt","r"))==NULL){printf("无法打开此文件\n");exit(0);}
	for(i=0;!(feof(fp1));i++)
	fscanf(fp1,"%d%s%d%d%d%d%d%d%d%d%d%d/n",&stu[i].num,stu[i].name,&stu[i].course[0],&stu[i].course[1],&stu[i].course[2],&stu[i].course[3],&stu[i].course[4],&stu[i].course[5],&stu[i].course[6],&stu[i].course[7],&stu[i].course[8],&stu[i].course[9]);
				
    for(m=0; m<i; m++)
	 if(num==stu[m].num||strcmp(nam,stu[m].name)==0){
	    printf("学生信息\n学生学号:%d 学生姓名:%s 学生课程的编号:%07d %07d %07d %07d %07d %07d %07d %07d %07d %07d\n",stu[m].num,stu[m].name,stu[m].course[0],stu[m].course[1],stu[m].course[2],stu[m].course[3],stu[m].course[4],stu[m].course[5],stu[m].course[6],stu[m].course[7],stu[m].course[8],stu[m].course[9]); 
		for(g=0; g<10; g++)
		   for(k=0; k<j; k++)
			   if(stu[m].course[g]==cla[k].num) printf("课程编号:%07d 名称:%s 性质:%s 总学时:%d 授课学时:%d 实验或上机学时:%d 学分:%.2f 上课学期:%d\n",cla[k].num,cla[k].name,cla[k].nature,cla[k].toperiod,cla[k].giperiod,cla[k].experiod,cla[k].credit,cla[k].term);}

	 else l++;
	if(i==l){color(10);printf("查询不到该条选课信息\n");}
    fclose(fp2);fclose(fp1);
	color(10);
	printf("请选择1.返回上一级 2.返回主界面3.退出\n");
	scanf("%d",&n1);
	switch(n1){
	case 1:system("cls");stucheck();break;
	case 2:system("cls");welcome();break;
	case 3:exit(0);break;}

}