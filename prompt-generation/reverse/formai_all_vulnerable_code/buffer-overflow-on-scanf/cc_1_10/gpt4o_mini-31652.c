//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit Amount\n");
    printf("4. Withdraw Amount\n");
    printf("5. List All Accounts\n");
    printf("6. Exit\n");
    printf("Select an option: ");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached.\n");
        return;
    }
    
    Account newAccount;

    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully!\n");
}

void viewAccount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    printf("Enter account number to view: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("\n--- Account Details ---\n");
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void depositAmount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;
    printf("Enter account number to deposit: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%lf", &amount);
            if (amount <= 0) {
                printf("Invalid deposit amount. Must be greater than 0.\n");
            } else {
                accounts[i].balance += amount;
                printf("Amount deposited successfully! New balance: $%.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void withdrawAmount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    double amount;
    printf("Enter account number to withdraw: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%lf", &amount);
            if (amount <= 0) {
                printf("Invalid withdrawal amount. Must be greater than 0.\n");
            } else if (amount > accounts[i].balance) {
                printf("Insufficient funds. Current balance: $%.2f\n", accounts[i].balance);
            } else {
                accounts[i].balance -= amount;
                printf("Amount withdrawn successfully! New balance: $%.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    printf("Account not found.\n");
}

void listAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    
    printf("\n--- List of All Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %s, Name: %s, Balance: $%.2f\n",
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                depositAmount();
                break;
            case 4:
                withdrawAmount();
                break;
            case 5:
                listAllAccounts();
                break;
            case 6:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    }
    return 0;
}