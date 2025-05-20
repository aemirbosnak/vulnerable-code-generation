//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: modular
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

Student* database[MAX_STUDENTS];
int student_count = 0;

// Function prototypes
void add_student();
void view_students();
void search_student();
void delete_student();
void free_memory();

int main() {
    int choice;

    while (1) {
        printf("\nStudent Database Menu:\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: view_students(); break;
            case 3: search_student(); break;
            case 4: delete_student(); break;
            case 5: free_memory(); exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Database is full. Cannot add more students.\n");
        return;
    }
    
    Student* new_student = (Student*)malloc(sizeof(Student));
    printf("Enter Student ID: ");
    scanf("%d", &new_student->id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", new_student->name);  // Read string with spaces
    printf("Enter Student GPA: ");
    scanf("%f", &new_student->gpa);
    
    database[student_count] = new_student;
    student_count++;
    printf("Student added successfully!\n");
}

void view_students() {
    if (student_count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\nList of Students:\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", 
                database[i]->id, database[i]->name, database[i]->gpa);
    }
}

void search_student() {
    int id;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);
    
    for (int i = 0; i < student_count; i++) {
        if (database[i]->id == id) {
            printf("Found Student - ID: %d, Name: %s, GPA: %.2f\n", 
                    database[i]->id, database[i]->name, database[i]->gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void delete_student() {
    int id;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);
    
    for (int i = 0; i < student_count; i++) {
        if (database[i]->id == id) {
            free(database[i]); // Free the memory
            // Shift the remaining students
            for (int j = i; j < student_count - 1; j++) {
                database[j] = database[j + 1];
            }
            student_count--;
            printf("Student with ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Student with ID %d not found.\n", id);
}

void free_memory() {
    for (int i = 0; i < student_count; i++) {
        free(database[i]);
    }
    printf("Memory freed.\n");
}