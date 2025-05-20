//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Database of accounts
struct account {
    int account_number;
    char name[50];
    double balance;
};

// Function to create a new account
void create_account(struct account *accounts, int *num_accounts) {
    // Get the account details from the user
    printf("Creating a new account!\n");
    printf("Enter your name: ");
    scanf(" %[^\n]", accounts[*num_accounts].name);
    printf("Enter your account number: ");
    scanf(" %d", &accounts[*num_accounts].account_number);
    printf("Enter your initial balance: ");
    scanf(" %lf", &accounts[*num_accounts].balance);

    // Increment the number of accounts
    (*num_accounts)++;
}

// Function to deposit money into an account
void deposit(struct account *accounts, int num_accounts) {
    // Get the account number and the amount to deposit
    int account_number;
    double amount;
    printf("Depositing money!\n");
    printf("Enter your account number: ");
    scanf(" %d", &account_number);
    printf("Enter the amount to deposit: ");
    scanf(" %lf", &amount);

    // Find the account with the given account number
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            break;
        }
    }

    // If the account was found, add the amount to the balance
    if (i < num_accounts) {
        accounts[i].balance += amount;
        printf("Successfully deposited %lf into your account!\n", amount);
    } else {
        printf("Account not found!\n");
    }
}

// Function to withdraw money from an account
void withdraw(struct account *accounts, int num_accounts) {
    // Get the account number and the amount to withdraw
    int account_number;
    double amount;
    printf("Withdrawing money!\n");
    printf("Enter your account number: ");
    scanf(" %d", &account_number);
    printf("Enter the amount to withdraw: ");
    scanf(" %lf", &amount);

    // Find the account with the given account number
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            break;
        }
    }

    // If the account was found, withdraw the amount from the balance
    if (i < num_accounts) {
        if (accounts[i].balance >= amount) {
            accounts[i].balance -= amount;
            printf("Successfully withdrew %lf from your account!\n", amount);
        } else {
            printf("Insufficient funds!\n");
        }
    } else {
        printf("Account not found!\n");
    }
}

// Function to display the balance of an account
void balance(struct account *accounts, int num_accounts) {
    // Get the account number
    int account_number;
    printf("Checking your balance!\n");
    printf("Enter your account number: ");
    scanf(" %d", &account_number);

    // Find the account with the given account number
    int i;
    for (i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            break;
        }
    }

    // If the account was found, display the balance
    if (i < num_accounts) {
        printf("Your balance is: %lf\n", accounts[i].balance);
    } else {
        printf("Account not found!\n");
    }
}

// Main function
int main() {
    // Array of accounts
    struct account accounts[100];

    // Number of accounts
    int num_accounts = 0;

    // Create a new account
    create_account(accounts, &num_accounts);

    // Deposit money into the account
    deposit(accounts, num_accounts);

    // Withdraw money from the account
    withdraw(accounts, num_accounts);

    // Display the balance of the account
    balance(accounts, num_accounts);

    return 0;
}