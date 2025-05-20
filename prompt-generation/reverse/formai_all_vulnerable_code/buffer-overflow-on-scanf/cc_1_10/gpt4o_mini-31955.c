//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DATABASE_SIZE 100
#define NAME_SIZE 50

typedef struct {
    int id;
    char name[NAME_SIZE];
} Record;

typedef struct {
    Record records[DATABASE_SIZE];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void paranoidInsert(Database *db, int id, const char *name) {
    if (id <= 0) {
        fprintf(stderr, "Error: Invalid ID. IDs must be positive.\n");
        return;
    }
    if (db->count >= DATABASE_SIZE) {
        fprintf(stderr, "Error: Database is full. No more records can be added.\n");
        return;
    }
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            fprintf(stderr, "Warning: Record with ID %d already exists. Overwrite is not allowed!\n", id);
            return;
        }
    }

    db->records[db->count].id = id;
    strncpy(db->records[db->count].name, name, NAME_SIZE - 1);
    db->records[db->count].name[NAME_SIZE - 1] = '\0'; // Ensuring null-termination
    db->count++;

    printf("Record with ID %d and Name '%s' inserted successfully.\n", id, name);
}

void paranoidRemove(Database *db, int id) {
    if (id <= 0) {
        fprintf(stderr, "Error: Invalid ID. IDs must be positive.\n");
        return;
    }

    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1]; // Shift left
            }
            db->count--;
            printf("Record with ID %d removed successfully.\n", id);
            return;
        }
    }

    fprintf(stderr, "Warning: No record with ID %d found to remove.\n", id);
}

void paranoidDisplay(Database *db) {
    if (db->count == 0) {
        fprintf(stderr, "Warning: No records to display. The database is empty.\n");
        return;
    }
    printf("Current Records:\n");
    printf("ID\tName\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\n", db->records[i].id, db->records[i].name);
    }
}

int main() {
    Database db;
    initializeDatabase(&db);
    
    int choice, id;
    char name[NAME_SIZE];

    while (1) {
        printf("\n--- Paranoid Database Menu ---\n");
        printf("1. Insert Record\n");
        printf("2. Remove Record\n");
        printf("3. Display Records\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            fprintf(stderr, "Invalid input! Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                if (scanf("%d", &id) != 1) {
                    fprintf(stderr, "Invalid input! Please enter a valid ID.\n");
                    break;
                }
                printf("Enter Name: ");
                scanf(" %[^\n]", name);
                paranoidInsert(&db, id, name);
                break;

            case 2:
                printf("Enter ID to remove: ");
                if (scanf("%d", &id) != 1) {
                    fprintf(stderr, "Invalid input! Please enter a valid ID.\n");
                    break;
                }
                paranoidRemove(&db, id);
                break;

            case 3:
                paranoidDisplay(&db);
                break;

            case 4:
                printf("Exiting the program. Remember to stay alert!\n");
                exit(0);

            default:
                fprintf(stderr, "Invalid choice! Please choose between 1-4.\n");
                break;
        }
    }

    return 0;
}