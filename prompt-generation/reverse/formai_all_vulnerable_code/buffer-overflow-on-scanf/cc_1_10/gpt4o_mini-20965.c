//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void displayMenu();
void addStudent();
void viewStudents();
void searchStudent();
void deleteStudent();
void writeDataToFile();
void readDataFromFile();
void clearBuffer();

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float grade;
} Student;

Student students[MAX_STUDENTS];
int studentCount = 0;

// Main function
int main() {
    readDataFromFile();
    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        clearBuffer(); // Clear the newline character from buffer
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                writeDataToFile();
                break;
            case 6:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Save Data\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a student
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Unable to add more students. Maximum limit reached.\n");
        return;
    }
    Student newStudent;
    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    clearBuffer(); // Clear the newline character from buffer
    printf("Enter student name: ");
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = 0; // Remove newline character
    printf("Enter student grade: ");
    scanf("%f", &newStudent.grade);
    students[studentCount++] = newStudent;
    printf("Student added successfully!\n");
}

// Function to view all students
void viewStudents() {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\nList of Students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

// Function to search for a student
void searchStudent() {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            printf("Student found: ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to delete a student
void deleteStudent() {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            printf("Student with ID %d deleted successfully!\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to write data to a file
void writeDataToFile() {
    FILE *file = fopen("students.dat", "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }
    fwrite(students, sizeof(Student), studentCount, file);
    fclose(file);
    printf("Data saved successfully!\n");
}

// Function to read data from a file
void readDataFromFile() {
    FILE *file = fopen("students.dat", "rb");
    if (!file) {
        printf("No previous data found. Starting fresh.\n");
        return;
    }
    studentCount = fread(students, sizeof(Student), MAX_STUDENTS, file);
    fclose(file);
    printf("Data loaded successfully!\n");
}

// Function to clear buffer
void clearBuffer() {
    while (getchar() != '\n');
}