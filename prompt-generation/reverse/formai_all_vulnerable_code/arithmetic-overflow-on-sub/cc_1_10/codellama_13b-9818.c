//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: authentic
/*
 * Banking Record System
 *
 * This program allows users to interact with a banking system
 * and perform various actions such as depositing, withdrawing,
 * and checking the balance of their accounts.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store bank account information
struct account {
    char name[256];
    char account_number[256];
    int balance;
};

// Function to deposit money into an account
void deposit(struct account *account, int amount) {
    account->balance += amount;
    printf("Deposited %d into account %s\n", amount, account->account_number);
}

// Function to withdraw money from an account
void withdraw(struct account *account, int amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrew %d from account %s\n", amount, account->account_number);
    } else {
        printf("Insufficient funds in account %s\n", account->account_number);
    }
}

// Function to check the balance of an account
void check_balance(struct account *account) {
    printf("Balance of account %s is %d\n", account->account_number, account->balance);
}

// Main function to handle user input and perform actions
int main() {
    struct account accounts[5];
    char command;
    int amount;

    // Initialize the accounts
    for (int i = 0; i < 5; i++) {
        strcpy(accounts[i].name, "User");
        strcpy(accounts[i].account_number, "1234567890");
        accounts[i].balance = 0;
    }

    // Prompt the user to enter a command
    printf("Enter a command (d/w/b): ");
    scanf("%c", &command);

    // If the command is 'd', deposit money into the account
    if (command == 'd') {
        printf("Enter the amount to deposit: ");
        scanf("%d", &amount);
        deposit(&accounts[0], amount);
    }

    // If the command is 'w', withdraw money from the account
    if (command == 'w') {
        printf("Enter the amount to withdraw: ");
        scanf("%d", &amount);
        withdraw(&accounts[0], amount);
    }

    // If the command is 'b', check the balance of the account
    if (command == 'b') {
        check_balance(&accounts[0]);
    }

    return 0;
}