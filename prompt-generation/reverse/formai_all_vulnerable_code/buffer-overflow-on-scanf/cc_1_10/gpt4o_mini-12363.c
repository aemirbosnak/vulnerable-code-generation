//GPT-4o-mini DATASET v1.0 Category: File handling ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

typedef struct {
    int id;
    char name[MAX_LENGTH];
    float gpa;
} Student;

void addStudent(const char *filename);
void viewStudents(const char *filename);
void searchStudent(const char *filename, int id);

int main() {
    const char *filename = "students.dat";
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(filename);
                break;
            case 2:
                viewStudents(filename);
                break;
            case 3: {
                int id;
                printf("Enter student ID to search: ");
                scanf("%d", &id);
                searchStudent(filename, id);
                break;
            }
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addStudent(const char *filename) {
    Student student;
    FILE *file = fopen(filename, "ab");
    if (!file) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    printf("Enter Student ID: ");
    scanf("%d", &student.id);
    printf("Enter Student Name: ");
    getchar(); // To consume the newline character
    fgets(student.name, MAX_LENGTH, stdin);
    student.name[strcspn(student.name, "\n")] = 0; // Remove newline character
    printf("Enter Student GPA: ");
    scanf("%f", &student.gpa);

    fwrite(&student, sizeof(Student), 1, file);
    fclose(file);

    printf("Student added successfully!\n");
}

void viewStudents(const char *filename) {
    Student student;
    FILE *file = fopen(filename, "rb");
    
    if (!file) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    printf("\n--- Student Records ---\n");
    while (fread(&student, sizeof(Student), 1, file)) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", student.id, student.name, student.gpa);
    }

    fclose(file);
}

void searchStudent(const char *filename, int id) {
    Student student;
    FILE *file = fopen(filename, "rb");

    if (!file) {
        perror("Unable to open file!");
        exit(EXIT_FAILURE);
    }

    int found = 0;
    while (fread(&student, sizeof(Student), 1, file)) {
        if (student.id == id) {
            printf("Student found - ID: %d, Name: %s, GPA: %.2f\n", student.id, student.name, student.gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("No student found with ID: %d\n", id);
    }
    
    fclose(file);
}