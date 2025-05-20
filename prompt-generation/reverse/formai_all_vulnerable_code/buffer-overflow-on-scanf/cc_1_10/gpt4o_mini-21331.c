//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 100
#define FILENAME "students.txt"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float grade;
} Student;

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
        printf("-----------------------------------------\n");
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
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void addStudent() {
    FILE *file = fopen(FILENAME, "a");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Student student;
    
    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    clearBuffer();
    printf("Enter Student Name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    strtok(student.name, "\n");  // Remove newline character
    printf("Enter Student Grade: ");
    scanf("%f", &student.grade);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student record added successfully.\n");
}

void viewStudents() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Student student;
    printf("\n--- List of Students ---\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", student.id, student.name, student.grade);
    }
    fclose(file);
}

void deleteStudent() {
    FILE *file = fopen(FILENAME, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Student students[MAX_STUDENTS];
    int count = 0;

    // Read all students into memory
    while (fread(&students[count], sizeof(Student), 1, file)) {
        count++;
    }
    fclose(file);

    int idToDelete;
    printf("Enter Student ID to delete: ");
    scanf("%d", &idToDelete);

    // Open file for writing
    file = fopen(FILENAME, "w");
    if (!file) {
        perror("Error opening file");
        return;
    }

    int found = 0;
    for (int i = 0; i < count; i++) {
        if (students[i].id != idToDelete) {
            fwrite(&students[i], sizeof(Student), 1, file);
        } else {
            found = 1;
            printf("Student with ID %d deleted successfully.\n", idToDelete);
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", idToDelete);
    }

    fclose(file);
}