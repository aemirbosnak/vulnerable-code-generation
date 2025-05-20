//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ADDRESS_LENGTH 100

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, int id, const char *name, const char *address) {
    if (db->count >= MAX_RECORDS) {
        printf("Database full! Cannot add more records.\n");
        return;
    }
    db->records[db->count].id = id;
    strncpy(db->records[db->count].name, name, NAME_LENGTH);
    strncpy(db->records[db->count].address, address, ADDRESS_LENGTH);
    db->count++;
    printf("Record added successfully!\n");
}

void viewRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records available.\n");
        return;
    }
    printf("\n--- Records ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Address: %s\n",
               db->records[i].id, db->records[i].name, db->records[i].address);
    }
    printf("----------------\n");
}

void deleteRecord(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            db->records[i] = db->records[db->count - 1]; // Swap with last record
            db->count--;
            printf("Record with ID %d deleted.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void searchByName(const Database *db, const char *name) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcasecmp(db->records[i].name, name) == 0) { // Case insensitive search
            printf("Found Record: ID: %d, Name: %s, Address: %s\n", 
                   db->records[i].id, db->records[i].name, db->records[i].address);
            found = 1;
        }
    }
    if (!found) {
        printf("No record found with name: %s\n", name);
    }
}

void clearDatabase(Database *db) {
    db->count = 0;
    printf("Database cleared.\n");
}

void displayMenu() {
    printf("\n--- Database Menu ---\n");
    printf("1. Add Record\n");
    printf("2. View Records\n");
    printf("3. Delete Record\n");
    printf("4. Search by Name\n");
    printf("5. Clear Database\n");
    printf("0. Exit\n");
}

int main() {
    Database db;
    initDatabase(&db);
    
    int choice = -1;

    while (choice != 0) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id;
            char name[NAME_LENGTH], address[ADDRESS_LENGTH];
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf(" %[^\n]", name); // Space before %[^\n] to consume newline
            printf("Enter Address: ");
            scanf(" %[^\n]", address);
            addRecord(&db, id, name, address);
        } else if (choice == 2) {
            viewRecords(&db);
        } else if (choice == 3) {
            int id;
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteRecord(&db, id);
        } else if (choice == 4) {
            char name[NAME_LENGTH];
            printf("Enter Name to search: ");
            scanf(" %[^\n]", name);
            searchByName(&db, name);
        } else if (choice == 5) {
            clearDatabase(&db);
        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }
    }
    
    printf("Thank you for using the Database Simulator!\n");
    return 0;
}