//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

typedef struct BankAccount {
    int accountNumber;
    char accountHolderName[50];
    double accountBalance;
} BankAccount;

int main() {
    // Create an array of 10 bank accounts
    BankAccount accounts[10];

    // Initialize the accounts with some sample data
    for (int i = 0; i < 10; i++) {
        accounts[i].accountNumber = 1000 + i;
        sprintf(accounts[i].accountHolderName, "Account Holder %d", i + 1);
        accounts[i].accountBalance = 1000.0 * (i + 1);
    }

    // Display the account details
    printf("Account Details:\n");
    for (int i = 0; i < 10; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder Name: %s\n", accounts[i].accountHolderName);
        printf("Account Balance: %.2f\n\n", accounts[i].accountBalance);
    }

    // Prompt the user to enter an account number
    int accountNumber;
    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    // Find the account in the array
    int accountIndex = -1;
    for (int i = 0; i < 10; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            accountIndex = i;
            break;
        }
    }

    // If the account was not found, display an error message
    if (accountIndex == -1) {
        printf("Account not found!\n");
    } else {
        // Display the account details
        printf("Account Details:\n");
        printf("Account Number: %d\n", accounts[accountIndex].accountNumber);
        printf("Account Holder Name: %s\n", accounts[accountIndex].accountHolderName);
        printf("Account Balance: %.2f\n", accounts[accountIndex].accountBalance);

        // Prompt the user to enter the amount to withdraw
        double amount;
        printf("Enter the amount to withdraw: ");
        scanf("%lf", &amount);

        // Withdraw the amount from the account
        if (amount <= accounts[accountIndex].accountBalance) {
            accounts[accountIndex].accountBalance -= amount;
            printf("Withdrawal successful!\n");
        } else {
            printf("Insufficient funds!\n");
        }

        // Display the updated account balance
        printf("Account Balance: %.2f\n", accounts[accountIndex].accountBalance);
    }

    return 0;
}