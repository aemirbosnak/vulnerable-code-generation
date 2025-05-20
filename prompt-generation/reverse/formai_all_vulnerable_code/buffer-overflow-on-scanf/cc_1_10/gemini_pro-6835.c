//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int account_number;
    double balance;
} account_t;

int main() {
    // Create an array of 10 accounts
    account_t accounts[10];

    // Initialize the accounts with some funny names and balances
    for (int i = 0; i < 10; i++) {
        sprintf(accounts[i].name, "Account %d", i);
        accounts[i].account_number = 100000 + i;
        accounts[i].balance = (double)rand() / RAND_MAX * 10000;
    }

    // Print the accounts
    for (int i = 0; i < 10; i++) {
        printf("%s (%d): $%.2f\n", accounts[i].name, accounts[i].account_number, accounts[i].balance);
    }

    // Get the account number from the user
    int account_number;
    printf("Enter the account number: ");
    scanf("%d", &account_number);

    // Find the account by account number
    account_t *account = NULL;
    for (int i = 0; i < 10; i++) {
        if (accounts[i].account_number == account_number) {
            account = &accounts[i];
            break;
        }
    }

    // If the account was not found, print an error message
    if (account == NULL) {
        printf("Account not found\n");
        return 1;
    }

    // Get the amount to withdraw
    double amount;
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    // If the amount is greater than the balance, print an error message
    if (amount > account->balance) {
        printf("Insufficient funds\n");
        return 1;
    }

    // Withdraw the amount from the account
    account->balance -= amount;

    // Print the new balance
    printf("New balance: $%.2f\n", account->balance);

    return 0;
}