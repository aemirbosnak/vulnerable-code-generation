//Falcon2-11B DATASET v1.0 Category: Online Examination System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
int numStudents;
int *studentMarks;

// Function prototypes
void readStudents(int numStudents, int *studentMarks);
void displayStudents(int numStudents, int *studentMarks);

// Main function
int main() {
    int numStudents, i;

    // Read number of students
    printf("Enter number of students: ");
    scanf("%d", &numStudents);

    // Read marks for each student
    readStudents(numStudents, &studentMarks);

    // Display marks for each student
    displayStudents(numStudents, &studentMarks);

    return 0;
}

// Function to read marks for each student
void readStudents(int numStudents, int *studentMarks) {
    int i;

    // Allocate memory for marks
    studentMarks = (int *)malloc(numStudents * sizeof(int));

    // Read marks for each student
    for (i = 0; i < numStudents; i++) {
        printf("Enter mark for student %d: ", i+1);
        scanf("%d", &studentMarks[i]);
    }
}

// Function to display marks for each student
void displayStudents(int numStudents, int *studentMarks) {
    int i;

    // Display marks for each student
    for (i = 0; i < numStudents; i++) {
        printf("Student %d has mark %d\n", i+1, studentMarks[i]);
    }
}