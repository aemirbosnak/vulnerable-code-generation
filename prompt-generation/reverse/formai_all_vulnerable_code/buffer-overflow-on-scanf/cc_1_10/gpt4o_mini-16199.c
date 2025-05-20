//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define COURSE_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char course[COURSE_LENGTH];
} Student;

Student database[MAX_RECORDS];
int record_count = 0;

void addStudent() {
    if (record_count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more students.\n");
        return;
    }

    Student new_student;
    new_student.id = record_count + 1;

    printf("Enter student name: ");
    scanf(" %[^\n]", new_student.name);
    printf("Enter course: ");
    scanf(" %[^\n]", new_student.course);

    database[record_count] = new_student;
    record_count++;
    printf("Student added successfully.\n");
}

void displayStudents() {
    if (record_count == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\nStudent Records:\n");
    printf("ID\tName\t\tCourse\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < record_count; i++) {
        printf("%d\t%s\t%s\n", database[i].id, database[i].name, database[i].course);
    }
}

void findStudentById() {
    int id;
    printf("Enter student ID to find: ");
    scanf("%d", &id);

    if (id <= 0 || id > record_count) {
        printf("No student found with ID %d.\n", id);
        return;
    }

    Student student = database[id - 1];
    printf("Found Student:\n");
    printf("ID: %d\n", student.id);
    printf("Name: %s\n", student.name);
    printf("Course: %s\n", student.course);
}

void deleteStudentById() {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > record_count) {
        printf("No student found with ID %d.\n", id);
        return;
    }

    for (int i = id - 1; i < record_count - 1; i++) {
        database[i] = database[i + 1];
    }
    record_count--;
    printf("Student with ID %d deleted successfully.\n", id);
}

void menu() {
    int choice;
    do {
        printf("\n=== Student Database Menu ===\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Find Student by ID\n");
        printf("4. Delete Student by ID\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                findStudentById();
                break;
            case 4:
                deleteStudentById();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}