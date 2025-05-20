//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char address[NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int size;
} Database;

typedef struct {
    int index;
    int record_id;
} IndexEntry;

typedef struct {
    IndexEntry index[MAX_RECORDS];
    int size;
} Index;

// Function declarations
void initializeDatabase(Database *db);
void addRecord(Database *db, int id, const char *name, const char *address);
void displayRecords(const Database *db);
void initializeIndex(Index *index);
void createIndex(const Database *db, Index *index);
void displayIndex(const Index *index);
int searchRecordById(const Index *index, const Database *db, int id);

int main() {
    Database db;
    Index index;
    int choice, id;
    char name[NAME_LENGTH];
    char address[NAME_LENGTH];

    initializeDatabase(&db);
    initializeIndex(&index);

    while (1) {
        printf("Simple Database Indexing System\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Create Index\n");
        printf("4. Display Index\n");
        printf("5. Search Record by ID\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Address: ");
                scanf("%s", address);
                addRecord(&db, id, name, address);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                createIndex(&db, &index);
                printf("Index created successfully.\n");
                break;
            case 4:
                displayIndex(&index);
                break;
            case 5:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int record_idx = searchRecordById(&index, &db, id);
                if (record_idx != -1) {
                    printf("Found Record: ID=%d, Name=%s, Address=%s\n", 
                            db.records[record_idx].id, 
                            db.records[record_idx].name, 
                            db.records[record_idx].address);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

void initializeDatabase(Database *db) {
    db->size = 0;
}

void addRecord(Database *db, int id, const char *name, const char *address) {
    if (db->size < MAX_RECORDS) {
        db->records[db->size].id = id;
        strncpy(db->records[db->size].name, name, NAME_LENGTH);
        strncpy(db->records[db->size].address, address, NAME_LENGTH);
        db->size++;
    } else {
        printf("Database is full. Cannot add more records.\n");
    }
}

void displayRecords(const Database *db) {
    printf("Records in the database:\n");
    for (int i = 0; i < db->size; i++) {
        printf("ID: %d, Name: %s, Address: %s\n", 
               db->records[i].id, 
               db->records[i].name, 
               db->records[i].address);
    }
}

void initializeIndex(Index *index) {
    index->size = 0;
}

void createIndex(const Database *db, Index *index) {
    for (int i = 0; i < db->size; i++) {
        index->index[i].index = i;
        index->index[i].record_id = db->records[i].id;
    }
    index->size = db->size;
}

void displayIndex(const Index *index) {
    printf("Index Entries:\n");
    for (int i = 0; i < index->size; i++) {
        printf("Entry[%d]: ID=%d\n", i, index->index[i].record_id);
    }
}

int searchRecordById(const Index *index, const Database *db, int id) {
    for (int i = 0; i < index->size; i++) {
        if (index->index[i].record_id == id) {
            return index->index[i].index;
        }
    }
    return -1; // Not found
}