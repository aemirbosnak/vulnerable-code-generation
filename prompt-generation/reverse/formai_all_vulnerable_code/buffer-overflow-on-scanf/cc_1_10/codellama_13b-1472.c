//Code Llama-13B DATASET v1.0 Category: Banking Record System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Struct for bank account
typedef struct {
    char name[50];
    int account_number;
    float balance;
} Account;

// Function to create a new account
void create_account(Account *account) {
    printf("Enter your name: ");
    scanf("%s", account->name);
    account->account_number = rand();
    account->balance = 0.0;
}

// Function to deposit money into an account
void deposit(Account *account, float amount) {
    account->balance += amount;
    printf("Deposited %0.2f into account %d.\n", amount, account->account_number);
}

// Function to withdraw money from an account
void withdraw(Account *account, float amount) {
    if (amount > account->balance) {
        printf("Insufficient funds.\n");
        return;
    }
    account->balance -= amount;
    printf("Withdrew %0.2f from account %d.\n", amount, account->account_number);
}

// Function to display account information
void display_account(Account *account) {
    printf("Name: %s\n", account->name);
    printf("Account number: %d\n", account->account_number);
    printf("Balance: %0.2f\n", account->balance);
}

int main() {
    srand(time(NULL));

    // Create a new account
    Account account;
    create_account(&account);

    // Deposit money into the account
    deposit(&account, 100.00);

    // Withdraw money from the account
    withdraw(&account, 50.00);

    // Display account information
    display_account(&account);

    return 0;
}