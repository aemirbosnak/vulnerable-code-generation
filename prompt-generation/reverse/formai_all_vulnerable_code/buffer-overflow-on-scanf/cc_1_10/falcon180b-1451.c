//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bank account
typedef struct {
    int account_number;
    char name[50];
    float balance;
} account;

// Function to create a new account
void create_account(account* new_account) {
    printf("Enter account number: ");
    scanf("%d", &new_account->account_number);
    printf("Enter name: ");
    scanf("%s", new_account->name);
    new_account->balance = 0;
}

// Function to display account information
void display_account(account account) {
    printf("Account Number: %d\n", account.account_number);
    printf("Name: %s\n", account.name);
    printf("Balance: $%.2f\n", account.balance);
}

// Function to deposit money into an account
void deposit_money(account* account, float amount) {
    account->balance += amount;
    printf("Deposit successful! New balance: $%.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw_money(account* account, float amount) {
    if(account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal successful! New balance: $%.2f\n", account->balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

// Function to transfer money between two accounts
void transfer_money(account* from_account, account* to_account, float amount) {
    if(from_account->balance >= amount) {
        from_account->balance -= amount;
        to_account->balance += amount;
        printf("Transfer successful! New balance for account %d: $%.2f\n", from_account->account_number, from_account->balance);
        printf("New balance for account %d: $%.2f\n", to_account->account_number, to_account->balance);
    } else {
        printf("Insufficient funds.\n");
    }
}

int main() {
    account account1, account2;

    // Create new accounts
    create_account(&account1);
    create_account(&account2);

    // Deposit money into account 1
    deposit_money(&account1, 1000);

    // Withdraw money from account 1
    withdraw_money(&account1, 500);

    // Transfer money from account 1 to account 2
    transfer_money(&account1, &account2, 200);

    // Display account information
    display_account(account1);
    display_account(account2);

    return 0;
}