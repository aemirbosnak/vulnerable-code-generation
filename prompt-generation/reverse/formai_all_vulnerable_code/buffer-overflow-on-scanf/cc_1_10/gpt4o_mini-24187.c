//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

void displayMenu() {
    printf("\n=== Student Database Menu ===\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Delete Student\n");
    printf("4. Exit\n");
    printf("=============================\n");
    printf("Choose an option: ");
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }
    
    printf("Enter Student ID: ");
    scanf("%d", &students[*count].id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[*count].name);
    printf("Enter Student Age: ");
    scanf("%d", &students[*count].age);
    
    (*count)++;
    printf("Student added successfully.\n");
}

void viewStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students in the database.\n");
        return;
    }
    
    printf("\n=== List of Students ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", students[i].id, students[i].name, students[i].age);
    }
    printf("=========================\n");
}

void deleteStudent(Student students[], int *count) {
    if (*count == 0) {
        printf("No students to delete.\n");
        return;
    }

    int id, i, found = 0;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    
    for (i = 0; i < *count; i++) {
        if (students[i].id == id) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (; i < *count - 1; i++) {
            students[i] = students[i + 1];
        }
        (*count)--;
        printf("Student with ID %d deleted successfully.\n", id);
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                viewStudents(students, count);
                break;
            case 3:
                deleteStudent(students, &count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}