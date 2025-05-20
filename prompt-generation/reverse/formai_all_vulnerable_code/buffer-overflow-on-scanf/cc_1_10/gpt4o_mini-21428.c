//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

struct Student {
    int id;
    char name[MAX_SIZE];
    float gpa;
};

void printStudent(const struct Student *student) {
    if (student == NULL) {
        printf("Invalid student data!\n");
        return;
    }
    printf("Student ID: %d\n", student->id);
    printf("Name: %s\n", student->name);
    printf("GPA: %.2f\n", student->gpa);
}

struct Student* createStudent(int id, const char *name, float gpa) {
    struct Student *newStudent = (struct Student *)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        fprintf(stderr, "Memory allocation failed for new student\n");
        exit(EXIT_FAILURE);
    }
  
    newStudent->id = id;
    strncpy(newStudent->name, name, MAX_SIZE - 1);
    newStudent->name[MAX_SIZE - 1] = '\0'; // Ensuring null-termination
    newStudent->gpa = gpa;
    
    return newStudent;
}

void deleteStudent(struct Student *student) {
    if (student != NULL) {
        free(student);
        student = NULL; // Avoid dangling pointer
    }
}

void handleMemory(void) {
    struct Student *students[10];
    int count = 0;

    while (count < 10) {
        int id;
        char name[MAX_SIZE];
        float gpa;

        printf("Enter student ID (or -1 to stop): ");
        scanf("%d", &id);
        if (id == -1) {
            break;
        }

        printf("Enter student name: ");
        scanf(" %[^\n]", name); // Read string with spaces
        printf("Enter GPA: ");
        scanf("%f", &gpa);

        students[count] = createStudent(id, name, gpa);
        count++;
    }

    printf("\nRegistered Students:\n");
    for (int i = 0; i < count; ++i) {
        printStudent(students[i]);
    }

    // Clean up memory
    for (int i = 0; i < count; ++i) {
        deleteStudent(students[i]);
    }
}

void menu() {
    printf("Welcome to the Student Registration System\n");
    printf("1. Register a new student\n");
    printf("2. Exit\n");
}

int main() {
    int choice = 0;
  
    while (choice != 2) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                handleMemory();
                break;
            case 2:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}