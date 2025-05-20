//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int age;
} Person;

typedef struct {
    Person records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, int id, const char *name, int age) {
    if (db->count < MAX_RECORDS) {
        db->records[db->count].id = id;
        strncpy(db->records[db->count].name, name, NAME_LENGTH);
        db->records[db->count].age = age;
        db->count++;
        printf("Record added: %d, %s, %d\n", id, name, age);
    } else {
        printf("Database is full. Cannot add more records.\n");
    }
}

void displayRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\n--- Records in Database ---\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
    printf("---------------------------\n");
}

void findRecordById(const Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Record found: ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
            return;
        }
    }
    printf("Record with ID %d not found.\n", id);
}

void deleteRecordById(Database *db, int id) {
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            printf("Deleting record: ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
            // Shift records to the left
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record deleted successfully.\n");
            return;
        }
    }
    printf("Record with ID %d not found for deletion.\n", id);
}

void clearDatabase(Database *db) {
    db->count = 0;
    printf("Database cleared. No records remain.\n");
}

int main() {
    Database db;
    initializeDatabase(&db);

    int choice, id, age;
    char name[NAME_LENGTH];

    while (1) {
        printf("\n--- Simple Database Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Find Record by ID\n");
        printf("4. Delete Record by ID\n");
        printf("5. Clear Database\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
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
                displayRecords(&db);
                break;
            case 3:
                printf("Enter ID to find: ");
                scanf("%d", &id);
                findRecordById(&db, id);
                break;
            case 4:
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                deleteRecordById(&db, id);
                break;
            case 5:
                clearDatabase(&db);
                break;
            case 6:
                printf("Exiting the program. Farewell!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }

    return 0;
}