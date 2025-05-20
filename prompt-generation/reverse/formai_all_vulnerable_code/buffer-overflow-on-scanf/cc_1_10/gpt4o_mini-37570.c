//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LEN 50

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LEN];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void clearBuffer() {
    while (getchar() != '\n'); // Clear input buffer
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached! Cannot create more accounts.\n");
        return;
    }

    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple incremental account numbers
    printf("Enter account holder's name: ");
    fgets(newAccount.accountHolder, NAME_LEN, stdin);
    newAccount.accountHolder[strcspn(newAccount.accountHolder, "\n")] = 0; // Remove newline character

    newAccount.balance = 0.0; // Starting balance is zero

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account created successfully! Your account number is %d\n", newAccount.accountNumber);
}

void viewAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n--- Accounts List ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder: %s\n", accounts[i].accountHolder);
        printf("Balance: %.2f\n\n", accounts[i].balance);
    }
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number to deposit to: ");
    scanf("%d", &accountNumber);
    clearBuffer();

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    clearBuffer();

    if (amount < 0) {
        printf("Amount should be positive!\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f into account number %d\n", amount, accountNumber);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number to withdraw from: ");
    scanf("%d", &accountNumber);
    clearBuffer();

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    clearBuffer();

    if (amount < 0) {
        printf("Amount should be positive!\n");
        return;
    }

    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient funds! Current balance is %.2f\n", accounts[accountNumber - 1].balance);
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account number %d\n", amount, accountNumber);
}

void balanceInquiry() {
    int accountNumber;

    printf("Enter account number to check balance: ");
    scanf("%d", &accountNumber);
    clearBuffer();

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number!\n");
        return;
    }

    printf("Current balance for account number %d is %.2f\n", accountNumber, accounts[accountNumber - 1].balance);
}

void showMenu() {
    printf("\n--- C Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. View Accounts\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Balance Inquiry\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice;

    while (1) {
        showMenu();
        scanf("%d", &choice);
        clearBuffer();

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                balanceInquiry();
                break;
            case 6:
                printf("Thank you for using the C Banking Record System! Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}