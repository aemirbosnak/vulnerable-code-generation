//FormAI DATASET v1.0 Category: Banking Record System ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100 // Maximum number of accounts
#define MAX_NAME_LEN 50 // Maximum length of account holder's name

typedef struct {
    int account_number;
    char name[MAX_NAME_LEN];
    double balance;
} Account; // Define the Account struct

Account accounts[MAX_ACCOUNTS]; // Create an array of Accounts
int num_accounts = 0; // Keep track of the number of accounts in the system

// Function prototypes
void add_account();
void delete_account();
void deposit_funds();
void withdraw_funds();
void display_accounts();

int main(void) {
    int choice;

    do {
        printf("\n1. Add account\n");
        printf("2. Delete account\n");
        printf("3. Deposit funds\n");
        printf("4. Withdraw funds\n");
        printf("5. Display accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_account();
                break;
            case 2:
                delete_account();
                break;
            case 3:
                deposit_funds();
                break;
            case 4:
                withdraw_funds();
                break;
            case 5:
                display_accounts();
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}

// Add a new account to the system
void add_account() {
    Account acct;

    if (num_accounts == MAX_ACCOUNTS) {
        printf("Error: Account limit reached. No new accounts can be added.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &acct.account_number);

    // Check if account number is already in use
    for (int i = 0; i < num_accounts; i++) {
        if (acct.account_number == accounts[i].account_number) {
            printf("Error: Account number already in use. Please try again.\n");
            return;
        }
    }

    printf("Enter account holder's name: ");
    scanf("%s", acct.name);

    printf("Enter initial balance: ");
    scanf("%lf", &acct.balance);

    accounts[num_accounts] = acct;
    num_accounts++;

    printf("Account added successfully.\n");
}

// Delete an existing account from the system
void delete_account() {
    int acct_num, found = 0;

    printf("Enter account number to delete: ");
    scanf("%d", &acct_num);

    for (int i = 0; i < num_accounts; i++) {
        if (acct_num == accounts[i].account_number) {
            // Shift all accounts after the deleted account back by one
            for (int j = i; j < num_accounts - 1; j++) {
                accounts[j] = accounts[j+1];
            }
            num_accounts--;
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("Account deleted successfully.\n");
    } else {
        printf("Error: Account number not found. Please try again.\n");
    }
}

// Deposit funds into an account
void deposit_funds() {
    int acct_num, found = 0;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &acct_num);

    for (int i = 0; i < num_accounts; i++) {
        if (acct_num == accounts[i].account_number) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            accounts[i].balance += amount;
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("Funds deposited successfully.\n");
    } else {
        printf("Error: Account number not found. Please try again.\n");
    }
}

// Withdraw funds from an account
void withdraw_funds() {
    int acct_num, found = 0;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &acct_num);

    for (int i = 0; i < num_accounts; i++) {
        if (acct_num == accounts[i].account_number) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount > accounts[i].balance) {
                printf("Error: Insufficient funds.\n");
                return;
            }
            accounts[i].balance -= amount;
            found = 1;
            break;
        }
    }

    if (found == 1) {
        printf("Funds withdrawn successfully.\n");
    } else {
        printf("Error: Account number not found. Please try again.\n");
    }
}

// Display all accounts in the system
void display_accounts() {
    printf("%-10s%-20s%s\n", "Account", "Name", "Balance");
    for (int i = 0; i < num_accounts; i++) {
        printf("%-10d%-20s%.2f\n", accounts[i].account_number, accounts[i].name, accounts[i].balance);
    }
}