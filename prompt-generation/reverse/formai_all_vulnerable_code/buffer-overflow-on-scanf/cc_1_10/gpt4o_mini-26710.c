//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    float gpa;
} Student;

void addStudent(Student* students, int* studentCount) {
    if (*studentCount >= MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }
    
    Student newStudent;
    newStudent.id = *studentCount + 1; // Simple incremental ID
    printf("Enter student name: ");
    scanf(" %[^\n]", newStudent.name); // Read string with spaces
    printf("Enter student GPA: ");
    scanf("%f", &newStudent.gpa);
    
    students[*studentCount] = newStudent;
    (*studentCount)++;
    printf("Student added successfully!\n");
}

void displayStudents(const Student* students, int studentCount) {
    printf("\n--- Student List ---\n");
    for (int i = 0; i < studentCount; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", 
               students[i].id, 
               students[i].name, 
               students[i].gpa);
    }
}

void searchStudent(const Student* students, int studentCount) {
    char name[NAME_LENGTH];
    printf("Enter the name of the student to search: ");
    scanf(" %[^\n]", name);
    int found = 0;

    printf("--- Search Results ---\n");
    for (int i = 0; i < studentCount; i++) {
        if (strcasecmp(students[i].name, name) == 0) {
            printf("ID: %d, Name: %s, GPA: %.2f\n", 
                   students[i].id, 
                   students[i].name, 
                   students[i].gpa);
            found = 1;
            break; // Stop searching after finding the first match
        }
    }
    if (!found) {
        printf("No student found with the name '%s'.\n", name);
    }
}

int main() {
    Student students[MAX_STUDENTS];
    int studentCount = 0;
    int choice;

    do {
        printf("\n----- Student Management System -----\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search for a Student\n");
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
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}