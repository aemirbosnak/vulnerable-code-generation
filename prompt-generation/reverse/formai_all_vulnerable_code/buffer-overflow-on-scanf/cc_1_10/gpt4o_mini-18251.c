//GPT-4o-mini DATASET v1.0 Category: Database simulation ; Style: enthusiastic
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

Record database[MAX_RECORDS];
int recordCount = 0;

void addRecord() {
    if (recordCount >= MAX_RECORDS) {
        printf("Database is full! Cannot add more records.\n");
        return;
    }

    Record newRecord;

    printf("Enter ID: ");
    scanf("%d", &newRecord.id);
    printf("Enter Name: ");
    scanf("%s", newRecord.name);
    printf("Enter Email: ");
    scanf("%s", newRecord.email);

    database[recordCount++] = newRecord;
    printf("Record added successfully!\n");
}

void displayRecords() {
    if (recordCount == 0) {
        printf("No records in the database!\n");
        return;
    }

    printf("\n--- Database Records ---\n");
    for (int i = 0; i < recordCount; i++) {
        printf("ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
    }
    printf("------------------------\n");
}

void searchRecord() {
    int searchId;
    printf("Enter the ID to search: ");
    scanf("%d", &searchId);

    for (int i = 0; i < recordCount; i++) {
        if (database[i].id == searchId) {
            printf("Record found -> ID: %d, Name: %s, Email: %s\n", database[i].id, database[i].name, database[i].email);
            return;
        }
    }
    printf("Record with ID %d not found!\n", searchId);
}

void deleteRecord() {
    int deleteId;
    printf("Enter the ID to delete: ");
    scanf("%d", &deleteId);

    for (int i = 0; i < recordCount; i++) {
        if (database[i].id == deleteId) {
            for (int j = i; j < recordCount - 1; j++) {
                database[j] = database[j + 1];
            }
            recordCount--;
            printf("Record with ID %d deleted successfully!\n", deleteId);
            return;
        }
    }
    printf("Record with ID %d not found!\n", deleteId);
}

void displayMenu() {
    printf("\n=== Welcome to the C Database Simulation ===\n");
    printf("1. Add Record\n");
    printf("2. Display Records\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
    printf("==============================================\n");
}

int main() {
    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                displayRecords();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}