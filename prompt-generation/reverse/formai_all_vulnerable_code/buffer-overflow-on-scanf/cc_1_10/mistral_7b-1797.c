//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define ACCOUNT_SIZE 50

typedef struct {
    char name[ACCOUNT_SIZE];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

void add_account(char *name, float initial_balance) {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    strcpy(accounts[num_accounts].name, name);
    accounts[num_accounts].balance = initial_balance;
    num_accounts++;
}

void deposit(int account_number, float amount) {
    if (account_number < 0 || account_number >= num_accounts) {
        printf("Error: Invalid account number.\n");
        return;
    }

    accounts[account_number].balance += amount;
}

void withdraw(int account_number, float amount) {
    if (account_number < 0 || account_number >= num_accounts) {
        printf("Error: Invalid account number.\n");
        return;
    }

    if (accounts[account_number].balance < amount) {
        printf("Error: Insufficient balance.\n");
        return;
    }

    accounts[account_number].balance -= amount;
}

void print_accounts() {
    for (int i = 0; i < num_accounts; i++) {
        printf("Account %d: %s, Balance: %.2f\n", i, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    char name[ACCOUNT_SIZE];
    int choice, account_number;
    float amount;

    while (1) {
        printf("\nBanking System\n");
        printf("1. Add Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Print Accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account name: ");
                scanf("%s", name);
                printf("Enter initial balance: ");
                scanf("%f", &amount);
                add_account(name, amount);
                break;
            case 2:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(account_number, amount);
                break;
            case 3:
                printf("Enter account number: ");
                scanf("%d", &account_number);
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(account_number, amount);
                break;
            case 4:
                print_accounts();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}