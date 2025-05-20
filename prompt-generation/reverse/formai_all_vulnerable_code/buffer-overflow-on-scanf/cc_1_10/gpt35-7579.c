//FormAI DATASET v1.0 Category: Banking Record System ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Declare the structure for the banking records
typedef struct {
    char name[50];
    char account_number[20];
    double balance;
} BankRecord;

// Declare functions to be used
void addRecord(BankRecord *records, int *record_count);
void displayRecords(BankRecord *records, int record_count);
void searchRecord(BankRecord *records, int record_count);

// Main function
int main() {
    int option, record_count = 0;

    BankRecord *records = (BankRecord*) malloc(10 * sizeof(BankRecord)); // Initially allocate space for 10 records
    if (records == NULL) {
        printf("Memory allocation failed. Exiting program.");
        return 1;
    }

    // Display the menu options
    do {
        printf("Please select an option:\n");
        printf("1. Add record\n");
        printf("2. Display all records\n");
        printf("3. Search for a record\n");
        printf("4. Exit\n");
        printf("Option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                addRecord(records, &record_count);
                break;
            case 2:
                displayRecords(records, record_count);
                break;
            case 3:
                searchRecord(records, record_count);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option selected. Please try again.\n");
                break;
        }
    } while (option != 4);

    // Free allocated memory
    free(records);

    return 0;
}

// Function to add a new record
void addRecord(BankRecord *records, int *record_count) {
    if (*record_count == 10) {
        printf("Maximum number of records reached. Cannot add more.\n");
        return;
    }

    printf("Please enter the name of the account holder: ");
    scanf("%s", records[*record_count].name);

    printf("Please enter the account number: ");
    scanf("%s", records[*record_count].account_number);

    printf("Please enter the account balance: ");
    scanf("%lf", &records[*record_count].balance);

    (*record_count)++; // Increment the record_count
    printf("New record added successfully.\n");
}

// Function to display all records
void displayRecords(BankRecord *records, int record_count) {
    if (record_count == 0) {
        printf("No records to display.\n");
        return;
    }

    printf("Name\t\tAccount number\t\tBalance\n");
    for (int i = 0; i < record_count; i++) {
        printf("%s\t\t%s\t\t%.2lf\n", records[i].name, records[i].account_number, records[i].balance);
    }
}

// Function to search for a record by account number
void searchRecord(BankRecord *records, int record_count) {
    if (record_count == 0) {
        printf("No records to search for.\n");
        return;
    }

    char search_account_number[20];
    printf("Please enter the account number to search for: ");
    scanf("%s", search_account_number);

    int found = 0;
    for (int i = 0; i < record_count; i++) {
        if (strcmp(records[i].account_number, search_account_number) == 0) {
            printf("Record found:\n");
            printf("Name: %s\n", records[i].name);
            printf("Account number: %s\n", records[i].account_number);
            printf("Balance: %.2lf\n", records[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record with account number %s not found.\n", search_account_number);
    }
}