//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float gpa;
} Student;

void initializeStudent(Student* s, int id, const char* name, float gpa) {
    s->id = id;
    strncpy(s->name, name, MAX_NAME_LENGTH);
    s->gpa = gpa;
}

void printStudent(const Student* s) {
    printf("ID: %d, Name: %s, GPA: %.2f\n", s->id, s->name, s->gpa);
}

Student* allocateStudentsArray(int numStudents) {
    Student* students = (Student*)malloc(numStudents * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return students;
}

void freeStudentsArray(Student* students) {
    free(students);
}

void displayAllStudents(const Student* students, int numStudents) {
    for (int i = 0; i < numStudents; i++) {
        printStudent(&students[i]);
    }
}

float calculateAverageGPA(const Student* students, int numStudents) {
    float totalGPA = 0.0f;
    for (int i = 0; i < numStudents; i++) {
        totalGPA += students[i].gpa;
    }
    return (numStudents > 0) ? (totalGPA / numStudents) : 0.0f;
}

int main() {
    int numStudents;
    printf("Enter number of students (max %d): ", MAX_STUDENTS);
    scanf("%d", &numStudents);
    if (numStudents > MAX_STUDENTS || numStudents < 1) {
        fprintf(stderr, "Invalid number of students!\n");
        return EXIT_FAILURE;
    }

    Student* students = allocateStudentsArray(numStudents);

    for (int i = 0; i < numStudents; i++) {
        int id;
        char name[MAX_NAME_LENGTH];
        float gpa;

        printf("Enter details for student %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &id);
        printf("Name: ");
        scanf("%s", name);
        printf("GPA: ");
        scanf("%f", &gpa);

        initializeStudent(&students[i], id, name, gpa);
    }

    printf("\nStudents details:\n");
    displayAllStudents(students, numStudents);

    float averageGPA = calculateAverageGPA(students, numStudents);
    printf("\nAverage GPA: %.2f\n", averageGPA);

    freeStudentsArray(students);
    return EXIT_SUCCESS;
}