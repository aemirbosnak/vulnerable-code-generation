//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
} Record;

int recordCount = 0;
Record database[MAX_RECORDS];

void addRecord();
void viewRecords();
void deleteRecord();
void searchRecord();
void menu();

int main() {
    menu();
    return 0;
}

void menu() {
    int choice;
    do {
        printf("\n--- Simple Database Simulation ---\n");
        printf("1. Add Record\n");
        printf("2. View Records\n");
        printf("3. Delete Record\n");
        printf("4. Search Record\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addRecord(); break;
            case 2: viewRecords(); break;
            case 3: deleteRecord(); break;
            case 4: searchRecord(); break;
            case 5: printf("Exiting... Goodbye!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);
}

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database full! Cannot add more records.\n");
        return;
    }
    Record newRecord;
    newRecord.id = recordCount + 1;
    printf("Enter name: ");
    scanf(" %[^\n]", newRecord.name); // Read string with spaces
    printf("Enter address: ");
    scanf(" %[^\n]", newRecord.address);
    database[recordCount++] = newRecord;
    printf("Record added successfully! ID: %d\n", newRecord.id);
}

void viewRecords() {
    printf("\n--- Viewing All Records ---\n");
    if (recordCount == 0) {
        printf("No records found!\n");
        return;
    }
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s, Address: %s\n", database[i].id, database[i].name, database[i].address);
    }
}

void deleteRecord() {
    int id;
    printf("Enter ID of record to delete: ");
    scanf("%d", &id);
    if (id < 1 || id > recordCount) {
        printf("Invalid ID! No record deleted.\n");
        return;
    }
    for (int i = id - 1; i < recordCount - 1; i++) {
        database[i] = database[i + 1]; // Shift records
    }
    recordCount--;
    printf("Record ID %d deleted successfully!\n", id);
}

void searchRecord() {
    char searchName[MAX_NAME_LENGTH];
    printf("Enter name to search: ");
    scanf(" %[^\n]", searchName);
    printf("\n--- Search Results for '%s' ---\n", searchName);
    int found = 0;
    for (int i = 0; i < recordCount; i++) {
        if (strcmp(database[i].name, searchName) == 0) {
            printf("ID: %d, Name: %s, Address: %s\n", database[i].id, database[i].name, database[i].address);
            found = 1;
        }
    }
    if (!found) {
        printf("No records found with the name '%s'.\n", searchName);
    }
}