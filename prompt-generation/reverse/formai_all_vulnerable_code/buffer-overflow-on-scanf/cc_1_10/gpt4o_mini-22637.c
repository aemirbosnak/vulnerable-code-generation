//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, int id, const char *name) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, MAX_NAME_LENGTH);
        db->count++;
        printf("Record added: ID = %d, Name = %s\n", id, name);
    } else {
        printf("Database is full, cannot add more records.\n");
    }
}

void viewRecords(const Database *db) {
    printf("\n--- Records in Database ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
    }
    printf("---------------------------\n");
}

int searchById(const Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return i; // Return index of the found record
        }
    }
    return -1; // Not found
}

void displayRecord(const Database *db, int index) {
    if (index >= 0 && index < db->count) {
        printf("Found Record - ID: %d, Name: %s\n", db->records[index].id, db->records[index].name);
    } else {
        printf("Record not found.\n");
    }
}

void menu() {
    printf("\n--- Database Indexing System Menu ---\n");
    printf("1. Add Record\n");
    printf("2. View Records\n");
    printf("3. Search Record by ID\n");
    printf("4. Exit\n");
    printf("------------------------------------\n");
}

int main() {
    Database db;
    initializeDatabase(&db);
    
    int choice;
    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                int id;
                char name[MAX_NAME_LENGTH];
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf(" %[^\n]", name); // This allows spaces in the name
                addRecord(&db, id, name);
                break;
            }
            case 2:
                viewRecords(&db);
                break;
            case 3: {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int index = searchById(&db, id);
                displayRecord(&db, index);
                break;
            }
            case 4:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}