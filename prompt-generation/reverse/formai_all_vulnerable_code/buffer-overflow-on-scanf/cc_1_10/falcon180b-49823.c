//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for bank account
typedef struct {
    int account_number;
    char name[50];
    float balance;
} account;

// Function to create a new account
void create_account(account *new_account) {
    printf("Enter account holder's name: ");
    scanf("%s", new_account->name);
    new_account->account_number = rand() % 100000;
    new_account->balance = 0.0;
    printf("Account created with account number %d\n", new_account->account_number);
}

// Function to deposit money into an account
void deposit_money(account *account_to_deposit, float amount) {
    account_to_deposit->balance += amount;
    printf("Deposit of $%.2f made to account %d\n", amount, account_to_deposit->account_number);
}

// Function to withdraw money from an account
void withdraw_money(account *account_to_withdraw, float amount) {
    if (account_to_withdraw->balance >= amount) {
        account_to_withdraw->balance -= amount;
        printf("Withdrawal of $%.2f made from account %d\n", amount, account_to_withdraw->account_number);
    } else {
        printf("Insufficient funds in account %d\n", account_to_withdraw->account_number);
    }
}

// Function to check balance of an account
void check_balance(account *account_to_check) {
    printf("Current balance in account %d is $%.2f\n", account_to_check->account_number, account_to_check->balance);
}

// Function to close an account
void close_account(account *account_to_close) {
    printf("Account %d closed\n", account_to_close->account_number);
}

// Main function
int main() {
    account my_account;
    int choice;
    char option;

    do {
        printf("Enter 'c' to create account, 'd' to deposit, 'w' to withdraw, 'b' to check balance, 'x' to close account, or 'q' to quit\n");
        scanf("%c", &option);

        switch (option) {
        case 'c':
            create_account(&my_account);
            break;
        case 'd':
            printf("Enter account number to deposit into: ");
            scanf("%d", &choice);
            deposit_money(&my_account, 50.00);
            break;
        case 'w':
            printf("Enter account number to withdraw from: ");
            scanf("%d", &choice);
            withdraw_money(&my_account, 25.00);
            break;
        case 'b':
            check_balance(&my_account);
            break;
        case 'x':
            close_account(&my_account);
            break;
        case 'q':
            printf("Exiting program...\n");
            break;
        default:
            printf("Invalid option\n");
        }
    } while (option!= 'q');

    return 0;
}