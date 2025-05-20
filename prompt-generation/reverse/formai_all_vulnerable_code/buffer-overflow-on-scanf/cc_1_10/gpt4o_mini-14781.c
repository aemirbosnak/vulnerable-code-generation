//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: single-threaded
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

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addStudent(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full, cannot add more students.\n");
        return;
    }
    
    Student newStudent;
    printf("Enter Student ID: ");
    scanf("%d", &newStudent.id);
    printf("Enter Student Name: ");
    scanf(" %[^\n]", newStudent.name);
    printf("Enter Student Age: ");
    scanf("%d", &newStudent.age);
    
    db->records[db->count] = newStudent;
    db->count++;
    printf("Student added successfully!\n");
}

void deleteStudent(Database *db) {
    int id, i, found = 0;
    printf("Enter Student ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Student deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void viewStudents(Database *db) {
    if (db->count == 0) {
        printf("No students in the database.\n");
        return;
    }
    
    printf("\nList of Students:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", 
               db->records[i].id, 
               db->records[i].name, 
               db->records[i].age);
    }
}

void searchStudent(Database *db) {
    int id, found = 0;
    printf("Enter Student ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Student found - ID: %d, Name: %s, Age: %d\n", 
                   db->records[i].id, 
                   db->records[i].name, 
                   db->records[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student with ID %d not found.\n", id);
    }
}

void displayMenu() {
    printf("\nDatabase Menu:\n");
    printf("1. Add Student\n");
    printf("2. Delete Student\n");
    printf("3. View Students\n");
    printf("4. Search Student\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Database db;
    initializeDatabase(&db);
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(&db);
                break;
            case 2:
                deleteStudent(&db);
                break;
            case 3:
                viewStudents(&db);
                break;
            case 4:
                searchStudent(&db);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 5);

    return 0;
}