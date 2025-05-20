//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    char name[32];
    int balance;
} Account;

typedef struct {
    Account *from;
    Account *to;
    char description[64];
    int amount;
} Transaction;

int num_accounts = 0;
Account accounts[MAX_ACCOUNTS];

int num_transactions = 0;
Transaction transactions[MAX_TRANSACTIONS];

void add_account(char *name) {
    strcpy(accounts[num_accounts].name, name);
    accounts[num_accounts].balance = 0;
    num_accounts++;
}

int get_account_index(char *name) {
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

void add_transaction(Account *from, Account *to, char *description, int amount) {
    strcpy(transactions[num_transactions].from->name, from->name);
    strcpy(transactions[num_transactions].to->name, to->name);
    strcpy(transactions[num_transactions].description, description);
    transactions[num_transactions].amount = amount;
    num_transactions++;
}

void print_accounts() {
    printf("Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: $%d\n", accounts[i].name, accounts[i].balance);
    }
}

void print_transactions() {
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("From %s to %s: $%d (%s)\n", transactions[i].from->name, transactions[i].to->name, transactions[i].amount, transactions[i].description);
    }
}

int main() {
    add_account("Checking");
    add_account("Savings");

    Account *checking = get_account_index("Checking");
    Account *savings = get_account_index("Savings");

    checking->balance = 1000;
    savings->balance = 500;

    add_transaction(checking, savings, "Transfer", 200);

    print_accounts();
    print_transactions();

    return 0;
}