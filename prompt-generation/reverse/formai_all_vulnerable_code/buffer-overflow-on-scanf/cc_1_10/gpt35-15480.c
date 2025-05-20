//FormAI DATASET v1.0 Category: Banking Record System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for bank account record
struct bankRecord {
    char accountNumber[10];
    char accountName[50];
    float balance;
};

// Function prototypes
void displayMenu();
void addRecord(struct bankRecord *records, int *numRecords);
void displayAll(struct bankRecord *records, int numRecords);
void displayOne(struct bankRecord *records, int numRecords, char *accountNumber);
void deposit(struct bankRecord *records, int numRecords, char *accountNumber, float amount);
void withdraw(struct bankRecord *records, int numRecords, char *accountNumber, float amount);

int main() {
    struct bankRecord records[100]; // Maximum 100 records
    int numRecords = 0;

    char choice;
    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                addRecord(records, &numRecords);
                break;

            case '2':
                displayAll(records, numRecords);
                break;

            case '3':
                {
                    char accountNumber[10];
                    printf("Enter the account number: ");
                    scanf("%s", accountNumber);
                    displayOne(records, numRecords, accountNumber);
                    break;
                }

            case '4':
                {
                    char accountNumber[10];
                    float amount;
                    printf("Enter the account number: ");
                    scanf("%s", accountNumber);
                    printf("Enter the amount to deposit: ");
                    scanf("%f", &amount);
                    deposit(records, numRecords, accountNumber, amount);
                    break;
                }

            case '5':
                {
                    char accountNumber[10];
                    float amount;
                    printf("Enter the account number: ");
                    scanf("%s", accountNumber);
                    printf("Enter the amount to withdraw: ");
                    scanf("%f", &amount);
                    withdraw(records, numRecords, accountNumber, amount);
                    break;
                }

            case '6':
                printf("Exiting the program...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '6');

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n===== Bank Record System =====\n");
    printf("1. Add Record\n");
    printf("2. Display All Records\n");
    printf("3. Display One Record\n");
    printf("4. Deposit\n");
    printf("5. Withdraw\n");
    printf("6. Quit\n");
}

// Function to add a record
void addRecord(struct bankRecord *records, int *numRecords) {
    // Check if maximum number of records has been reached
    if (*numRecords == 100) {
        printf("Maximum number of records has been reached. Cannot add more records.\n");
        return;
    }

    struct bankRecord record;

    // Read the account number
    printf("Enter the account number: ");
    scanf("%s", record.accountNumber);

    // Check if the account number already exists
    for (int i = 0; i < *numRecords; i++) {
        if (strcmp(record.accountNumber, records[i].accountNumber) == 0) {
            printf("Record with this account number already exists. Please try again.\n");
            return;
        }
    }

    // Read the account name
    printf("Enter the account name: ");
    scanf("%s", record.accountName);

    // Read the balance
    printf("Enter the balance: ");
    scanf("%f", &record.balance);

    // Add the record to the array
    records[*numRecords] = record;
    *numRecords += 1;

    printf("Record added successfully.\n");
}

// Function to display all records
void displayAll(struct bankRecord *records, int numRecords) {
    if (numRecords == 0) {
        printf("No records found.\n");
        return;
    }

    printf("\n===== All Records =====\n");
    printf("Account Number\tAccount Name\tBalance\n");

    for (int i = 0; i < numRecords; i++) {
        printf("%s\t\t%s\t\t%.2f\n", records[i].accountNumber, records[i].accountName, records[i].balance);
    }
}

// Function to display one record
void displayOne(struct bankRecord *records, int numRecords, char *accountNumber) {
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].accountNumber, accountNumber) == 0) {
            printf("\n===== Record Found =====\n");
            printf("Account Number: %s\n", records[i].accountNumber);
            printf("Account Name: %s\n", records[i].accountName);
            printf("Balance: %.2f\n", records[i].balance);
            return;
        }
    }

    printf("Record with this account number not found.\n");
}

// Function to deposit to a record
void deposit(struct bankRecord *records, int numRecords, char *accountNumber, float amount) {
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].accountNumber, accountNumber) == 0) {
            records[i].balance += amount;
            printf("Deposit successful. New balance is %.2f\n", records[i].balance);
            return;
        }
    }

    printf("Record with this account number not found.\n");
}

// Function to withdraw from a record
void withdraw(struct bankRecord *records, int numRecords, char *accountNumber, float amount) {
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].accountNumber, accountNumber) == 0) {
            if (records[i].balance >= amount) {
                records[i].balance -= amount;
                printf("Withdrawal successful. New balance is %.2f\n", records[i].balance);
                return;
            }
            else {
                printf("Insufficient balance. Cannot withdraw.\n");
                return;
            }
        }
    }

    printf("Record with this account number not found.\n");
}