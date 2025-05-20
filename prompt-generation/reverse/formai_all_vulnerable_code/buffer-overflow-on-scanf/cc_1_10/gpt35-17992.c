//FormAI DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for a Banking Record
typedef struct {
    char name[50];
    int accountNumber;
    float balance;
} BankRecord;

// Function to display the menu options
void displayMenuOptions() {
    printf("Welcome to the Banking Record System\n");
    printf("1. Add a new record\n");
    printf("2. View all records\n");
    printf("3. Search for a record by account number\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

// Function to add a new record to the system
void addNewRecord(BankRecord *records, int *numRecords) {
    // Get the details for the new record
    BankRecord newRecord;
    printf("\nEnter name: ");
    scanf("%s", newRecord.name);
    printf("Enter account number: ");
    scanf("%d", &newRecord.accountNumber);
    printf("Enter balance: ");
    scanf("%f", &newRecord.balance);
    
    // Add the new record to the array of records
    records[*numRecords] = newRecord;
    (*numRecords)++;
}

// Function to view all the records in the system
void viewAllRecords(BankRecord *records, int numRecords) {
    // Loop through all the records and display their details
    for(int i = 0; i < numRecords; i++) {
        printf("\nName: %s\n", records[i].name);
        printf("Account Number: %d\n", records[i].accountNumber);
        printf("Balance: $%.2f\n", records[i].balance);
    }
}

// Function to search for a record by account number
void searchByAccountNumber(BankRecord *records, int numRecords) {
    // Get the account number to search for
    int searchAccountNumber;
    printf("\nEnter the account number to search for: ");
    scanf("%d", &searchAccountNumber);
    
    // Loop through all the records and print the details if a match is found
    for(int i = 0; i < numRecords; i++) {
        if(records[i].accountNumber == searchAccountNumber) {
            printf("\nName: %s\n", records[i].name);
            printf("Account Number: %d\n", records[i].accountNumber);
            printf("Balance: $%.2f\n", records[i].balance);
            return;
        }
    }
    // If the account number is not found, display an error message
    printf("\nRecord not found for account number %d\n", searchAccountNumber);
}

int main() {
    // Create an array to hold the bank records
    BankRecord records[100];
    int numRecords = 0;
    
    int choice;
    do {
        // Display the menu options and get the user's choice
        displayMenuOptions();
        scanf("%d", &choice);
        
        // Perform the selected action
        switch(choice) {
            case 1:
                addNewRecord(records, &numRecords);
                break;
            case 2:
                viewAllRecords(records, numRecords);
                break;
            case 3:
                searchByAccountNumber(records, numRecords);
                break;
            case 4:
                // Exit the program
                printf("\nThank you for using the Banking Record System!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a valid choice.\n");
                break;
        }
    } while(choice != 4);
    
    return 0;
}