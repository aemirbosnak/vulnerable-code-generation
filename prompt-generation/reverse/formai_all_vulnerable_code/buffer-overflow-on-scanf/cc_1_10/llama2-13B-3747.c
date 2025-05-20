//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_LENGTH 5

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int grade[MAX_GRADE_LENGTH];
} student_t;

// Function to print student information
void print_student(student_t *student) {
    printf("Name: %s\nGrade: ", student->name);
    for (int i = 0; i < MAX_GRADE_LENGTH; i++) {
        printf("%d ", student->grade[i]);
    }
    printf("\n");
}

// Function to get student information
student_t get_student() {
    char name[MAX_NAME_LENGTH];
    int grade[MAX_GRADE_LENGTH];

    // Ask user for name
    printf("What is your name? ");
    fgets(name, MAX_NAME_LENGTH, stdin);

    // Ask user for grade
    for (int i = 0; i < MAX_GRADE_LENGTH; i++) {
        printf("What is your grade for %s? ", name);
        scanf("%d", &grade[i]);
    }

    // Create student structure and return it
    student_t student = {name, grade};
    return student;
}

int main() {
    // Create student structure and print it
    student_t student = get_student();
    print_student(&student);

    // Ask user to enter their name and grade again
    printf("Would you like to enter your name and grade again? ");
    char answer;
    scanf(" %c", &answer);

    // If user enters 'y', print student information again
    if (answer == 'y') {
        student = get_student();
        print_student(&student);
    }

    return 0;
}