//FormAI DATASET v1.0 Category: Banking Record System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for the banking record
struct BankRecord {
    int accountNumber;
    char firstName[50];
    char lastName[50];
    float balance;
};

// Function to add a new record to the system
void AddRecord(struct BankRecord *records, int *numRecords) {
    struct BankRecord newRecord;
    printf("Enter account number: ");
    scanf("%d", &newRecord.accountNumber);
    printf("Enter first name: ");
    scanf("%s", newRecord.firstName);
    printf("Enter last name: ");
    scanf("%s", newRecord.lastName);
    printf("Enter balance: ");
    scanf("%f", &newRecord.balance);
    records[*numRecords] = newRecord;
    (*numRecords)++;
    printf("Record added successfully!\n\n");
}

// Function to find a record by account number
void FindRecord(struct BankRecord *records, int numRecords) {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < numRecords; i++) {
        if (records[i].accountNumber == accountNumber) {
            printf("Account number: %d\n", records[i].accountNumber);
            printf("First name: %s\n", records[i].firstName);
            printf("Last name: %s\n", records[i].lastName);
            printf("Balance: %.2f\n\n", records[i].balance);
            return;
        }
    }
    printf("Record not found!\n\n");
}

// Function to print all records in the system
void PrintAllRecords(struct BankRecord *records, int numRecords) {
    printf("Printing all records...\n\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Account number: %d\n", records[i].accountNumber);
        printf("First name: %s\n", records[i].firstName);
        printf("Last name: %s\n", records[i].lastName);
        printf("Balance: %.2f\n\n", records[i].balance);
    }
}

// Function to delete a record by account number
void DeleteRecord(struct BankRecord *records, int *numRecords) {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < *numRecords; i++) {
        if (records[i].accountNumber == accountNumber) {
            for (int j = i; j < (*numRecords - 1); j++) {
                records[j] = records[j + 1];
            }
            (*numRecords)--;
            printf("Record deleted successfully!\n\n");
            return;
        }
    }
    printf("Record not found!\n\n");
}

int main() {
    struct BankRecord records[100];
    int numRecords = 0;
    int option;
    do {
        printf("Please select an option:\n");
        printf("1. Add a new record\n");
        printf("2. Find a record by account number\n");
        printf("3. Print all records\n");
        printf("4. Delete a record by account number\n");
        printf("5. Exit\n");
        printf("Option: ");
        scanf("%d", &option);
        switch (option) {
            case 1:
                AddRecord(records, &numRecords);
                break;
            case 2:
                FindRecord(records, numRecords);
                break;
            case 3:
                PrintAllRecords(records, numRecords);
                break;
            case 4:
                DeleteRecord(records, &numRecords);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid option!\n\n");
        }
    } while(1);
    return 0;
}