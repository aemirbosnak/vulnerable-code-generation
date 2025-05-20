//FormAI DATASET v1.0 Category: Database simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define max number of records
#define MAX_RECORDS 100

// Define a struct to hold the record data
typedef struct Record {
    int id;
    char name[50];
    int age;
} Record;

// Declare variables to hold the records
Record database[MAX_RECORDS];

// Declare a variable to keep track of the number of records
int num_records = 0;

// Declare function prototypes
void add_record();
void delete_record();
void search_record();
void display_records();

// Main function
int main() {
    char choice;

    // Print menu options
    printf("Welcome to the database simulation.\n");
    printf("Please choose one of the following options:\n");
    printf("1. Add a record\n");
    printf("2. Delete a record\n");
    printf("3. Search for a record\n");
    printf("4. Display all records\n");
    printf("5. Exit\n");

    // Loop until the user chooses to exit
    while (1) {
        printf("\nEnter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1': add_record();
                      break;

            case '2': delete_record();
                      break;

            case '3': search_record();
                      break;

            case '4': display_records();
                      break;

            case '5': printf("\nExiting program...\n");
                      exit(0);

            default: printf("\nInvalid choice. Please try again.\n");
                     break;
        }
    }

    return 0;
}

// Function to add a new record to the database
void add_record() {
    Record new_record;

    printf("\nAdding a new record...\n");

    // Prompt the user for record information
    printf("Enter the record ID: ");
    scanf("%d", &new_record.id);

    printf("Enter the record name: ");
    scanf("%s", new_record.name);

    printf("Enter the record age: ");
    scanf("%d", &new_record.age);

    // Add the record to the database
    database[num_records] = new_record;
    num_records++;

    printf("\nRecord added successfully.\n");
}

// Function to delete a record from the database
void delete_record() {
    int delete_id, i, found = 0;

    printf("\nDeleting a record...\n");

    // Prompt the user for the ID of the record to be deleted
    printf("Enter the ID of the record to be deleted: ");
    scanf("%d", &delete_id);

    for (i = 0; i < num_records; i++) {
        if (database[i].id == delete_id) {
            found = 1;
            break;
        }
    }

    // Delete the record if it exists in the database
    if (found) {
        for (i = i; i < num_records-1; i++) {
            database[i] = database[i+1];
        }

        num_records--;

        printf("\nRecord deleted successfully.\n");
    }
    else {
        printf("\nRecord not found in database.\n");
    }
}

// Function to search for a record in the database
void search_record() {
    int search_id, i, found = 0;

    printf("\nSearching for a record...\n");

    // Prompt the user for the ID of the record to be searched for
    printf("Enter the ID of the record to be searched for: ");
    scanf("%d", &search_id);

    for (i = 0; i < num_records; i++) {
        if (database[i].id == search_id) {
            found = 1;
            break;
        }
    }

    // Print the record if it exists in the database
    if (found) {
        printf("\nRecord found: ID=%d, Name=%s, Age=%d\n", database[i].id, database[i].name, database[i].age);
    }
    else {
        printf("\nRecord not found in database.\n");
    }
}

// Function to display all records in the database
void display_records() {
    int i;

    printf("\nDisplaying all records...\n");

    // Print all records in the database
    for (i = 0; i < num_records; i++) {
        printf("\nRecord %d: ID=%d, Name=%s, Age=%d\n", i+1, database[i].id, database[i].name, database[i].age);
    }

    // Print number of records in the database
    printf("\nTotal number of records: %d\n", num_records);
}