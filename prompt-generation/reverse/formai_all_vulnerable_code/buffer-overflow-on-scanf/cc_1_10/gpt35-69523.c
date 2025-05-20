//FormAI DATASET v1.0 Category: Database simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

// Maximum number of students in the database
#define MAX_STUDENTS 100

// Struct to define a student
typedef struct {
    int id;
    char name[30];
    float gpa;
} Student;

// Function to add a new student to the database
void addStudent(Student database[], int *size) {
    // Check if the database is full
    if (*size >= MAX_STUDENTS) {
        printf("Error: Database is full!\n");
        return;
    }

    // Get user input for the new student's details
    printf("Enter student ID: ");
    scanf("%d", &database[*size].id);
    printf("Enter student name: ");
    scanf("%s", database[*size].name);
    printf("Enter student GPA: ");
    scanf("%f", &database[*size].gpa);

    // Increment the size of the database
    (*size)++;
}

// Function to display all students in the database
void displayStudents(Student database[], int size) {
    printf("ID\tName\t\tGPA\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%s\t\t%f\n", database[i].id, database[i].name, database[i].gpa);
    }
}

// Function to search for a student by ID and display their details
void searchStudent(Student database[], int size) {
    int searchId;
    printf("Enter student ID to search for: ");
    scanf("%d", &searchId);

    for (int i = 0; i < size; i++) {
        if (database[i].id == searchId) {
            printf("ID: %d\tName: %s\tGPA: %f\n", database[i].id, database[i].name, database[i].gpa);
            return;
        }
    }

    printf("Student not found!\n");
}

int main() {
    // Initialize the database with 3 example students
    Student database[MAX_STUDENTS] = {
        {1001, "John Doe", 3.4},
        {1002, "Jane Smith", 3.6},
        {1003, "Bob Johnson", 2.8},
    };

    // Set the size of the database to match the number of initialized students
    int size = 3;

    // Display a menu to the user and perform their chosen action
    while (1) {
        printf("\n========== STUDENT DATABASE ==========\n");
        printf("1. Add new student\n");
        printf("2. Display all students\n");
        printf("3. Search for a student\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(database, &size);
                break;
            case 2:
                displayStudents(database, size);
                break;
            case 3:
                searchStudent(database, size);
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}