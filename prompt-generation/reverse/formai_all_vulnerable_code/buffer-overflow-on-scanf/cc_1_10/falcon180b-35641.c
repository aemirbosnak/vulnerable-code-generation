//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a bank account
typedef struct {
    int account_number;
    char name[50];
    double balance;
} BankAccount;

// Function to create a new bank account
void create_account(BankAccount* account) {
    printf("Enter your name: ");
    scanf("%s", account->name);
    printf("Enter your account number: ");
    scanf("%d", &account->account_number);
    printf("Enter your initial deposit amount: ");
    scanf("%lf", &account->balance);
}

// Function to deposit money into an account
void deposit_money(BankAccount* account, double amount) {
    account->balance += amount;
    printf("Deposit of $%.2f made to account %d.\n", amount, account->account_number);
}

// Function to withdraw money from an account
void withdraw_money(BankAccount* account, double amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
        printf("Withdrawal of $%.2f made from account %d.\n", amount, account->account_number);
    } else {
        printf("Insufficient funds in account %d.\n", account->account_number);
    }
}

// Function to check the balance of an account
void check_balance(BankAccount* account) {
    printf("Current balance of account %d: $%.2f\n", account->account_number, account->balance);
}

// Main function
int main() {
    BankAccount my_account;
    create_account(&my_account);
    deposit_money(&my_account, 1000);
    check_balance(&my_account);
    withdraw_money(&my_account, 500);
    check_balance(&my_account);
    return 0;
}