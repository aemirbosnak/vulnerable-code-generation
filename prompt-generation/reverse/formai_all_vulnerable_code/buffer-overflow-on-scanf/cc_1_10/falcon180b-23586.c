//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a bank account
typedef struct {
    int account_number;
    char name[50];
    float balance;
} BankAccount;

// Function prototypes
void create_account(BankAccount* account);
void deposit_money(BankAccount* account, float amount);
void withdraw_money(BankAccount* account, float amount);
void display_account_info(BankAccount* account);
void close_account(BankAccount* account);

// Main function
int main() {
    BankAccount my_account;
    char choice;

    // Initialize the account
    create_account(&my_account);

    do {
        printf("\nBanking System Menu:\n");
        printf("1. Deposit Money\n");
        printf("2. Withdraw Money\n");
        printf("3. Display Account Info\n");
        printf("4. Close Account\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter the amount to deposit: ");
            scanf("%f", &my_account.balance);
            deposit_money(&my_account, my_account.balance);
            break;
        case '2':
            printf("Enter the amount to withdraw: ");
            scanf("%f", &my_account.balance);
            withdraw_money(&my_account, my_account.balance);
            break;
        case '3':
            display_account_info(&my_account);
            break;
        case '4':
            close_account(&my_account);
            break;
        case '5':
            printf("Thank you for using our banking system.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

    } while (choice!= '5');

    return 0;
}

// Function to create a new bank account
void create_account(BankAccount* account) {
    int i;
    do {
        printf("Enter a 6-digit account number: ");
        scanf("%d", &account->account_number);
        for (i = 0; i < 6; i++) {
            if (account->account_number % 10 == 0) {
                printf("Invalid account number.\n");
                break;
            }
            account->account_number /= 10;
        }
    } while (i!= 6);

    printf("Enter your name: ");
    scanf("%s", account->name);

    account->balance = 0.0;
}

// Function to deposit money into an account
void deposit_money(BankAccount* account, float amount) {
    account->balance += amount;
    printf("Deposit successful. New balance: %.2f\n", account->balance);
}

// Function to withdraw money from an account
void withdraw_money(BankAccount* account, float amount) {
    if (amount > account->balance) {
        printf("Insufficient funds.\n");
    } else {
        account->balance -= amount;
        printf("Withdrawal successful. New balance: %.2f\n", account->balance);
    }
}

// Function to display account info
void display_account_info(BankAccount* account) {
    printf("Account Number: %d\n", account->account_number);
    printf("Name: %s\n", account->name);
    printf("Balance: %.2f\n", account->balance);
}

// Function to close an account
void close_account(BankAccount* account) {
    printf("Are you sure you want to close this account? (y/n) ");
    char choice;
    scanf("%c", &choice);

    if (choice == 'y' || choice == 'Y') {
        printf("Account closed.\n");
    } else {
        printf("Account not closed.\n");
    }
}