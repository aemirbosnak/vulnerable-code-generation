//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum accounts reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1;

    printf("Enter name for Account %d: ", newAccount.accountNumber);
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0; // Initialize balance to 0

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully. Account Number: %d\n", newAccount.accountNumber);
}

void displayAccount(int accountNumber) {
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    Account account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Balance: %.2f\n", account.balance);
}

void deposit(int accountNumber) {
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Amount %.2f deposited. New balance: %.2f\n", amount, accounts[accountNumber - 1].balance);
}

void withdraw(int accountNumber) {
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        return;
    }
    
    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient funds.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Amount %.2f withdrawn. New balance: %.2f\n", amount, accounts[accountNumber - 1].balance);
}

void showMenu() {
    printf("\n--- Banking Menu ---\n");
    printf("1. Create Account\n");
    printf("2. Display Account\n");
    printf("3. Deposit Amount\n");
    printf("4. Withdraw Amount\n");
    printf("5. Exit\n");
}

int main() {
    int choice, accountNumber;

    while (1) {
        showMenu();
        printf("Enter your choice: ");
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
                printf("Enter account number to deposit: ");
                scanf("%d", &accountNumber);
                deposit(accountNumber);
                break;
            case 4:
                printf("Enter account number to withdraw: ");
                scanf("%d", &accountNumber);
                withdraw(accountNumber);
                break;
            case 5:
                printf("Exiting system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}