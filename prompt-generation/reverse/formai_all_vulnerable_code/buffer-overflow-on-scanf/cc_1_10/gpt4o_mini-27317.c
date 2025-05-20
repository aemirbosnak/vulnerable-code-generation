//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function Prototypes
void initializeDatabase(Database* db);
void addRecord(Database* db, int id, const char* name, int age);
void printRecords(const Database* db);
void searchRecordById(const Database* db, int id);
void freeDatabase(Database* db);

int main() {
    Database db;
    int choice, id, age;
    char name[NAME_LENGTH];

    initializeDatabase(&db);

    do {
        printf("\nDatabase Indexing System:\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Search Record by ID\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                printf("Enter Age: ");
                scanf("%d", &age);
                addRecord(&db, id, name, age);
                break;
            case 2:
                printRecords(&db);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                searchRecordById(&db, id);
                break;
            case 4:
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);

    freeDatabase(&db);
    return 0;
}

void initializeDatabase(Database* db) {
    db->count = 0;
}

void addRecord(Database* db, int id, const char* name, int age) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, NAME_LENGTH);
        db->records[db->count].age = age;
        db->count++;
        printf("Record added successfully!\n");
    } else {
        printf("Database is full, cannot add more records.\n");
    }
}

void printRecords(const Database* db) {
    printf("\n--- Records ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

void searchRecordById(const Database* db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Record found: ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void freeDatabase(Database* db) {
    // In this simple example, there's no dynamic memory allocation,
    // but this function could be used to clear up allocated resources if necessary.
    // Placeholder for potential future enhancements.
}