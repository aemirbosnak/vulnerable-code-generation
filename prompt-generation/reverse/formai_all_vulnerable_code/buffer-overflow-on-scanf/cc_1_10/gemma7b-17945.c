//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of questions
#define MAX_QUESTIONS 50

// Define the maximum number of attempts
#define MAX_ATTEMPTS 3

// Student structure
typedef struct Student {
    char name[50];
    int rollNo;
    float marks[MAX_QUESTIONS];
    int attempts[MAX_ATTEMPTS];
} Student;

// Function to read student data
void readStudentData(Student *student) {
    printf("Enter student name: ");
    scanf("%s", student->name);

    printf("Enter student roll number: ");
    scanf("%d", &student->rollNo);

    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter student marks for question %d: ", i + 1);
        scanf("%f", &student->marks[i]);
    }

    for (int i = 0; i < MAX_ATTEMPTS; i++) {
        printf("Enter number of attempts for attempt %d: ", i + 1);
        scanf("%d", &student->attempts[i]);
    }
}

// Function to calculate student marks
float calculateStudentMarks(Student student) {
    int totalMarks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        totalMarks += student.marks[i];
    }

    return (totalMarks / MAX_QUESTIONS) * 100;
}

// Function to print student results
void printStudentResults(Student student) {
    printf("Student Name: %s\n", student.name);
    printf("Roll No: %d\n", student.rollNo);
    printf("Marks: %.2f%%\n", calculateStudentMarks(student));
    printf("Attempts: %d\n", student.attempts[0]);
}

int main() {
    Student students[MAX_STUDENTS];

    // Read student data
    readStudentData(&students[0]);

    // Calculate student marks
    float marks = calculateStudentMarks(students[0]);

    // Print student results
    printStudentResults(students[0]);

    return 0;
}