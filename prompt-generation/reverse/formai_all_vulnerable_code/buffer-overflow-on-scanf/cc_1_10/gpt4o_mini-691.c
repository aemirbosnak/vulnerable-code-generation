//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100
#define FILENAME "students.txt"

struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
};

void addStudent();
void viewStudents();
void deleteStudent();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer(); // Clear buffer after scanf

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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    struct Student newStudent;
    FILE *file = fopen(FILENAME, "a");

    if (file == NULL) {
        printf("Error opening file! Please try again later.\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &newStudent.id);
    clearBuffer(); // Clear buffer after scanf
    printf("Enter student name: ");
    fgets(newStudent.name, MAX_NAME_LENGTH, stdin);
    strtok(newStudent.name, "\n"); // Remove newline character

    fwrite(&newStudent, sizeof(struct Student), 1, file);
    fclose(file);

    printf("Student added successfully!\n");
}

void viewStudents() {
    struct Student student;
    FILE *file = fopen(FILENAME, "r");

    if (file == NULL) {
        printf("Error opening file! Please try again later.\n");
        return;
    }

    printf("\n--- List of Students ---\n");
    while (fread(&student, sizeof(struct Student), 1, file)) {
        printf("ID: %d, Name: %s\n", student.id, student.name);
    }
    fclose(file);
}

void deleteStudent() {
    struct Student student;
    FILE *file = fopen(FILENAME, "r");
    FILE *tempFile = fopen("temp.txt", "w");
    int idToDelete, found = 0;

    if (file == NULL || tempFile == NULL) {
        printf("Error opening file! Please try again later.\n");
        return;
    }

    printf("Enter student ID to delete: ");
    scanf("%d", &idToDelete);

    while (fread(&student, sizeof(struct Student), 1, file)) {
        if (student.id == idToDelete) {
            found = 1;
            printf("Deleting Student - ID: %d, Name: %s\n", student.id, student.name);
            continue; // Skip writing this record to tempFile
        }
        fwrite(&student, sizeof(struct Student), 1, tempFile);
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Student deleted successfully!\n");
    } else {
        printf("Student with ID %d not found.\n", idToDelete);
    }
}

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}