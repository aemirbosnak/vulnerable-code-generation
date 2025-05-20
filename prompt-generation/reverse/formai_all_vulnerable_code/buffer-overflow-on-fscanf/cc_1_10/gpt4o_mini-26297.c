//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100
#define DATA_FILE "students.txt"

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Student;

// Function prototypes
void addStudent();
void viewStudents();
void deleteStudent();
int getStudentCount();
void clearBuffer();

int main() {
    int choice;

    while (1) {
        printf("\n=== Student Records Management ===\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearBuffer();

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
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    FILE *file;
    Student student;

    file = fopen(DATA_FILE, "a");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter student ID: ");
    scanf("%d", &student.id);
    clearBuffer();
    printf("Enter student name: ");
    fgets(student.name, MAX_NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0;  // Remove newline character
    printf("Enter student age: ");
    scanf("%d", &student.age);
    clearBuffer();

    fprintf(file, "%d;%s;%d\n", student.id, student.name, student.age);
    fclose(file);

    printf("Student added successfully!\n");
}

void viewStudents() {
    FILE *file;
    Student student;
    int count = 0;

    file = fopen(DATA_FILE, "r");
    if (!file) {
        printf("Error opening file!\n");
        return;
    }

    printf("\n=== List of Students ===\n");
    while (fscanf(file, "%d;%49[^;];%d\n", &student.id, student.name, &student.age) != EOF) {
        printf("ID: %d, Name: %s, Age: %d\n", student.id, student.name, student.age);
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("No students found.\n");
    }
}

void deleteStudent() {
    FILE *file, *tempFile;
    Student student;
    int idToDelete, found = 0;

    printf("Enter student ID to delete: ");
    scanf("%d", &idToDelete);
    clearBuffer();

    file = fopen(DATA_FILE, "r");
    tempFile = fopen("temp.txt", "w");
    if (!file || !tempFile) {
        printf("Error opening file!\n");
        return;
    }

    while (fscanf(file, "%d;%49[^;];%d\n", &student.id, student.name, &student.age) != EOF) {
        if (student.id != idToDelete) {
            fprintf(tempFile, "%d;%s;%d\n", student.id, student.name, student.age);
        } else {
            found = 1;
            printf("Student with ID %d deleted.\n", idToDelete);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(DATA_FILE);
    rename("temp.txt", DATA_FILE);

    if (!found) {
        printf("No student found with ID %d.\n", idToDelete);
    }
}

int getStudentCount() {
    FILE *file;
    Student student;
    int count = 0;

    file = fopen(DATA_FILE, "r");
    if (!file) {
        return 0;
    }

    while (fscanf(file, "%d;%49[^;];%d\n", &student.id, student.name, &student.age) != EOF) {
        count++;
    }
    fclose(file);
    return count;
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}