//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// Define a structure for student information
typedef struct student
{
    char name[50];
    int roll_no;
    float marks;
} student;

// Function to compare two students
int compare_students(student a, student b)
{
    return a.marks - b.marks;
}

// Function to create a student
student create_student()
{
    student s;
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Enter roll no: ");
    scanf("%d", &s.roll_no);
    printf("Enter marks: ");
    scanf("%f", &s.marks);
    return s;
}

// Function to display student information
void display_student(student s)
{
    printf("Name: %s\n", s.name);
    printf("Roll No: %d\n", s.roll_no);
    printf("Marks: %.2f\n", s.marks);
}

int main()
{
    // Create an array of students
    student students[100];

    // Create and display a student
    students[0] = create_student();
    display_student(students[0]);

    // Sort the students by marks
    qsort(students, 100, sizeof(student), compare_students);

    // Display the sorted students
    for (int i = 0; i < 100; i++)
    {
        display_student(students[i]);
    }

    return 0;
}