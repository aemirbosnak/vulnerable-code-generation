//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of exams
#define MAX_EXAMS 20

// Define the maximum number of marks for each exam
#define MAX_MARKS 100

// Student structure
typedef struct Student
{
    char name[50];
    int roll_no;
    float marks[MAX_EXAMS];
    char status;
} Student;

// Exam structure
typedef struct Exam
{
    char subject_name[50];
    int marks[MAX_STUDENTS];
    float average_marks;
} Exam;

// Function to add a student
void add_student(Student *students)
{
    // Allocate memory for a new student
    students = (Student *)realloc(students, (MAX_STUDENTS + 1) * sizeof(Student));

    // Get the student's name, roll number, and marks
    printf("Enter student's name: ");
    scanf("%s", students[MAX_STUDENTS].name);

    printf("Enter student's roll number: ");
    scanf("%d", &students[MAX_STUDENTS].roll_no);

    printf("Enter student's marks for each exam: ");
    for (int i = 0; i < MAX_EXAMS; i++)
    {
        scanf("%f", &students[MAX_STUDENTS].marks[i]);
    }

    // Set the student's status
    students[MAX_STUDENTS].status = 'A';
}

// Function to add an exam
void add_exam(Exam *exams)
{
    // Allocate memory for a new exam
    exams = (Exam *)realloc(exams, (MAX_EXAMS + 1) * sizeof(Exam));

    // Get the exam's name, marks for each student, and average marks
    printf("Enter exam's name: ");
    scanf("%s", exams[MAX_EXAMS].subject_name);

    printf("Enter marks for each student: ");
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        scanf("%d", &exams[MAX_EXAMS].marks[i]);
    }

    // Calculate the average marks for the exam
    exams[MAX_EXAMS].average_marks = (float)(sum_marks(exams[MAX_EXAMS].marks) / MAX_STUDENTS);
}

// Function to sum the marks of an array of numbers
int sum_marks(int *marks)
{
    int sum = 0;
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        sum += marks[i];
    }
    return sum;
}

// Main function
int main()
{
    // Create an array of students
    Student *students = NULL;

    // Create an array of exams
    Exam *exams = NULL;

    // Add some students and exams
    add_student(students);
    add_student(students);
    add_exam(exams);
    add_exam(exams);

    // Print the students' marks
    for (int i = 0; i < MAX_STUDENTS; i++)
    {
        printf("Student name: %s\n", students[i].name);
        printf("Roll number: %d\n", students[i].roll_no);
        printf("Marks: ");
        for (int j = 0; j < MAX_EXAMS; j++)
        {
            printf("%f ", students[i].marks[j]);
        }
        printf("\n");
    }

    // Print the exams' average marks
    for (int i = 0; i < MAX_EXAMS; i++)
    {
        printf("Exam name: %s\n", exams[i].subject_name);
        printf("Average marks: %f\n", exams[i].average_marks);
        printf("\n");
    }

    return 0;
}