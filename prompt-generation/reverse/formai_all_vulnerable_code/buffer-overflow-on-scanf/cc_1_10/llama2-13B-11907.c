//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_GRADE_VALUE 100

// Structure to store student information
typedef struct {
    char name[MAX_NAME_LENGTH];
    int grade;
} student_t;

// Function to print a welcome message
void welcome(void) {
    printf("Welcome to the Retro C Programming Challenge!\n");
}

// Function to print a goodbye message
void goodbye(void) {
    printf("Goodbye, fellow coder!\n");
}

// Function to get the student's name and grade
void get_student_info(student_t *student) {
    printf("Please enter your name: ");
    fgets(student->name, MAX_NAME_LENGTH, stdin);
    printf("Please enter your grade (1-100): ");
    scanf("%d", &student->grade);
}

// Function to calculate the average grade
void calculate_average(student_t *student) {
    int sum = 0;
    for (int i = 0; i < MAX_GRADE_VALUE; i++) {
        sum += student->grade;
    }
    student->grade = sum / MAX_GRADE_VALUE;
}

// Function to print the student's information
void print_student(student_t *student) {
    printf("Student: %s\nGrade: %d\n", student->name, student->grade);
}

// Main program
int main() {
    student_t student;

    // Welcome the user
    welcome();

    // Get the student's name and grade
    get_student_info(&student);

    // Calculate the average grade
    calculate_average(&student);

    // Print the student's information
    print_student(&student);

    // Goodbye the user
    goodbye();

    return 0;
}