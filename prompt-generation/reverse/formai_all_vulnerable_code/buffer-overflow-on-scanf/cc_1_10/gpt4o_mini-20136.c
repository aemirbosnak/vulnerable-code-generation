//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
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
    
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    newAccount.balance = 0.0; // Initialize balance to 0

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for deposit: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            
            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Deposited %.2f to account %s. New balance: %.2f\n", amount, accounts[i].accountNumber, accounts[i].balance);
            } else {
                printf("Deposit amount must be positive.\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrew %.2f from account %s. New balance: %.2f\n", amount, accounts[i].accountNumber, accounts[i].balance);
            } else {
                if (amount <= 0) {
                    printf("Withdrawal amount must be positive.\n");
                } else {
                    printf("Insufficient balance for withdrawal.\n");
                }
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts created yet.\n");
        return;
    }
    
    printf("\nAccounts List:\n");
    printf("-------------------------------------------------\n");
    printf("%-20s %-20s %s\n", "Name", "Account Number", "Balance");
    printf("-------------------------------------------------\n");
    
    for (int i = 0; i < accountCount; i++) {
        printf("%-20s %-20s %.2f\n", accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }
    printf("-------------------------------------------------\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n===== Banking Record System =====\n");
        printf("1. Add Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Accounts\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
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
                displayAccounts();
                break;
            case 5:
                printf("Exiting system. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}