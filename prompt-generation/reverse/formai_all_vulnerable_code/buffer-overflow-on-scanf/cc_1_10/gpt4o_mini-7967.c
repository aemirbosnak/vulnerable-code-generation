//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 50
#define COURSE_LENGTH 30
#define MAX_STUDENTS 100

typedef struct {
    char name[NAME_LENGTH];
    int age;
    char course[COURSE_LENGTH];
    float gpa;
} Student;

void addStudent(Student **students, int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students, limit reached.\n");
        return;
    }

    Student *newStudent = (Student *)malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    printf("Enter student name: ");
    scanf("%s", newStudent->name);

    printf("Enter student age: ");
    scanf("%d", &newStudent->age);
    
    printf("Enter student course: ");
    scanf("%s", newStudent->course);
    
    printf("Enter student's GPA: ");
    scanf("%f", &newStudent->gpa);

    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully!\n");
}

void displayStudents(Student **students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i]->name);
        printf("Age: %d\n", students[i]->age);
        printf("Course: %s\n", students[i]->course);
        printf("GPA: %.2f\n", students[i]->gpa);
        printf("--------------------\n");
    }
}

void freeMemory(Student **students, int count) {
    for (int i = 0; i < count; i++) {
        free(students[i]);
    }
    printf("Memory freed for all students.\n");
}

int main() {
    Student *students[MAX_STUDENTS];
    int count = 0;
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                displayStudents(students, count);
                break;
            case 3:
                freeMemory(students, count);
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
                break;
        }
    } while (choice != 3);

    return 0;
}