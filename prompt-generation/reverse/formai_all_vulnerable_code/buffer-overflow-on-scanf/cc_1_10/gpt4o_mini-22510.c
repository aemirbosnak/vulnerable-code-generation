//GPT-4o-mini DATASET v1.0 Category: Searching algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Struct to represent a student
typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// Function Prototypes
void displayMenu();
void addStudent(Student students[], int *count);
void searchStudent(const Student students[], int count);
void displayStudents(const Student students[], int count);
void sortStudents(Student students[], int count);
int comparison(const void *a, const void *b);

// Main function
int main() {
    Student students[MAX_SIZE];
    int count = 0;
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(students, &count);
                break;
            case 2:
                searchStudent(students, count);
                break;
            case 3:
                displayStudents(students, count);
                break;
            case 4:
                sortStudents(students, count);
                printf("Students sorted by ID.\n");
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n=== Student Management System ===\n");
    printf("1. Add Student\n");
    printf("2. Search Student\n");
    printf("3. Display All Students\n");
    printf("4. Sort Students\n");
    printf("5. Exit\n");
}

// Function to add a new student
void addStudent(Student students[], int *count) {
    if (*count >= MAX_SIZE) {
        printf("Cannot add more students. Maximum capacity reached.\n");
        return;
    }

    Student newStudent;
    newStudent.id = *count + 1; // Simple ID assignment
    printf("Enter student name: ");
    scanf(" %[^\n]", newStudent.name); // Read string with spaces
    printf("Enter student grade: ");
    scanf("%f", &newStudent.grade);

    students[*count] = newStudent;
    (*count)++;
    printf("Student added successfully.\n");
}

// Function to search for a student by ID
void searchStudent(const Student students[], int count) {
    if (count == 0) {
        printf("No students available for search.\n");
        return;
    }

    int searchId;
    printf("Enter student ID to search: ");
    scanf("%d", &searchId);

    // Searching for the student
    for (int i = 0; i < count; i++) {
        if (students[i].id == searchId) {
            printf("Student Found:\n");
            printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
            return;
        }
    }
    
    printf("No student found with ID: %d\n", searchId);
}

// Function to display all students
void displayStudents(const Student students[], int count) {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n=== List of Students ===\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Grade: %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

// Function to sort students by ID
void sortStudents(Student students[], int count) {
    if (count == 0) {
        printf("No students to sort.\n");
        return;
    }
    qsort(students, count, sizeof(Student), comparison);
}

// Comparison function for qsort
int comparison(const void *a, const void *b) {
    Student *studentA = (Student *)a;
    Student *studentB = (Student *)b;
    return (studentA->id - studentB->id);
}