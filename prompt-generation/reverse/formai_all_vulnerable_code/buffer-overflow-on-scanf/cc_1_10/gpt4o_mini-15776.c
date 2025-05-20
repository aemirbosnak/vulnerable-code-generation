//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: surprised
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
        printf("Database is full! Can't add more students.\n");
        return;
    }

    Student new_student;

    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student name: ");
    getchar(); // Consume newline left by previous input
    fgets(new_student.name, NAME_LENGTH, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0; // Remove newline character
    printf("Enter student GPA: ");
    scanf("%f", &new_student.gpa);

    students[student_count++] = new_student;
    printf("Student added successfully!\n\n");
}

void find_student() {
    int id;
    printf("Enter student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id) {
            printf("Student found: ID: %d, Name: %s, GPA: %.2f\n\n", students[i].id, students[i].name, students[i].gpa);
            return;
        }
    }
    printf("Student with ID %d not found!\n\n", id);
}

void display_all_students() {
    if (student_count == 0) {
        printf("No students in the database!\n\n");
        return;
    }

    printf("Listing all students:\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
    printf("\n");
}

void db_menu() {
    int choice;

    while (1) {
        printf("Welcome to the Student Database!\n");
        printf("1. Add Student\n");
        printf("2. Find Student\n");
        printf("3. Display All Students\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                find_student();
                break;
            case 3:
                display_all_students();
                break;
            case 4:
                printf("Exiting the database. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n\n");
        }
    }
}

int main() {
    db_menu();
    return 0;
}