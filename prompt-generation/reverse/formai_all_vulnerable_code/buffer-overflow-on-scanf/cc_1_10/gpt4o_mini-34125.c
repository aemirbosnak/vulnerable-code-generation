//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: introspective
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
    int size;
} Database;

// Function Declarations
void initializeDatabase(Database *db);
void addRecord(Database *db, int id, const char *name);
int compareRecords(const void *a, const void *b);
void sortDatabase(Database *db);
void displayRecords(const Database *db);
Record* searchRecord(const Database *db, int id);

// Main Function
int main() {
    Database db;
    initializeDatabase(&db);

    int option, id;
    char name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nSimple Database Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Sort Records\n");
        printf("3. Display Records\n");
        printf("4. Search Record by ID\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                addRecord(&db, id, name);
                break;
            case 2:
                sortDatabase(&db);
                printf("Records sorted.\n");
                break;
            case 3:
                displayRecords(&db);
                break;
            case 4:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record *record = searchRecord(&db, id);
                if (record) {
                    printf("Record Found - ID: %d, Name: %s\n", record->id, record->name);
                } else {
                    printf("Record not found!\n");
                }
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}

// Initialize the database
void initializeDatabase(Database *db) {
    db->size = 0;
}

// Add a record to the database
void addRecord(Database *db, int id, const char *name) {
    if (db->size >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }
    db->records[db->size].id = id;
    strncpy(db->records[db->size].name, name, MAX_NAME_LENGTH - 1);
    db->records[db->size].name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
    db->size++;
    printf("Record added - ID: %d, Name: %s\n", id, name);
}

// Comparison function for sorting
int compareRecords(const void *a, const void *b) {
    return ((Record *)a)->id - ((Record *)b)->id;
}

// Sort the records in the database by ID
void sortDatabase(Database *db) {
    qsort(db->records, db->size, sizeof(Record), compareRecords);
}

// Display the records in the database
void displayRecords(const Database *db) {
    if (db->size == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("Records:\n");
    for (int i = 0; i < db->size; i++) {
        printf("ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
    }
}

// Search for a record by ID
Record* searchRecord(const Database *db, int id) {
    for (int i = 0; i < db->size; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}