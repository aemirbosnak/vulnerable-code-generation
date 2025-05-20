//FormAI DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about a student
struct Student {
    int rollNumber;
    char name[50];
    float marks;
};

// Function to add a new student to the database
void addStudent(struct Student students[], int *numberOfStudents) {
    int rollNumber;
    char name[50];
    float marks;

    // Get information about new student from the user
    printf("\nEnter details of new student below:\n");
    printf("Roll Number: ");
    scanf("%d", &rollNumber);

    // Check if student already exists
    for (int i=0; i<*numberOfStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nError: student with roll number %d already exists!\n", rollNumber);
            return;
        }
    }

    printf("Name: ");
    scanf("%s", name);
    printf("Marks: ");
    scanf("%f", &marks);

    // Add new student to the database
    students[*numberOfStudents].rollNumber = rollNumber;
    strcpy(students[*numberOfStudents].name, name);
    students[*numberOfStudents].marks = marks;
    (*numberOfStudents)++;

    printf("\nNew student with roll number %d has been successfully added to the database!\n", rollNumber);
}

// Function to display all students in the database
void displayStudents(struct Student students[], int numberOfStudents) {
    printf("\nDatabase contains %d student(s):\n", numberOfStudents);
    for (int i=0; i<numberOfStudents; i++) {
        printf("%d. Roll Number: %d, Name: %s, Marks: %.2f\n", i+1, students[i].rollNumber, students[i].name, students[i].marks);
    }
}

// Function to search for a student in the database
void searchStudent(struct Student students[], int numberOfStudents) {
    int rollNumber;
    printf("\nEnter roll number of student to search: ");
    scanf("%d", &rollNumber);
    for (int i=0; i<numberOfStudents; i++) {
        if (students[i].rollNumber == rollNumber) {
            printf("\nStudent found!\nRoll Number: %d, Name: %s, Marks: %.2f\n", students[i].rollNumber, students[i].name, students[i].marks);
            return;
        }
    }
    printf("\nError: student with roll number %d does not exist in the database!\n", rollNumber);
}

int main() {
    // Initialize database with a maximum capacity of 100 students
    struct Student database[100];
    int numberOfStudents = 0;

    // Display menu and handle user's choice
    int choice;
    do {
        printf("\nAvailable Operations:\n");
        printf("1. Add a new student to the database\n");
        printf("2. Display all students in the database\n");
        printf("3. Search for a student in the database\n");
        printf("4. Exit\n");
        printf("\nEnter your choice [1-4]: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(database, &numberOfStudents);
                break;
            case 2:
                displayStudents(database, numberOfStudents);
                break;
            case 3:
                searchStudent(database, numberOfStudents);
                break;
            case 4:
                printf("\nExiting program...");
                exit(0);
            default:
                printf("\nError: invalid choice! Please choose again.\n");
        }
    } while (1);

    return 0;
}