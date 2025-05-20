//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct account {
    char name[50];
    char account_number[20];
    double balance;
} account;

void create_account(account *accounts, int *num_accounts) {
    printf("Enter name: ");
    scanf(" %[^\n]%*c", accounts[*num_accounts].name);
    printf("Enter account number: ");
    scanf(" %[^\n]%*c", accounts[*num_accounts].account_number);
    printf("Enter balance: ");
    scanf(" %lf", &accounts[*num_accounts].balance);
    (*num_accounts)++;
}

void deposit(account *accounts, int num_accounts) {
    char account_number[20];
    double amount;

    printf("Enter account number: ");
    scanf(" %[^\n]%*c", account_number);
    printf("Enter amount: ");
    scanf(" %lf", &amount);

    int found = 0;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            accounts[i].balance += amount;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Account not found\n");
    }
}

void withdraw(account *accounts, int num_accounts) {
    char account_number[20];
    double amount;

    printf("Enter account number: ");
    scanf(" %[^\n]%*c", account_number);
    printf("Enter amount: ");
    scanf(" %lf", &amount);

    int found = 0;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                found = 1;
                break;
            } else {
                printf("Insufficient funds\n");
                break;
            }
        }
    }

    if (!found) {
        printf("Account not found\n");
    }
}

void transfer(account *accounts, int num_accounts) {
    char from_account_number[20];
    char to_account_number[20];
    double amount;

    printf("Enter from account number: ");
    scanf(" %[^\n]%*c", from_account_number);
    printf("Enter to account number: ");
    scanf(" %[^\n]%*c", to_account_number);
    printf("Enter amount: ");
    scanf(" %lf", &amount);

    int from_account_found = 0;
    int to_account_found = 0;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_number, from_account_number) == 0) {
            if (amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                from_account_found = 1;
            } else {
                printf("Insufficient funds\n");
                break;
            }
        }
        if (strcmp(accounts[i].account_number, to_account_number) == 0) {
            accounts[i].balance += amount;
            to_account_found = 1;
        }
    }

    if (!from_account_found) {
        printf("From account not found\n");
    }
    if (!to_account_found) {
        printf("To account not found\n");
    }
}

void print_accounts(account *accounts, int num_accounts) {
    printf("\n**** Accounts ****\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Name: %s\n", accounts[i].name);
        printf("Account number: %s\n", accounts[i].account_number);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("\n");
    }
}

int main() {
    account accounts[100];
    int num_accounts = 0;

    int choice;
    do {
        printf("\n**** Banking Record System ****\n");
        printf("1. Create account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Print accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        switch (choice) {
            case 1:
                create_account(accounts, &num_accounts);
                break;
            case 2:
                deposit(accounts, num_accounts);
                break;
            case 3:
                withdraw(accounts, num_accounts);
                break;
            case 4:
                transfer(accounts, num_accounts);
                break;
            case 5:
                print_accounts(accounts, num_accounts);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    return 0;
}