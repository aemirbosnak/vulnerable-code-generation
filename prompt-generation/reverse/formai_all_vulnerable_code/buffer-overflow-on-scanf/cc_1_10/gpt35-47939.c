//FormAI DATASET v1.0 Category: Banking Record System ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure for our banking record system
struct BankRecord {
    int accountNumber;
    char accountHolder[30];
    float balance;
};

// Function to create a new bank record
struct BankRecord createRecord(int accountNumber, char accountHolder[], float balance) {
    struct BankRecord record;
    record.accountNumber = accountNumber;
    strcpy(record.accountHolder, accountHolder);
    record.balance = balance;
    return record;
}

// Function to display a bank record
void displayRecord(struct BankRecord record) {
    printf("Account Number: %d\n", record.accountNumber);
    printf("Account Holder: %s\n", record.accountHolder);
    printf("Balance: $%.2f\n", record.balance);
}

// Function to deposit money into a bank record
void deposit(struct BankRecord* record, float amount) {
    record->balance += amount;
}

// Function to withdraw money from a bank record
void withdraw(struct BankRecord* record, float amount) {
    if(record->balance >= amount) {
        record->balance -= amount;
    } else {
        printf("Insufficient funds!\n");
    }
}

// Function to find a bank record by account number
struct BankRecord* findByAccountNumber(struct BankRecord records[], int numRecords, int accountNumber) {
    for(int i = 0; i < numRecords; i++) {
        if(records[i].accountNumber == accountNumber) {
            return &records[i];
        }
    }
    return NULL;
}

int main() {
    // Create an array of bank records
    struct BankRecord records[100];
    int numRecords = 0;

    // Display a menu of options for the user
    int choice = 0;
    while(choice != 4) {
        printf("Banking Record System Menu:\n");
        printf("1. Create a new record\n");
        printf("2. Deposit money\n");
        printf("3. Withdraw money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Handle the user's choice
        switch(choice) {
            case 1: {
                // Get information from the user and create a new record
                int accountNumber;
                char accountHolder[30];
                float balance;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter account holder: ");
                scanf("%s", accountHolder);
                printf("Enter balance: ");
                scanf("%f", &balance);
                struct BankRecord newRecord = createRecord(accountNumber, accountHolder, balance);

                // Add the new record to the array of records
                records[numRecords] = newRecord;
                numRecords++;

                // Display the new record
                displayRecord(newRecord);
                printf("Record created successfully!\n");
                break;
            }
            case 2: {
                // Get information from the user and deposit money into a record
                int accountNumber;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                struct BankRecord* record = findByAccountNumber(records, numRecords, accountNumber);
                if(record == NULL) {
                    printf("Record not found!\n");
                } else {
                    deposit(record, amount);
                    displayRecord(*record);
                    printf("Deposit successful!\n");
                }
                break;
            }
            case 3: {
                // Get information from the user and withdraw money from a record
                int accountNumber;
                float amount;
                printf("Enter account number: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                struct BankRecord* record = findByAccountNumber(records, numRecords, accountNumber);
                if(record == NULL) {
                    printf("Record not found!\n");
                } else {
                    withdraw(record, amount);
                    displayRecord(*record);
                }
                break;
            }
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}