//FormAI DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of accounts that can be stored in the system
#define MAX_ACCOUNTS 100

// Define the structure of a bank account
typedef struct {
    int account_number;
    char name[50];
    double balance;
} Account;

// Define global variables
Account accounts[MAX_ACCOUNTS];
int num_accounts = 0;

// Define function prototypes
void create_account();
void deposit(int account_number);
void withdraw(int account_number);
void display_account(int account_number);
void display_all_accounts();

int main() {
    int choice = 0;
    int account_number = 0;

    printf("Welcome to the C Banking Record System.\n");

    do {
        printf("Please choose an option:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Create Account
                create_account();
                break;
            case 2: // Deposit
                printf("Please enter the account number: ");
                scanf("%d", &account_number);
                deposit(account_number);
                break;
            case 3: // Withdraw
                printf("Please enter the account number: ");
                scanf("%d", &account_number);
                withdraw(account_number);
                break;
            case 4: // Display Account
                printf("Please enter the account number: ");
                scanf("%d", &account_number);
                display_account(account_number);
                break;
            case 5: // Display All Accounts
                display_all_accounts();
                break;
            case 6: // Exit
                printf("Thank you for using the C Banking Record System.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

void create_account() {
    if (num_accounts >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached. Cannot create a new account.\n");
        return;
    }

    Account account;

    printf("Please enter the account number: ");
    scanf("%d", &account.account_number);

    // Check if an account with the same account number already exists
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account.account_number) {
            printf("An account with the same account number already exists. Please try again.\n");
            return;
        }
    }

    printf("Please enter the name of the account holder: ");
    scanf("%s", account.name);

    printf("Please enter the initial balance: ");
    scanf("%lf", &account.balance);

    accounts[num_accounts++] = account;

    printf("Account created successfully.\n");
}

void deposit(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            double amount;
            printf("Please enter the amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful. New balance for account %d is %.2lf.\n", account_number, accounts[i].balance);
            return;
        }
    }
    printf("Account %d not found. Deposit failed.\n", account_number);
}

void withdraw(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            double amount;
            printf("Please enter the amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient funds. Withdrawal failed.\n");
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrawal successful. New balance for account %d is %.2lf.\n", account_number, accounts[i].balance);
            return;
        }
    }
    printf("Account %d not found. Withdrawal failed.\n", account_number);
}

void display_account(int account_number) {
    for (int i = 0; i < num_accounts; i++) {
        if (accounts[i].account_number == account_number) {
            printf("Account Number: %d\n", accounts[i].account_number);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Balance: %.2lf\n", accounts[i].balance);
            return;
        }
    }
    printf("Account %d not found. Cannot display account information.\n", account_number);
}

void display_all_accounts() {
    if (num_accounts == 0) {
        printf("No accounts found.\n");
        return;
    }

    printf("%-20s%-20s%-20s\n", "Account Number", "Account Holder", "Account Balance");
    for (int i = 0; i < num_accounts; i++) {
        printf("%-20d%-20s%-20.2lf\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}