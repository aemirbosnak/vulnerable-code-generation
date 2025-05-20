//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
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
    char account_name[50];
} Transaction;

int main() {
    int num_accounts, num_transactions;
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];

    printf("Welcome to the Personal Finance Planner!\n");
    printf("Please enter the number of accounts you have:\n");
    scanf("%d", &num_accounts);

    for (int i = 0; i < num_accounts; i++) {
        printf("Enter account name #%d:\n", i+1);
        scanf("%s", accounts[i].name);
        printf("Enter starting balance for %s:\n", accounts[i].name);
        scanf("%lf", &accounts[i].balance);
    }

    printf("Please enter the number of transactions you have:\n");
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction description #%d:\n", i+1);
        scanf("%[^\n]s", transactions[i].description);
        printf("Enter transaction amount:\n");
        scanf("%lf", &transactions[i].amount);
        printf("Enter account name for transaction:\n");
        scanf("%s", transactions[i].account_name);
    }

    // Print account summary
    printf("\nAccount Summary:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Account #%d: %s\n", i+1, accounts[i].name);
        printf("Starting balance: $%.2lf\n", accounts[i].balance);
    }

    // Print transaction summary
    printf("\nTransaction Summary:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("Transaction #%d: %s\n", i+1, transactions[i].description);
        printf("Amount: $%.2lf\n", transactions[i].amount);
        printf("Account: %s\n", transactions[i].account_name);
    }

    return 0;
}