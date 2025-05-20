//FormAI DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for Database table
typedef struct Database {
    int id;
    char name[50];
    int age;
} Database;

// Function prototypes
void addRecord(Database* db, int* count);
void displayRecords(Database* db, int count);
void searchRecord(Database* db, int count);

int main() {
    // Initialize variables
    int choice, count=0;
    Database* db = malloc(sizeof(Database));

    // Main loop
    do {
        // Display menu
        printf("\n--DATABASE SIMULATOR--\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Search Record\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Check for user input
        switch(choice) {
            case 1:
                addRecord(db, &count);
                break;
            case 2:
                displayRecords(db, count);
                break;
            case 3:
                searchRecord(db, count);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid input. Please try again.\n");
                break;
        }
    } while(choice != 4); // End of main loop

    // Free dynamically allocated memory
    free(db);

    return 0;
}

// Function to add new record to database
void addRecord(Database* db, int* count) {
    printf("\nADD RECORD\n");

    // Resize database table array
    *count += 1;
    db = realloc(db, (*count) * sizeof(Database));

    // Get user input for new record data
    printf("Enter ID: ");
    scanf("%d", &db[*count-1].id);
    printf("Enter Name: ");
    scanf("%s", db[*count-1].name);
    printf("Enter Age: ");
    scanf("%d", &db[*count-1].age);

    // Display added record
    printf("\nRecord Added:\n");
    printf("ID: %d\n", db[*count-1].id);
    printf("Name: %s\n", db[*count-1].name);
    printf("Age: %d\n\n", db[*count-1].age);
}

// Function to display all records in database
void displayRecords(Database* db, int count) {
    printf("\nDISPLAY RECORDS\n");

    // Check if database is empty
    if(count == 0) {
        printf("No records found.\n");
    } else {
        // Display column headers
        printf("%-10s %-20s %-10s\n", "ID", "NAME", "AGE");
        printf("------------------------------------------\n");

        // Loop through all records and display data
        for(int i=0; i<count; i++) {
            printf("%-10d %-20s %-10d\n", db[i].id, db[i].name, db[i].age);
        }
    }
}

// Function to search for a record by ID
void searchRecord(Database* db, int count) {
    int id;
    int found = 0;

    printf("\nSEARCH RECORD\n");

    // Get ID to search for
    printf("Enter ID to search for: ");
    scanf("%d", &id);

    // Loop through all records and check for matching ID
    for(int i=0; i<count; i++) {
        if(db[i].id == id) {
            // Display matching record
            printf("\nRecord Found:\n");
            printf("ID: %d\n", db[i].id);
            printf("Name: %s\n", db[i].name);
            printf("Age: %d\n", db[i].age);
            found = 1;
            break;
        }
    }

    // If no matching record was found
    if(found == 0) {
        printf("No records found with ID %d.\n", id);
    }
}