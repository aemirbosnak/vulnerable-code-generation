//LLAMA2-13B DATASET v1.0 Category: Educational ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_NAME_LEN 20
#define MAX_GRADE_LEN 5

// Global variables
int numStudents = 0;
struct student {
    char name[MAX_NAME_LEN];
    int grade[MAX_GRADE_LEN];
} students[10];

// Function declarations
void inputStudentData(struct student *s);
void displayStudentData(struct student *s);
void calculateAverageGrade(struct student *s);
void printAverageGrade(struct student *s);

int main() {
    // Initialize variables
    numStudents = 0;
    srand(time(NULL));

    // Welcome message
    printf("Welcome to the Student Grade System! \n");

    // Main loop
    while (1) {
        // Display menu options
        printf("Menu options:\n");
        printf("1. Add a new student\n");
        printf("2. Display all students' data\n");
        printf("3. Calculate and display the average grade for all students\n");
        printf("4. Exit\n");

        // Get user input
        int choice = getchar();

        // Process user input
        switch (choice) {
            case '1':
                // Add a new student
                inputStudentData(&students[numStudents]);
                numStudents++;
                break;

            case '2':
                // Display all students' data
                displayStudentData(students);
                break;

            case '3':
                // Calculate and display the average grade for all students
                calculateAverageGrade(students);
                printAverageGrade(students);
                break;

            case '4':
                // Exit
                break;

            default:
                printf("Invalid input. Please try again.\n");
                continue;
        }
    }

    // Exit program
    return 0;
}

// Function to input student data
void inputStudentData(struct student *s) {
    // Get student name
    printf("Enter student name: ");
    fgets(s->name, MAX_NAME_LEN, stdin);

    // Get student grade
    printf("Enter student grade: ");
    scanf("%d%*c", &s->grade[0]);

    // Check if grade is valid
    if (s->grade[0] < 0 || s->grade[0] > 100) {
        printf("Invalid grade. Please try again.\n");
        return;
    }

    // Add student to array
    numStudents++;
    s++;
}

// Function to display student data
void displayStudentData(struct student *s) {
    printf("Student Data:\n");
    printf("Name: %s\n", s->name);
    printf("Grade: %d\n", s->grade[0]);
}

// Function to calculate and display the average grade for all students
void calculateAverageGrade(struct student *s) {
    int totalGrade = 0;
    for (int i = 0; i < numStudents; i++) {
        totalGrade += s[i].grade[0];
    }

    // Calculate average grade
    double averageGrade = (double)totalGrade / numStudents;

    // Display average grade
    printf("Average Grade: %f\n", averageGrade);
}

// Function to print the average grade for all students
void printAverageGrade(struct student *s) {
    calculateAverageGrade(s);
}