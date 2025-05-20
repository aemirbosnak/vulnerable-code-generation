//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: calm
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

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }

    Record newRecord;
    newRecord.id = db->count + 1;

    printf("Enter Name: ");
    scanf("%s", newRecord.name);
    
    printf("Enter Age: ");
    scanf("%d", &newRecord.age);
    
    db->records[db->count] = newRecord;
    db->count++;

    printf("Record added successfully!\n");
}

void displayRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records found in the database.\n");
        return;
    }

    printf("\nRecords in Database:\n");
    printf("ID\tName\t\tAge\n");
    printf("---------------------------------\n");
    
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
}

void deleteRecord(Database *db) {
    if (db->count == 0) {
        printf("No records to delete.\n");
        return;
    }

    int id;
    printf("Enter the ID of the record to delete: ");
    scanf("%d", &id);

    if (id <= 0 || id > db->count) {
        printf("Invalid ID. Record not found.\n");
        return;
    }

    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }

    db->count--;
    printf("Record deleted successfully!\n");
}

void searchRecord(const Database *db) {
    if (db->count == 0) {
        printf("No records found in the database.\n");
        return;
    }

    char name[NAME_LENGTH];
    printf("Enter the name to search: ");
    scanf("%s", name);

    printf("\nSearch Results:\n");
    printf("ID\tName\t\tAge\n");
    printf("---------------------------------\n");
    
    int found = 0;
    
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].name, name) == 0) {
            printf("%d\t%s\t\t%d\n", db->records[i].id, db->records[i].name, db->records[i].age);
            found = 1;
        }
    }
    
    if (!found) {
        printf("No records found with the name '%s'.\n", name);
    }
}

void clearDatabase(Database *db) {
    db->count = 0;
    printf("All records have been cleared from the database.\n");
}

int main() {
    Database db;
    initializeDatabase(&db);
    
    int choice;
    
    do {
        printf("\n--- Simple Database Menu ---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Delete Record\n");
        printf("4. Search Record\n");
        printf("5. Clear Database\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord(&db);
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                deleteRecord(&db);
                break;
            case 4:
                searchRecord(&db);
                break;
            case 5:
                clearDatabase(&db);
                break;
            case 0:
                printf("Exiting the database program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}