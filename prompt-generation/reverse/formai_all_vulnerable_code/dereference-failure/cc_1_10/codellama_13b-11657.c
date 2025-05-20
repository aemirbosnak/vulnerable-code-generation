//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: high level of detail
/*
 * Banking Record System Example Program
 *
 * This program allows users to create, read, update, and delete banking records.
 * It also allows users to search for records by account number and balance.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold banking record data
struct BankingRecord {
    int accountNumber;
    float balance;
    char name[30];
    char address[100];
};

// Function to create a new banking record
void createRecord(struct BankingRecord *record) {
    printf("Enter account number: ");
    scanf("%d", &record->accountNumber);
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter address: ");
    scanf("%s", record->address);
    printf("Enter balance: ");
    scanf("%f", &record->balance);
}

// Function to read a banking record
void readRecord(struct BankingRecord *record) {
    printf("Account number: %d\n", record->accountNumber);
    printf("Name: %s\n", record->name);
    printf("Address: %s\n", record->address);
    printf("Balance: %.2f\n", record->balance);
}

// Function to update a banking record
void updateRecord(struct BankingRecord *record) {
    printf("Enter account number: ");
    scanf("%d", &record->accountNumber);
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter address: ");
    scanf("%s", record->address);
    printf("Enter balance: ");
    scanf("%f", &record->balance);
}

// Function to delete a banking record
void deleteRecord(struct BankingRecord *record) {
    printf("Enter account number: ");
    scanf("%d", &record->accountNumber);
    free(record);
}

// Function to search for a banking record by account number
void searchRecord(struct BankingRecord *records, int numRecords) {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < numRecords; i++) {
        if (records[i].accountNumber == accountNumber) {
            printf("Account number: %d\n", records[i].accountNumber);
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Balance: %.2f\n", records[i].balance);
            break;
        }
    }
}

// Function to search for a banking record by balance
void searchRecordByBalance(struct BankingRecord *records, int numRecords) {
    float balance;
    printf("Enter balance: ");
    scanf("%f", &balance);
    for (int i = 0; i < numRecords; i++) {
        if (records[i].balance == balance) {
            printf("Account number: %d\n", records[i].accountNumber);
            printf("Name: %s\n", records[i].name);
            printf("Address: %s\n", records[i].address);
            printf("Balance: %.2f\n", records[i].balance);
            break;
        }
    }
}

int main() {
    struct BankingRecord *records;
    int numRecords = 0;
    char choice;

    // Initialize records
    records = (struct BankingRecord *) malloc(numRecords * sizeof(struct BankingRecord));

    // Menu loop
    while (1) {
        printf("Menu:\n");
        printf("c - Create new record\n");
        printf("r - Read record\n");
        printf("u - Update record\n");
        printf("d - Delete record\n");
        printf("s - Search record by account number\n");
        printf("b - Search record by balance\n");
        printf("q - Quit\n");
        printf("Enter choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case 'c':
                createRecord(&records[numRecords++]);
                break;
            case 'r':
                readRecord(&records[numRecords++]);
                break;
            case 'u':
                updateRecord(&records[numRecords++]);
                break;
            case 'd':
                deleteRecord(&records[numRecords++]);
                break;
            case 's':
                searchRecord(records, numRecords);
                break;
            case 'b':
                searchRecordByBalance(records, numRecords);
                break;
            case 'q':
                return 0;
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    // Free memory
    free(records);

    return 0;
}