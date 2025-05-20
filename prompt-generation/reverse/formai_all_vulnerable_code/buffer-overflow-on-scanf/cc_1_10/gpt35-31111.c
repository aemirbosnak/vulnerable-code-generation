//FormAI DATASET v1.0 Category: Database simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of records allowed
#define MAX_RECORDS 100

// Define the structure of a record
struct Record {
    int id;
    char name[50];
    int age;
};

// Define the global database array
struct Record database[MAX_RECORDS];

// Define the number of records currently in the database
int numRecords = 0;

// Function to add a record to the database
void addRecord() {
    // Check if the database is full
    if (numRecords == MAX_RECORDS) {
        printf("The database is full. No more records can be added.\n");
        return;
    }

    // Ask the user for the record information
    struct Record record;
    printf("Enter the ID number: ");
    scanf("%d", &record.id);
    printf("Enter the name: ");
    scanf("%s", record.name);
    printf("Enter the age: ");
    scanf("%d", &record.age);

    // Add the record to the database
    database[numRecords] = record;
    numRecords++;
    printf("Record added to the database.\n");
}

// Function to search for a record in the database
void searchRecord() {
    // Ask the user for the ID number to search for
    int id;
    printf("Enter the ID number to search for: ");
    scanf("%d", &id);

    // Search for the record in the database
    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (database[i].id == id) {
            printf("Record found:\n");
            printf("ID: %d\nName: %s\nAge: %d\n", database[i].id, database[i].name, database[i].age);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found in the database.\n");
    }
}

// Function to delete a record from the database
void deleteRecord() {
    // Ask the user for the ID number to delete
    int id;
    printf("Enter the ID number to delete: ");
    scanf("%d", &id);

    // Search for the record in the database
    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (database[i].id == id) {
            // Move all the records after this one back by one
            for (int j = i; j < numRecords - 1; j++) {
                database[j] = database[j + 1];
            }

            numRecords--;
            found = 1;
            printf("Record deleted from the database.\n");
            break;
        }
    }

    if (!found) {
        printf("Record not found in the database.\n");
    }
}

int main() {
    int choice;

    // Display the main menu and ask the user for a choice
    do {
        printf("\nDATABASE MENU\n");
        printf("1. Add a record\n");
        printf("2. Search for a record\n");
        printf("3. Delete a record\n");
        printf("4. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1:
                addRecord();
                break;
            case 2:
                searchRecord();
                break;
            case 3:
                deleteRecord();
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}