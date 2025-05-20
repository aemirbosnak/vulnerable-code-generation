//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: single-threaded
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

// Function declarations
void initializeDatabase(Database *db);
void insertRecord(Database *db, int id, const char *name, int age);
void displayRecords(const Database *db);
Record* searchRecordById(const Database *db, int id);
void deleteRecordById(Database *db, int id);
void menu();

int main() {
    Database db;
    initializeDatabase(&db);
    
    int choice;

    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int id, age;
            char name[NAME_LENGTH];
            printf("Enter ID: ");
            scanf("%d", &id);
            printf("Enter Name: ");
            scanf("%s", name);
            printf("Enter Age: ");
            scanf("%d", &age);
            insertRecord(&db, id, name, age);
        } else if (choice == 2) {
            displayRecords(&db);
        } else if (choice == 3) {
            int id;
            printf("Enter ID to search: ");
            scanf("%d", &id);
            Record* record = searchRecordById(&db, id);
            if (record != NULL) {
                printf("Record Found - ID: %d, Name: %s, Age: %d\n", record->id, record->name, record->age);
            } else {
                printf("Record not found.\n");
            }
        } else if (choice == 4) {
            int id;
            printf("Enter ID to delete: ");
            scanf("%d", &id);
            deleteRecordById(&db, id);
        }
    } while (choice != 5);

    return 0;
}

void initializeDatabase(Database *db) {
    db->count = 0;
}

void insertRecord(Database *db, int id, const char *name, int age) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, NAME_LENGTH);
        db->records[db->count].age = age;
        db->count++;
        printf("Record inserted.\n");
    } else {
        printf("Database is full! Cannot insert record.\n");
    }
}

void displayRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("Records in database:\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

Record* searchRecordById(const Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

void deleteRecordById(Database *db, int id) {
    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record deleted.\n");
            break;
        }
    }
    if (!found) {
        printf("Record not found for deletion.\n");
    }
}

void menu() {
    printf("\n--- Database Menu ---\n");
    printf("1. Insert Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record by ID\n");
    printf("4. Delete Record by ID\n");
    printf("5. Exit\n");
}