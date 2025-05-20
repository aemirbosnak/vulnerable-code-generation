//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 100
#define FILE_NAME "students.dat"

// Define a structure for Student
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
    char grade;
} Student;

// Function to add a student record
void addStudent() {
    FILE *file = fopen(FILE_NAME, "ab");
    Student student;

    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    // Input student details
    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", student.name);
    printf("Enter Student Age: ");
    scanf("%d", &student.age);
    printf("Enter Student Grade (A-F): ");
    scanf(" %c", &student.grade);

    // Write student record to file
    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student record added successfully!\n");
}

// Function to display all student records
void displayStudents() {
    FILE *file = fopen(FILE_NAME, "rb");
    Student student;

    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    printf("\nList of Students:\n");
    printf("-------------------------------------------------\n");
    printf("%-10s %-30s %-5s %-5s\n", "ID", "Name", "Age", "Grade");
    printf("-------------------------------------------------\n");

    while (fread(&student, sizeof(Student), 1, file)) {
        printf("%-10d %-30s %-5d %-5c\n", student.id, student.name, student.age, student.grade);
    }

    fclose(file);
}

// Function to search a student by ID
void searchStudent() {
    FILE *file = fopen(FILE_NAME, "rb");
    Student student;
    int searchId;

    if (file == NULL) {
        perror("Unable to open file!");
        return;
    }

    printf("Enter Student ID to search: ");
    scanf("%d", &searchId);

    int found = 0;

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == searchId) {
            printf("Student Found:\n");
            printf("ID: %d\nName: %s\nAge: %d\nGrade: %c\n", student.id, student.name, student.age, student.grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", searchId);
    }

    fclose(file);
}

// Function to show the menu
void showMenu() {
    printf("\nStudent Management System\n");
    printf("==========================\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Exit\n");
    printf("==========================\n");
}

// Main function
int main() {
    int choice;

    do {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}