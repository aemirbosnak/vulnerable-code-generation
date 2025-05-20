//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store banking record
struct BankRecord {
    int account_number;
    char name[50];
    float balance;
};

// Function to add a new record
void addRecord(struct BankRecord *records, int *n) {
    // Print a message to prompt user for input
    printf("Enter account number: ");
    scanf("%d", &records[*n].account_number);
    printf("Enter name: ");
    scanf("%s", records[*n].name);
    printf("Enter balance: ");
    scanf("%f", &records[*n].balance);
    // Increment the number of records
    (*n)++;
}

// Function to display all records
void displayAllRecords(struct BankRecord *records, int n) {
    // Print a heading
    printf("Account Number\tName\t\tBalance\n");
    // Loop through all records
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%s\t\t%f\n", records[i].account_number, records[i].name, records[i].balance);
    }
}

// Function to search for a record
void searchRecord(struct BankRecord *records, int n) {
    // Print a message to prompt user for input
    printf("Enter account number to search: ");
    int search_account_number;
    scanf("%d", &search_account_number);
    // Loop through all records
    for (int i = 0; i < n; i++) {
        // Check if account number matches
        if (records[i].account_number == search_account_number) {
            // Print the record
            printf("Account Number\tName\t\tBalance\n");
            printf("%d\t\t%s\t\t%f\n", records[i].account_number, records[i].name, records[i].balance);
            return;
        }
    }
    // If record is not found, print an error message
    printf("Record not found\n");
}

int main() {
    // Initialize variables
    struct BankRecord records[100];
    int n = 0;
    int choice;
    // Loop until user chooses to exit
    do {
        // Print menu
        printf("Banking Record System\n");
        printf("1. Add new record\n");
        printf("2. Display all records\n");
        printf("3. Search for a record\n");
        printf("4. Exit\n");
        // Get user choice
        scanf("%d", &choice);
        // Check user choice
        switch (choice) {
            case 1:
                addRecord(records, &n);
                break;
            case 2:
                displayAllRecords(records, n);
                break;
            case 3:
                searchRecord(records, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}