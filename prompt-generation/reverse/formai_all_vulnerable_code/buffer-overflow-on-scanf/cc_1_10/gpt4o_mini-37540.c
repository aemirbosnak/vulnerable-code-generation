//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define FILENAME "students.txt"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

void addStudent() {
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL) {
        perror("Could not open file for appending");
        return;
    }

    Student student;

    printf("Enter student ID: ");
    scanf("%d", &student.id);
    printf("Enter student name: ");
    getchar(); // to consume newline left in buffer
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // remove newline character
    printf("Enter student grade: ");
    scanf("%f", &student.grade);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);

    printf("Student added successfully!\n");
}

void viewStudents() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Could not open file for reading");
        return;
    }

    Student student;
    printf("\nStudent Records:\n");
    printf("-------------------------------------------------\n");
    printf("| ID   | Name                                   | Grade |\n");
    printf("-------------------------------------------------\n");

    while (fread(&student, sizeof(Student), 1, file)) {
        printf("| %-4d | %-38s | %-5.2f |\n", student.id, student.name, student.grade);
    }
    printf("-------------------------------------------------\n");
    
    fclose(file);
}

void deleteStudent() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        perror("Could not open file for reading");
        return;
    }

    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Could not open temporary file for writing");
        fclose(file);
        return;
    }

    Student student;
    int idToDelete;
    printf("Enter student ID to delete: ");
    scanf("%d", &idToDelete);

    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id != idToDelete) {
            fwrite(&student, sizeof(Student), 1, tempFile);
        } else {
            found = 1;
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILENAME);
    rename("temp.txt", FILENAME);

    if (found) {
        printf("Student with ID %d deleted successfully!\n", idToDelete);
    } else {
        printf("No student found with ID %d.\n", idToDelete);
    }
}

void displayMenu() {
    printf("\nStudent Management System\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Delete Student\n");
    printf("4. Exit\n");
    printf("Select an option: ");
}

int main() {
    int choice;

    do {
        displayMenu();
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}