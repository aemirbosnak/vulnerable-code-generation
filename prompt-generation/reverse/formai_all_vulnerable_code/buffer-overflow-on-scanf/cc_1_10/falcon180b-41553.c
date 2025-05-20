//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    float balance;
} Account;

typedef struct {
    char description[100];
    float amount;
    int account_index;
} Transaction;

int num_accounts = 0;
Account accounts[MAX_ACCOUNTS];

int num_transactions = 0;
Transaction transactions[MAX_TRANSACTIONS];

void add_account() {
    num_accounts++;
    printf("Enter account name: ");
    scanf("%s", accounts[num_accounts-1].name);
    accounts[num_accounts-1].balance = 0.0;
}

void add_transaction() {
    num_transactions++;
    printf("Enter transaction description: ");
    scanf("%s", transactions[num_transactions-1].description);
    printf("Enter amount: ");
    scanf("%f", &transactions[num_transactions-1].amount);
    printf("Enter account index (0-%d): ", num_accounts-1);
    scanf("%d", &transactions[num_transactions-1].account_index);
}

void print_accounts() {
    printf("Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%d. %s: $%.2f\n", i+1, accounts[i].name, accounts[i].balance);
    }
}

void print_transactions() {
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%d. %s (%d): $%.2f\n", i+1, transactions[i].description, transactions[i].account_index+1, transactions[i].amount);
    }
}

void main() {
    printf("Welcome to the Personal Finance Planner!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add account\n");
        printf("2. Add transaction\n");
        printf("3. Print accounts\n");
        printf("4. Print transactions\n");
        printf("5. Quit\n");

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
                print_accounts();
                break;
            case 4:
                print_transactions();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}