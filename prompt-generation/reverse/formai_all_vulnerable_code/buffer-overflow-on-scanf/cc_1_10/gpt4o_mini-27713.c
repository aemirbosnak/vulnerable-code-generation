//GPT-4o-mini DATASET v1.0 Category: Error handling ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float grade;
} Student;

void handleFileError(const char *filename) {
    fprintf(stderr, "Error: Unable to open the file \"%s\".\n", filename);
    exit(EXIT_FAILURE);
}

void handleMemoryError() {
    fprintf(stderr, "Error: Memory allocation failed.\n");
    exit(EXIT_FAILURE);
}

void handleInputError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}

void readStudentsFromFile(const char *filename, Student students[], int *count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        handleFileError(filename);
    }

    while (*count < MAX_STUDENTS && fscanf(file, "%s %d %f", 
        students[*count].name, &students[*count].age, &students[*count].grade) == 3) {
        (*count)++;
    }

    fclose(file);
    if (*count == MAX_STUDENTS && !feof(file)) {
        handleInputError("Too many students in the file; limit exceeded.");
    }
}

void addStudent(Student students[], int *count) {
    if (*count >= MAX_STUDENTS) {
        handleInputError("Cannot add more students; maximum limit reached.");
    }

    Student newStudent;
    printf("Enter student's name: ");
    if (scanf("%s", newStudent.name) != 1) {
        handleInputError("Invalid input for name.");
    }
    
    printf("Enter student's age: ");
    if (scanf("%d", &newStudent.age) != 1) {
        handleInputError("Invalid input for age.");
    }

    printf("Enter student's grade: ");
    if (scanf("%f", &newStudent.grade) != 1) {
        handleInputError("Invalid input for grade.");
    }

    students[*count] = newStudent;
    (*count)++;
}

void displayStudents(const Student students[], int count) {
    printf("Student List:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s, Age: %d, Grade: %.2f\n", students[i].name, students[i].age, students[i].grade);
    }
}

void saveStudentsToFile(const char *filename, const Student students[], int count) {
    FILE *file = fopen(filename, "w");
    if (!file) {
        handleFileError(filename);
    }

    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2f\n", students[i].name, students[i].age, students[i].grade);
    }

    fclose(file);
}

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    char filename[MAX_NAME_LENGTH];

    printf("Enter the filename to read students from: ");
    scanf("%s", filename);
    readStudentsFromFile(filename, students, &count);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Save Students to File\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            handleInputError("Invalid input for choice.");
            continue;
        }

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                printf("Enter the filename to save students to: ");
                scanf("%s", filename);
                saveStudentsToFile(filename, students, count);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                handleInputError("Invalid choice. Please select again.");
                break;
        }
    } while (choice != 4);

    return 0;
}