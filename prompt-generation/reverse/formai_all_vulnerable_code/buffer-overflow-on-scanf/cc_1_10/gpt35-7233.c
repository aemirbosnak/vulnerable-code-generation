//FormAI DATASET v1.0 Category: Database simulation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

// Struct to represent a student
typedef struct {
    int id;
    char name[50];
    float gpa;
} Student;

// Globals
int numStudents = 0;
Student *students;

// Function to add a student to the database
void addStudent() {
    // Increment number of students
    numStudents++;

    // Allocate memory for new student
    students = (Student*)realloc(students, numStudents * sizeof(Student));
    
    // Ask for student details
    printf("Enter student ID: ");
    scanf("%d", &students[numStudents-1].id);
    printf("Enter student name: ");
    scanf("%s", students[numStudents-1].name);
    printf("Enter student GPA: ");
    scanf("%f", &students[numStudents-1].gpa);
}

// Function to print all students in the database
void printStudents() {
    printf("Student Database:\n");
    for(int i = 0; i < numStudents; i++) {
        printf("\nID: %d\n", students[i].id);
        printf("Name: %s\n", students[i].name);
        printf("GPA: %.2f\n", students[i].gpa);
    }
    printf("\n");
}

int main() {
    int choice;
    while(1) {
        // Display menu
        printf("Menu:\n");
        printf("1. Add student\n");
        printf("2. Print all students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                printStudents();
                break;
            case 3:
                // Free memory allocated for students
                free(students);
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice, please choose again\n");
                break;
        }
    }
    return 0;
}