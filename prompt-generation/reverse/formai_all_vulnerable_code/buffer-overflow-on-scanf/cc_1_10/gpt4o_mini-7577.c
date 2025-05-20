//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define TRANSACTION_HISTORY_LENGTH 10

typedef struct {
    char name[NAME_LENGTH];
    float balance;
    char transactionHistory[TRANSACTION_HISTORY_LENGTH][100];
    int transactionCount;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts, limit reached!\n");
        return;
    }

    Account newAccount;
    printf("Enter the name for the new account: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0;
    newAccount.transactionCount = 0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully!\n");
}

void deposit(int accountIndex) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    if (amount <= 0) {
        printf("Invalid amount!\n");
        return;
    }

    accounts[accountIndex].balance += amount;
    snprintf(accounts[accountIndex].transactionHistory[accounts[accountIndex].transactionCount], 100, 
             "Deposited: $%.2f", amount);
    accounts[accountIndex].transactionCount++;

    printf("Deposit successful! New balance: $%.2f\n", accounts[accountIndex].balance);
}

void withdraw(int accountIndex) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount <= 0 || amount > accounts[accountIndex].balance) {
        printf("Invalid amount or insufficient balance!\n");
        return;
    }

    accounts[accountIndex].balance -= amount;
    snprintf(accounts[accountIndex].transactionHistory[accounts[accountIndex].transactionCount], 100, 
             "Withdrew: $%.2f", amount);
    accounts[accountIndex].transactionCount++;

    printf("Withdrawal successful! New balance: $%.2f\n", accounts[accountIndex].balance);
}

void viewTransactions(int accountIndex) {
    printf("Transaction history for %s:\n", accounts[accountIndex].name);
    for (int i = 0; i < accounts[accountIndex].transactionCount; i++) {
        printf("%s\n", accounts[accountIndex].transactionHistory[i]);
    }
}

void displayMenu() {
    printf("Banking System Menu:\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Transactions\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    int choice, accountIndex;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                printf("Enter account index (0 to %d): ", accountCount - 1);
                scanf("%d", &accountIndex);
                if (accountIndex >= 0 && accountIndex < accountCount) {
                    deposit(accountIndex);
                } else {
                    printf("Invalid account index!\n");
                }
                break;
            case 3:
                printf("Enter account index (0 to %d): ", accountCount - 1);
                scanf("%d", &accountIndex);
                if (accountIndex >= 0 && accountIndex < accountCount) {
                    withdraw(accountIndex);
                } else {
                    printf("Invalid account index!\n");
                }
                break;
            case 4:
                printf("Enter account index (0 to %d): ", accountCount - 1);
                scanf("%d", &accountIndex);
                if (accountIndex >= 0 && accountIndex < accountCount) {
                    viewTransactions(accountIndex);
                } else {
                    printf("Invalid account index!\n");
                }
                break;
            case 5:
                printf("Exiting program. Have a nice day!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}