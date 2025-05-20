//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts
#define MAX_ACCOUNTS 100

// Define the account structure
typedef struct {
    char name[50];
    char account_number[20];
    double balance;
} account;

// Define the function to create a new account
void create_account(account *accounts, int *num_accounts) {
    // Get the account holder's name
    printf("Enter the account holder's name: ");
    scanf("%s", accounts[*num_accounts].name);

    // Get the account number
    printf("Enter the account number: ");
    scanf("%s", accounts[*num_accounts].account_number);

    // Get the initial balance
    printf("Enter the initial balance: ");
    scanf("%lf", &accounts[*num_accounts].balance);

    // Increment the number of accounts
    (*num_accounts)++;
}

// Define the function to deposit money into an account
void deposit_money(account *accounts, int num_accounts) {
    // Get the account number
    char account_number[20];
    printf("Enter the account number: ");
    scanf("%s", account_number);

    // Find the account
    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            account_index = i;
            break;
        }
    }

    // If the account was not found, print an error message
    if (account_index == -1) {
        printf("Account not found.\n");
        return;
    }

    // Get the amount to deposit
    double amount;
    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);

    // Deposit the money
    accounts[account_index].balance += amount;

    // Print a confirmation message
    printf("Deposit successful.\n");
}

// Define the function to withdraw money from an account
void withdraw_money(account *accounts, int num_accounts) {
    // Get the account number
    char account_number[20];
    printf("Enter the account number: ");
    scanf("%s", account_number);

    // Find the account
    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            account_index = i;
            break;
        }
    }

    // If the account was not found, print an error message
    if (account_index == -1) {
        printf("Account not found.\n");
        return;
    }

    // Get the amount to withdraw
    double amount;
    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    // Withdraw the money
    accounts[account_index].balance -= amount;

    // Print a confirmation message
    printf("Withdrawal successful.\n");
}

// Define the function to print the account balance
void print_balance(account *accounts, int num_accounts) {
    // Get the account number
    char account_number[20];
    printf("Enter the account number: ");
    scanf("%s", account_number);

    // Find the account
    int account_index = -1;
    for (int i = 0; i < num_accounts; i++) {
        if (strcmp(accounts[i].account_number, account_number) == 0) {
            account_index = i;
            break;
        }
    }

    // If the account was not found, print an error message
    if (account_index == -1) {
        printf("Account not found.\n");
        return;
    }

    // Print the account balance
    printf("Account balance: %.2lf\n", accounts[account_index].balance);
}

// Define the main function
int main() {
    // Create an array of accounts
    account accounts[MAX_ACCOUNTS];

    // Initialize the number of accounts to 0
    int num_accounts = 0;

    // Create a menu-driven program to allow the user to perform various operations on the accounts
    int choice;
    do {
        // Print the menu
        printf("\n1. Create a new account\n");
        printf("2. Deposit money into an account\n");
        printf("3. Withdraw money from an account\n");
        printf("4. Print the account balance\n");
        printf("5. Quit\n");

        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the selected operation
        switch (choice) {
            case 1:
                create_account(accounts, &num_accounts);
                break;
            case 2:
                deposit_money(accounts, num_accounts);
                break;
            case 3:
                withdraw_money(accounts, num_accounts);
                break;
            case 4:
                print_balance(accounts, num_accounts);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}