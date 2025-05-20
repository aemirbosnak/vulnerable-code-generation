//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Define a record structure to hold bank account information
struct record {
    int account_number;
    char name[50];
    float balance;
};

// Global variables to keep track of all the records
struct record records[MAX_RECORDS];
int num_records = 0;

// Function to add a new record given an account number, name and balance
void add_record(int account_number, char *name, float balance) {
    // Check that there is room to add a new record
    if(num_records < MAX_RECORDS) {
        // Create a new record and add it to the list
        struct record new_record;
        new_record.account_number = account_number;
        strcpy(new_record.name, name);
        new_record.balance = balance;
        records[num_records] = new_record;
        num_records++;
        printf("Record added successfully!\n");
    } else {
        printf("Error: Maximum number of records reached (%d)\n", MAX_RECORDS);
    }
}

// Function to display all the records currently saved
void display_records() {
    // Check that there are records to display
    if(num_records == 0) {
        printf("No records found.\n");
        return;
    }
    // Loop through all the records and print their information
    printf("Account\tName\tBalance\n");
    for(int i = 0; i < num_records; i++) {
        printf("%d\t%s\t%.2f\n", records[i].account_number, records[i].name, records[i].balance);
    }
}

int main() {
    // Print welcome message
    printf("Welcome to the Banking Record System.\n");

    // Run program loop until user chooses to exit
    while(1) {
        // Print menu options
        printf("\nChoose an option:\n");
        printf("1. Add a new record\n");
        printf("2. Display all records\n");
        printf("3. Exit\n");
        
        // Get user input
        int choice;
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add a new record
                printf("\nEnter account number: ");
                int account_number;
                scanf("%d", &account_number);
                printf("Enter name: ");
                char name[50];
                scanf("%s", name);
                printf("Enter balance: ");
                float balance;
                scanf("%f", &balance);
                add_record(account_number, name, balance);
                break;

            case 2:
                // Display all records
                display_records();
                break;

            case 3:
                // Exit program
                printf("Goodbye!\n");
                exit(0);

            default:
                // Error handling
                printf("Error: Invalid choice, please try again.\n");
                break;
        }
    }
    return 0;
}