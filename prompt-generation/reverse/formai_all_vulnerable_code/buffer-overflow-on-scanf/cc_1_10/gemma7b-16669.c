//Gemma-7B DATASET v1.0 Category: Online Examination System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of students
#define MAX_STUDENTS 100

// Define the maximum number of questions
#define MAX_QUESTIONS 50

// Define the maximum number of attempts
#define MAX_ATTEMPTS 3

// Define the student structure
typedef struct student {
    char name[50];
    int rollno;
    float marks[MAX_QUESTIONS];
    int attempts[MAX_ATTEMPTS];
} student;

// Function to create a student
student *createStudent() {
    student *s = (student *)malloc(sizeof(student));
    s->name[0] = '\0';
    s->rollno = 0;
    s->marks[0] = 0.0f;
    s->attempts[0] = 0;
    return s;
}

// Function to add a student
void addStudent(student **students, int *numStudents) {
    *students = (student *)realloc(*students, (*numStudents + 1) * sizeof(student));
    (*numStudents)++;
    students[*numStudents - 1] = createStudent();
}

// Function to take student marks
void takeMarks(student *s) {
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("Enter marks for question %d: ", i + 1);
        scanf("%f", &s->marks[i]);
    }
}

// Function to check if a student has passed
int hasPassed(student *s) {
    int totalMarks = 0;
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        totalMarks += s->marks[i];
    }
    return totalMarks / MAX_QUESTIONS >= 50;
}

// Function to display student results
void displayResults(student *s) {
    printf("Student name: %s\n", s->name);
    printf("Roll no: %d\n", s->rollno);
    printf("Marks: ");
    for (int i = 0; i < MAX_QUESTIONS; i++) {
        printf("%d ", (int)s->marks[i]);
    }
    printf("\n");
    if (hasPassed(s)) {
        printf("Pass\n");
    } else {
        printf("Fail\n");
    }
}

int main() {
    // Create an array of students
    student **students = NULL;
    int numStudents = 0;

    // Add some students
    addStudent(students, &numStudents);
    addStudent(students, &numStudents);
    addStudent(students, &numStudents);

    // Take student marks
    takeMarks(students[0]);
    takeMarks(students[1]);
    takeMarks(students[2]);

    // Display student results
    displayResults(students[0]);
    displayResults(students[1]);
    displayResults(students[2]);

    return 0;
}