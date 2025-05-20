//FormAI DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 1000 // Maximum number of records that can be stored

// Structure to hold the account information
typedef struct {
    int account_number;
    char account_name[50];
    double balance;
} account;

// Function to add a new account to the record system
void add_account(account *records, int *num_records) {
    if (*num_records < MAX_RECORDS) {
        account new_account;
        printf("Enter account number: ");
        scanf("%d", &new_account.account_number);
        printf("Enter account name: ");
        scanf("%s", new_account.account_name);
        printf("Enter account balance: ");
        scanf("%lf", &new_account.balance);
        records[*num_records] = new_account;
        (*num_records)++;
        printf("Account added successfully!\n");
    } else {
        printf("Record system is full. Cannot add new account.\n");
    }
}

// Function to remove an account from the record system
void remove_account(account *records, int *num_records) {
    int account_number;
    int found = 0;
    printf("Enter account number to be removed: ");
    scanf("%d", &account_number);
    for (int i = 0; i < *num_records; i++) {
        if (records[i].account_number == account_number) {
            found = 1;
            for (int j = i; j < *num_records - 1; j++) {
                records[j] = records[j+1];
            }
            (*num_records)--;
            printf("Account removed successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Account not found.\n");
    }
}

// Function to display all the accounts in the record system
void display_accounts(account *records, int *num_records) {
    printf("Account Number\tAccount Name\t\tAccount Balance\n");
    for (int i = 0; i < *num_records; i++) {
        printf("%d\t\t%s\t\t%.2lf\n", records[i].account_number, records[i].account_name, records[i].balance);
    }
}

int main() {
    account records[MAX_RECORDS];
    int num_records = 0;
    int choice = 0;
    while (1) {
        printf("\n----- Banking Record System -----\n");
        printf("1. Add new account\n");
        printf("2. Remove account\n");
        printf("3. Display all accounts\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                add_account(records, &num_records);
                break;
            case 2:
                remove_account(records, &num_records);
                break;
            case 3:
                display_accounts(records, &num_records);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}