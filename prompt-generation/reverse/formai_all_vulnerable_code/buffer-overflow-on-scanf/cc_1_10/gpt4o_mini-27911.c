//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50
#define MAX_TITLE_LEN 100

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
    char title[MAX_TITLE_LEN];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, const char *name, const char *title) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    db->records[db->count].id = db->count + 1; // simple ID assignment
    strncpy(db->records[db->count].name, name, MAX_NAME_LEN);
    strncpy(db->records[db->count].title, title, MAX_TITLE_LEN);
    db->count++;
    printf("Record added: ID=%d, Name=%s, Title=%s\n", db->records[db->count-1].id, name, title);
}

void displayRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records available.\n");
        return;
    }
    printf("\n----- Database Records -----\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Title: %s\n", db->records[i].id, db->records[i].name, db->records[i].title);
    }
    printf("----------------------------\n");
}

void searchRecordById(const Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Found Record: ID=%d, Name=%s, Title=%s\n", db->records[i].id, db->records[i].name, db->records[i].title);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void deleteRecordById(Database *db, int id) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1]; // Shift to fill the gap
            }
            db->count--;
            printf("Record with ID %d deleted.\n", id);
            break;
        }
    }
    if (!found) {
        printf("Record with ID %d not found, nothing deleted.\n", id);
    }
}

void clearDatabase(Database *db) {
    db->count = 0;
    printf("Database cleared. All records removed.\n");
}

int main() {
    Database db;
    initializeDatabase(&db);

    int choice;
    char name[MAX_NAME_LEN];
    char title[MAX_TITLE_LEN];
    int id;

    while (1) {
        printf("\n---- Database Menu ----\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Delete Record by ID\n");
        printf("5. Clear Database\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Name: ");
            scanf(" %[^\n]", name); // Read until newline to allow spaces
            printf("Enter Title: ");
            scanf(" %[^\n]", title);
            addRecord(&db, name, title);
            break;
        case 2:
            displayRecords(&db);
            break;
        case 3:
            printf("Enter ID to search: ");
            scanf("%d", &id);
            searchRecordById(&db, id);
            break;
        case 4:
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteRecordById(&db, id);
            break;
        case 5:
            clearDatabase(&db);
            break;
        case 0:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}