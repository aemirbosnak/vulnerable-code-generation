//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define INITIAL_BALANCE 1000.0

typedef struct {
    char owner[NAME_LENGTH];
    int accountNumber;
    double balance;
    int isActive;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    newAccount.balance = INITIAL_BALANCE;
    newAccount.isActive = 1;

    printf("Enter account owner's name: ");
    scanf(" %[^\n]", newAccount.owner);

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created! Your account number is %d\n", newAccount.accountNumber);
}

void displayAccount(int accountNumber) {
    if (accountNumber < 1 || accountNumber > accountCount || !accounts[accountNumber - 1].isActive) {
        printf("Error: Account not found or inactive.\n");
        return;
    }

    Account acc = accounts[accountNumber - 1];
    printf("Account Owner: %s\n", acc.owner);
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Balance: %.2f\n", acc.balance);
}

void deposit(int accountNumber, double amount) {
    if (accountNumber < 1 || accountNumber > accountCount || !accounts[accountNumber - 1].isActive) {
        printf("Error: Account not found or inactive.\n");
        return;
    }

    if (amount <= 0) {
        printf("Error: Deposit amount must be positive.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Deposited %.2f to account %d. New balance: %.2f\n",
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdraw(int accountNumber, double amount) {
    if (accountNumber < 1 || accountNumber > accountCount || !accounts[accountNumber - 1].isActive) {
        printf("Error: Account not found or inactive.\n");
        return;
    }

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be positive.\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Error: Insufficient funds.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrew %.2f from account %d. New balance: %.2f\n",
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void deactivateAccount(int accountNumber) {
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Error: Account not found.\n");
        return;
    }

    accounts[accountNumber - 1].isActive = 0;
    printf("Account %d has been deactivated.\n", accountNumber);
}

void displayAllAccounts() {
    printf("--------------------------------------------------\n");
    printf("Active Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].isActive) {
            printf("Account Owner: %s, Account Number: %d, Balance: %.2f\n",
                   accounts[i].owner, accounts[i].accountNumber, accounts[i].balance);
        }
    }
    printf("--------------------------------------------------\n");
}

int main() {
    int choice, accountNumber;
    double amount;

    while (1) {
        printf("\nPost-Apocalyptic Banking System\n");
        printf("1. Create Account\n");
        printf("2. Display Account\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Deactivate Account\n");
        printf("6. Display All Accounts\n");
        printf("7. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter account number to display: ");
                scanf("%d", &accountNumber);
                displayAccount(accountNumber);
                break;
            case 3:
                printf("Enter account number to deposit funds: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to deposit: ");
                scanf("%lf", &amount);
                deposit(accountNumber, amount);
                break;
            case 4:
                printf("Enter account number to withdraw funds: ");
                scanf("%d", &accountNumber);
                printf("Enter amount to withdraw: ");
                scanf("%lf", &amount);
                withdraw(accountNumber, amount);
                break;
            case 5:
                printf("Enter account number to deactivate: ");
                scanf("%d", &accountNumber);
                deactivateAccount(accountNumber);
                break;
            case 6:
                displayAllAccounts();
                break;
            case 7:
                printf("Exiting the system. Stay safe!\n");
                exit(0);
            default:
                printf("Error: Invalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}