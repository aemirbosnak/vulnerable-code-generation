//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 30

typedef struct {
    int id;
    char name[NAME_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function prototypes
void initialize_database(Database *db);
void add_record(Database *db, int id, const char* name);
void display_records(Database *db);
Record* search_record(Database *db, int id);
void display_menu();

int main() {
    Database db;
    initialize_database(&db);
    
    int choice, id;
    char name[NAME_LENGTH];

    while (1) {
        display_menu();
        printf("Enter your choice: ");
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
                display_records(&db);
                break;
            case 3:
                printf("Enter ID to search: ");
                scanf("%d", &id);
                Record* found = search_record(&db, id);
                if (found != NULL) {
                    printf("Record Found: ID = %d, Name = %s\n", found->id, found->name);
                } else {
                    printf("Record not found.\n");
                }
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void initialize_database(Database *db) {
    db->count = 0;
}

void add_record(Database *db, int id, const char* name) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add new record.\n");
        return;
    }
    db->records[db->count].id = id;
    strncpy(db->records[db->count].name, name, NAME_LENGTH - 1);
    db->records[db->count].name[NAME_LENGTH - 1] = '\0'; // Ensure null termination
    db->count++;
    printf("Record added successfully!\n");
}

void display_records(Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    printf("Displaying Records:\n");
    printf("ID\tName\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\n", db->records[i].id, db->records[i].name);
    }
}

Record* search_record(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return &db->records[i];
        }
    }
    return NULL;
}

void display_menu() {
    printf("\n===============================\n");
    printf("      Simple Database         \n");
    printf("===============================\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record by ID\n");
    printf("4. Exit\n");
}