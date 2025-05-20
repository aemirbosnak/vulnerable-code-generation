//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: systematic
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

void createAccount();
void displayAccounts();
void deposit();
void withdraw();
void deleteAccount();

int main() {
    int choice;

    while (1) {
        printf("\n==== Banking Record System ====\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Delete Account\n");
        printf("6. Exit\n");
        printf("==============================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                deleteAccount();
                break;
            case 6:
                printf("Exiting the system. Bye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    }
    return 0;
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1;

    printf("Enter account holder name: ");
    getchar(); // consume leftover newline character
    fgets(newAccount.accountHolder, NAME_LENGTH, stdin);
    newAccount.accountHolder[strcspn(newAccount.accountHolder, "\n")] = 0; // remove newline

    newAccount.balance = 0.0;
    accounts[accountCount++] = newAccount;

    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n==== List of Accounts ====\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder: %s\n", accounts[i].accountHolder);
        printf("Balance: %.2f\n", accounts[i].balance);
        printf("==========================\n");
    }
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number to deposit into: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f into Account Number %d.\n", amount, accountNumber);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number to withdraw from: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount! Please enter a positive value.\n");
        return;
    }

    if (accounts[accountNumber - 1].balance < amount) {
        printf("Insufficient balance!\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f from Account Number %d.\n", amount, accountNumber);
}

void deleteAccount() {
    int accountNumber;

    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }
    
    for (int i = accountNumber - 1; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1];
    }

    accountCount--;
    printf("Account Number %d has been deleted successfully.\n", accountNumber);
}