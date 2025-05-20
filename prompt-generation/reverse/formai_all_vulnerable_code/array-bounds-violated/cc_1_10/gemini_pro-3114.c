//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[50];
    double balance;
} account;

int main() {
    // Declare an array of accounts
    account accounts[100];

    // Initialize the accounts
    for (int i = 0; i < 100; i++) {
        accounts[i].account_number = i + 1;
        sprintf(accounts[i].name, "Customer %d", i + 1);
        accounts[i].balance = 1000.00;
    }

    // Declare some variables
    int account_number;
    char name[50];
    double amount;
    int choice;

    // Get the account number
    printf("Enter the account number: ");
    scanf("%d", &account_number);

    // Get the name
    printf("Enter the name: ");
    scanf(" %s", name);

    // Get the amount
    printf("Enter the amount: ");
    scanf("%lf", &amount);

    // Get the choice
    printf("Enter the choice (1 for deposit, 2 for withdrawal): ");
    scanf("%d", &choice);

    // Perform the transaction
    switch (choice) {
        case 1:
            // Deposit the amount
            accounts[account_number - 1].balance += amount;
            break;
        case 2:
            // Withdraw the amount
            accounts[account_number - 1].balance -= amount;
            break;
        default:
            // Invalid choice
            printf("Invalid choice\n");
            break;
    }

    // Print the new balance
    printf("The new balance is: %.2lf\n", accounts[account_number - 1].balance);

    return 0;
}