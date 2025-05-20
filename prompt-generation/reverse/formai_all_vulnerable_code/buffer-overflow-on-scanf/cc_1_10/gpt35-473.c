//FormAI DATASET v1.0 Category: Database simulation ; Style: excited
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// STRUCT DECLARATION
struct student
{
    char name[20];
    int age;
    char course[10];
    int marks;
} s[100];

// FUNCTION DECLARATION
void displayMenu();
void addStudent();
void updateStudent();
void deleteStudent();
void searchStudent();

// GLOBAL VARIABLES
int n=0; //number of students stored in database

//MAIN FUNCTION
int main()
{
    int choice;
    displayMenu();
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    while(choice!=0)
    {
        switch(choice)
        {
            case 1:
                addStudent();
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                break;
            case 2:
                updateStudent();
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                break;
            case 3:
                deleteStudent();
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                break;
            case 4:
                searchStudent();
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                break;
            default:
                printf("\nInvalid Choice!!");
                printf("\nEnter your choice: ");
                scanf("%d",&choice);
                break;
        }
    }

    printf("\nThank you for using Student Database System!");
    return 0;
}

// FUNCTION DEFINITION
void displayMenu()
{
    printf("\t********** MENU ************\n\n");
    printf("\t1. Add Student\n");
    printf("\t2. Update Student\n");
    printf("\t3. Delete Student\n");
    printf("\t4. Search Student\n");
    printf("\t0. Exit\n");
    printf("\n\t*****************************\n");
}

void addStudent()
{
    printf("\nEnter Student Details:\n");
    printf("Name: ");
    scanf("%s", s[n].name);
    printf("Age: ");
    scanf("%d", &s[n].age);
    printf("Course: ");
    scanf("%s", s[n].course);
    printf("Marks: ");
    scanf("%d", &s[n].marks);
    printf("\nStudent added successfully!\n");

    n++; // increment student count
}

void updateStudent()
{
    int i,flag=0;
    char name[20];
    printf("\nEnter Name of Student to Update: ");
    scanf("%s", name);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].name,name)==0)
        {
            printf("\nEnter Updated Student Details:\n");
            printf("Name: ");
            scanf("%s", s[i].name);
            printf("Age: ");
            scanf("%d", &s[i].age);
            printf("Course: ");
            scanf("%s", s[i].course);
            printf("Marks: ");
            scanf("%d", &s[i].marks);
            printf("\nStudent updated successfully!\n");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Invalid Name! Student not found in database.\n");
    }
}

void deleteStudent()
{
    int i,j,flag=0;
    char name[20];
    printf("\nEnter Name of Student to Delete: ");
    scanf("%s", name);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].name,name)==0)
        {
            for(j=i;j<n-1;j++)
            {
                s[j]=s[j+1]; // shift all students one position left
            }
            n--; // decrement student count
            printf("Student deleted successfully!\n");
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Invalid Name! Student not found in database.\n");
    }
}

void searchStudent()
{
    int i,flag=0;
    char name[20];
    printf("\nEnter Name of Student to Search: ");
    scanf("%s", name);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].name,name)==0)
        {
            printf("\n\tStudent Details:\n");
            printf("\tName  : %s\n", s[i].name);
            printf("\tAge   : %d\n", s[i].age);
            printf("\tCourse: %s\n", s[i].course);
            printf("\tMarks : %d\n", s[i].marks);
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("Invalid Name! Student not found in database.\n");
    }
}