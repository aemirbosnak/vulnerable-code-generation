//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: artistic
// Banking Record System
// --------------------
// This program allows users to create and manage bank accounts.
//
// Usage:
//   - Create a new account: ./bank [account name] [initial balance]
//   - Deposit money: ./bank [account name] deposit [amount]
//   - Withdraw money: ./bank [account name] withdraw [amount]
//   - Check account balance: ./bank [account name] balance
//   - Exit program: ./bank [account name] exit
//
// Example usage:
//   - Create a new account with a balance of $100: ./bank John 100
//   - Deposit $50: ./bank John deposit 50
//   - Withdraw $20: ./bank John withdraw 20
//   - Check balance: ./bank John balance
//   - Exit program: ./bank John exit
//
// Output:
//   - Account created successfully
//   - Deposit successful
//   - Withdraw successful
//   - Balance is $70
//   - Exiting program
//
// Note: This is a simplified example and does not handle errors or edge cases.
//
// Created by [Your Name]

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store account information
typedef struct {
    char name[50];
    float balance;
} Account;

// Function to create a new account
void create_account(Account* account, char* name, float initial_balance) {
    strcpy(account->name, name);
    account->balance = initial_balance;
}

// Function to deposit money into an account
void deposit(Account* account, float amount) {
    account->balance += amount;
}

// Function to withdraw money from an account
void withdraw(Account* account, float amount) {
    account->balance -= amount;
}

// Function to check the balance of an account
float balance(Account* account) {
    return account->balance;
}

// Function to exit the program
void exit_program(Account* account) {
    printf("Exiting program...\n");
    free(account);
    exit(0);
}

int main(int argc, char* argv[]) {
    // Check for valid arguments
    if (argc < 3) {
        printf("Invalid arguments.\n");
        exit(1);
    }

    // Create a new account
    Account* account = malloc(sizeof(Account));
    create_account(account, argv[1], atof(argv[2]));

    // Handle commands
    for (int i = 3; i < argc; i++) {
        char* command = argv[i];
        if (strcmp(command, "deposit") == 0) {
            float amount = atof(argv[i + 1]);
            deposit(account, amount);
            i++;
        } else if (strcmp(command, "withdraw") == 0) {
            float amount = atof(argv[i + 1]);
            withdraw(account, amount);
            i++;
        } else if (strcmp(command, "balance") == 0) {
            printf("Balance is %.2f\n", balance(account));
        } else if (strcmp(command, "exit") == 0) {
            exit_program(account);
        } else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}