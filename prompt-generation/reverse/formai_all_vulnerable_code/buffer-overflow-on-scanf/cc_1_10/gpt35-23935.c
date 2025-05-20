//FormAI DATASET v1.0 Category: Banking Record System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000 // Maximum records that can be stored

/* Structure to store the bank record */
struct bankRecord {
    char fullName[50];
    int accountNumber;
    float accountBalance;
};

/* Function to add a new record to the record system */
void addRecord(struct bankRecord records[], int *numberOfRecords) {
    struct bankRecord newRecord;

    printf("Enter the following details for the new record:\n");
    
    // Get the full name
    printf("Full Name: ");
    fgets(newRecord.fullName, 50, stdin);
    newRecord.fullName[strcspn(newRecord.fullName, "\n")] = 0;

    // Get the account number
    printf("Account Number: ");
    scanf("%d", &newRecord.accountNumber);
    getchar(); // Clear newline character from buffer

    // Get the account balance
    printf("Account Balance: ");
    scanf("%f", &newRecord.accountBalance);
    getchar(); // Clear newline character from buffer

    // Add the new record to the records array
    records[*numberOfRecords] = newRecord;
    (*numberOfRecords)++;
}

/* Function to print all the records in the record system */
void printAllRecords(struct bankRecord records[], int numberOfRecords) {
    printf("All Records:\n");
    printf("-----------------------------------------------------------\n");
    printf("Name\t\tAccount Number\t\tAccount Balance\n");
    printf("-----------------------------------------------------------\n");

    for (int i = 0; i < numberOfRecords; i++) {
        printf("%s\t\t%d\t\t\t%.2f\n", records[i].fullName, records[i].accountNumber, records[i].accountBalance);
    }

    printf("-----------------------------------------------------------\n");
}

/* Function to search for a record in the record system */
void searchRecord(struct bankRecord records[], int numberOfRecords) {
    int searchAccountNumber;

    printf("Enter the account number you want to search: ");
    scanf("%d", &searchAccountNumber);

    for (int i = 0; i < numberOfRecords; i++) {
        if (records[i].accountNumber == searchAccountNumber) {
            printf("\nRecord Found:\n");
            printf("-----------------------------------------------------------\n");
            printf("Name\t\tAccount Number\t\tAccount Balance\n");
            printf("-----------------------------------------------------------\n");
            printf("%s\t\t%d\t\t\t%.2f\n", records[i].fullName, records[i].accountNumber, records[i].accountBalance);
            printf("-----------------------------------------------------------\n");
            return;
        }
    }

    printf("\nRecord with account number %d not found!\n", searchAccountNumber);
}

/* Function to update a record in the record system */
void updateRecord(struct bankRecord records[], int numberOfRecords) {
    int updateAccountNumber;

    printf("Enter the account number you want to update: ");
    scanf("%d", &updateAccountNumber);

    for (int i = 0; i < numberOfRecords; i++) {
        if (records[i].accountNumber == updateAccountNumber) {
            printf("\nEnter the new details for the record:\n");
            
            // Get the full name
            printf("Full Name: ");
            fgets(records[i].fullName, 50, stdin);
            records[i].fullName[strcspn(records[i].fullName, "\n")] = 0;

            // Get the account balance
            printf("Account Balance: ");
            scanf("%f", &records[i].accountBalance);
            getchar(); // Clear newline character from buffer

            printf("\nRecord updated successfully!\n");
            return;
        }
    }

    printf("\nRecord with account number %d not found!\n", updateAccountNumber);
}

/* Function to delete a record from the record system */
void deleteRecord(struct bankRecord records[], int *numberOfRecords) {
    int deleteAccountNumber;

    printf("Enter the account number you want to delete: ");
    scanf("%d", &deleteAccountNumber);

    for (int i = 0; i < *numberOfRecords; i++) {
        if (records[i].accountNumber == deleteAccountNumber) {
            // Shift all the records after this one back by one position
            for (int j = i; j < *numberOfRecords - 1; j++) {
                records[j] = records[j+1];
            }

            (*numberOfRecords)--;
            printf("\nRecord deleted successfully!\n");
            return;
        }
    }

    printf("\nRecord with account number %d not found!\n", deleteAccountNumber);
}

int main() {
    struct bankRecord records[MAX_RECORDS];
    int numberOfRecords = 0;
    int choice;

    do {
        printf("\nBank Record System\n");
        printf("-----------------------------------------------------------\n");
        printf("1. Add New Record\n");
        printf("2. Print All Records\n");
        printf("3. Search For a Record\n");
        printf("4. Update a Record\n");
        printf("5. Delete a Record\n");
        printf("6. Exit\n");
        printf("-----------------------------------------------------------\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1:
                addRecord(records, &numberOfRecords);
                break;
            case 2:
                printAllRecords(records, numberOfRecords);
                break;
            case 3:
                searchRecord(records, numberOfRecords);
                break;
            case 4:
                updateRecord(records, numberOfRecords);
                break;
            case 5:
                deleteRecord(records, &numberOfRecords);
                break;
            case 6:
                printf("\nExiting...\n");
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}