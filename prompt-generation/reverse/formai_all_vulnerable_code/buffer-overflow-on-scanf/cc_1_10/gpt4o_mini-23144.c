//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50
#define FILE_NAME "students.db"

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

void addStudent();
void displayStudents();
void searchStudentById(int id);
void clearBuffer();

int main() {
    int choice, id;

    while (1) {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                clearBuffer();
                searchStudentById(id);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void addStudent() {
    FILE *file;
    Student student;

    file = fopen(FILE_NAME, "ab");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    clearBuffer();
    printf("Enter Student Name: ");
    fgets(student.name, NAME_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove newline
    printf("Enter Student Age: ");
    scanf("%d", &student.age);
    clearBuffer();

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);
    printf("Student added successfully!\n");
}

void displayStudents() {
    FILE *file;
    Student student;
    int count = 0;

    file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    printf("\n--- Student Records ---\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s, Age: %d\n", student.id, student.name, student.age);
        count++;
    }
    if (count == 0) {
        printf("No records found.\n");
    }
    
    fclose(file);
}

void searchStudentById(int id) {
    FILE *file;
    Student student;
    int found = 0;

    file = fopen(FILE_NAME, "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return;
    }

    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            printf("Found Record - ID: %d, Name: %s, Age: %d\n", student.id, student.name, student.age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No record found for ID: %d\n", id);
    }

    fclose(file);
}

void clearBuffer() {
    while (getchar() != '\n');
}