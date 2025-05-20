//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define global variables for bank account
int balance = 0;
char name[100];

// Function to deposit money into account
void deposit(int amount) {
    balance += amount;
    printf("Deposit successful! Your new balance is %d\n", balance);
}

// Function to withdraw money from account
void withdrawal(int amount) {
    if (amount > balance) {
        printf("Insufficient funds! Your current balance is %d\n", balance);
    } else {
        balance -= amount;
        printf("Withdrawal successful! Your new balance is %d\n", balance);
    }
}

// Function to check balance in account
void checkBalance() {
    printf("Your current balance is %d\n", balance);
}

// Function to manage user accounts
void manageAccounts() {
    printf("Welcome to the Bank! What would you like to do?\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. Check Balance\n");
    printf("4. Manage Accounts\n");
    printf("5. Exit\n");

    char choice;
    scanf("%c", &choice);

    switch (choice) {
        case '1':
            deposit(100);
            break;
        case '2':
            withdrawal(50);
            break;
        case '3':
            checkBalance();
            break;
        case '4':
            manageAccounts();
            break;
        case '5':
            exit(0);
        default:
            printf("Invalid option!\n");
            break;
    }
}

int main() {
    // Initialize variables
    deposit(500);
    manageAccounts();

    return 0;
}