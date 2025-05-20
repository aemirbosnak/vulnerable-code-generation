//LLAMA2-13B DATASET v1.0 Category: Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_AGE 100
#define MAX_GPA 4.0

// Define a structure to hold student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    double gpa;
} student_t;

// Define a function to get user input
void get_user_input(student_t *student) {
    printf("Enter your name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    printf("Enter your age: ");
    scanf("%d", &student->age);
    printf("Enter your GPA: ");
    scanf("%lf", &student->gpa);
}

// Define a function to print student information
void print_student(student_t *student) {
    printf("Name: %s\n", student->name);
    printf("Age: %d\n", student->age);
    printf("GPA: %lf\n", student->gpa);
}

int main() {
    student_t student;

    // Get user input for student information
    get_user_input(&student);

    // Print student information
    print_student(&student);

    // Ask user if they want to add another student
    printf("Do you want to add another student? (y/n): ");
    char input;
    scanf(" %c", &input);

    // If user wants to add another student, continue to loop
    if (input == 'y' || input == 'Y') {
        // Get user input for another student
        get_user_input(&student);

        // Print both students' information
        print_student(&student);

        // Ask user if they want to add another student again
        printf("Do you want to add another student? (y/n): ");
        scanf(" %c", &input);
    }

    return 0;
}