//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define BUFFER_LENGTH 256

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached!\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple account number generation
    printf("Enter account holder name: ");
    scanf(" %49[^\n]", newAccount.name);
    newAccount.balance = 0.0;
    
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created. Account number: %d\n", newAccount.accountNumber);
}

void deposit() {
    int accNum;
    float amount;
    printf("Enter account number for deposit: ");
    scanf("%d", &accNum);
    
    if (accNum <= 0 || accNum > accountCount) {
        printf("Invalid account number!\n");
        return;
    }
    
    printf("Enter deposit amount: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }
    
    accounts[accNum - 1].balance += amount;
    printf("Deposited %.2f to account number %d. New balance: %.2f\n",
           amount, accNum, accounts[accNum - 1].balance);
}

void withdraw() {
    int accNum;
    float amount;
    printf("Enter account number for withdrawal: ");
    scanf("%d", &accNum);
    
    if (accNum <= 0 || accNum > accountCount) {
        printf("Invalid account number!\n");
        return;
    }
    
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);
    
    if (amount <= 0 || amount > accounts[accNum - 1].balance) {
        printf("Invalid withdrawal amount!\n");
        return;
    }
    
    accounts[accNum - 1].balance -= amount;
    printf("Withdrew %.2f from account number %d. New balance: %.2f\n",
           amount, accNum, accounts[accNum - 1].balance);
}

void viewAccounts() {
    printf("\nAccount List:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n",
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    printf("\n");
}

void exitSystem() {
    printf("Exiting the banking system. Thank you!\n");
    exit(0);
}

int main() {
    int choice;

    while (1) {
        printf("=== Banking Record System ===\n");
        printf("1. Add Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View All Accounts\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                viewAccounts();
                break;
            case 5:
                exitSystem();
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    }

    return 0;
}