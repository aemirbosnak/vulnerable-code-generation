//FormAI DATASET v1.0 Category: Banking Record System ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define structure to store banking record data
struct record {
    char name[50];
    int account_number;
    float balance;
};

// Function prototypes
void displayMenu();
void addRecord();
void viewRecord();
void searchRecord();
void deleteRecord();

// Declare global variable to store record data
struct record banking_record[100];
int num_records = 0;

int main() {
    int choice;

    // Display menu and repeat until user exits
    do {
        displayMenu();
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                addRecord();
                break;
            case 2:
                viewRecord();
                break;
            case 3:
                searchRecord();
                break;
            case 4:
                deleteRecord();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while(choice != 5);

    return 0;
}

// Function to display menu
void displayMenu() {
    printf("\n--- BANKING RECORD SYSTEM ---\n");
    printf("1. Add Record\n");
    printf("2. View Record\n");
    printf("3. Search Record\n");
    printf("4. Delete Record\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// Function to add record
void addRecord() {
    // Check if there is enough space to add a record
    if(num_records == 100) {
        printf("Maximum number of records reached.\n");
        return;
    }

    // Read record data from user
    printf("Enter name: ");
    scanf("%s", banking_record[num_records].name);
    printf("Enter account number: ");
    scanf("%d", &banking_record[num_records].account_number);
    printf("Enter balance: ");
    scanf("%f", &banking_record[num_records].balance);

    // Increment number of records
    num_records++;

    // Print success message
    printf("Record added successfully.\n");
}

// Function to view record
void viewRecord() {
    int i;

    // Check if there are any records to view
    if(num_records == 0) {
        printf("No records found.\n");
        return;
    }

    // Print header
    printf("%-20s %-20s %-20s\n", "Name", "Account Number", "Balance");
    printf("--------------------------------------------------------\n");

    // Loop through all records
    for(i = 0; i < num_records; i++) {
        // Print each record
        printf("%-20s %-20d %-20.2f\n", banking_record[i].name, banking_record[i].account_number, banking_record[i].balance);
    }
}

// Function to search record
void searchRecord() {
    int i, account_number;

    // Check if there are any records to search
    if(num_records == 0) {
        printf("No records found.\n");
        return;
    }

    // Read account number to search for
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Loop through all records
    for(i = 0; i < num_records; i++) {
        // Check if account number matches
        if(banking_record[i].account_number == account_number) {
            // Print matching record
            printf("%-20s %-20d %-20.2f\n", banking_record[i].name, banking_record[i].account_number, banking_record[i].balance);
            return;
        }
    }

    // If no matching record was found
    printf("Record not found.\n");
}

// Function to delete record
void deleteRecord() {
    int i, account_number;

    // Check if there are any records to delete
    if(num_records == 0) {
        printf("No records found.\n");
        return;
    }

    // Read account number to delete
    printf("Enter account number: ");
    scanf("%d", &account_number);

    // Loop through all records
    for(i = 0; i < num_records; i++) {
        // Check if account number matches
        if(banking_record[i].account_number == account_number) {
            // Shift all records after the matching record to the left by one
            for(int j = i; j < num_records - 1; j++) {
                strcpy(banking_record[j].name, banking_record[j+1].name);
                banking_record[j].account_number = banking_record[j+1].account_number;
                banking_record[j].balance = banking_record[j+1].balance;
            }

            // Decrement number of records
            num_records--;

            // Print success message
            printf("Record deleted successfully.\n");
            return;
        }
    }

    // If no matching record was found
    printf("Record not found.\n");
}