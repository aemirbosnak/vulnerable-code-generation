//FormAI DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Constants
#define MAX_RECORDS 100
#define MAX_NAME_LEN 50

// Structs
typedef struct {
    int acctNum;
    char name[MAX_NAME_LEN];
    double balance;
} BankRecord;

// Function prototypes
void addRecord(BankRecord records[], int *numRecords);
void displayRecords(BankRecord records[], int numRecords);
void searchRecords(BankRecord records[], int numRecords);
void updateRecord(BankRecord records[], int numRecords);

// Main function
int main() {
    BankRecord records[MAX_RECORDS];
    int numRecords = 0;
    int choice;

    do {
        printf("\n===== Banking Record System =====");
        printf("\n1. Add record");
        printf("\n2. Display records");
        printf("\n3. Search records");
        printf("\n4. Update record");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord(records, &numRecords);
                break;
            case 2:
                displayRecords(records, numRecords);
                break;
            case 3:
                searchRecords(records, numRecords);
                break;
            case 4:
                updateRecord(records, numRecords);
                break;
            case 5:
                printf("\nExiting program...\n");
                exit(0);
            default:
                printf("\nInvalid choice, please try again.\n");
        }
    } while (true);

    return 0;
}

// Function to add a new record to the system
void addRecord(BankRecord records[], int *numRecords) {
    if (*numRecords == MAX_RECORDS) {
        printf("\nRecord limit reached, unable to add new record.\n");
        return;
    }

    printf("\nEnter account number: ");
    scanf("%d", &records[*numRecords].acctNum);

    printf("Enter name: ");
    scanf(" %[^\n]s", records[*numRecords].name);

    printf("Enter balance: ");
    scanf("%lf", &records[*numRecords].balance);

    (*numRecords)++;

    printf("\nRecord added successfully!\n");
}

// Function to display all records in the system
void displayRecords(BankRecord records[], int numRecords) {
    if (numRecords == 0) {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n===== Bank Records =====\n");
    printf("%-15s%-25s%-15s\n", "Account Num", "Name", "Balance");
    for (int i = 0; i < numRecords; i++) {
        printf("%-15d%-25s%-15.2lf\n", records[i].acctNum, records[i].name, records[i].balance);
    }
}

// Function to search for a record by account number
void searchRecords(BankRecord records[], int numRecords) {
    if (numRecords == 0) {
        printf("\nNo records found.\n");
        return;
    }

    int searchNum;
    printf("\nEnter account number to search: ");
    scanf("%d", &searchNum);

    for (int i = 0; i < numRecords; i++) {
        if (records[i].acctNum == searchNum) {
            printf("%-15s%-25s%-15s\n", "Account Num", "Name", "Balance");
            printf("%-15d%-25s%-15.2lf\n", records[i].acctNum, records[i].name, records[i].balance);
            return;
        }
    }

    printf("\nRecord with account number %d not found.\n", searchNum);
}

// Function to update a record by account number
void updateRecord(BankRecord records[], int numRecords) {
    if (numRecords == 0) {
        printf("\nNo records found.\n");
        return;
    }

    int updateNum;
    printf("\nEnter account number to update: ");
    scanf("%d", &updateNum);

    for (int i = 0; i < numRecords; i++) {
        if (records[i].acctNum == updateNum) {
            printf("\nEnter updated account number: ");
            scanf("%d", &records[i].acctNum);

            printf("Enter updated name: ");
            scanf(" %[^\n]s", records[i].name);

            printf("Enter updated balance: ");
            scanf("%lf", &records[i].balance);

            printf("\nRecord updated successfully!\n");
            return;
        }
    }

    printf("\nRecord with account number %d not found.\n", updateNum);
}