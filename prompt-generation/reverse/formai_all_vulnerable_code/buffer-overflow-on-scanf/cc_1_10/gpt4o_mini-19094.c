//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Student;

typedef struct {
    Student records[MAX_RECORDS];
    int count;
} Database;

// Function to initialize the database
void initDatabase(Database *db) {
    db->count = 0;
}

// Function to add a new student record
void addStudent(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }
    
    Student newStudent;
    newStudent.id = db->count + 1; // Assigning ID based on count
    printf("Enter name: ");
    scanf("%s", newStudent.name);
    printf("Enter age: ");
    scanf("%d", &newStudent.age);

    db->records[db->count] = newStudent;
    db->count++;
    printf("Student added successfully! (ID: %d)\n", newStudent.id);
}

// Function to display all student records
void displayStudents(Database *db) {
    if (db->count == 0) {
        printf("No records found.\n");
        return;
    }
    
    printf("\n--- Student Records ---\n");
    printf("ID\tName\tAge\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
    printf("----------------------\n");
}

// Function to delete a student record by ID
void deleteStudent(Database *db) {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    
    if (id <= 0 || id > db->count) {
        printf("Invalid ID. No record found.\n");
        return;
    }
    
    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1]; // Shift records to left
    }
    db->count--;
    printf("Student record with ID %d deleted successfully!\n", id);
}

// Main function
int main() {
    Database db;
    initDatabase(&db);
    int choice;

    do {
        printf("\n--- Database Management System ---\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Delete Student\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&db);
                break;
            case 2:
                displayStudents(&db);
                break;
            case 3:
                deleteStudent(&db);
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