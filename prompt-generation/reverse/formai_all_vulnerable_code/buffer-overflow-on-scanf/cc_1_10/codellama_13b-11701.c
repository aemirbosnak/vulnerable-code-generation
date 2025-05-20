//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: peaceful
/*
 * Banking Record System
 * Program to manage banking records
 *
 * Author: [Your Name]
 * Date: [Today's Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store banking records
struct Record {
    char name[50];
    char account_number[20];
    int balance;
    int deposit;
    int withdraw;
};

// Function to add a new record
void addRecord(struct Record *record) {
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter account number: ");
    scanf("%s", record->account_number);
    printf("Enter initial balance: ");
    scanf("%d", &record->balance);
    printf("Enter deposit amount: ");
    scanf("%d", &record->deposit);
    printf("Enter withdraw amount: ");
    scanf("%d", &record->withdraw);
}

// Function to display all records
void displayAllRecords(struct Record *records, int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s\n", records[i].name);
        printf("Account number: %s\n", records[i].account_number);
        printf("Balance: %d\n", records[i].balance);
        printf("Deposit: %d\n", records[i].deposit);
        printf("Withdraw: %d\n", records[i].withdraw);
    }
}

// Function to display a specific record
void displayRecord(struct Record *records, int n, int index) {
    if (index < 0 || index >= n) {
        printf("Invalid index\n");
        return;
    }
    printf("Name: %s\n", records[index].name);
    printf("Account number: %s\n", records[index].account_number);
    printf("Balance: %d\n", records[index].balance);
    printf("Deposit: %d\n", records[index].deposit);
    printf("Withdraw: %d\n", records[index].withdraw);
}

// Function to update a record
void updateRecord(struct Record *record) {
    printf("Enter name: ");
    scanf("%s", record->name);
    printf("Enter account number: ");
    scanf("%s", record->account_number);
    printf("Enter balance: ");
    scanf("%d", &record->balance);
    printf("Enter deposit amount: ");
    scanf("%d", &record->deposit);
    printf("Enter withdraw amount: ");
    scanf("%d", &record->withdraw);
}

// Function to delete a record
void deleteRecord(struct Record *records, int n, int index) {
    if (index < 0 || index >= n) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < n - 1; i++) {
        records[i] = records[i + 1];
    }
    n--;
}

int main() {
    struct Record records[100];
    int n = 0;

    // Add records
    for (int i = 0; i < 100; i++) {
        addRecord(&records[i]);
        n++;
    }

    // Display all records
    displayAllRecords(records, n);

    // Display a specific record
    displayRecord(records, n, 50);

    // Update a record
    updateRecord(&records[50]);

    // Delete a record
    deleteRecord(records, n, 75);

    // Display all records again
    displayAllRecords(records, n);

    return 0;
}