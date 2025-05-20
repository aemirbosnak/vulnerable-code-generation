//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
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
    printf("How many accounts do you have? (up to %d): ", MAX_ACCOUNTS);
    scanf("%d", &num_accounts);

    for (int i = 0; i < num_accounts; i++) {
        printf("Enter account name %d: ", i+1);
        scanf("%s", accounts[i].name);
        accounts[i].balance = 0;
    }

    printf("How many transactions do you want to enter? (up to %d): ", MAX_TRANSACTIONS);
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction description for account %d: ", i+1);
        scanf("%s", transactions[i].description);
        printf("Enter amount: ");
        scanf("%lf", &transactions[i].amount);
        printf("Enter account index (1-%d): ", num_accounts);
        scanf("%d", &transactions[i].account_index);
    }

    for (int i = 0; i < num_transactions; i++) {
        int account_index = transactions[i].account_index - 1;
        Account* account = &accounts[account_index];
        account->balance += transactions[i].amount;
        printf("Transaction %d: %s -> %s ($%.2f)\n", i+1, transactions[i].description, account->name, transactions[i].amount);
    }

    return 0;
}