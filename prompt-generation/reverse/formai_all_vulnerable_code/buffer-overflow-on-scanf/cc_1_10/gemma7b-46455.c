//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store student data
typedef struct student
{
    char name[50];
    int roll_no;
    float marks;
} student;

// Function to insert a student into the database
void insert_student(student *s)
{
    printf("Enter student name: ");
    scanf("%s", s->name);

    printf("Enter student roll no: ");
    scanf("%d", &s->roll_no);

    printf("Enter student marks: ");
    scanf("%f", &s->marks);
}

// Function to display all students
void display_students(student *s)
{
    printf("List of students:\n");

    for (int i = 0; s[i].name != NULL; i++)
    {
        printf("Name: %s\n", s[i].name);
        printf("Roll No: %d\n", s[i].roll_no);
        printf("Marks: %.2f\n", s[i].marks);
        printf("\n");
    }
}

int main()
{
    // Create an array of students
    student *s = NULL;

    // Insert a student into the database
    insert_student(s);

    // Insert another student into the database
    insert_student(s);

    // Display all students
    display_students(s);

    return 0;
}