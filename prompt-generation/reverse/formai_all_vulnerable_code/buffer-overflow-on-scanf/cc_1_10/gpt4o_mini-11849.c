//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define ID_LENGTH 10
#define NAME_LENGTH 50

typedef struct {
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
} Student;

typedef struct {
    Student students[MAX_STUDENTS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addStudent(Database *db, const char *id, const char *name) {
    if (db->count < MAX_STUDENTS) {
        strcpy(db->students[db->count].id, id);
        strcpy(db->students[db->count].name, name);
        db->count++;
    } else {
        printf("Database is full, cannot add more students.\n");
    }
}

Student* searchById(Database *db, const char *id) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->students[i].id, id) == 0) {
            return &db->students[i];
        }
    }
    return NULL;
}

void viewStudents(Database *db) {
    printf("List of Students:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %s, Name: %s\n", db->students[i].id, db->students[i].name);
    }
}

int main() {
    Database db;
    initializeDatabase(&db);

    int option;
    char id[ID_LENGTH];
    char name[NAME_LENGTH];

    do {
        printf("\nDatabase Menu:\n");
        printf("1. Add Student\n");
        printf("2. Search by ID\n");
        printf("3. View All Students\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);
        getchar();  // To consume the newline character after scanf

        switch (option) {
            case 1:
                printf("Enter Student ID: ");
                fgets(id, ID_LENGTH, stdin);
                id[strcspn(id, "\n")] = 0;  // Remove newline character

                printf("Enter Student Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0;  // Remove newline character

                addStudent(&db, id, name);
                printf("Student added successfully!\n");
                break;

            case 2:
                printf("Enter Student ID to search: ");
                fgets(id, ID_LENGTH, stdin);
                id[strcspn(id, "\n")] = 0;  // Remove newline character

                Student *foundStudent = searchById(&db, id);
                if (foundStudent) {
                    printf("Student found: ID: %s, Name: %s\n", foundStudent->id, foundStudent->name);
                } else {
                    printf("Student with ID %s not found.\n", id);
                }
                break;

            case 3:
                viewStudents(&db);
                break;

            case 4:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while (option != 4);

    return 0;
}