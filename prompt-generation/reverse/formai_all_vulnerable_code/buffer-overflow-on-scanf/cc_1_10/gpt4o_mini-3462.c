//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.accountHolder);
    newAccount.balance = 0.0f;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Deposited %.2f to account number %d. New Balance: %.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Amount must be greater than zero.\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient balance!\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrew %.2f from account number %d. New Balance: %.2f\n", amount, accountNumber, accounts[accountNumber - 1].balance);
}

void showAccountDetails() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    Account acc = accounts[accountNumber - 1];
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder: %s\n", acc.accountHolder);
    printf("Current Balance: %.2f\n", acc.balance);
}

void displayAllAccounts() {
    printf("List of all accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Holder: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
}

int main() {
    int choice;

    while (1) {
        printf("\n=== Banking Record System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Show Account Details\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                showAccountDetails();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Exiting the system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}