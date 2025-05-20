//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[100];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void displayMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit Money\n");
    printf("4. Withdraw Money\n");
    printf("5. List All Accounts\n");
    printf("6. Exit\n");
    printf("-----------------------------\n");
    printf("Please choose an option: ");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }
    
    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder's name: ");
    scanf(" %[^\n]", newAccount.name); // to read string with spaces
    newAccount.balance = 0.0;

    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void viewAccount() {
    int accNum;
    printf("Enter account number to view: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Account Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void depositMoney() {
    int accNum;
    float amount;
    printf("Enter account number to deposit into: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Deposited %.2f successfully. New balance: %.2f\n", amount, accounts[i].balance);
                return;
            } else {
                printf("Enter a valid amount!\n");
                return;
            }
        }
    }
    printf("Account not found.\n");
}

void withdrawMoney() {
    int accNum;
    float amount;
    printf("Enter account number to withdraw from: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrew %.2f successfully. New balance: %.2f\n", amount, accounts[i].balance);
                return;
            } else {
                printf("Insufficient balance or invalid amount!\n");
                return;
            }
        }
    }
    printf("Account not found.\n");
}

void listAllAccounts() {
    printf("\n--- List of All Accounts ---\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d | Holder: %s | Balance: %.2f\n", 
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
                depositMoney();
                break;
                
            case 4:
                withdrawMoney();
                break;
                
            case 5:
                listAllAccounts();
                break;
                
            case 6:
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}