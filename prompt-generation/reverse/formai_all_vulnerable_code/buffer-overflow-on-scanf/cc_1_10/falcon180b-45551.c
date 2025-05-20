//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100
#define MAX_TRANSACTION_NAME_LENGTH 50

typedef struct {
    char name[MAX_TRANSACTION_NAME_LENGTH];
    float amount;
    char category[MAX_TRANSACTION_NAME_LENGTH];
} transaction;

typedef struct {
    char name[MAX_TRANSACTION_NAME_LENGTH];
    float balance;
} account;

int num_accounts = 0;
account accounts[MAX_ACCOUNTS];
int num_transactions = 0;
transaction transactions[MAX_TRANSACTIONS];

void add_account() {
    num_accounts++;
    accounts[num_accounts - 1].balance = 0;
}

void add_transaction() {
    num_transactions++;
}

void print_accounts() {
    printf("Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: $%.2f\n", accounts[i].name, accounts[i].balance);
    }
}

void print_transactions() {
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s: $%.2f - %s\n", transactions[i].name, transactions[i].amount, transactions[i].category);
    }
}

int main() {
    printf("Welcome to the Cyberpunk Personal Finance Planner!\n");

    char choice;
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("A - Add account\n");
        printf("T - Add transaction\n");
        printf("P - Print accounts\n");
        printf("R - Print transactions\n");
        printf("Q - Quit\n");
        scanf("%c", &choice);

        switch (choice) {
            case 'A':
                add_account();
                printf("Account added!\n");
                break;
            case 'T':
                add_transaction();
                printf("Transaction added!\n");
                break;
            case 'P':
                print_accounts();
                break;
            case 'R':
                print_transactions();
                break;
            case 'Q':
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}