//FormAI DATASET v1.0 Category: Banking Record System ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for the banking record
typedef struct {
    char name[50];
    int accountNumber;
    double balance;
} bankingRecord;

// Function to add a new record
void addRecord(bankingRecord *record, int index) {
    printf("\nEnter name of customer: ");
    scanf("%s", record[index].name);
    printf("Enter account number: ");
    scanf("%d", &record[index].accountNumber);
    printf("Enter balance amount: ");
    scanf("%lf", &record[index].balance);
}

// Function to print all records
void printAllRecords(bankingRecord *record, int recordsCount) {
    printf("\n*** All Bank Records ***\n");
    for(int i = 0; i < recordsCount; i++) {
        printf("\nName: %s\n", record[i].name);
        printf("Account Number: %d\n", record[i].accountNumber);
        printf("Balance: $%.2lf\n", record[i].balance);
    }
}

// Function to search for a record by account number
void searchRecord(bankingRecord *record, int recordsCount) {
    int accountNumber;
    printf("\nEnter account number to search for: ");
    scanf("%d", &accountNumber);

    for(int i = 0; i < recordsCount; i++) {
        if(record[i].accountNumber == accountNumber) {
            printf("Record found!\n");
            printf("Name: %s\n", record[i].name);
            printf("Account Number: %d\n", record[i].accountNumber);
            printf("Balance: $%.2lf\n", record[i].balance);
            return;
        }
    }

    printf("Record not found.\n");
}

// Function to delete a record by account number
void deleteRecord(bankingRecord *record, int *recordsCount) {
    int accountNumber;
    printf("\nEnter account number to delete: ");
    scanf("%d", &accountNumber);

    for(int i = 0; i < *recordsCount; i++) {
        if(record[i].accountNumber == accountNumber) {
            // Move all records after this one back by 1 index
            for(int j = i; j < *recordsCount - 1; j++) {
                record[j] = record[j+1];
            }
            (*recordsCount)--;
            printf("Record deleted.\n");
            return;
        }
    }

    printf("Record not found.\n");
}

// Menu function to allow user to interact with program
void menu(bankingRecord *record, int *recordsCount) {
    int choice = 0;
    while(choice != 5) {
        printf("\n*** Welcome to Banking Record System! ***\n");
        printf("1. Add new record\n");
        printf("2. Print all records\n");
        printf("3. Search for a record\n");
        printf("4. Delete a record\n");
        printf("5. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addRecord(record, *recordsCount);
                (*recordsCount)++;
                printf("Record added successfully.\n");
                break;
            case 2:
                printAllRecords(record, *recordsCount);
                break;
            case 3:
                searchRecord(record, *recordsCount);
                break;
            case 4:
                deleteRecord(record, recordsCount);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}

int main() {
    int recordsCount = 0;
    bankingRecord record[50];
    menu(record, &recordsCount);
    return 0;
}