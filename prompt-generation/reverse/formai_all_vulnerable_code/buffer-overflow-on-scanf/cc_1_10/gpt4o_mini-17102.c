//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

Student database[MAX_STUDENTS];
int student_count = 0;

void add_student();
void view_students();
void delete_student();
void display_menu();
int find_student_index(int id);

int main() {
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        fflush(stdin); // Clear input buffer

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
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void display_menu() {
    printf("\n----- Student Database -----\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Delete Student\n");
    printf("4. Exit\n");
}

void add_student() {
    if (student_count >= MAX_STUDENTS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }

    Student new_student;

    printf("Enter Student ID: ");
    scanf("%d", &new_student.id);
    fflush(stdin); // Clear input buffer

    printf("Enter Student Name: ");
    fgets(new_student.name, NAME_LENGTH, stdin);
    new_student.name[strcspn(new_student.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Student Age: ");
    scanf("%d", &new_student.age);

    database[student_count] = new_student;
    student_count++;

    printf("Student added successfully!\n");
}

void view_students() {
    if (student_count == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("\n----- Student Records -----\n");
    printf("| ID  | Name                          | Age |\n");
    printf("|-----|-------------------------------|-----|\n");

    for (int i = 0; i < student_count; i++) {
        printf("| %-3d | %-30s | %-3d |\n", database[i].id, database[i].name, database[i].age);
    }
    
    printf("|-----|-------------------------------|-----|\n");
}

void delete_student() {
    int id;

    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    int index = find_student_index(id);
    if (index == -1) {
        printf("Student with ID %d not found!\n", id);
        return;
    }

    for (int i = index; i < student_count - 1; i++) {
        database[i] = database[i + 1]; // Shift left to delete
    }
    student_count--;
    printf("Student with ID %d has been deleted.\n", id);
}

int find_student_index(int id) {
    for (int i = 0; i < student_count; i++) {
        if (database[i].id == id) {
            return i;
        }
    }
    return -1; // Not found
}