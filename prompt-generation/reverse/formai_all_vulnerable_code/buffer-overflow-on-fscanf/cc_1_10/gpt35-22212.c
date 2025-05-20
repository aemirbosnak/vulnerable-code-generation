//FormAI DATASET v1.0 Category: Banking Record System ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants for file locations and record structure
#define RECORD_SIZE 50
#define FILENAME "bank_records.txt"

// Define the bank record structure
typedef struct {
    int account_number;
    char name[20];
    double balance;
} BankRecord;

// Function prototypes
void createRecord();
void displayRecord(int account_number);

int main() {
    int choice, account_number;
    do {
        // Display menu
        printf("\nWelcome to the Banking Record System\n");
        printf("1. Create a record\n");
        printf("2. Display a record\n");
        printf("3. Exit\n");
        
        // Get user's choice
        printf("Enter your choice (1-3): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createRecord();
                break;
            case 2:
                printf("Enter the account number to display: ");
                scanf("%d", &account_number);
                displayRecord(account_number);
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);
    return 0;
}

// Function to create a new bank record
void createRecord() {
    BankRecord record;
    
    // Get account number
    printf("Enter the account number: ");
    scanf("%d", &record.account_number);
    
    // Get name
    printf("Enter the name: ");
    scanf("%s", record.name);
    
    // Get balance
    printf("Enter the initial balance: ");
    scanf("%lf", &record.balance);
    
    // Open file for appending
    FILE* file = fopen(FILENAME, "a");
    
    // Write record to file
    fprintf(file, "%d %s %.2f\n", record.account_number, record.name, record.balance);
    
    // Close file
    fclose(file);
    
    // Display success message
    printf("Record created successfully.\n");
}

// Function to display an existing bank record
void displayRecord(int account_number) {
    BankRecord record;
    int found = 0;
    
    // Open file for reading
    FILE* file = fopen(FILENAME, "r");
    
    // Iterate over records in file and find the one with the specified account number
    while (!feof(file)) {
        fscanf(file, "%d %s %lf", &record.account_number, record.name, &record.balance);
        if (record.account_number == account_number) {
            printf("Account number: %d\n", record.account_number);
            printf("Name: %s\n", record.name);
            printf("Balance: $%.2f\n", record.balance);
            found = 1;
            break;
        }
    }
    
    // Close file
    fclose(file);
    
    // Display error message if record was not found
    if (!found) {
        printf("Record not found.\n");
    }
}