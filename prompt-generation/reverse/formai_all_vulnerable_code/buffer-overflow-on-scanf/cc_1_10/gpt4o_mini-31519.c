//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }
    printf("Enter account number: ");
    scanf("%d", &accounts[accountCount].accountNumber);
    printf("Enter account holder name: ");
    scanf(" %[^\n]", accounts[accountCount].name);
    accounts[accountCount].balance = 0.0;
    accountCount++;
    printf("Account created successfully!\n");
}

void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number to deposit: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposited $%.2f to account number %d\n", amount, accountNumber);
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter account number to withdraw: ");
    scanf("%d", &accountNumber);
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient balance!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrew $%.2f from account number %d\n", amount, accountNumber);
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAccounts() {
    printf("\n--- Account Details ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d\n", accounts[i].accountNumber);
        printf("Account Holder Name: %s\n", accounts[i].name);
        printf("Account Balance: $%.2f\n\n", accounts[i].balance);
    }
}

void menu() {
    int choice;
    while (1) {
        printf("=== Bank Menu ===\n");
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
                printf("Thank you for using the banking system!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Exciting Bank Record System!\n");
    menu();
    return 0;
}