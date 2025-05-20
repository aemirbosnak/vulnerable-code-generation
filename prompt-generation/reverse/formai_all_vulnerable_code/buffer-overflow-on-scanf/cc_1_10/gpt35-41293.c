//FormAI DATASET v1.0 Category: Online Examination System ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
    char name[50];
    int roll_no;
    int marks;
    int total_marks;
};

int main()
{
    int n,i,j,total_questions,answer,correct_answer=0,wrong_answer=0;
    printf("\nWelcome to the Online Examination System!\n");
    printf("\nEnter number of students: ");
    scanf("%d",&n);
    printf("\nEnter total number of questions in the examination: ");
    scanf("%d",&total_questions);
    struct student s[n];
    for(i=0;i<n;i++)
    {
        printf("\nStudent %d\n",i+1);
        printf("Enter name: ");
        scanf("%s",s[i].name);
        printf("Enter roll number: ");
        scanf("%d",&s[i].roll_no);
        s[i].total_marks=total_questions;
        for(j=0;j<total_questions;j++)
        {
            printf("Question %d: ",j+1);
            scanf("%d",&answer);
            if(answer==2)
                correct_answer++;
            else
                wrong_answer++;
        }
        s[i].marks=correct_answer;
        correct_answer=0;
        wrong_answer=0;
    }
    printf("\n\n---Results---\n\n");
    printf("Name\tRoll No.\tMarks\n");
    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t\t%d/%d\n",s[i].name,s[i].roll_no,s[i].marks,s[i].total_marks);
    }
    return 0;
}