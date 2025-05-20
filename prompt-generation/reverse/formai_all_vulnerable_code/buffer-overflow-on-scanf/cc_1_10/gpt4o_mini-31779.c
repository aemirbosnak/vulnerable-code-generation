//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: inquisitive
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

Student students[MAX_STUDENTS];
int student_count = 0;

// Function to display the menu
void display_menu() {
    printf("\n--- Student Database Menu ---\n");
    printf("1. Add Student\n");
    printf("2. View All Students\n");
    printf("3. Search Student by ID\n");
    printf("4. Exit\n");
    printf("------------------------------\n");
}

// Function to add a new student
void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Database full. Cannot add more students!\n");
        return;
    }
    
    Student new_student;
    printf("Enter Student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter Student Name: ");
    getchar(); // consume the newline left by scanf
    fgets(new_student.name, NAME_LENGTH, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0; // remove newline
    printf("Enter Student GPA: ");
    scanf("%f", &new_student.gpa);

    // Store the new student in the array
    students[student_count] = new_student;
    student_count++;
    printf("Student added successfully!\n");
}

// Function to view all students
void view_students() {
    if (student_count == 0) {
        printf("No students in the database.\n");
        return;
    }
    printf("\n--- List of Students ---\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

// Function to search for a student by ID
void search_student() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            printf("Student found! ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }
    printf("No student found with ID: %d\n", id);
}

int main() {
    int choice;
    
    printf("Welcome to the Student Database System!\n");
    
    do {
        display_menu();
        printf("Please select an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                search_student();
                break;
            case 4:
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
    } while (choice != 4);

    return 0;
}