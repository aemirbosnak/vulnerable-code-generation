//FormAI DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for each banking record
typedef struct {
    char name[50];
    int accountNumber;
    double balance;
} record;

// Declare global variables
record bankingRecords[100];
int numRecords = 0;

// Function to add a new record
void addRecord() {
    if (numRecords == 100) {
        printf("Error: Maximum number of records has been reached.\n");
        return;
    }
    record newRecord;
    printf("Please enter the name of the account holder: ");
    scanf("%s", newRecord.name);
    printf("Please enter the account number: ");
    scanf("%d", &newRecord.accountNumber);
    printf("Please enter the balance: ");
    scanf("%lf", &newRecord.balance);
    bankingRecords[numRecords] = newRecord;
    numRecords++;
    printf("Record added successfully.\n");
}

// Function to view all records
void viewRecords() {
    printf("Current Banking Records:\n");
    for (int i = 0; i < numRecords; i++) {
        printf("Name: %s\n", bankingRecords[i].name);
        printf("Account Number: %d\n", bankingRecords[i].accountNumber);
        printf("Balance: $%.2lf\n", bankingRecords[i].balance);
    }
}

// Function to search for a record
void searchRecord(int accountNumber) {
    for (int i = 0; i < numRecords; i++) {
        if (bankingRecords[i].accountNumber == accountNumber) {
            printf("Name: %s\n", bankingRecords[i].name);
            printf("Account Number: %d\n", bankingRecords[i].accountNumber);
            printf("Balance: $%.2lf\n", bankingRecords[i].balance);
            return;
        }
    }
    printf("Record not found.\n");
}

// Main function
int main() {
    char input[10];
    while (1) {
        printf("Please enter a command ('add', 'view', 'search', or 'exit'): ");
        scanf("%s", input);
        if (strcmp(input, "add") == 0) {
            addRecord();
        } else if (strcmp(input, "view") == 0) {
            viewRecords();
        } else if (strcmp(input, "search") == 0) {
            int accountNumber;
            printf("Please enter the account number to search for: ");
            scanf("%d", &accountNumber);
            searchRecord(accountNumber);
        } else if (strcmp(input, "exit") == 0) {
            printf("Exiting program.\n");
            exit(0);
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}