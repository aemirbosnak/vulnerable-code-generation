//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ROLL_NUMBER_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    char rollNumber[ROLL_NUMBER_LENGTH];
} Student;

typedef struct {
    Student students[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addStudent(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full, cannot add more students.\n");
        return;
    }

    printf("Enter student's name: ");
    scanf("%s", db->students[db->count].name);
    printf("Enter student's roll number: ");
    scanf("%s", db->students[db->count].rollNumber);
    db->count++;
    printf("Student added successfully.\n");
}

void viewStudents(const Database *db) {
    if (db->count == 0) {
        printf("No records found.\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        printf("Student %d: Name: %s, Roll No: %s\n", i + 1, db->students[i].name, db->students[i].rollNumber);
    }
}

void deleteStudent(Database *db) {
    if (db->count == 0) {
        printf("No records to delete.\n");
        return;
    }

    char rollNumber[ROLL_NUMBER_LENGTH];
    printf("Enter roll number of the student to delete: ");
    scanf("%s", rollNumber);

    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->students[i].rollNumber, rollNumber) == 0) {
            for (int j = i; j < db->count - 1; j++) {
                db->students[j] = db->students[j + 1];
            }
            db->count--;
            printf("Student with roll number %s deleted successfully.\n", rollNumber);
            return;
        }
    }
    printf("No student found with roll number %s.\n", rollNumber);
}

void displayMenu() {
    printf("\nSimple Database Management System\n");
    printf("1. Add Student\n");
    printf("2. View Students\n");
    printf("3. Delete Student\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(&db);
                break;
            case 2:
                viewStudents(&db);
                break;
            case 3:
                deleteStudent(&db);
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}