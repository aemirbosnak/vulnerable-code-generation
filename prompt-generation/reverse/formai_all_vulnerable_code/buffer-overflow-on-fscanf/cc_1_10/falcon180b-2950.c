//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 1000
#define MAX_TRANSACTIONS 100

struct account {
    int account_number;
    char name[50];
    float balance;
};

struct transaction {
    int account_number;
    char type[10];
    float amount;
    char date[10];
};

int main() {
    FILE *accounts_file, *transactions_file;
    int num_accounts = 0, num_transactions = 0;
    struct account accounts[MAX_ACCOUNTS];
    struct transaction transactions[MAX_TRANSACTIONS];

    // Open accounts file
    accounts_file = fopen("accounts.txt", "r");
    if (accounts_file == NULL) {
        printf("Error: Could not open accounts file.\n");
        exit(1);
    }

    // Read accounts from file
    while (fscanf(accounts_file, "%d %s %f\n", &accounts[num_accounts].account_number, accounts[num_accounts].name, &accounts[num_accounts].balance)!= EOF) {
        num_accounts++;
    }
    fclose(accounts_file);

    // Open transactions file
    transactions_file = fopen("transactions.txt", "r");
    if (transactions_file == NULL) {
        printf("Error: Could not open transactions file.\n");
        exit(1);
    }

    // Read transactions from file
    while (fscanf(transactions_file, "%d %s %f %s\n", &transactions[num_transactions].account_number, transactions[num_transactions].type, &transactions[num_transactions].amount, transactions[num_transactions].date)!= EOF) {
        num_transactions++;
    }
    fclose(transactions_file);

    // Display account information
    printf("Account Information:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: $%.2f\n\n", accounts[i].balance);
    }

    // Display transaction information
    printf("Transaction Information:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("Account Number: %d\n", transactions[i].account_number);
        printf("Type: %s\n", transactions[i].type);
        printf("Amount: $%.2f\n", transactions[i].amount);
        printf("Date: %s\n\n", transactions[i].date);
    }

    return 0;
}