//GPT-4o-mini DATASET v1.0 Category: Educational ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 30

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number auto-increment
    printf("Enter the name for the account holder: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0; // Starting balance
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accountNumber;
    double amount;
    printf("Enter the account number to deposit to: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Enter amount to deposit: ");
    scanf("%lf", &amount);
    if (amount <= 0) {
        printf("Invalid amount. Deposit failed.\n");
        return;
    }
    accounts[accountNumber - 1].balance += amount;
    printf("Successfully deposited %.2f into account number %d.\n", amount, accountNumber);
}

void withdraw() {
    int accountNumber;
    double amount;
    printf("Enter the account number to withdraw from: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount);
    if (amount <= 0 || amount > accounts[accountNumber - 1].balance) {
        printf("Invalid amount or insufficient funds. Withdrawal failed.\n");
        return;
    }
    accounts[accountNumber - 1].balance -= amount;
    printf("Successfully withdrew %.2f from account number %d.\n", amount, accountNumber);
}

void displayAccount() {
    int accountNumber;
    printf("Enter the account number to display: ");
    scanf("%d", &accountNumber);
    if (accountNumber <= 0 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    Account acc = accounts[accountNumber - 1];
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Account Holder Name: %s\n", acc.name);
    printf("Available Balance: %.2f\n", acc.balance);
}

void displayAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    for (int i = 0; i < accountCount; i++) {
        Account acc = accounts[i];
        printf("\nAccount Number: %d\n", acc.accountNumber);
        printf("Account Holder Name: %s\n", acc.name);
        printf("Available Balance: %.2f\n", acc.balance);
    }
}

int main() {
    int choice;
    do {
        printf("\n--- Simple Banking System ---\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Display Account\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");
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
                displayAccount();
                break;
            case 5:
                displayAllAccounts();
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);
    return 0;
}