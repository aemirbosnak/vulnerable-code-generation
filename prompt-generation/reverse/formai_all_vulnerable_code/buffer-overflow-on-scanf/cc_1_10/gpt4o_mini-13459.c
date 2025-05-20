//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_RECORDS 100
#define FILE_NAME "students.txt"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

void addStudent();
void viewStudents();
void deleteStudent();
int getNumberOfStudents();

int main() {
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

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
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    Student student;
    FILE *file = fopen(FILE_NAME, "a");
    if (!file) {
        perror("Failed to open the file");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &student.id);
    getchar(); // Consume newline character
    printf("Enter student name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove trailing newline
    printf("Enter student grade: ");
    scanf("%f", &student.grade);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

void viewStudents() {
    Student student;
    FILE *file = fopen(FILE_NAME, "r");
    if (!file) {
        perror("Failed to open the file");
        return;
    }

    printf("\nStudent Records:\n");
    printf("%-10s %-30s %-10s\n", "ID", "Name", "Grade");
    printf("---------------------------------------------------\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("%-10d %-30s %-10.2f\n", student.id, student.name, student.grade);
    }
    fclose(file);
}

void deleteStudent() {
    int idToDelete, records, i;
    Student student;
    FILE *file = fopen(FILE_NAME, "rb");
    FILE *tempFile = fopen("temp.txt", "wb");
    
    if (!file || !tempFile) {
        perror("File operation failed");
        if (file) fclose(file);
        if (tempFile) fclose(tempFile);
        return;
    }

    printf("Enter student ID to delete: ");
    scanf("%d", &idToDelete);

    records = getNumberOfStudents();
    for (i = 0; i < records; i++) {
        fread(&student, sizeof(Student), 1, file);
        if (student.id != idToDelete) {
            fwrite(&student, sizeof(Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    remove(FILE_NAME);
    rename("temp.txt", FILE_NAME);

    printf("Student with ID %d deleted successfully!\n", idToDelete);
}

int getNumberOfStudents() {
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        return 0;
    }

    fseek(file, 0, SEEK_END);
    int numberOfStudents = ftell(file) / sizeof(Student);
    fclose(file);
    return numberOfStudents;
}