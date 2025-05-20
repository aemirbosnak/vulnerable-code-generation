//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: creative
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
    printf("Enter Student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]s", new_student.name);
    printf("Enter Student GPA: ");
    scanf("%f", &new_student.gpa);
    
    students[student_count++] = new_student;
    printf("Student added successfully!\n");
}

void view_students() {
    if (student_count == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < student_count; i++) {
        printf("ID: %d, Name: %s, GPA: %.2f\n", 
                students[i].id, students[i].name, students[i].gpa);
    }
    printf("-----------------------\n");
}

void delete_student() {
    if (student_count == 0) {
        printf("No students to delete.\n");
        return;
    }

    int id_to_delete;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id_to_delete);

    int found = 0;
    for (int i = 0; i < student_count; i++) {
        if (students[i].id == id_to_delete) {
            found = 1;
            for (int j = i; j < student_count - 1; j++) {
                students[j] = students[j + 1];
            }
            student_count--;
            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("No student found with ID %d.\n", id_to_delete);
    }
}

void display_menu() {
    printf("\n--- Student Management System ---\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Delete Student\n");
    printf("4. Exit\n");
    printf("---------------------------------\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    do {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                view_students();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}