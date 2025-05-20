//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a structure to store student information
typedef struct Student
{
    char name[50];
    int roll_no;
    float marks;
} Student;

// Function to insert a student into the database
void insertStudent(Student *student)
{
    printf("Enter student's name: ");
    scanf("%s", student->name);

    printf("Enter student's roll number: ");
    scanf("%d", &student->roll_no);

    printf("Enter student's marks: ");
    scanf("%f", &student->marks);
}

// Function to search for a student in the database
Student *searchStudent(Student *students, int numStudents, char *name)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            return &students[i];
        }
    }

    return NULL;
}

// Function to update a student's marks in the database
void updateStudentMarks(Student *student, float newMarks)
{
    student->marks = newMarks;
}

// Function to delete a student from the database
void deleteStudent(Student *students, int numStudents, int rollNo)
{
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].roll_no == rollNo)
        {
            students[i] = students[numStudents - 1];
            numStudents--;
            return;
        }
    }

    printf("Student not found.");
}

int main()
{
    // Create an array of students
    Student students[100];

    // Insert some students into the database
    insertStudent(&students[0]);
    insertStudent(&students[1]);
    insertStudent(&students[2]);

    // Search for a student in the database
    Student *student = searchStudent(students, 3, "John Doe");

    // If the student is found, update their marks
    if (student)
    {
        updateStudentMarks(student, 90.0);
    }

    // Delete a student from the database
    deleteStudent(students, 3, 123);

    return 0;
}