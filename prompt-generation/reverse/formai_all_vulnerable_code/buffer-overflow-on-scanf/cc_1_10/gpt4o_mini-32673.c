//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LEN 50

typedef struct {
    int id;
    char name[MAX_NAME_LEN];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function to initialize the database
void initializeDatabase(Database* db) {
    db->count = 0;
}

// Function to add a record to the database
void addRecord(Database* db, int id, const char* name) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, MAX_NAME_LEN);
        db->count++;
    } else {
        printf("Database is full. Cannot add more records.\n");
    }
}

// Function to display all records
void displayRecords(const Database* db) {
    printf("Records in the database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
    }
}

// Function to find a record by ID
void findRecordById(const Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Record found: ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

// Function to delete a record by ID
void deleteRecordById(Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record with ID %d deleted.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found. Deletion failed.\n", id);
}

// Function to sort records by name (bubble sort for simplicity)
void sortRecordsByName(Database* db) {
    for (int i = 0; i < db->count - 1; i++) {
        for (int j = 0; j < db->count - i - 1; j++) {
            if (strcmp(db->records[j].name, db->records[j + 1].name) > 0) {
                Record temp = db->records[j];
                db->records[j] = db->records[j + 1];
                db->records[j + 1] = temp;
            }
        }
    }
}

// Main function to interact with the user
int main() {
    Database db;
    initializeDatabase(&db);

    int choice;
    do {
        printf("\nDatabase Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Find Record by ID\n");
        printf("4. Delete Record by ID\n");
        printf("5. Sort Records by Name\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id;
            char name[MAX_NAME_LEN];
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            addRecord(&db, id, name);
        } else if (choice == 2) {
            displayRecords(&db);
        } else if (choice == 3) {
            int id;
            printf("Enter ID to find: ");
            scanf("%d", &id);
            findRecordById(&db, id);
        } else if (choice == 4) {
            int id;
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteRecordById(&db, id);
        } else if (choice == 5) {
            sortRecordsByName(&db);
            printf("Records sorted by name.\n");
        } else if (choice != 0) {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    printf("Exiting program. Goodbye!\n");
    return 0;
}