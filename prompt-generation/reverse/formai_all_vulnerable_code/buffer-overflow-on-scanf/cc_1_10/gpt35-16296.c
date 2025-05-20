//FormAI DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to hold banking record information
typedef struct banking_record {
    char name[50];
    int account_number;
    float balance;
} record;

// Function to add a new record to the system
void add_record(record *records, int *num_records) {
    // Check if we've reached the maximum number of records
    if (*num_records == 100) {
        printf("Error: Maximum number of records reached.\n");
        return;
    }

    // Create a new record struct
    record new_record;

    // Prompt the user for the new record information
    printf("Enter the customer's name: ");
    scanf("%s", new_record.name);

    printf("Enter the customer's account number: ");
    scanf("%d", &new_record.account_number);

    printf("Enter the customer's balance: ");
    scanf("%f", &new_record.balance);

    // Add the new record to the records array
    records[*num_records] = new_record;

    // Increment the number of records
    (*num_records)++;

    // Inform the user that the record was added successfully
    printf("Record added successfully.\n");
}

// Function to remove a record from the system
void remove_record(record *records, int *num_records) {
    // Check if there are any records to remove
    if (*num_records == 0) {
        printf("Error: No records to remove.\n");
        return;
    }

    // Prompt the user for the account number of the record to remove
    int account_number;
    printf("Enter the account number of the record to remove: ");
    scanf("%d", &account_number);

    // Search for the record with the given account number
    int i, record_index = -1;
    for (i = 0; i < *num_records; i++) {
        if (records[i].account_number == account_number) {
            record_index = i;
            break;
        }
    }

    // Check if the record was found
    if (record_index == -1) {
        printf("Error: Record not found.\n");
        return;
    }

    // Shift all records after the removed record down one position
    for (i = record_index; i < *num_records - 1; i++) {
        records[i] = records[i+1];
    }

    // Decrement the number of records
    (*num_records)--;

    // Inform the user that the record was removed successfully
    printf("Record removed successfully.\n");
}

// Function to display all records in the system
void display_records(record *records, int num_records) {
    // Check if there are any records to display
    if (num_records == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("-----------------------------------------------------------\n");
    printf("Name\t\tAccount Number\tBalance\n");
    printf("-----------------------------------------------------------\n");

    // Loop through all records and print the information
    int i;
    for (i = 0; i < num_records; i++) {
        printf("%s\t\t%d\t\t$%.2f\n", records[i].name, records[i].account_number, records[i].balance);
    }

    printf("-----------------------------------------------------------\n");
}

int main() {
    // Create an array to hold banking record structs
    record records[100];

    // Create a variable to hold the number of records currently in the system
    int num_records = 0;

    // Display a welcome message
    printf("Welcome to the Cyberbank Banking Record System.\n");

    // Loop until the user chooses to exit
    int choice;
    do {
        // Display the menu
        printf("\nPlease select an option:\n");
        printf("1. Add a record\n");
        printf("2. Remove a record\n");
        printf("3. Display all records\n");
        printf("4. Exit\n");

        // Prompt the user for their choice
        printf("Choice: ");
        scanf("%d", &choice);

        // Perform the appropriate action based on the user's choice
        switch (choice) {
            case 1:
                add_record(records, &num_records);
                break;

            case 2:
                remove_record(records, &num_records);
                break;

            case 3:
                display_records(records, num_records);
                break;

            case 4:
                printf("Thank you for using the Cyberbank Banking Record System.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    // Exit the program
    return 0;
}