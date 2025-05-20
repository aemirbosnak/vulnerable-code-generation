//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

Student database[MAX_RECORDS];
int record_count = 0;

// Function Declarations
void display_menu();
void add_student();
void delete_student();
void view_students();
void search_student();
int find_student_index(int id);
void clear_buffer();

// Main function
int main() {
    int choice;

    while (1) {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                delete_student();
                break;
            case 3:
                view_students();
                break;
            case 4:
                search_student();
                break;
            case 5:
                printf("Exiting the database program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the main menu
void display_menu() {
    printf("\n--- Student Database ---\n");
    printf("1. Add Student\n");
    printf("2. Delete Student\n");
    printf("3. View Students\n");
    printf("4. Search Student\n");
    printf("5. Exit\n");
}

// Function to add a student
void add_student() {
    if (record_count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }

    Student new_student;
    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    clear_buffer();
    printf("Enter student Name: ");
    fgets(new_student.name, NAME_LENGTH, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0; // Remove newline character
    printf("Enter student Age: ");
    scanf("%d", &new_student.age);
    
    database[record_count++] = new_student;
    printf("Student added successfully!\n");
}

// Function to delete a student
void delete_student() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    int index = find_student_index(id);
    if (index != -1) {
        for (int i = index; i < record_count - 1; i++) {
            database[i] = database[i + 1];
        }
        record_count--;
        printf("Student with ID %d deleted successfully.\n", id);
    } else {
        printf("No student found with ID %d.\n", id);
    }
}

// Function to view all students
void view_students() {
    if (record_count == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("\nStudents List:\n");
    for (int i = 0; i < record_count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", database[i].id, database[i].name, database[i].age);
    }
}

// Function to search for a student by ID
void search_student() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    int index = find_student_index(id);
    if (index != -1) {
        printf("Found Student - ID: %d, Name: %s, Age: %d\n", 
                database[index].id, database[index].name, database[index].age);
    } else {
        printf("No student found with ID %d.\n", id);
    }
}

// Helper function to find student index by ID
int find_student_index(int id) {
    for (int i = 0; i < record_count; i++) {
        if (database[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}

// Function to clear the input buffer
void clear_buffer() {
    while (getchar() != '\n'); // Clear input until newline
}