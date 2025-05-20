//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_COURSE_LENGTH 30

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char course[MAX_COURSE_LENGTH];
    int age;
} Student;

typedef struct {
    Student records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database* db) {
    db->count = 0;
}

void addStudent(Database* db, int id, const char* name, const char* course, int age) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, MAX_NAME_LENGTH);
        strncpy(db->records[db->count].course, course, MAX_COURSE_LENGTH);
        db->records[db->count].age = age;
        db->count++;
        printf("Student ID %d added successfully.\n", id);
    } else {
        printf("Database is full! Cannot add more records.\n");
    }
}

void deleteStudent(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Student ID %d deleted successfully.\n", id);
            return;
        }
    }
    printf("Student ID %d not found!\n", id);
}

void displayStudents(const Database* db) {
    if (db->count == 0) {
        printf("No records to display!\n");
        return;
    }
    printf("\n--- Student Records ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Course: %s, Age: %d\n",
               db->records[i].id, db->records[i].name, 
               db->records[i].course, db->records[i].age);
    }
    printf("-----------------------\n");
}

void searchStudent(const Database* db, const char* name) {
    printf("\n--- Search Results for '%s' ---\n", name);
    for (int i = 0; i < db->count; i++) {
        if (strstr(db->records[i].name, name) != NULL) {
            printf("Match Found - ID: %d, Name: %s, Course: %s, Age: %d\n",
                   db->records[i].id, db->records[i].name, 
                   db->records[i].course, db->records[i].age);
        }
    }
    printf("-----------------------\n");
}

void menu(Database* db) {
    int choice, id, age;
    char name[MAX_NAME_LENGTH], course[MAX_COURSE_LENGTH];

    do {
        printf("\n--- Student Database Menu ---\n");
        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Display All Students\n");
        printf("4. Search Student by Name\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                printf("Enter Course: ");
                scanf(" %[^\n]", course);
                printf("Enter Age: ");
                scanf("%d", &age);
                addStudent(db, id, name, course, age);
                break;
            case 2:
                printf("Enter ID to Delete: ");
                scanf("%d", &id);
                deleteStudent(db, id);
                break;
            case 3:
                displayStudents(db);
                break;
            case 4:
                printf("Enter Name to Search: ");
                scanf(" %[^\n]", name);
                searchStudent(db, name);
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
    Database db;
    initializeDatabase(&db);
    menu(&db);
    return 0;
}