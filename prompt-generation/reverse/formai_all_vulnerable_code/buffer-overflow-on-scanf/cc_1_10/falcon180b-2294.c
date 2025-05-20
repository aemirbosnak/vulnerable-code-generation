//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    int account_number;
    double balance;
} Account;

typedef struct {
    int account_number_from;
    int account_number_to;
    char description[100];
    double amount;
    int type; // 1 for deposit, -1 for withdrawal
} Transaction;

int main() {
    // Initialize accounts and transactions
    Account accounts[MAX_ACCOUNTS];
    memset(accounts, 0, sizeof(accounts));

    Transaction transactions[MAX_TRANSACTIONS];
    memset(transactions, 0, sizeof(transactions));

    // Add accounts
    int num_accounts = 0;
    while (num_accounts < MAX_ACCOUNTS) {
        printf("Enter account name: ");
        scanf("%s", accounts[num_accounts].name);
        printf("Enter account number: ");
        scanf("%d", &accounts[num_accounts].account_number);
        printf("Enter initial balance: ");
        scanf("%lf", &accounts[num_accounts].balance);
        num_accounts++;
    }

    // Add transactions
    int num_transactions = 0;
    while (num_transactions < MAX_TRANSACTIONS) {
        printf("Enter transaction description: ");
        scanf("%s", transactions[num_transactions].description);
        printf("Enter account number from: ");
        scanf("%d", &transactions[num_transactions].account_number_from);
        printf("Enter account number to: ");
        scanf("%d", &transactions[num_transactions].account_number_to);
        printf("Enter amount: ");
        scanf("%lf", &transactions[num_transactions].amount);
        printf("Enter transaction type (1 for deposit, -1 for withdrawal): ");
        scanf("%d", &transactions[num_transactions].type);
        num_transactions++;
    }

    // Display accounts
    printf("\nAccounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s (%d) - Balance: $%.2lf\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }

    // Display transactions
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        if (transactions[i].type == 1) {
            printf("Deposit of $%.2lf from account %d to account %d\n", transactions[i].amount, transactions[i].account_number_from, transactions[i].account_number_to);
        } else {
            printf("Withdrawal of $%.2lf from account %d to account %d\n", transactions[i].amount, transactions[i].account_number_from, transactions[i].account_number_to);
        }
    }

    return 0;
}