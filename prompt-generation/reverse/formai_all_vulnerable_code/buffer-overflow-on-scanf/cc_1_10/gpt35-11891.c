//FormAI DATASET v1.0 Category: Banking Record System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure for banking record
typedef struct BankRecord {
    char name[20];
    int accNum;
    double balance;
} BankRecord;

// Function to add a new record
void addRecord(BankRecord* records, int* numRecords) {
    printf("\nEnter name: ");
    scanf("%s", &(records[*numRecords].name));

    printf("Enter account number: ");
    scanf("%d", &(records[*numRecords].accNum));

    printf("Enter balance: ");
    scanf("%lf", &(records[*numRecords].balance));

    (*numRecords)++;
}

// Function to print all records
void printRecords(BankRecord* records, int numRecords) {
    printf("\nName\tAccount Number\tBalance\n");
    for (int i = 0; i < numRecords; i++) {
        printf("%s\t%d\t%.2lf\n", records[i].name, records[i].accNum, records[i].balance);
    }
}

// Function to find a record by name
void findRecordByName(BankRecord* records, int numRecords) {
    char searchName[20];
    printf("\nEnter name to search for: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (strcmp(records[i].name, searchName) == 0) {
            printf("\nRecord found!\n");
            printf("Name: %s\n", records[i].name);
            printf("Account Number: %d\n", records[i].accNum);
            printf("Balance: %.2lf\n", records[i].balance);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("\nRecord not found.\n");
    }
}

// Function for withdrawing money from an account
void withdrawMoney(BankRecord* records, int numRecords) {
    int accNum;
    double amount;
    printf("\nEnter account number: ");
    scanf("%d", &accNum);

    int found = 0;
    for (int i = 0; i < numRecords; i++) {
        if (records[i].accNum == accNum) {
            found = 1;
            printf("\nEnter amount to withdraw: ");
            scanf("%lf", &amount);

            if (amount > records[i].balance) {
                printf("\nCannot withdraw more than available balance.\n");
            }
            else {
                records[i].balance -= amount;
                printf("\n%.2lf withdrawn from account number %d.\n", amount, accNum);
                printf("Current balance: %.2lf\n", records[i].balance);
            }
            break;
        }
    }
    if (!found) {
        printf("\nAccount not found.\n");
    }
}

int main() {
    BankRecord records[100];
    int numRecords = 0;
    int choice;

    while (1) {
        printf("\nBanking Record System\n");
        printf("1. Add new record\n");
        printf("2. Print all records\n");
        printf("3. Find record by name\n");
        printf("4. Withdraw money\n");
        printf("5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &numRecords);
                break;
            case 2:
                printRecords(records, numRecords);
                break;
            case 3:
                findRecordByName(records, numRecords);
                break;
            case 4:
                withdrawMoney(records, numRecords);
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}