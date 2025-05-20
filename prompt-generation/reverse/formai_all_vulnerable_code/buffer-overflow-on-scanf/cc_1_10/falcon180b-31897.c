//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

typedef struct account {
    char name[50];
    double balance;
} Account;

typedef struct transaction {
    char description[100];
    double amount;
    int account_index;
} Transaction;

int num_accounts;
Account accounts[MAX_ACCOUNTS];
int num_transactions;
Transaction transactions[MAX_TRANSACTIONS];

void add_account() {
    printf("Enter account name: ");
    scanf("%s", accounts[num_accounts].name);
    accounts[num_accounts].balance = 0;
    num_accounts++;
}

void deposit(int account_index) {
    printf("Enter deposit amount: ");
    scanf("%lf", &transactions[num_transactions].amount);
    transactions[num_transactions].account_index = account_index;
    transactions[num_transactions].description[0] = '\0';
    num_transactions++;
}

void withdraw(int account_index) {
    printf("Enter withdrawal amount: ");
    scanf("%lf", &transactions[num_transactions].amount);
    transactions[num_transactions].account_index = account_index;
    strcpy(transactions[num_transactions].description, "Withdrawal");
    num_transactions++;
}

void transfer(int from_account_index, int to_account_index) {
    printf("Enter transfer amount: ");
    scanf("%lf", &transactions[num_transactions].amount);
    transactions[num_transactions].account_index = from_account_index;
    strcpy(transactions[num_transactions].description, "Transfer to account ");
    strcat(transactions[num_transactions].description, accounts[to_account_index].name);
    num_transactions++;
}

void print_accounts() {
    printf("Accounts:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: $%.2f\n", accounts[i].name, accounts[i].balance);
    }
}

void print_transactions() {
    printf("Transactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - $%.2f (%s)\n", transactions[i].description, transactions[i].amount, accounts[transactions[i].account_index].name);
    }
}

int main() {
    num_accounts = 0;
    num_transactions = 0;

    add_account();
    add_account();

    deposit(0);
    withdraw(0);
    deposit(1);
    transfer(0, 1);

    print_accounts();
    print_transactions();

    return 0;
}