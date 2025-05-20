//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
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
    int category;
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
    accounts[num_accounts].balance = 0.0;
    num_accounts++;
}

void deposit(int account_index) {
    printf("Enter deposit amount: ");
    scanf("%lf", &transactions[num_transactions].amount);
    transactions[num_transactions].category = 1;
    accounts[account_index].balance += transactions[num_transactions].amount;
    num_transactions++;
}

void withdraw(int account_index) {
    printf("Enter withdrawal amount: ");
    scanf("%lf", &transactions[num_transactions].amount);
    transactions[num_transactions].category = 2;
    accounts[account_index].balance -= transactions[num_transactions].amount;
    num_transactions++;
}

void transfer(int from_account_index, int to_account_index) {
    printf("Enter transfer amount: ");
    scanf("%lf", &transactions[num_transactions].amount);
    transactions[num_transactions].category = 3;
    accounts[from_account_index].balance -= transactions[num_transactions].amount;
    accounts[to_account_index].balance += transactions[num_transactions].amount;
    num_transactions++;
}

void view_accounts() {
    printf("Account Name\tBalance\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s\t\t%.2lf\n", accounts[i].name, accounts[i].balance);
    }
}

void view_transactions() {
    printf("Transaction Description\tAmount\tCategory\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s\t\t%.2lf\t\t%d\n", transactions[i].description, transactions[i].amount, transactions[i].category);
    }
}

int main() {
    add_account();
    add_account();

    deposit(0);
    withdraw(0);
    transfer(0, 1);

    view_accounts();
    view_transactions();

    return 0;
}