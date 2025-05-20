//Falcon-180B DATASET v1.0 Category: File handling ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define max 100

typedef struct
{
    char name[30];
    int age;
    int rollno;
    float marks;
}student;

void main()
{
    FILE *fp;
    int i,n,ch;
    student s[10];
    char filename[50];
    printf("Enter the name of the file: ");
    scanf("%s",filename);
    fp=fopen(filename,"a");
    if(fp==NULL)
    {
        printf("File not found");
        exit(0);
    }
    printf("Enter the number of students: ");
    scanf("%d",&n);
    printf("Enter the details of the students:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter the name of the student: ");
        scanf("%s",s[i].name);
        printf("Enter the age of the student: ");
        scanf("%d",&s[i].age);
        printf("Enter the roll number of the student: ");
        scanf("%d",&s[i].rollno);
        printf("Enter the marks of the student: ");
        scanf("%f",&s[i].marks);
        fprintf(fp,"%s\t%d\t%d\t%.2f\n",s[i].name,s[i].age,s[i].rollno,s[i].marks);
    }
    printf("Do you want to view the file? (y/n)");
    scanf(" %c",&ch);
    if(ch=='y'||ch=='Y')
    {
        rewind(fp);
        while(!feof(fp))
        {
            fscanf(fp,"%s\t%d\t%d\t%.2f",s[i].name,&s[i].age,&s[i].rollno,&s[i].marks);
            printf("%s\t%d\t%d\t%.2f\n",s[i].name,s[i].age,s[i].rollno,s[i].marks);
        }
    }
    fclose(fp);
}