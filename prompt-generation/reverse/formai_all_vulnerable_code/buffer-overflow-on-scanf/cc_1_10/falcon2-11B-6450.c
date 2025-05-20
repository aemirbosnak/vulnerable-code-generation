//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: recursive
#include <stdio.h>

// Function to deposit money in a bank account
void deposit(int account_number, int amount) {
    printf("Depositing %d into account %d\n", amount, account_number);
    // Deposit the amount into the account
    int balance = 100; // Initial balance
    balance += amount;
    printf("New balance: %d\n", balance);
}

// Function to withdraw money from a bank account
void withdraw(int account_number, int amount) {
    printf("Withdrawing %d from account %d\n", amount, account_number);
    // Withdraw the amount from the account
    int balance = 100; // Initial balance
    balance -= amount;
    printf("New balance: %d\n", balance);
}

// Function to check account balance
int check_balance(int account_number) {
    printf("Checking balance for account %d\n", account_number);
    int balance = 100; // Initial balance
    return balance;
}

// Main program
int main() {
    int account_number = 123; // Account number
    int amount = 100; // Amount to deposit or withdraw
    int balance;

    printf("Welcome to the C Banking Record System!\n");
    printf("Please enter an action: \n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Exit\n");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            deposit(account_number, amount);
            break;
        case 2:
            withdraw(account_number, amount);
            break;
        case 3:
            balance = check_balance(account_number);
            printf("Balance: %d\n", balance);
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}