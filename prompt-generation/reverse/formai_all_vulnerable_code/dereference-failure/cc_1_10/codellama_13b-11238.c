//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: puzzling
/*
* Puzzling Banking Record System
*
* A unique program that keeps track of banking records in a
* puzzling style.
*
* Author: [Your Name]
* Date: [Today's Date]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structure for storing banking records
struct BankRecord {
    char name[50];
    int accountNumber;
    double balance;
};

// Function to add a new record
void addRecord(struct BankRecord *record) {
    printf("Enter the name of the person: ");
    fgets(record->name, 50, stdin);
    printf("Enter the account number: ");
    scanf("%d", &record->accountNumber);
    printf("Enter the initial balance: ");
    scanf("%lf", &record->balance);
}

// Function to display all records
void displayAllRecords(struct BankRecord *record, int n) {
    printf("Name\t\tAccount Number\tBalance\n");
    for (int i = 0; i < n; i++) {
        printf("%s\t%d\t\t%.2lf\n", record[i].name, record[i].accountNumber, record[i].balance);
    }
}

// Function to display a specific record
void displayRecord(struct BankRecord *record, int n) {
    int accountNumber;
    printf("Enter the account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < n; i++) {
        if (record[i].accountNumber == accountNumber) {
            printf("Name: %s\nAccount Number: %d\nBalance: %.2lf\n", record[i].name, record[i].accountNumber, record[i].balance);
            break;
        }
    }
}

// Function to update a specific record
void updateRecord(struct BankRecord *record, int n) {
    int accountNumber;
    double amount;
    printf("Enter the account number: ");
    scanf("%d", &accountNumber);
    printf("Enter the amount to be updated: ");
    scanf("%lf", &amount);
    for (int i = 0; i < n; i++) {
        if (record[i].accountNumber == accountNumber) {
            record[i].balance += amount;
            break;
        }
    }
}

// Function to delete a specific record
void deleteRecord(struct BankRecord *record, int n) {
    int accountNumber;
    printf("Enter the account number: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < n; i++) {
        if (record[i].accountNumber == accountNumber) {
            record[i] = record[n - 1];
            n--;
            break;
        }
    }
}

int main() {
    struct BankRecord *record = (struct BankRecord*)malloc(sizeof(struct BankRecord));
    int n = 0;
    int choice;
    do {
        printf("1. Add a new record\n");
        printf("2. Display all records\n");
        printf("3. Display a specific record\n");
        printf("4. Update a specific record\n");
        printf("5. Delete a specific record\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(record + n);
                n++;
                break;
            case 2:
                displayAllRecords(record, n);
                break;
            case 3:
                displayRecord(record, n);
                break;
            case 4:
                updateRecord(record, n);
                break;
            case 5:
                deleteRecord(record, n);
                break;
            case 6:
                free(record);
                return 0;
        }
    } while (1);
    return 0;
}