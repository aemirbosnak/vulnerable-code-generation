//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database *db) {
    db->count = 0;
}

void addRecord(Database *db, char *name, char *phone) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full!\n");
        return;
    }
    
    Record newRecord;
    newRecord.id = db->count + 1;
    strncpy(newRecord.name, name, NAME_LENGTH);
    strncpy(newRecord.phone, phone, PHONE_LENGTH);
    
    db->records[db->count] = newRecord;
    db->count++;
}

void displayRecords(Database *db) {
    printf("ID\tName\t\tPhone Number\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%s\n", db->records[i].id, db->records[i].name, db->records[i].phone);
    }
}

void searchRecord(Database *db, int id) {
    if (id <= 0 || id > db->count) {
        printf("Record with ID %d not found.\n", id);
        return;
    }
    Record record = db->records[id - 1];
    printf("ID: %d\nName: %s\nPhone: %s\n", record.id, record.name, record.phone);
}

void deleteRecord(Database *db, int id) {
    if (id <= 0 || id > db->count) {
        printf("Record with ID %d not found.\n", id);
        return;
    }

    for (int i = id - 1; i < db->count - 1; i++) {
        db->records[i] = db->records[i + 1];
    }
    db->count--;
    printf("Record with ID %d deleted successfully.\n", id);
}

int main() {
    Database db;
    initializeDatabase(&db);

    int choice;
    char name[NAME_LENGTH];
    char phone[PHONE_LENGTH];
    int id;

    do {
        printf("\nSimple Database Menu\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Delete Record\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone);
                addRecord(&db, name, phone);
                printf("Record added successfully.\n");
                break;
            case 2:
                displayRecords(&db);
                break;
            case 3:
                printf("Enter record ID to search: ");
                scanf("%d", &id);
                searchRecord(&db, id);
                break;
            case 4:
                printf("Enter record ID to delete: ");
                scanf("%d", &id);
                deleteRecord(&db, id);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}