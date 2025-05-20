//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: decentralized
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
        printf("Unable to create more accounts.\n");
        return;
    }
    
    Account newAccount;
    newAccount.accountNumber = accountCount + 1; // Simple incrementing account number
    printf("Enter name for Account #%d: ", newAccount.accountNumber);
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0; // Initialize balance
    
    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Account #%d created successfully for %s.\n", newAccount.accountNumber, newAccount.name);
}

void viewAccount(int accountNumber) {
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }
    
    Account acc = accounts[accountNumber - 1];
    printf("\n=== Account Details ===\n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Name: %s\n", acc.name);
    printf("Balance: %.2f\n", acc.balance);
    printf("=======================\n");
}

void updateBalance(int accountNumber) {
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Account not found!\n");
        return;
    }
    
    float amount;
    printf("Enter amount to update balance for Account #%d (negative to withdraw): ", accountNumber);
    scanf("%f", &amount);
    
    accounts[accountNumber - 1].balance += amount;
    printf("Balance updated. New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void displayAllAccounts() {
    printf("\n=== All Accounts ===\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Name: %s, Balance: %.2f\n", 
               accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
    printf("====================\n");
}

void menu() {
    int choice;
    while (1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Update Balance\n");
        printf("4. Display All Accounts\n");
        printf("5. Exit\n");
        printf("=============================\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2: {
                int accNum;
                printf("Enter Account Number to view: ");
                scanf("%d", &accNum);
                viewAccount(accNum);
                break;
            }
            case 3: {
                int accNum;
                printf("Enter Account Number to update balance: ");
                scanf("%d", &accNum);
                updateBalance(accNum);
                break;
            }
            case 4:
                displayAllAccounts();
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    menu();
    return 0;
}