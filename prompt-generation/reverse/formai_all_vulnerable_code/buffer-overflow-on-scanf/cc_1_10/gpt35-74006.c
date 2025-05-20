//FormAI DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for records
typedef struct record {
    char name[50];
    char account_type[10];
    int account_number;
    float balance;
} Record;

// Function to add a new record
void addRecord(Record *records, int *n) {
    printf("\nAdding New Record\n");
    printf("-----------------\n");
    // Prompt for inputs
    printf("Enter Name: ");
    scanf("%s", records[*n].name);
    printf("Enter Account Type(savings/current): ");
    scanf("%s", records[*n].account_type);
    printf("Enter Account Number: ");
    scanf("%d", &records[*n].account_number);
    printf("Enter Current Balance: ");
    scanf("%f", &records[*n].balance);
    // Increase count of records
    (*n)++;
}

// Function to print all records
void printRecords(Record *records, int n) {
    printf("\nAll Records\n");
    printf("-----------\n");
    // Loop through records and print
    for (int i = 0; i < n; i++) {
        printf("Name: %s\tAccount Type: %s\tAccount Number: %d\tBalance: $%.2f\n", records[i].name, records[i].account_type, records[i].account_number, records[i].balance);
    }
}

// Function to search for a record by account number
void searchRecord(Record *records, int n) {
    printf("\nSearch by Account Number\n");
    printf("------------------------\n");
    // Prompt for account number
    int account_number;
    printf("Enter Account Number: ");
    scanf("%d", &account_number);
    // Loop through records and search
    for (int i = 0; i < n; i++) {
        if (records[i].account_number == account_number) {
            printf("Name: %s\tAccount Type: %s\tAccount Number: %d\tBalance: $%.2f\n", records[i].name, records[i].account_type, records[i].account_number, records[i].balance);
            return;
        }
    }
    printf("Record not found for Account Number: %d\n", account_number);
}

int main() {
    // Initializing variables
    Record *records = (Record*)malloc(sizeof(Record)*100);
    int n = 0;
    int choice = 0;
    do {
        printf("\nBanking Record System\n");
        printf("_____________________\n");
        printf("(1) Add New Record\n");
        printf("(2) Print All Records\n");
        printf("(3) Search by Account Number\n");
        printf("(4) Exit\n");
        // Get user's choice
        printf("Enter Choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addRecord(records, &n);
                break;
            case 2:
                printRecords(records, n);
                break;
            case 3:
                searchRecord(records, n);
                break;
            case 4:
                printf("\nExiting Program...\n");
                break;
            default:
                printf("\nInvalid Choice\n");
        }
    } while (choice != 4);
    free(records);
    return 0;
}