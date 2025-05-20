//FormAI DATASET v1.0 Category: Online Examination System ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct student
{
    char name[100];
    int rollno;
    float marks;
};

// Function to insert student details
void insertStudent(struct student *s)
{
    printf("\nEnter student name: ");
    scanf("%s",s->name);
    printf("Enter student roll number: ");
    scanf("%d",&s->rollno);
    printf("Enter student marks: ");
    scanf("%f",&s->marks);
}

// Function to display a particular student's details
void displayStudent(struct student s)
{
    printf("\nName: %s",s.name);
    printf("\nRoll No: %d",s.rollno);
    printf("\nMarks: %.2f",s.marks);
}

// Function to display all students' details
void displayAllStudents(struct student *s, int n)
{
    int i;
    printf("\n---Student Details---\n");
    for(i=0;i<n;i++)
    {
        displayStudent(s[i]);
    }
    printf("\n");
}

// Function to search for a student by roll number
void searchStudent(struct student *s, int n)
{
    int rno,i,flag = 0;
    printf("\nEnter student roll number to search: ");
    scanf("%d",&rno);
    for(i=0;i<n;i++)
    {
        if(s[i].rollno == rno)
        {
            displayStudent(s[i]);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nNo such student found!\n");
    }
}

// Function to update a student's details
void updateStudent(struct student *s, int n)
{
    int rno,i,flag = 0;
    printf("\nEnter student roll number to update: ");
    scanf("%d",&rno);
    for(i=0;i<n;i++)
    {
        if(s[i].rollno == rno)
        {
            printf("\nEnter new details:\n");
            insertStudent(&s[i]);
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nNo such student found!\n");
    }
}

// Function to delete a student's details
void deleteStudent(struct student *s, int *n)
{
    int rno,i,flag = 0;
    printf("\nEnter student roll number to delete: ");
    scanf("%d",&rno);
    for(i=0;i<*n;i++)
    {
        if(s[i].rollno == rno)
        {
            while(i<*n-1)
            {
                s[i] = s[i+1];
                i++;
            }
            (*n)--;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("\nNo such student found!\n");
    }
}

// Main function
int main()
{
    int n=0,choice;
    struct student *s;
    s = (struct student*)malloc(sizeof(struct student));
    do
    {
        printf("\n---Menu---");
        printf("\n1. Insert new student");
        printf("\n2. Display all students");
        printf("\n3. Search for a student");
        printf("\n4. Update a student's details");
        printf("\n5. Delete a student's details");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: 
                    n++;
                    s = (struct student*)realloc(s,n*sizeof(struct student));
                    insertStudent(&s[n-1]);
                    break;

            case 2: 
                    displayAllStudents(s,n);
                    break;

            case 3: 
                    searchStudent(s,n);
                    break;

            case 4: 
                    updateStudent(s,n);
                    break;

            case 5: 
                    deleteStudent(s,&n);
                    break;

            case 6: 
                    printf("\nExiting...\n");
                    break;

            default: 
                    printf("\nInvalid choice!\n");
                    break;
        }
    }while(choice != 6);
    free(s);
    return 0;
}