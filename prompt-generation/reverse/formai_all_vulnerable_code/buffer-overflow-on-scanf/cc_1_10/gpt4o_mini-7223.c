//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: intelligent
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

Student student_db[MAX_STUDENTS];
int student_count = 0;

// Function to add a new student
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }

    Student new_student;
    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student Name: ");
    getchar(); // consumes the newline character left in buffer
    fgets(new_student.name, NAME_LENGTH, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = '\0'; // Remove newline
    printf("Enter student GPA: ");
    scanf("%f", &new_student.gpa);

    student_db[student_count++] = new_student;
    printf("Student added successfully!\n");
}

// Function to display all students
void display_students() {
    if (student_count == 0) {
        printf("No students in the database.\n");
        return;
    }
    
    printf("\n--- Student List ---\n");
    printf("ID\tName\t\tGPA\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t%.2f\n", student_db[i].id, student_db[i].name, student_db[i].gpa);
    }
}

// Function to search for a student by ID
void search_student() {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (student_db[i].id == id) {
            printf("Student found:\n");
            printf("ID: %d\nName: %s\nGPA: %.2f\n", student_db[i].id, student_db[i].name, student_db[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to display menu and handle user input
void display_menu() {
    int choice;

    while (1) {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                display_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    display_menu();
    return 0;
}