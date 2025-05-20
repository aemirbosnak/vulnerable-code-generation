//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100
#define MAX_STUDENTS 100

// Student structure definition
typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    float gpa;
} Student;

// Function prototypes
void addStudent(Student *students, int *studentCount);
void displayStudents(const Student *students, int studentCount);
void searchStudent(const Student *students, int studentCount);

// Main function
int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &studentCount);
                break;
            case 2:
                displayStudents(students, studentCount);
                break;
            case 3:
                searchStudent(students, studentCount);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new student
void addStudent(Student *students, int *studentCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached.\n");
        return;
    }

    Student newStudent;
    newStudent.id = *studentCount + 1;

    printf("Enter student name: ");
    scanf(" %[^\n]", newStudent.name); // Read string with spaces
    printf("Enter GPA: ");
    scanf("%f", &newStudent.gpa);

    students[*studentCount] = newStudent;
    (*studentCount)++;

    printf("Student added successfully: ID=%d, Name=%s, GPA=%.2f\n",
           newStudent.id, newStudent.name, newStudent.gpa);
}

// Function to display all students
void displayStudents(const Student *students, int studentCount) {
    if (studentCount == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nList of Students:\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n",
               students[i].id, students[i].name, students[i].gpa);
    }
}

// Function to search for a student by name
void searchStudent(const Student *students, int studentCount) {
    if (studentCount == 0) {
        printf("No students to search.\n");
        return;
    }

    char searchName[MAX_NAME_LENGTH];
    printf("Enter the name of the student to search: ");
    scanf(" %[^\n]", searchName);

    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcasecmp(students[i].name, searchName) == 0) {
            printf("Student found! ID: %d, Name: %s, GPA: %.2f\n",
                   students[i].id, students[i].name, students[i].gpa);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with the name '%s' not found.\n", searchName);
    }
}