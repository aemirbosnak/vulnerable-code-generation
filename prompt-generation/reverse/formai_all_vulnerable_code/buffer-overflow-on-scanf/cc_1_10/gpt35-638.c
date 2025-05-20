//FormAI DATASET v1.0 Category: Banking Record System ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Define a structure for bank records
struct bankRecord {
    char accountNumber[10];
    char firstName[20];
    char lastName[20];
    float balance;
};

// Function to add a new bank record
void addRecord(struct bankRecord *records, int *n) {
    printf("Enter account number: ");
    scanf("%s", records[*n].accountNumber);

    printf("Enter first name: ");
    scanf("%s", records[*n].firstName);

    printf("Enter last name: ");
    scanf("%s", records[*n].lastName);

    printf("Enter balance: ");
    scanf("%f", &records[*n].balance);

    printf("Record added successfully!\n");
    (*n)++;
}

// Function to search for a bank record
void searchRecord(struct bankRecord *records, int n) {
    char accountNumber[10];
    printf("Enter account number to search: ");
    scanf("%s", accountNumber);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(records[i].accountNumber, accountNumber) == 0) {
            printf("Account number: %s\n", records[i].accountNumber);
            printf("First name: %s\n", records[i].firstName);
            printf("Last name: %s\n", records[i].lastName);
            printf("Balance: %.2f\n", records[i].balance);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

// Function to update a bank record
void updateRecord(struct bankRecord *records, int n) {
    char accountNumber[10];
    printf("Enter account number to update: ");
    scanf("%s", accountNumber);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(records[i].accountNumber, accountNumber) == 0) {
            printf("Enter new balance: ");
            scanf("%f", &records[i].balance);
            printf("Record updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

// Function to delete a bank record
void deleteRecord(struct bankRecord *records, int *n) {
    char accountNumber[10];
    printf("Enter account number to delete: ");
    scanf("%s", accountNumber);

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if (strcmp(records[i].accountNumber, accountNumber) == 0) {
            (*n)--;
            for (int j = i; j < *n; j++) {
                records[j] = records[j+1];
            }
            printf("Record deleted successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found.\n");
    }
}

int main() {
    struct bankRecord records[100];
    int n = 0, choice;

    printf("Welcome to the Banking Record System!\n");

    do {
        printf("\nSelect an option:\n");
        printf("1. Add a new record\n");
        printf("2. Search for a record\n");
        printf("3. Update a record\n");
        printf("4. Delete a record\n");
        printf("5. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addRecord(records, &n);
                break;
            case 2:
                searchRecord(records, n);
                break;
            case 3:
                updateRecord(records, n);
                break;
            case 4:
                deleteRecord(records, &n);
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 5);

    return 0;
}