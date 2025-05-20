//FormAI DATASET v1.0 Category: Database simulation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_RECORDS 100

typedef struct {
    int id;
    char name[20];
    int age;
    char address[50];
} Record;

// Initialize an array for storing Records
Record records[MAX_RECORDS];

// Initialize the number of records in the array
int numRecords = 0;

void addRecord() {
    if (numRecords >= MAX_RECORDS) {
        printf("Error: Database is full.\n");
        return;
    }

    Record newRecord;

    // Get new record values from user
    printf("Enter new record information:\n");
    printf("ID: ");
    scanf("%d", &newRecord.id);
    printf("Name: ");
    scanf("%s", newRecord.name);
    printf("Age: ");
    scanf("%d", &newRecord.age);
    printf("Address: ");
    scanf("%s", newRecord.address);

    // Add new record to array
    records[numRecords++] = newRecord;

    printf("Record added successfully!\n");
}

void findRecord() {
    int recordId;

    // Get record ID from user
    printf("Enter ID of record to find: ");
    scanf("%d", &recordId);

    // Search for record in array
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == recordId) {
            // Print record information
            printf("Record found:\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Address: %s\n", records[i].address);
            return;
        }
    }

    // If record not found
    printf("Record not found.\n");
}

void deleteRecord() {
    int recordId;
    bool foundRecord = false;

    // Get record ID from user
    printf("Enter ID of record to delete: ");
    scanf("%d", &recordId);

    // Search for record in array
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == recordId) {
            // Shift all records after deleted record back by one index
            for (int j = i; j < numRecords - 1; j++) {
                records[j] = records[j+1];
            }

            foundRecord = true;
            numRecords--;

            printf("Record deleted successfully!\n");
            break;
        }
    }

    // If record not found
    if (!foundRecord) {
        printf("Record not found.\n");
    }
}

void printAllRecords() {
    printf("Database contains %d record%s:\n", numRecords, numRecords == 1 ? "" : "s");

    // Print header
    printf("%-4s  %-20s %-4s  %-50s\n", "ID", "Name", "Age", "Address");

    // Print each record
    for (int i = 0; i < numRecords; i++) {
        printf("%-4d  %-20s %-4d  %-50s\n", records[i].id, records[i].name, records[i].age, records[i].address);
    }
}

int main() {
    int choice;

    printf("Welcome to the database simulator!\n");

    do {
        // Show menu and get user input
        printf("\n1. Add Record\n");
        printf("2. Find Record\n");
        printf("3. Delete Record\n");
        printf("4. Print All Records\n");
        printf("5. Quit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        // Execute user's choice
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                findRecord();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                printAllRecords();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 5); // Continue until user chooses to quit

    return 0;
}