//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 30
#define ADDRESS_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function declarations
void initializeDatabase(Database *db);
void insertRecord(Database *db, const char *name, const char *address);
void displayRecords(const Database *db);
Record* searchRecordByName(const Database *db, const char *name);

int main() {
    Database db;
    initializeDatabase(&db);
    
    int choice;
    char name[NAME_LENGTH];
    char address[ADDRESS_LENGTH];

    while (1) {
        printf("\nDatabase Indexing System\n");
        printf("1. Insert Record\n");
        printf("2. Display All Records\n");
        printf("3. Search Record by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter address: ");
                scanf("%s", address);
                insertRecord(&db, name, address);
                break;

            case 2:
                displayRecords(&db);
                break;

            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                Record *foundRecord = searchRecordByName(&db, name);
                if (foundRecord) {
                    printf("Record found: Name: %s, Address: %s\n", foundRecord->name, foundRecord->address);
                } else {
                    printf("Record not found!\n");
                }
                break;

            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void initializeDatabase(Database *db) {
    db->count = 0;
}

void insertRecord(Database *db, const char *name, const char *address) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full! Cannot insert more records.\n");
        return;
    }

    // Create a new record
    Record newRecord;
    strncpy(newRecord.name, name, NAME_LENGTH);
    strncpy(newRecord.address, address, ADDRESS_LENGTH);
    
    // Insert the record into the database
    int i;
    for (i = db->count - 1; (i >= 0 && strcmp(newRecord.name, db->records[i].name) < 0); i--) {
        db->records[i + 1] = db->records[i];  // Shift records to the right
    }
    db->records[i + 1] = newRecord;
    db->count++;
    printf("Record inserted successfully!\n");
}

void displayRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("\nRecords in the database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("Name: %s, Address: %s\n", db->records[i].name, db->records[i].address);
    }
}

Record* searchRecordByName(const Database *db, const char *name) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            return &db->records[i];  // Return pointer to the found record
        }
    }
    return NULL;  // Record not found
}