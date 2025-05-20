//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    double balance;
} Account;

typedef struct {
    char description[100];
    double amount;
    int account_index;
} Transaction;

int main() {
    int num_accounts, num_transactions;
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter the number of accounts you have:\n");
    scanf("%d", &num_accounts);

    for (int i = 0; i < num_accounts; i++) {
        printf("Enter account name %d:\n", i+1);
        scanf("%s", accounts[i].name);
        accounts[i].balance = 0.0;
    }

    printf("Please enter the number of transactions you want to add:\n");
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction description %d:\n", i+1);
        scanf("%s", transactions[i].description);
        printf("Enter transaction amount %d:\n", i+1);
        scanf("%lf", &transactions[i].amount);
        printf("Enter account index %d:\n", i+1);
        scanf("%d", &transactions[i].account_index);
    }

    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - $%.2f - %s\n", transactions[i].description, transactions[i].amount, accounts[transactions[i].account_index].name);
    }

    printf("Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s - Balance: $%.2f\n", accounts[i].name, accounts[i].balance);
    }

    return 0;
}