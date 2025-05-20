//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    BankAccount newAccount;
    newAccount.accountNumber = accountCount + 1; // Account number starts from 1
    printf("Enter account holder's name: ");
    scanf(" %[^\n]s", newAccount.accountHolder); // Read string with spaces
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void viewAccountDetails() {
    int accountNumber;
    printf("Enter account number to view details: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    BankAccount account = accounts[accountNumber - 1];
    printf("Account Number: %d\n", account.accountNumber);
    printf("Account Holder: %s\n", account.accountHolder);
    printf("Balance: $%.2f\n", account.balance);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number to deposit money: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited $%.2f to account number %d. New Balance: $%.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number to withdraw money: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid withdrawal amount.\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient funds. Current balance: $%.2f\n", accounts[accountNumber - 1].balance);
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew $%.2f from account number %d. New Balance: $%.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void displayMenu() {
    printf("\n--- Banking System Menu ---\n");
    printf("1. Create Account\n");
    printf("2. View Account Details\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: createAccount(); break;
            case 2: viewAccountDetails(); break;
            case 3: depositMoney(); break;
            case 4: withdrawMoney(); break;
            case 5: exit(0);
            default: printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}