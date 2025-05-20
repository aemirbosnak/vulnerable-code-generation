//FormAI DATASET v1.0 Category: Online Examination System ; Style: Dennis Ritchie
#include<stdio.h>

struct student
{
    int roll_no;
    char name[25];
    float marks;
};

void input(struct student s[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the details of student %d:\n",i+1);
        printf("Roll No: ");
        scanf("%d",&s[i].roll_no);

        printf("Name: ");
        scanf("%s",s[i].name);

        printf("Marks: ");
        scanf("%f",&s[i].marks);
    }
}

void display(struct student s[], int n)
{
    int i;
    printf("\n--------------------------------------------------\n");
    printf("\t\tSTUDENT DETAILS\n");
    printf("--------------------------------------------------\n");
    printf("Roll No\t\tName\t\tMarks\n");
    printf("--------------------------------------------------\n");

    for(i=0;i<n;i++)
    {
        printf("%d\t\t%s\t\t%.2f\n",s[i].roll_no,s[i].name,s[i].marks);
    }
}

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d",&n);

    struct student s[n];

    input(s,n);

    display(s,n);

    return 0;
}