//GPT-4o-mini DATASET v1.0 Category: Data structures visualization ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int size;
} StudentDatabase;

void initializeDatabase(StudentDatabase *db) {
    db->size = 0;
}

void addStudent(StudentDatabase *db, const char *name, int age, float gpa) {
    if (db->size < MAX_STUDENTS) {
        strncpy(db->students[db->size].name, name, MAX_NAME_LENGTH - 1);
        db->students[db->size].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensuring null termination
        db->students[db->size].age = age;
        db->students[db->size].gpa = gpa;
        db->size++;
    } else {
        printf("Database is full! Cannot add more students.\n");
    }
}

void displayStudents(const StudentDatabase *db) {
    printf("\nStudent List:\n");
    printf("--------------------------------------------------\n");
    printf("%-20s %-5s %-5s\n", "Name", "Age", "GPA");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < db->size; i++) {
        printf("%-20s %-5d %.2f\n", db->students[i].name, db->students[i].age, db->students[i].gpa);
    }
    printf("--------------------------------------------------\n");
}

void deleteStudent(StudentDatabase *db, const char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->students[i].name, name) == 0) {
            db->students[i] = db->students[db->size - 1]; // Replace with the last student
            db->size--; // Remove the last student
            printf("Deleted student: %s\n", name);
            return;
        }
    }
    printf("Student %s not found.\n", name);
}

void findStudent(const StudentDatabase *db, const char *name) {
    for (int i = 0; i < db->size; i++) {
        if (strcmp(db->students[i].name, name) == 0) {
            printf("Found student: %s, Age: %d, GPA: %.2f\n", db->students[i].name, db->students[i].age, db->students[i].gpa);
            return;
        }
    }
    printf("Student %s not found.\n", name);
}

void menu() {
    printf("\nStudent Database Menu:\n");
    printf("1. Add Student\n");
    printf("2. Display Students\n");
    printf("3. Delete Student\n");
    printf("4. Find Student\n");
    printf("5. Exit\n");
}

int main() {
    StudentDatabase db;
    initializeDatabase(&db);
    int option;
    char name[MAX_NAME_LENGTH];
    int age;
    float gpa;

    while (1) {
        menu();
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option) {
            case 1: // Add Student
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                printf("Enter GPA: ");
                scanf("%f", &gpa);
                addStudent(&db, name, age, gpa);
                break;
            case 2: // Display Students
                displayStudents(&db);
                break;
            case 3: // Delete Student
                printf("Enter Name to Delete: ");
                scanf(" %[^\n]", name);
                deleteStudent(&db, name);
                break;
            case 4: // Find Student
                printf("Enter Name to Find: ");
                scanf(" %[^\n]", name);
                findStudent(&db, name);
                break;
            case 5: // Exit
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid option! Please choose again.\n");
        }
    }
    return 0;
}