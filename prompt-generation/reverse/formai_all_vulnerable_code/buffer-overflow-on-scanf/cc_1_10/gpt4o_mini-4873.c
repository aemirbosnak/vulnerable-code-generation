//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Database;

// Function declarations
void addRecord(Database *db);
void displayRecords(const Database *db);
void deleteRecord(Database *db);
void searchRecord(const Database *db);
void menu();

int main() {
    Database db;
    db.count = 0;
    int choice;

    do {
        menu();
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void menu() {
    printf("\n------- Database Menu -------\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Delete Record\n");
    printf("4. Search Record\n");
    printf("5. Exit\n");
    printf("----------------------------\n");
}

void addRecord(Database *db) {
    if (db->count >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }

    Record newRecord;
    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    getchar(); // clear newline character
    printf("Enter Name: ");
    fgets(newRecord.name, MAX_NAME_LENGTH, stdin);
    newRecord.name[strcspn(newRecord.name, "\n")] = 0; // Remove newline character
    printf("Enter Age: ");
    scanf("%d", &newRecord.age);

    db->records[db->count] = newRecord;
    db->count++;
    printf("Record added successfully!\n");
}

void displayRecords(const Database *db) {
    if (db->count == 0) {
        printf("No records to display.\n");
        return;
    }
    
    printf("\n------- Record List -------\n");
    for (int i = 0; i < db->count; i++) {
        printf("ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
    }
    printf("---------------------------\n");
}

void deleteRecord(Database *db) {
    int idToDelete;
    printf("Enter ID of the record to delete: ");
    scanf("%d", &idToDelete);

    int found = 0;
    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == idToDelete) {
            found = 1;
            for (int j = i; j < db->count - 1; j++) {
                db->records[j] = db->records[j + 1];
            }
            db->count--;
            printf("Record deleted successfully!\n");
            break;
        }
    }

    if (!found) {
        printf("Record with ID %d not found.\n", idToDelete);
    }
}

void searchRecord(const Database *db) {
    int idToSearch;
    printf("Enter ID of the record to search: ");
    scanf("%d", &idToSearch);

    for (int i = 0; i < db->count; i++) {
        if (db->records[i].id == idToSearch) {
            printf("Record found: ID: %d, Name: %s, Age: %d\n", db->records[i].id, db->records[i].name, db->records[i].age);
            return;
        }
    }
    
    printf("No record found with ID %d.\n", idToSearch);
}