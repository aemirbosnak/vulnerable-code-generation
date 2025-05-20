//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    int account_number;
    double balance;
} Account;

typedef struct {
    char description[100];
    int account_number;
    double amount;
} Transaction;

int main() {
    int num_accounts, num_transactions;
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];

    printf("Welcome to the Personal Finance Planner!\n");

    // Initialize accounts
    num_accounts = 0;
    while (num_accounts < MAX_ACCOUNTS) {
        printf("Enter account name (or 'done' to finish): ");
        scanf("%s", accounts[num_accounts].name);
        if (strcmp(accounts[num_accounts].name, "done") == 0) {
            break;
        }
        printf("Enter account number: ");
        scanf("%d", &accounts[num_accounts].account_number);
        printf("Enter initial balance: ");
        scanf("%lf", &accounts[num_accounts].balance);
        num_accounts++;
    }

    // Initialize transactions
    num_transactions = 0;
    while (num_transactions < MAX_TRANSACTIONS) {
        printf("Enter transaction description: ");
        scanf("%s", transactions[num_transactions].description);
        printf("Enter account number: ");
        scanf("%d", &transactions[num_transactions].account_number);
        printf("Enter transaction amount: ");
        scanf("%lf", &transactions[num_transactions].amount);
        num_transactions++;
    }

    // Main menu
    while (true) {
        printf("\nMain Menu:\n");
        printf("1. View account balances\n");
        printf("2. View transaction history\n");
        printf("3. Make a transaction\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1: // View account balances
            printf("\nAccount Balances:\n");
            for (int i = 0; i < num_accounts; i++) {
                printf("%s: $%.2lf\n", accounts[i].name, accounts[i].balance);
            }
            break;

        case 2: // View transaction history
            printf("\nTransaction History:\n");
            for (int i = 0; i < num_transactions; i++) {
                printf("%s: $%.2lf\n", transactions[i].description, transactions[i].amount);
            }
            break;

        case 3: // Make a transaction
            printf("\nMake a Transaction:\n");
            printf("Enter transaction description: ");
            scanf("%s", transactions[num_transactions].description);
            printf("Enter account number: ");
            scanf("%d", &transactions[num_transactions].account_number);
            printf("Enter transaction amount: ");
            scanf("%lf", &transactions[num_transactions].amount);
            num_transactions++;
            printf("\nTransaction complete!\n");
            break;

        case 4: // Exit
            printf("\nExiting program...\n");
            return 0;

        default:
            printf("\nInvalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}