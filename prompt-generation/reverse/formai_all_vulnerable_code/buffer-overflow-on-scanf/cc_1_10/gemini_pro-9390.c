//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: happy
#include <stdio.h>
#include <stdlib.h>

struct account {
    char name[50];
    int account_number;
    double balance;
};

int main() {
    // Create an array of accounts
    struct account accounts[100];

    // Initialize the accounts with some sample data
    for (int i = 0; i < 100; i++) {
        sprintf(accounts[i].name, "Customer %d", i + 1);
        accounts[i].account_number = i + 1000;
        accounts[i].balance = 1000.00 + i * 10.00;
    }

    // Print the account information
    for (int i = 0; i < 100; i++) {
        printf("Account %d:\n", accounts[i].account_number);
        printf("Name: %s\n", accounts[i].name);
        printf("Balance: $%.2f\n\n", accounts[i].balance);
    }

    // Get the account number from the user
    int account_number;
    printf("Enter the account number: ");
    scanf("%d", &account_number);

    // Find the account in the array
    int index = -1;
    for (int i = 0; i < 100; i++) {
        if (accounts[i].account_number == account_number) {
            index = i;
            break;
        }
    }

    // If the account was not found, print an error message
    if (index == -1) {
        printf("Account not found.\n");
        return 1;
    }

    // Get the transaction type from the user
    char transaction_type;
    printf("Enter the transaction type (D for deposit, W for withdrawal): ");
    scanf(" %c", &transaction_type);

    // Get the amount of the transaction
    double amount;
    printf("Enter the amount of the transaction: ");
    scanf("%lf", &amount);

    // Perform the transaction
    switch (transaction_type) {
        case 'D':
            accounts[index].balance += amount;
            printf("Deposit successful. New balance: $%.2f\n", accounts[index].balance);
            break;
        case 'W':
            if (amount <= accounts[index].balance) {
                accounts[index].balance -= amount;
                printf("Withdrawal successful. New balance: $%.2f\n", accounts[index].balance);
            } else {
                printf("Insufficient funds.\n");
            }
            break;
        default:
            printf("Invalid transaction type.\n");
            break;
    }

    return 0;
}