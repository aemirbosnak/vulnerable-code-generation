//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    double balance;
    int account_number;
} bank_account;

void print_account(bank_account account) {
    printf("Name: %s\n", account.name);
    printf("Balance: %f\n", account.balance);
    printf("Account Number: %d\n", account.account_number);
}

int main() {
    // Create an array of bank accounts.
    bank_account accounts[10];

    // Initialize the accounts.
    for (int i = 0; i < 10; i++) {
        accounts[i].name = malloc(20 * sizeof(char));
        accounts[i].balance = 0.0;
        accounts[i].account_number = i + 1;
    }

    // Get the user's input.
    int account_number;
    double amount;
    char choice;

    while (1) {
        printf("Enter your account number: ");
        scanf("%d", &account_number);

        printf("Enter the amount you want to deposit or withdraw: ");
        scanf("%lf", &amount);

        printf("Enter 'd' to deposit or 'w' to withdraw: ");
        scanf(" %c", &choice);

        // Perform the transaction.
        switch (choice) {
            case 'd':
                accounts[account_number - 1].balance += amount;
                break;
            case 'w':
                accounts[account_number - 1].balance -= amount;
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        // Print the account balance.
        print_account(accounts[account_number - 1]);

        // Ask the user if they want to continue.
        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice);

        if (choice == 'n') {
            break;
        }
    }

    // Free the memory that was allocated for the accounts.
    for (int i = 0; i < 10; i++) {
        free(accounts[i].name);
    }

    return 0;
}