//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 30
#define MAX_BUF_SIZE 128

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

void addStudent(const char *filename);
void deleteStudent(const char *filename);
void displayStudents(const char *filename);
void searchStudent(const char *filename);
void clearInputBuffer();

int main() {
    int choice;
    const char *filename = "students.dat";

    while (1) {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        
        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                deleteStudent(filename);
                break;
            case 3:
                displayStudents(filename);
                break;
            case 4:
                searchStudent(filename);
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}

void addStudent(const char *filename) {
    FILE *file = fopen(filename, "ab");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Student student;
    printf("Enter student ID: ");
    scanf("%d", &student.id);
    clearInputBuffer();

    printf("Enter student name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = '\0'; // Strips newline

    printf("Enter student grade: ");
    scanf("%f", &student.grade);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

void deleteStudent(const char *filename) {
    FILE *file = fopen(filename, "rb");
    FILE *tempFile = fopen("temp.dat", "wb");
    if (!file || !tempFile) {
        perror("Unable to open file");
        return;
    }

    int studentId;
    printf("Enter student ID to delete: ");
    scanf("%d", &studentId);

    Student student;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id != studentId) {
            fwrite(&student, sizeof(Student), 1, tempFile);
        } else {
            found = 1;
        }
    }
    fclose(file);
    fclose(tempFile);
    
    if (found) {
        remove(filename);
        rename("temp.dat", filename);
        printf("Student with ID %d deleted successfully!\n", studentId);
    } else {
        remove("temp.dat");
        printf("Student with ID %d not found!\n", studentId);
    }
}

void displayStudents(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    Student student;
    printf("\n--- List of Students ---\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
    }
    fclose(file);
}

void searchStudent(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    int studentId;
    printf("Enter student ID to search: ");
    scanf("%d", &studentId);

    Student student;
    int found = 0;

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == studentId) {
            printf("Found - ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", studentId);
    }
    fclose(file);
}

void clearInputBuffer() {
    while (getchar() != '\n');
}