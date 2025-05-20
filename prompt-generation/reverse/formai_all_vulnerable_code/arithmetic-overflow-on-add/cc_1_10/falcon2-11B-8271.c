//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for the records in the database
struct record {
    char name[50];
    char address[100];
    int age;
};

// Define the function to create a new record
void createRecord(struct record *record) {
    printf("Enter the name: ");
    scanf("%s", record->name);
    printf("Enter the address: ");
    scanf("%s", record->address);
    printf("Enter the age: ");
    scanf("%d", &record->age);
}

// Define the function to add a record to the database
void addRecord(struct record *record, int count) {
    if (count < 10) {
        printf("Record added.\n");
    } else {
        printf("Database is full.\n");
    }
}

// Define the function to query the database
void queryDatabase(struct record *records, int count) {
    int query;
    printf("Enter the query: ");
    scanf("%d", &query);
    if (query >= 1 && query <= count) {
        printf("%s %s %d\n", records[query-1].name, records[query-1].address, records[query-1].age);
    } else {
        printf("Invalid query.\n");
    }
}

int main() {
    struct record records[10]; // Create an array to hold the records in the database
    int count = 0; // Initialize the count of records in the database
    int choice; // Initialize the choice variable

    // Prompt the user for the number of records to add
    printf("Enter the number of records to add: ");
    scanf("%d", &count);

    // Loop until the user wants to quit
    while (count!= 0) {
        // Prompt the user for the choice
        printf("Enter 1 to create a record, 2 to add a record, 3 to query the database, or 4 to quit: ");
        scanf("%d", &choice);

        // Process the user's choice
        switch (choice) {
            case 1: // Create a new record
                createRecord(&records[count]); // Add the record to the database
                count++; // Increment the count
                break;
            case 2: // Add a record to the database
                addRecord(&records[count], count); // Add the record to the database
                break;
            case 3: // Query the database
                queryDatabase(&records[0], count); // Query the database
                break;
            case 4: // Quit
                printf("Goodbye!\n");
                exit(0); // Exit the program
                break;
            default: // Invalid choice
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}