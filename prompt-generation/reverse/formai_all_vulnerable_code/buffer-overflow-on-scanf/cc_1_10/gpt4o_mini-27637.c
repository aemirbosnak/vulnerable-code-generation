//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void initializeDatabase(Database* db) {
    db->count = 0;
}

void addStudent(Database* db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    
    Student newStudent;
    newStudent.id = db->count + 1; // auto ID assignment
    printf("Enter name: ");
    scanf("%s", newStudent.name);
    printf("Enter age: ");
    scanf("%d", &newStudent.age);
    
    db->records[db->count] = newStudent;
    db->count++;
    printf("Student added successfully.\n");
}

void modifyStudent(Database* db) {
    int id;
    printf("Enter student ID to modify: ");
    scanf("%d", &id);
    
    if (id < 1 || id > db->count) {
        printf("Student ID not found.\n");
        return;
    }
    
    Student* student = &db->records[id - 1];
    printf("Modify name (current: %s): ", student->name);
    scanf("%s", student->name);
    printf("Modify age (current: %d): ", student->age);
    scanf("%d", &student->age);
    
    printf("Student modified successfully.\n");
}

void deleteStudent(Database* db) {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    
    if (id < 1 || id > db->count) {
        printf("Student ID not found.\n");
        return;
    }

    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
    printf("Student deleted successfully.\n");
}

void queryStudents(Database* db) {
    if (db->count == 0) {
        printf("No students in the database.\n");
        return;
    }
    
    printf("ID\tName\tAge\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

int main() {
    Database db;
    initializeDatabase(&db);
    
    int choice;
    do {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Modify Student\n");
        printf("3. Delete Student\n");
        printf("4. Query Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addStudent(&db);
                break;
            case 2:
                modifyStudent(&db);
                break;
            case 3:
                deleteStudent(&db);
                break;
            case 4:
                queryStudents(&db);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}