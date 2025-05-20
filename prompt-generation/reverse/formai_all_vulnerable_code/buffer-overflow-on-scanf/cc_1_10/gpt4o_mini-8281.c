//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define DESCRIPTION_LENGTH 200

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void init_database(Database *db) {
    db->count = 0;
}

int add_record(Database *db, const char *name, const char *description) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return -1;
    }
    db->records[db->count].id = db->count + 1;
    strncpy(db->records[db->count].name, name, NAME_LENGTH);
    strncpy(db->records[db->count].description, description, DESCRIPTION_LENGTH);
    db->count++;
    return 0;
}

void view_records(const Database *db) {
    if (db->count == 0) {
        printf("No records found in the database.\n");
        return;
    }
    printf("\n=== Database Records ===\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d\n", db->records[i].id);
        printf("Name: %s\n", db->records[i].name);
        printf("Description: %s\n", db->records[i].description);
        printf("------------------------\n");
    }
}

Record *find_record_by_id(const Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            return (Record *)&db->records[i];
        }
    }
    return NULL;
}

void delete_record(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record with ID %d has been deleted.\n", id);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void menu(Database *db) {
    int choice;
    char name[NAME_LENGTH];
    char description[DESCRIPTION_LENGTH];
    int id;

    do {
        printf("\n=== Database Management System ===\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Delete Record\n");
        printf("4. Find Record by ID\n");
        printf("0. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                fgets(name, NAME_LENGTH, stdin);
                name[strcspn(name, "\n")] = '\0';
                printf("Enter Description: ");
                fgets(description, DESCRIPTION_LENGTH, stdin);
                description[strcspn(description, "\n")] = '\0';
                add_record(db, name, description);
                break;
            case 2:
                view_records(db);
                break;
            case 3:
                printf("Enter ID of record to delete: ");
                scanf("%d", &id);
                delete_record(db, id);
                break;
            case 4:
                printf("Enter ID of record to find: ");
                scanf("%d", &id);
                Record *record = find_record_by_id(db, id);
                if (record) {
                    printf("\nRecord Found:\n");
                    printf("ID: %d\n", record->id);
                    printf("Name: %s\n", record->name);
                    printf("Description: %s\n", record->description);
                } else {
                    printf("Record with ID %d not found.\n", id);
                }
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }
    } while (choice != 0);
}

int main() {
    Database db;
    init_database(&db);
    menu(&db);
    return 0;
}