//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: beginner-friendly
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

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }

    Student new_student;

    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student name: ");
    scanf(" %[^\n]", new_student.name);
    printf("Enter student GPA: ");
    scanf("%f", &new_student.gpa);

    students[student_count++] = new_student;
    printf("Student added successfully!\n");
}

void display_students() {
    if (student_count == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("\nList of Students:\n");
    printf("ID\tName\t\tGPA\n");
    for (int i = 0; i < student_count; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

void search_student() {
    int search_id;
    printf("Enter student ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == search_id) {
            printf("Student found:\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("GPA: %.2f\n", students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found.\n", search_id);
}

void display_menu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Search Student\n");
    printf("4. Exit\n");
    printf("----------------------------------\n");
}

int main() {
    int choice;

    do {
        display_menu();
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
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}