//Falcon-180B DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct
{
    char name[20];
    int roll_no;
    int marks;
}student;

void add_student(student *s)
{
    printf("Enter name of the student: ");
    scanf("%s",s->name);
    printf("Enter roll number of the student: ");
    scanf("%d",&s->roll_no);
    printf("Enter marks of the student: ");
    scanf("%d",&s->marks);
    printf("\nStudent added successfully!");
}

void display_students(student s[],int n)
{
    printf("\nName\tRoll No.\tMarks\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t%d\t%d\n",s[i].name,s[i].roll_no,s[i].marks);
    }
}

void search_student(student s[],int n)
{
    char name[20];
    printf("\nEnter name of the student to search: ");
    scanf("%s",name);
    for(int i=0;i<n;i++)
    {
        if(strcmp(s[i].name,name)==0)
        {
            printf("\nName: %s",s[i].name);
            printf("\nRoll No.: %d",s[i].roll_no);
            printf("\nMarks: %d",s[i].marks);
        }
    }
}

void main()
{
    student s[MAX_SIZE];
    int n=0;

    while(TRUE)
    {
        printf("\n1.Add Student\n2.Display Students\n3.Search Student\n4.Exit");
        int choice;
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                if(n==MAX_SIZE)
                {
                    printf("\nMaximum number of students reached!");
                }
                else
                {
                    add_student(&s[n]);
                    n++;
                }
                break;

            case 2:
                if(n==0)
                {
                    printf("\nNo students added yet!");
                }
                else
                {
                    display_students(s,n);
                }
                break;

            case 3:
                if(n==0)
                {
                    printf("\nNo students added yet!");
                }
                else
                {
                    search_student(s,n);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }
}