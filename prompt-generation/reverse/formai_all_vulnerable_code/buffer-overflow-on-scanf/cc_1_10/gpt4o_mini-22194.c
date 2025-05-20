//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float gpa;
} Student;

Student studentDB[MAX_STUDENTS];
int studentCount = 0;

void addStudent();
void viewStudents();
void deleteStudent();
void searchStudent();

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("-----------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }

    Student newStudent;
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter Student Name: ");
    getchar(); // Consume newline character
    fgets(newStudent.name, NAME_LENGTH, stdin);
    newStudent.name[strcspn(newStudent.name, "\n")] = '\0'; // Remove newline
    printf("Enter Student GPA: ");
    scanf("%f", &newStudent.gpa);

    studentDB[studentCount] = newStudent;
    studentCount++;
    printf("Student added successfully!\n");
}

void viewStudents() {
    if (studentCount == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("\n--- List of Students ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", 
               studentDB[i].id, studentDB[i].name, studentDB[i].gpa);
    }
}

void deleteStudent() {
    if (studentCount == 0) {
        printf("No students to delete.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < studentCount; i++) {
        if (studentDB[i].id == id) {
            found = 1;
            for (int j = i; j < studentCount - 1; j++) {
                studentDB[j] = studentDB[j + 1]; // Shift students down
            }
            studentCount--;
            printf("Student with ID %d deleted successfully!\n", id);
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void searchStudent() {
    if (studentCount == 0) {
        printf("No students to search.\n");
        return;
    }

    int id, found = 0;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < studentCount; i++) {
        if (studentDB[i].id == id) {
            found = 1;
            printf("Student found! ID: %d, Name: %s, GPA: %.2f\n", 
                   studentDB[i].id, studentDB[i].name, studentDB[i].gpa);
            break;
        }
    }
    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}