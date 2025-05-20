//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    char *name;
    int account_number;
    double balance;
} account_t;

int main() {
    // Initialize the account database
    account_t accounts[] = {
        {"Alice", 123456, 1000.00},
        {"Bob", 654321, 2000.00},
        {"Carol", 987654, 3000.00}
    };
    const int num_accounts = sizeof(accounts) / sizeof(account_t);

    // Get the user's input
    char name[256];
    int account_number;
    double amount;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter your account number: ");
    scanf("%d", &account_number);
    printf("Enter the amount you want to withdraw: ");
    scanf("%lf", &amount);

    // Find the user's account
    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            account_index = i;
            break;
        }
    }

    // Check if the user's account was found
    if (account_index == -1) {
        printf("Account not found.\n");
        return 1;
    }

    // Check if the user has enough money in their account
    if (accounts[account_index].balance < amount) {
        printf("Insufficient funds.\n");
        return 1;
    }

    // Withdraw the money from the user's account
    accounts[account_index].balance -= amount;

    // Print the new balance
    printf("Your new balance is: %.2f\n", accounts[account_index].balance);

    return 0;
}