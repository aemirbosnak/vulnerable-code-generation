//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: genius
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store student data
typedef struct student
{
    char name[20];
    int rollno;
    float marks;
} student;

// Function to insert a student into the database
void insertStudent(student *s)
{
    printf("Enter student name: ");
    scanf("%s", s->name);

    printf("Enter student roll no: ");
    scanf("%d", &s->rollno);

    printf("Enter student marks: ");
    scanf("%f", &s->marks);
}

// Function to display all students
void displayStudents(student *s)
{
    printf("List of students:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("Name: %s\n", s[i].name);
        printf("Roll No: %d\n", s[i].rollno);
        printf("Marks: %.2f\n", s[i].marks);
    }
}

int main()
{
    // Create an array of students
    student *s = (student *)malloc(10 * sizeof(student));

    // Insert students into the database
    insertStudent(s);
    insertStudent(s);
    insertStudent(s);

    // Display all students
    displayStudents(s);

    return 0;
}