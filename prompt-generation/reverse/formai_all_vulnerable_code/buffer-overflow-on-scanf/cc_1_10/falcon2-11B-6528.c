//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int numQuestions;
int numStudents;
int numCorrect;
int *studentScores;
int *questions;

// Function prototypes
void readQuestions();
void readStudentScores();
void printScores();

int main() {
    // Read questions
    readQuestions();

    // Read student scores
    readStudentScores();

    // Print scores
    printScores();

    return 0;
}

void readQuestions() {
    // Read number of questions
    printf("Enter number of questions: ");
    scanf("%d", &numQuestions);

    // Allocate memory for questions array
    questions = (int*)malloc(numQuestions * sizeof(int));

    // Read questions
    printf("Enter questions:\n");
    for (int i = 0; i < numQuestions; i++) {
        scanf("%d", &questions[i]);
    }
}

void readStudentScores() {
    // Read number of students
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    // Allocate memory for student scores array
    studentScores = (int*)malloc(numStudents * sizeof(int));

    // Read student scores
    printf("Enter student scores:\n");
    for (int i = 0; i < numStudents; i++) {
        scanf("%d", &studentScores[i]);
    }
}

void printScores() {
    // Print scores
    printf("Scores:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("%d: %d\n", i + 1, studentScores[i]);
    }
}