//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50
#define MAX_DESC_LEN 200

typedef struct Student {
    int id;
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];
    struct Student* next;
} Student;

Student* head = NULL;

void add_student(int id, const char* name, const char* description) {
    Student* new_student = (Student*)malloc(sizeof(Student));
    if (!new_student) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_student->id = id;
    strncpy(new_student->name, name, MAX_NAME_LEN);
    strncpy(new_student->description, description, MAX_DESC_LEN);
    new_student->next = head;
    head = new_student;
    printf("Student added: %d, %s\n", id, name);
}

void delete_student(int id) {
    Student* current = head;
    Student* previous = NULL;

    while (current != NULL && current->id != id) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student with ID %d not found!\n", id);
        return;
    }

    if (previous == NULL) {
        head = current->next; // Delete the head
    } else {
        previous->next = current->next; // Bypass the current
    }
    
    free(current);
    printf("Student with ID %d deleted.\n", id);
}

void display_students() {
    Student* current = head;
    if (current == NULL) {
        printf("No students in the database.\n");
        return;
    }
    printf("Current Students:\n");
    while (current != NULL) {
        printf("ID: %d, Name: %s, Description: %s\n", 
            current->id, current->name, current->description);
        current = current->next;
    }
}

Student* search_student(int id) {
    Student* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void free_memory() {
    Student* current = head;
    Student* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    head = NULL;
}

int main() {
    int choice;
    int id;
    char name[MAX_NAME_LEN];
    char description[MAX_DESC_LEN];

    do {
        printf("\nStudent Database Options:\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display Students\n");
        printf("4. Search Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Student ID: ");
                scanf("%d", &id);
                printf("Enter Student Name: ");
                getchar(); // Clear the newline from the buffer
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                printf("Enter Description: ");
                fgets(description, MAX_DESC_LEN, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                add_student(id, name, description);
                break;
            case 2:
                printf("Enter Student ID to delete: ");
                scanf("%d", &id);
                delete_student(id);
                break;
            case 3:
                display_students();
                break;
            case 4:
                printf("Enter Student ID to search: ");
                scanf("%d", &id);
                Student* found = search_student(id);
                if (found) {
                    printf("Student Found: ID: %d, Name: %s, Description: %s\n", 
                        found->id, found->name, found->description);
                } else {
                    printf("Student with ID %d not found!\n", id);
                }
                break;
            case 5:
                free_memory();
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}