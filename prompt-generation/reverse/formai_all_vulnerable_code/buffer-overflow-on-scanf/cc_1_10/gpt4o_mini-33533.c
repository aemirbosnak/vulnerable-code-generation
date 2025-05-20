//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define ID_LENGTH 10

typedef struct {
    char id[ID_LENGTH];
    char name[NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

int addRecord(Database *db, const char *id, const char *name) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return -1;
    }
    strcpy(db->records[db->count].id, id);
    strcpy(db->records[db->count].name, name);
    db->count++;
    return 0;
}

int findRecordById(Database *db, const char *id, Record *result) {
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].id, id) == 0) {
            *result = db->records[i];
            return i; // Return the index of the record found
        }
    }
    return -1; // Not found
}

void printRecord(Record *record) {
    printf("Record ID: %s, Name: %s\n", record->id, record->name);
}

int deleteRecord(Database *db, const char *id) {
    int index = findRecordById(db, id, NULL);
    if (index == -1) {
        printf("No record found with ID: %s\n", id);
        return -1;
    }
    // Shift records to remove the deleted one
    for (int i = index; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
    return 0;
}

void listRecords(Database *db) {
    for (int i = 0; i < db->count; i++) {
        printRecord(&db->records[i]);
    }
}

void performDatabaseOperations(Database *db) {
    int choice;
    char id[ID_LENGTH], name[NAME_LENGTH];
    
    do {
        printf("\nDatabase Menu:\n");
        printf("1. Add Record\n");
        printf("2. Find Record by ID\n");
        printf("3. Delete Record by ID\n");
        printf("4. List All Records\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%s", id);
                printf("Enter Name: ");
                scanf("%s", name);
                if (addRecord(db, id, name) == 0) {
                    printf("Record added successfully.\n");
                }
                break;
            case 2:
                printf("Enter ID to find: ");
                scanf("%s", id);
                Record foundRecord;
                if (findRecordById(db, id, &foundRecord) != -1) {
                    printRecord(&foundRecord);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 3:
                printf("Enter ID to delete: ");
                scanf("%s", id);
                if (deleteRecord(db, id) == 0) {
                    printf("Record deleted successfully.\n");
                }
                break;
            case 4:
                listRecords(db);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5);
}

int main() {
    Database db;
    initializeDatabase(&db);
    performDatabaseOperations(&db);
    
    return 0;
}