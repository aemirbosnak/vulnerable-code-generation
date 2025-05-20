//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 100
#define MAX_STUDENTS 50

// Define a structure to hold student information
typedef struct {
    char name[NAME_LENGTH];
    int score;
} Student;

// Function to add a student
void addStudent(Student *students, int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students. Maximum limit reached!\n");
        return;
    }
    
    printf("Enter the name of the student: ");
    scanf("%s", students[*count].name);
    printf("Enter the score of the student: ");
    scanf("%d", &students[*count].score);
    
    (*count)++;
    printf("Student '%s' added successfully!\n", students[*count - 1].name);
}

// Function to display all students
void displayStudents(const Student *students, int count) {
    if (count == 0) {
        printf("No student records available.\n");
        return;
    }
    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Student %d: Name: %s, Score: %d\n", i + 1, students[i].name, students[i].score);
    }
}

// Function to search for a student by name
void searchStudent(const Student *students, int count) {
    char searchName[NAME_LENGTH];
    printf("Enter the name of the student to search: ");
    scanf("%s", searchName);

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("Found Student: Name: %s, Score: %d\n", students[i].name, students[i].score);
            return;
        }
    }
    printf("Student '%s' not found!\n", searchName);
}

// Function to free allocated memory (if needed in future extensions)
void freeMemory(Student **students) {
    free(*students);
    *students = NULL;  // Ensure dangling pointer is avoided
}

int main() {
    Student *students = (Student *)malloc(MAX_STUDENTS * sizeof(Student));
    if (students == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return EXIT_FAILURE;
    }

    int studentCount = 0;
    int choice;

    do {
        printf("\n--- Student Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 4);

    freeMemory(&students);
    return 0;
}