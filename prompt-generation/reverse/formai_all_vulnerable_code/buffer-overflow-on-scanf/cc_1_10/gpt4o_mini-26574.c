//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

// Structure to hold account information
typedef struct {
    int account_number;
    char name[NAME_LENGTH];
    float balance;
} Account;

// Global array of accounts
Account accounts[MAX_ACCOUNTS];
int account_count = 0;

// Function declarations
void create_account();
void deposit_money();
void withdraw_money();
void display_accounts();
void show_menu();

// Main function to drive the program
int main() {
    int choice;

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                create_account();
                break;
            case 2:
                deposit_money();
                break;
            case 3:
                withdraw_money();
                break;
            case 4:
                display_accounts();
                break;
            case 5:
                printf("Exiting the system...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display menu options
void show_menu() {
    printf("\n--- C Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Display All Accounts\n");
    printf("5. Exit\n");
}

// Function to create a new account
void create_account() {
    if (account_count >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create new account.\n");
        return;
    }
    Account new_account;
    new_account.account_number = account_count + 1;

    printf("Enter the name for account %d: ", new_account.account_number);
    scanf("%s", new_account.name);
    new_account.balance = 0.0;

    accounts[account_count] = new_account;
    account_count++;

    printf("Account created successfully! Account Number: %d\n", new_account.account_number);
}

// Function to deposit money into an account
void deposit_money() {
    int account_number;
    float amount;

    printf("Enter account number to deposit money: ");
    scanf("%d", &account_number);

    if (account_number <= 0 || account_number > account_count) {
        printf("Account does not exist!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Deposit amount must be positive!\n");
        return;
    }

    accounts[account_number - 1].balance += amount;
    printf("Successfully deposited %.2f. New balance: %.2f\n", amount, accounts[account_number - 1].balance);
}

// Function to withdraw money from an account
void withdraw_money() {
    int account_number;
    float amount;

    printf("Enter account number to withdraw money: ");
    scanf("%d", &account_number);

    if (account_number <= 0 || account_number > account_count) {
        printf("Account does not exist!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Withdrawal amount must be positive!\n");
        return;
    }

    if (accounts[account_number - 1].balance < amount) {
        printf("Insufficient balance! Current balance: %.2f\n", accounts[account_number - 1].balance);
        return;
    }

    accounts[account_number - 1].balance -= amount;
    printf("Successfully withdrew %.2f. New balance: %.2f\n", amount, accounts[account_number - 1].balance);
}

// Function to display all accounts and their balances
void display_accounts() {
    if (account_count == 0) {
        printf("No accounts available to display.\n");
        return;
    }

    printf("\n--- Account Details ---\n");
    for (int i = 0; i < account_count; i++) {
        printf("Account Number: %d\n", accounts[i].account_number);
        printf("Account Holder: %s\n", accounts[i].name);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("-----------------------\n");
    }
}