//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100
#define MAX_GPA 4.0

// Function to validate user input
void validateInput(int *age, double *gpa) {
    if (*age < 0 || *age > MAX_AGE) {
        printf("Error: Age must be a positive integer between 0 and %d\n", MAX_AGE);
        return;
    }

    if (*gpa < 0.0 || *gpa > MAX_GPA) {
        printf("Error: GPA must be a positive decimal between 0.0 and %f\n", MAX_GPA);
        return;
    }
}

// Function to calculate and print the student's grade
void calculateGrade(int age, double gpa) {
    int grade = 0;

    switch (age) {
        case 18:
            grade = (gpa > 3.5) ? 100 : 0;
            break;
        case 19:
            grade = (gpa > 3.0) ? 80 : 0;
            break;
        case 20:
            grade = (gpa > 2.5) ? 60 : 0;
            break;
        default:
            grade = 0;
            break;
    }

    printf("Your grade is %d\n", grade);
}

int main() {
    int age;
    double gpa;

    // Ask the user for their name
    printf("What is your name? ");
    char name[MAX_NAME_LENGTH];
    scanf("%19s", name);

    // Ask the user for their age and GPA
    printf("How old are you? ");
    scanf("%d", &age);

    printf("What is your GPA? ");
    scanf("%lf", &gpa);

    // Validate user input
    validateInput(&age, &gpa);

    // Calculate and print the student's grade
    calculateGrade(age, gpa);

    return 0;
}