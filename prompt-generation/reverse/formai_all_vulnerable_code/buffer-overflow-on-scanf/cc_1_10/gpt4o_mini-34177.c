//GPT-4o-mini DATASET v1.0 Category: String manipulation ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

// Function prototypes
void add_student(char students[][NAME_LENGTH], int *count);
void remove_student(char students[][NAME_LENGTH], int *count);
void search_student(char students[][NAME_LENGTH], int count);
void display_students(char students[][NAME_LENGTH], int count);
void clear_buffer();

int main() {
    char students[MAX_STUDENTS][NAME_LENGTH];
    int student_count = 0;
    int choice;

    while (1) {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Remove Student\n");
        printf("3. Search Student\n");
        printf("4. Display Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clear_buffer();

        switch (choice) {
            case 1:
                add_student(students, &student_count);
                break;
            case 2:
                remove_student(students, &student_count);
                break;
            case 3:
                search_student(students, student_count);
                break;
            case 4:
                display_students(students, student_count);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void add_student(char students[][NAME_LENGTH], int *count) {
    if (*count >= MAX_STUDENTS) {
        printf("Cannot add more students, list is full!\n");
        return;
    }
    
    printf("Enter student name: ");
    fgets(students[*count], NAME_LENGTH, stdin);
    students[*count][strcspn(students[*count], "\n")] = 0; // Remove newline character
    (*count)++;
    printf("Student added successfully!\n");
}

void remove_student(char students[][NAME_LENGTH], int *count) {
    char name[NAME_LENGTH];

    if (*count == 0) {
        printf("No students to remove!\n");
        return;
    }
    
    printf("Enter the name of the student to remove: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    for (int i = 0; i < *count; i++) {
        if (strcmp(students[i], name) == 0) {
            // Shift the array to remove the student
            for (int j = i; j < *count - 1; j++) {
                strcpy(students[j], students[j + 1]);
            }
            (*count)--;
            printf("Student '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("Student '%s' not found!\n", name);
}

void search_student(char students[][NAME_LENGTH], int count) {
    char name[NAME_LENGTH];

    printf("Enter the name of the student to search: ");
    fgets(name, NAME_LENGTH, stdin);
    name[strcspn(name, "\n")] = 0; // Remove newline character

    for (int i = 0; i < count; i++) {
        if (strcmp(students[i], name) == 0) {
            printf("Student '%s' found at position %d.\n", name, i + 1);
            return;
        }
    }
    printf("Student '%s' not found!\n", name);
}

void display_students(char students[][NAME_LENGTH], int count) {
    if (count == 0) {
        printf("No students to display!\n");
        return;
    }

    printf("List of Students:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, students[i]);
    }
}

void clear_buffer() {
    while (getchar() != '\n'); // Clear input buffer
}