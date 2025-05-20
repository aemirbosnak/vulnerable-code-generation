//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_DEPARTMENT_LENGTH 30
#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];
} Student;

void addStudent(const char *filename);
void displayStudents(const char *filename);
void searchStudent(const char *filename);

int main() {
    const char *filename = "students.txt";
    int choice;

    do {
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // clear the newline character from input buffer

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                displayStudents(filename);
                break;
            case 3:
                searchStudent(filename);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addStudent(const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Student student;
    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    getchar(); // clear the newline character from input buffer
    printf("Enter Student Name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // remove newline
    printf("Enter Student Department: ");
    fgets(student.department, MAX_DEPARTMENT_LENGTH, stdin);
    student.department[strcspn(student.department, "\n")] = 0; // remove newline

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

void displayStudents(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    Student student;
    printf("\n--- Student Records ---\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s, Department: %s\n", student.id, student.name, student.department);
    }
    fclose(file);
}

void searchStudent(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    int searchId;
    printf("Enter Student ID to search: ");
    scanf("%d", &searchId);

    Student student;
    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == searchId) {
            printf("Student Found: ID: %d, Name: %s, Department: %s\n", student.id, student.name, student.department);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", searchId);
    }

    fclose(file);
}