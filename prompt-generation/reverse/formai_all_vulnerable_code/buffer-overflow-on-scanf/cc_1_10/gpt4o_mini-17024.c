//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

// Structure to hold student information
typedef struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

// Function declarations
void displayStudents(Student* students, int count);
Student* addStudent(int* count);
void freeMemory(Student* students);

int main() {
    int count = 0;
    Student* students = NULL;
    int choice;

    printf("Welcome to the Retro Student Management System!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                students = addStudent(&count);
                break;

            case 2:
                displayStudents(students, count);
                break;

            case 3:
                printf("Exiting the program... Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while(choice != 3);

    freeMemory(students);
    return 0;
}

// Function to add a student
Student* addStudent(int* count) {
    Student* newStudent = realloc(NULL, (*count + 1) * sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    printf("Enter student ID: ");
    scanf("%d", &newStudent[*count].id);
    printf("Enter student name: ");
    scanf("%s", newStudent[*count].name);
    printf("Enter student grade: ");
    scanf("%f", &newStudent[*count].grade);

    (*count)++;
    printf("Student added successfully!\n");

    return newStudent;
}

// Function to display students
void displayStudents(Student* students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n--- Student List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Grade: %.2f\n", 
                students[i].id, students[i].name, students[i].grade);
    }
}

// Function to free memory
void freeMemory(Student* students) {
    free(students);
    printf("Memory freed successfully.\n");
}