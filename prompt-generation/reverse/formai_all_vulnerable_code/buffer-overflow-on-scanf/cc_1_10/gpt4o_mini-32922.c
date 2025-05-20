//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define INITIAL_BALANCE 0.0

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    BankAccount newAccount;
    newAccount.accountNumber = accountCount + 1;
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = INITIAL_BALANCE;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Error: Account number does not exist.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Error: Deposit amount must be greater than zero.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f into account %d. New balance: %.2f\n",
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void withdraw() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Error: Account number does not exist.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Error: Withdrawal amount must be greater than zero.\n");
        return;
    } else if (amount > accounts[accountNumber - 1].balance) {
        printf("Error: Insufficient funds in account %d.\n", accountNumber);
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account %d. New balance: %.2f\n",
           amount, accountNumber, accounts[accountNumber - 1].balance);
}

void displayAccounts() {
    printf("\nAccounts Summary:\n");
    printf("-------------------------------------------------\n");
    printf("Account Number | Name                      | Balance\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < accountCount; i++) {
        printf("%-15d | %-24s | %.2f\n",
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    printf("-------------------------------------------------\n");
}

int main() {
    int choice;

    while (1) {
        printf("\nBanking System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                displayAccounts();
                break;
            case 5:
                printf("Exiting the system...\n");
                exit(0);
            default:
                printf("Error: Invalid choice, please try again.\n");
        }
    }

    return 0;
}