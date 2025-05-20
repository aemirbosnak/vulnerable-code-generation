//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char accountNum[ACCOUNT_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum accounts reached. Cannot create more accounts.\n");
        return;
    }
    
    printf("Enter account holder's name: ");
    scanf(" %[^\n]s", accounts[accountCount].name);
    
    printf("Enter account number: ");
    scanf(" %[^\n]s", accounts[accountCount].accountNum);
    
    accounts[accountCount].balance = 0.0;
    accountCount++;
    
    printf("Account created successfully!\n");
}

void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts available to display.\n");
        return;
    }
    
    printf("\nList of Bank Accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Holder: %s, Account Number: %s, Balance: %.2f\n", 
               accounts[i].name, 
               accounts[i].accountNum, 
               accounts[i].balance);
    }
}

BankAccount* findAccount(char* accountNum) {
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNum, accountNum) == 0) {
            return &accounts[i];
        }
    }
    return NULL;
}

void deposit() {
    char accountNum[ACCOUNT_LENGTH];
    float amount;

    printf("Enter account number to deposit into: ");
    scanf(" %[^\n]s", accountNum);
    
    BankAccount* account = findAccount(accountNum);
    if (account == NULL) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }
    
    account->balance += amount;
    printf("Successfully deposited %.2f. New balance: %.2f\n", amount, account->balance);
}

void withdraw() {
    char accountNum[ACCOUNT_LENGTH];
    float amount;

    printf("Enter account number to withdraw from: ");
    scanf(" %[^\n]s", accountNum);
    
    BankAccount* account = findAccount(accountNum);
    if (account == NULL) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid withdrawal amount!\n");
        return;
    }
    
    if (amount > account->balance) {
        printf("Insufficient balance!\n");
        return;
    }
    
    account->balance -= amount;
    printf("Successfully withdrew %.2f. New balance: %.2f\n", amount, account->balance);
}

void menu() {
    int choice;

    do {
        printf("\n=== Banking Record System ===\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Select an option: ");
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
                printf("Exiting the banking system. Thank you!\n");
                break;
            default:
                printf("Invalid choice, please select again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}