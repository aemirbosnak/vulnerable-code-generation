//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Student
typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Function to allocate memory for students
Student* allocateStudents(int numberOfStudents) {
    Student* students = (Student*)malloc(numberOfStudents * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed for students.\n");
        exit(EXIT_FAILURE);
    }
    return students;
}

// Function to input student details
void enterStudentDetails(Student* student) {
    printf("Enter student ID: ");
    scanf("%d", &student->id);
    printf("Enter student name: ");
    getchar(); // Consume the newline left over
    fgets(student->name, sizeof(student->name), stdin);
    student->name[strcspn(student->name, "\n")] = 0; // Remove newline
    printf("Enter student grade: ");
    scanf("%f", &student->grade);
}

// Function to display student details
void displayStudentDetails(const Student* student) {
    printf("ID: %d, Name: %s, Grade: %.2f\n", student->id, student->name, student->grade);
}

// Function to free allocated memory
void freeStudents(Student* students) {
    free(students);
}

int main() {
    int numberOfStudents;

    printf("Enter the number of students: ");
    scanf("%d", &numberOfStudents);

    // Allocate memory for students
    Student* students = allocateStudents(numberOfStudents);

    // Input details for each student
    for (int i = 0; i < numberOfStudents; i++) {
        printf("Entering details for student %d:\n", i + 1);
        enterStudentDetails(&students[i]);
    }

    // Display student details
    printf("\nStudent Details:\n");
    for (int i = 0; i < numberOfStudents; i++) {
        displayStudentDetails(&students[i]);
    }

    // Free the allocated memory
    freeStudents(students);

    return 0;
}