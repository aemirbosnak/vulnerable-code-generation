//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    int account_number;
    double balance;
} Account;

Account *create_account(char *name, int account_number, double balance) {
    Account *account = (Account *)malloc(sizeof(Account));
    account->name = (char *)malloc(strlen(name) + 1);
    strcpy(account->name, name);
    account->account_number = account_number;
    account->balance = balance;
    return account;
}

void destroy_account(Account *account) {
    free(account->name);
    free(account);
}

int main() {
    // Create a database of accounts
    Account *accounts[100];
    int num_accounts = 0;

    // Create some accounts
    accounts[num_accounts++] = create_account("Alice", 12345, 1000.0);
    accounts[num_accounts++] = create_account("Bob", 23456, 2000.0);
    accounts[num_accounts++] = create_account("Carol", 34567, 3000.0);

    // Print the balances of the accounts
    printf("Balances:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: %f\n", accounts[i]->name, accounts[i]->balance);
    }

    // Transfer some money from one account to another
    double amount = 100.0;
    Account *from_account = accounts[0];
    Account *to_account = accounts[1];
    from_account->balance -= amount;
    to_account->balance += amount;

    // Print the balances of the accounts again
    printf("\nBalances after transfer:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: %f\n", accounts[i]->name, accounts[i]->balance);
    }

    // Destroy the accounts
    for (int i = 0; i < num_accounts; i++) {
        destroy_account(accounts[i]);
    }

    return 0;
}