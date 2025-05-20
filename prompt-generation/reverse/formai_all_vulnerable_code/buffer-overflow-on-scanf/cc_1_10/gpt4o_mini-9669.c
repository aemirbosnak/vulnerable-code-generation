//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: retro
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
    int count;
} Database;

void init_database(Database *db) {
    db->count = 0;
}

void add_record(Database *db, int id, const char *name) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, MAX_NAME_LENGTH);
        db->count++;
        printf("Record added: %d, %s\n", id, name);
    } else {
        printf("Database is full, cannot add more records.\n");
    }
}

int search_by_id(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return i; // Return the index of the found record
        }
    }
    return -1; // Not found
}

void display_records(Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("\n--- Database Records ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s\n", db->records[i].id, db->records[i].name);
    }
    printf("------------------------\n");
}

void display_record(Database *db, int index) {
    if (index >= 0 && index < db->count) {
        printf("Found Record - ID: %d, Name: %s\n", db->records[index].id, db->records[index].name);
    } else {
        printf("No record found at index %d.\n", index);
    }
}

int main() {
    Database db;
    init_database(&db);
    
    int choice, id;
    char name[MAX_NAME_LENGTH];

    do {
        printf("\n--- Retro Database Indexing System ---\n");
        printf("1. Add Record\n");
        printf("2. Search Record by ID\n");
        printf("3. Display All Records\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter ID: ");
                scanf("%d", &id);
                printf("Enter Name: ");
                scanf("%s", name);
                add_record(&db, id, name);
                break;

            case 2:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                int index = search_by_id(&db, id);
                display_record(&db, index);
                break;

            case 3:
                display_records(&db);
                break;

            case 4:
                printf("Exiting... Goodbye!\n");
                break;

            default:
                printf("Invalid option, please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}