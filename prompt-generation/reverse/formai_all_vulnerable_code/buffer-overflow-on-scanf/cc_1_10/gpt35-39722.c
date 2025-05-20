//FormAI DATASET v1.0 Category: Database simulation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100 // Maximum number of records that can be stored
#define MAX_NAME_LENGTH 20 // Maximum characters allowed for the name
#define MAX_ADDRESS_LENGTH 50 // Maximum characters allowed for the address

// Structure to hold the details of a person
struct Person {
    int id; 
    char firstName[MAX_NAME_LENGTH]; 
    char lastName[MAX_NAME_LENGTH]; 
    char address[MAX_ADDRESS_LENGTH];
};

// The database which stores the person records
struct Person records[MAX_RECORDS];

// The number of records currently in the database
int numRecords = 0;

// Function to add a new record to the database
void addRecord(int id, char* firstName, char* lastName, char* address) {
    struct Person newRecord;
    newRecord.id = id;
    strncpy(newRecord.firstName, firstName, MAX_NAME_LENGTH);
    strncpy(newRecord.lastName, lastName, MAX_NAME_LENGTH);
    strncpy(newRecord.address, address, MAX_ADDRESS_LENGTH);
    records[numRecords++] = newRecord;
    printf("Record added successfully!\n");
}

// Function to display all the records in the database
void displayRecords() {
    if (numRecords == 0) {
        printf("Database is empty!\n");
        return;
    }

    printf("All records in the database:\n");
    printf("| ID | First Name | Last Name | Address |\n");
    for (int i = 0; i < numRecords; i++) {
        printf("| %d | %s | %s | %s |\n", records[i].id, records[i].firstName, records[i].lastName, records[i].address);
    }
}

// Function to find a record by ID and display its details
void findRecord(int id) {
    for (int i = 0; i < numRecords; i++) {
        if (records[i].id == id) {
            printf("| ID | First Name | Last Name | Address |\n");
            printf("| %d | %s | %s | %s\n", records[i].id, records[i].firstName, records[i].lastName, records[i].address);
            return;
        }
    }

    printf("Record with ID %d not found!\n", id);
}

int main() {
    printf("Welcome to the database simulator!\n\n");
    printf("1. Add Record\n");
    printf("2. Find Record\n");
    printf("3. Display All Records\n");
    printf("4. Exit\n");

    int choice, id;
    char firstName[MAX_NAME_LENGTH], lastName[MAX_NAME_LENGTH], address[MAX_ADDRESS_LENGTH];

    do {
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID, First Name, Last Name, and Address: ");
                scanf("%d %s %s %s", &id, firstName, lastName, address);
                addRecord(id, firstName, lastName, address);
                break;

            case 2:
                printf("Enter ID to find: ");
                scanf("%d", &id);
                findRecord(id);
                break;

            case 3:
                displayRecords();
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }

    } while (choice != 4);

    return 0;
}