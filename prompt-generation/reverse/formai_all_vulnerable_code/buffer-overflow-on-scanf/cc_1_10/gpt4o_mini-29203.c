//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define FILE_NAME "students.dat"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float gpa;
} Student;

void addStudent();
void viewStudents();
void searchStudent(int id);
void deleteStudent(int id);
void displayMenu();

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                viewStudents();
                break;
            case 3: {
                int id;
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                searchStudent(id);
                break;
            }
            case 4: {
                int id;
                printf("Enter student ID to delete: ");
                scanf("%d", &id);
                deleteStudent(id);
                break;
            }
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    return 0;
}

void displayMenu() {
    printf("\n--- Student Record Management System ---\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Search Student\n");
    printf("4. Delete Student\n");
    printf("5. Exit\n");
}

void addStudent() {
    FILE *file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Student student;
    printf("Enter student ID: ");
    scanf("%d", &student.id);
    printf("Enter student name: ");
    getchar(); // Clear newline
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove newline
    printf("Enter student GPA: ");
    scanf("%f", &student.gpa);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student record added successfully.\n");
}

void viewStudents() {
    FILE *file = fopen(FILE_NAME, "rb");
    Student student;

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    printf("\n--- List of Students ---\n");
    while (fread(&student, sizeof(Student), 1, file) == 1) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", student.id, student.name, student.gpa);
    }

    fclose(file);
}

void searchStudent(int id) {
    FILE *file = fopen(FILE_NAME, "rb");
    Student student;
    int found = 0;

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.id == id) {
            printf("Found: ID: %d, Name: %s, GPA: %.2f\n", student.id, student.name, student.gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }

    fclose(file);
}

void deleteStudent(int id) {
    FILE *file = fopen(FILE_NAME, "rb");
    FILE *tempFile = fopen("temp.dat", "wb");
    Student student;
    int found = 0;

    if (file == NULL || tempFile == NULL) {
        perror("Error opening file");
        return;
    }

    while (fread(&student, sizeof(Student), 1, file) == 1) {
        if (student.id == id) {
            found = 1;
            printf("Deleting: ID: %d, Name: %s, GPA: %.2f\n", student.id, student.name, student.gpa);
        } else {
            fwrite(&student, sizeof(Student), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (found) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("Student record deleted successfully.\n");
    } else {
        printf("Student with ID %d not found for deletion.\n", id);
        remove("temp.dat");
    }
}