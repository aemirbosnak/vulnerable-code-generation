//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a bank account
typedef struct {
    char name[50];
    int account_number;
    double balance;
} Account;

// Function to create a new account
void create_account(Account* account) {
    printf("Enter your name: ");
    scanf("%s", account->name);
    printf("Enter your account number: ");
    scanf("%d", &account->account_number);
    account->balance = 0.0;
    printf("Account created successfully!\n");
}

// Function to deposit money into an account
void deposit_money(Account* account) {
    printf("Enter the amount you want to deposit: ");
    scanf("%lf", &account->balance);
    printf("Deposit successful!\n");
}

// Function to withdraw money from an account
void withdraw_money(Account* account) {
    printf("Enter the amount you want to withdraw: ");
    scanf("%lf", &account->balance);
    printf("Withdrawal successful!\n");
}

// Function to check the balance of an account
void check_balance(Account* account) {
    printf("Your current balance is: $%.2lf\n", account->balance);
}

// Main function
int main() {
    Account my_account;

    // Create a new account
    create_account(&my_account);

    // Deposit some money
    deposit_money(&my_account);

    // Withdraw some money
    withdraw_money(&my_account);

    // Check the balance
    check_balance(&my_account);

    return 0;
}