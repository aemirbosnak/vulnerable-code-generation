//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char accountHolder[NAME_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }
    
    BankAccount newAccount;
    
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    printf("Enter account holder name: ");
    scanf(" %[^\n]", newAccount.accountHolder);
    newAccount.balance = 0.0;
    
    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Account added successfully!\n");
}

void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    
    printf("\nList of Bank Accounts:\n");
    printf("----------------------------------\n");
    printf("%-20s %-20s %-10s\n", "Account Number", "Account Holder", "Balance");
    printf("----------------------------------\n");
    for (int i = 0; i < accountCount; i++) {
        printf("%-20s %-20s $%-9.2f\n", accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
    printf("----------------------------------\n");
}

void searchAccount() {
    char searchTerm[ACCOUNT_NUMBER_LENGTH];
    printf("Enter account number to search: ");
    scanf("%s", searchTerm);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, searchTerm) == 0) {
            printf("\nAccount found:\n");
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].accountHolder);
            printf("Balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void updateBalance() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;
    
    printf("Enter account number to update: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Current balance: $%.2f\n", accounts[i].balance);
            printf("Enter amount to add (use negative value to subtract): ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Updated balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

int main() {
    int choice;
    
    while (1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Add Account\n");
        printf("2. Display Accounts\n");
        printf("3. Search Account\n");
        printf("4. Update Balance\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                displayAccounts();
                break;
            case 3:
                searchAccount();
                break;
            case 4:
                updateBalance();
                break;
            case 5:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}