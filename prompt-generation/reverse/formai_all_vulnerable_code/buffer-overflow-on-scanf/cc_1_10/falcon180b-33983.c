//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    char name[30];
    int balance;
    int transactions;
} Account;

typedef struct {
    char description[50];
    int amount;
    int date;
} Transaction;

int main() {
    int numAccounts = 0;
    int numTransactions = 0;
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];

    while (numAccounts < MAX_ACCOUNTS) {
        printf("Enter account name: ");
        scanf("%s", accounts[numAccounts].name);
        accounts[numAccounts].balance = 0;
        accounts[numAccounts].transactions = 0;
        numAccounts++;
    }

    while (numTransactions < MAX_TRANSACTIONS) {
        printf("Enter transaction description: ");
        scanf("%s", transactions[numTransactions].description);
        printf("Enter amount: ");
        scanf("%d", &transactions[numTransactions].amount);
        printf("Enter date (YYYY-MM-DD): ");
        scanf("%s", transactions[numTransactions].date);
        numTransactions++;
    }

    printf("\nAccounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%s - Balance: $%d\n", accounts[i].name, accounts[i].balance);
    }

    printf("\nTransactions:\n");
    for (int i = 0; i < numTransactions; i++) {
        printf("%s - Amount: $%d - Date: %s\n", transactions[i].description, transactions[i].amount, transactions[i].date);
    }

    return 0;
}