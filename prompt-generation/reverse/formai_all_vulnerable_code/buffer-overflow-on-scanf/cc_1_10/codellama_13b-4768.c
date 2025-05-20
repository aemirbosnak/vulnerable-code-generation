//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: expert-level
/*
 * Banking Record System
 *
 * This program is a command-line interface (CLI) application that allows
 * users to manage their banking records.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100

// Structure to represent a bank account
typedef struct {
    int account_number;
    char name[50];
    char email[50];
    float balance;
} Account;

// Function to print a list of accounts
void print_accounts(Account accounts[], int num_accounts) {
    printf("ACCOUNT NUMBER | NAME | EMAIL | BALANCE\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%d | %s | %s | %.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].email, accounts[i].balance);
    }
}

// Function to add a new account
void add_account(Account accounts[], int *num_accounts) {
    if (*num_accounts >= MAX_RECORDS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    Account account;
    printf("Enter account number: ");
    scanf("%d", &account.account_number);

    printf("Enter name: ");
    scanf("%s", account.name);

    printf("Enter email: ");
    scanf("%s", account.email);

    printf("Enter balance: ");
    scanf("%f", &account.balance);

    accounts[*num_accounts] = account;
    (*num_accounts)++;
}

// Function to delete an account
void delete_account(Account accounts[], int *num_accounts) {
    int account_number;
    printf("Enter account number to delete: ");
    scanf("%d", &account_number);

    for (int i = 0; i < *num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            for (int j = i; j < *num_accounts; j++) {
                accounts[j] = accounts[j + 1];
            }
            (*num_accounts)--;
            break;
        }
    }
}

// Function to modify an account
void modify_account(Account accounts[], int *num_accounts) {
    int account_number;
    printf("Enter account number to modify: ");
    scanf("%d", &account_number);

    for (int i = 0; i < *num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Enter new name: ");
            scanf("%s", accounts[i].name);

            printf("Enter new email: ");
            scanf("%s", accounts[i].email);

            printf("Enter new balance: ");
            scanf("%f", &accounts[i].balance);

            break;
        }
    }
}

// Main function
int main() {
    Account accounts[MAX_RECORDS];
    int num_accounts = 0;

    while (1) {
        printf("1. Add account\n");
        printf("2. Delete account\n");
        printf("3. Modify account\n");
        printf("4. Print accounts\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account(accounts, &num_accounts);
                break;
            case 2:
                delete_account(accounts, &num_accounts);
                break;
            case 3:
                modify_account(accounts, &num_accounts);
                break;
            case 4:
                print_accounts(accounts, num_accounts);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}