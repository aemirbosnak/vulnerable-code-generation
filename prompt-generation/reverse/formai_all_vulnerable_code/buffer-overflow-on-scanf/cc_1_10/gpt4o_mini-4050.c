//GPT-4o-mini DATASET v1.0 Category: Memory management ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold student data
typedef struct {
    char name[100];
    int age;
    float gpa;
} Student;

// Function prototypes
void addStudent(Student **students, int *count);
void displayStudents(Student *students, int count);
void freeMemory(Student *students);

int main() {
    int studentCount = 0; // Holds the number of students
    int capacity = 5; // Initial capacity of the student list
    Student *students = NULL; // Dynamic array of students

    // Allocate initial memory for student array
    students = (Student *)malloc(capacity * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    char choice;
    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Exit\n");
        printf("Choose an option (1-3): ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                // Add a new student
                addStudent(&students, &studentCount);
                // Check if we need to expand the student array
                if (studentCount >= capacity) {
                    capacity *= 2; // Double the capacity
                    students = (Student *)realloc(students, capacity * sizeof(Student));
                    if (students == NULL) {
                        fprintf(stderr, "Memory reallocation failed!\n");
                        freeMemory(students);
                        return EXIT_FAILURE;
                    }
                }
                break;

            case '2':
                // Display all students
                displayStudents(students, studentCount);
                break;

            case '3':
                // Exiting the program
                freeMemory(students);
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid option. Please choose from 1-3.\n");
                break;
        }
    } while (choice != '3');

    return EXIT_SUCCESS;
}

void addStudent(Student **students, int *count) {
    // Input student data
    printf("Enter name: ");
    scanf(" %[^\n]", (*students)[*count].name);
    printf("Enter age: ");
    scanf("%d", &((*students)[*count].age));
    printf("Enter GPA: ");
    scanf("%f", &((*students)[*count].gpa));

    // Increment student count
    (*count)++;
}

void displayStudents(Student *students, int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }
    printf("\nList of Students:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-5s %-5s\n", "Name", "Age", "GPA");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-20s %-5d %-5.2f\n", students[i].name, students[i].age, students[i].gpa);
    }
    printf("--------------------------------------------------\n");
}

void freeMemory(Student *students) {
    free(students);
}