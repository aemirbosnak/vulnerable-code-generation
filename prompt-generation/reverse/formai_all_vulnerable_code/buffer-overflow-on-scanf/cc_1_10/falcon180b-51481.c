//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    char name[50];
    double balance;
} Account;

typedef struct {
    char description[100];
    double amount;
    int account_index;
} Transaction;

int num_accounts = 0;
Account accounts[MAX_ACCOUNTS];

int num_transactions = 0;
Transaction transactions[MAX_TRANSACTIONS];

void add_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    printf("Enter account name: ");
    scanf("%s", accounts[num_accounts].name);
    accounts[num_accounts].balance = 0;
    num_accounts++;
}

void add_transaction() {
    if (num_transactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    printf("Enter transaction description: ");
    scanf("%s", transactions[num_transactions].description);
    printf("Enter transaction amount: ");
    scanf("%lf", &transactions[num_transactions].amount);
    printf("Enter account index (1-%d): ", num_accounts);
    scanf("%d", &transactions[num_transactions].account_index);
    num_transactions++;
}

void display_accounts() {
    printf("\nAccounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: %.2lf\n", accounts[i].name, accounts[i].balance);
    }
}

void display_transactions() {
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s %.2lf (%s)\n", transactions[i].description, transactions[i].amount, accounts[transactions[i].account_index-1].name);
    }
}

void main() {
    printf("Personal Finance Planner\n");

    while (1) {
        printf("\nOptions:\n1. Add account\n2. Add transaction\n3. Display accounts\n4. Display transactions\n5. Exit");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                add_transaction();
                break;
            case 3:
                display_accounts();
                break;
            case 4:
                display_transactions();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}