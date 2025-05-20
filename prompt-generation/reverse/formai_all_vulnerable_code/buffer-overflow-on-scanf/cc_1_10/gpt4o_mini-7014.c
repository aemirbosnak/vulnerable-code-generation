//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char accountHolder[NAME_LENGTH];
    double balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void addAccount();
void viewAccounts();
void updateBalance();
void deleteAccount();
void printMenu();

int main() {
    int choice;
    
    while(1) {
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                addAccount();
                break;
            case 2:
                viewAccounts();
                break;
            case 3:
                updateBalance();
                break;
            case 4:
                deleteAccount();
                break;
            case 5:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}

void printMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Add Account\n");
    printf("2. View Accounts\n");
    printf("3. Update Balance\n");
    printf("4. Delete Account\n");
    printf("5. Exit\n");
}

void addAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot add more accounts, maximum limit reached.\n");
        return;
    }
    
    BankAccount newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple incremental account number
    printf("Enter account holder name: ");
    scanf("%s", newAccount.accountHolder);
    newAccount.balance = 0.0; // Initialize balance to zero
    
    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account added successfully.\n");
}

void viewAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    
    printf("\n--- Account List ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Holder: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
}

void updateBalance() {
    int accountNumber;
    double amount;
    
    printf("Enter account number to update balance: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to add/subtract (use negative for withdrawal): ");
    scanf("%lf", &amount);
    
    accounts[accountNumber - 1].balance += amount;
    printf("Balance updated successfully. New Balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void deleteAccount() {
    int accountNumber;
    
    printf("Enter account number to delete: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    for (int i = accountNumber - 1; i < accountCount - 1; i++) {
        accounts[i] = accounts[i + 1]; // Shift accounts to fill the gap
    }
    
    accountCount--;
    printf("Account deleted successfully.\n");
}