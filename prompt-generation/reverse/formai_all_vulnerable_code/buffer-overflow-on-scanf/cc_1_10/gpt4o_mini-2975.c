//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
} Student;

void printStudent(Student* student) {
    if (student != NULL) {
        printf("Student ID: %d, Name: %s\n", student->id, student->name);
    } else {
        printf("Invalid student pointer!\n");
    }
}

Student* createStudent(int id, const char* name) {
    Student* student = (Student*)malloc(sizeof(Student));
    if (student == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return NULL;
    }
    student->id = id;
    strncpy(student->name, name, sizeof(student->name) - 1);
    student->name[sizeof(student->name) - 1] = '\0'; // Ensure null-termination
    return student;
}

void freeStudent(Student* student) {
    free(student);
}

void displayAllStudents(Student** students, int count) {
    for (int i = 0; i < count; i++) {
        printStudent(students[i]);
    }
}

void getInput(char* buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        // Remove newline character if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0';
        }
    } else {
        fprintf(stderr, "Error reading input!\n");
    }
}

int main() {
    int numberOfStudents;
    
    printf("Enter the number of students: ");
    scanf("%d", &numberOfStudents);
    getchar(); // Consume newline after number input

    // Allocate memory for an array of student pointers
    Student** students = (Student**)malloc(numberOfStudents * sizeof(Student*));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed for student pointers array!\n");
        return EXIT_FAILURE;
    }

    for (int i = 0; i < numberOfStudents; i++) {
        int id;
        char name[50];

        printf("Enter ID for student %d: ", i + 1);
        scanf("%d", &id);
        getchar(); // Consume newline after ID input

        printf("Enter name for student %d: ", i + 1);
        getInput(name, sizeof(name));

        students[i] = createStudent(id, name);
        if (students[i] == NULL) {
            fprintf(stderr, "Failed to create student %d, exiting...\n", i + 1);
            for (int j = 0; j < i; j++) {
                freeStudent(students[j]);
            }
            free(students);
            return EXIT_FAILURE;
        }
    }

    printf("\nAll students:\n");
    displayAllStudents(students, numberOfStudents);

    // Cleanup memory
    for (int i = 0; i < numberOfStudents; i++) {
        freeStudent(students[i]);
    }
    free(students);

    return EXIT_SUCCESS;
}