//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function to initialize the database
void initDatabase(Database *db) {
    db->count = 0;
}

// Function to add a record to the database
void addRecord(Database *db, const char *name, const char *email) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    db->records[db->count].id = db->count + 1; // Simple id assignment
    strncpy(db->records[db->count].name, name, NAME_LENGTH);
    strncpy(db->records[db->count].email, email, EMAIL_LENGTH);
    db->count++;
    printf("Record added: [%d] %s - %s\n", db->records[db->count - 1].id, 
            db->records[db->count - 1].name, db->records[db->count - 1].email);
}

// Function to display all records
void displayRecords(const Database *db) {
    printf("\n---- Database Records ----\n");
    for (int i = 0; i < db->count; i++) {
        printf("[%d] %s - %s\n", db->records[i].id, db->records[i].name, db->records[i].email);
    }
    if (db->count == 0) {
        printf("No records found.\n");
    }
}

// Function to search for a record by name
void searchRecordByName(const Database *db, const char *name) {
    printf("\n---- Search Results ----\n");
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->records[i].name, name) == 0) {
            printf("[%d] %s - %s\n", db->records[i].id, db->records[i].name, db->records[i].email);
            found = 1;
        }
    }
    if (!found) {
        printf("No records found for name: %s\n", name);
    }
}

// Function to delete a record by id
void deleteRecordById(Database *db, int id) {
    if (id <= 0 || id > db->count) {
        printf("Invalid ID. No record deleted.\n");
        return;
    }
    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
    printf("Record with ID %d has been deleted.\n", id);
}

// Main menu functions
void displayMenu() {
    printf("\n---- Database Menu ----\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record by Name\n");
    printf("4. Delete Record by ID\n");
    printf("5. Exit\n");
}

int main() {
    Database db;
    initDatabase(&db);
    int choice;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
    int id;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline character

        switch (choice) {
            case 1:
                printf("Enter name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline character
                printf("Enter email: ");
                fgets(email, EMAIL_LENGTH, stdin);
                email[strcspn(email, "\n")] = 0; // Remove newline character
                addRecord(&db, name, email);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                printf("Enter name to search: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = 0; // Remove newline
                searchRecordByName(&db, name);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecordById(&db, id);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}