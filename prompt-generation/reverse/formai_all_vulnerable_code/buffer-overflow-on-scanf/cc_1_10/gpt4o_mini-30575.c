//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define NAME_LENGTH 50
#define EMAIL_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    char email[EMAIL_LENGTH];
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

void initializeDatabase(Database* db) {
    db->count = 0;
}

void addRecord(Database* db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full. Cannot add more records.\n");
        return;
    }

    Record newRecord;
    newRecord.id = db->count + 1; // Simple ID assignment
    printf("Enter Name: ");
    scanf(" %[^\n]", newRecord.name);
    printf("Enter Email: ");
    scanf(" %[^\n]", newRecord.email);

    db->records[db->count] = newRecord;
    db->count++;
    printf("Record added successfully!\n");
}

void deleteRecord(Database* db) {
    int id, i, found = 0;
    printf("Enter Record ID to delete: ");
    scanf("%d", &id);

    for (i = 0; i < db->count; i++) {
        if (db->records[i].id == id) {
            found = 1;
            // Shift the records left
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record deleted successfully!\n");
            break;
        }
    }

    if (!found)
        printf("Record with ID %d not found.\n", id);
}

void displayRecords(Database* db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("\nID\tName\t\tEmail\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < db->count; i++) {
        printf("%d\t%s\t%s\n", db->records[i].id, db->records[i].name, db->records[i].email);
    }
}

void searchRecord(Database* db) {
    char email[EMAIL_LENGTH];
    printf("Enter Email to search: ");
    scanf(" %[^\n]", email);

    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (strcmp(db->records[i].email, email) == 0) {
            printf("Record Found: ID: %d, Name: %s, Email: %s\n", db->records[i].id, db->records[i].name, db->records[i].email);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("No record found with email: %s\n", email);
}

void menu() {
    printf("\nDatabase Menu:\n");
    printf("1. Add Record\n");
    printf("2. Delete Record\n");
    printf("3. Display Records\n");
    printf("4. Search Record\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    Database db;
    initializeDatabase(&db);

    int choice;
    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addRecord(&db);
                break;
            case 2:
                deleteRecord(&db);
                break;
            case 3:
                displayRecords(&db);
                break;
            case 4:
                searchRecord(&db);
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}