//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a bank account
typedef struct {
    int account_number;
    char account_holder_name[50];
    float balance;
} Account;

// Function to create a new account
void create_account(Account *account) {
    printf("Enter account holder name: ");
    scanf("%s", account->account_holder_name);

    printf("Enter account number: ");
    scanf("%d", &account->account_number);

    printf("Enter initial balance: ");
    scanf("%f", &account->balance);
}

// Function to deposit money into an account
void deposit_money(Account *account, float amount) {
    account->balance += amount;
    printf("Deposit of %.2f successfully made.\n", amount);
    printf("Current balance: %.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw_money(Account *account, float amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal of %.2f successfully made.\n", amount);
        printf("Current balance: %.2f\n", account->balance);
    } else {
        printf("Insufficient balance.\n");
    }
}

// Function to check account balance
void check_balance(Account *account) {
    printf("Current balance: %.2f\n", account->balance);
}

// Function to close an account
void close_account(Account *account) {
    printf("Account closed successfully.\n");
}

int main() {
    Account my_account;

    // Create a new account
    create_account(&my_account);

    // Deposit some money
    deposit_money(&my_account, 1000);

    // Withdraw some money
    withdraw_money(&my_account, 500);

    // Check balance
    check_balance(&my_account);

    // Close account
    close_account(&my_account);

    return 0;
}