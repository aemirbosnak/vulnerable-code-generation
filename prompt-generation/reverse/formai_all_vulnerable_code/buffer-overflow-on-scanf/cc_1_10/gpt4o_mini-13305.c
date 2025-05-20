//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

struct Account {
    int accountNumber;
    char ownerName[50];
    float balance;
};

struct Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }
    
    struct Account newAccount;
    newAccount.accountNumber = accountCount + 1;
    
    printf("Enter account owner's name: ");
    scanf("%s", newAccount.ownerName);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Account created successfully! Account Number: %d\n", newAccount.accountNumber);
}

void depositMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    accounts[accountNumber - 1].balance += amount;
    printf("Deposit successful! New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void withdrawMoney() {
    int accountNumber;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount > accounts[accountNumber - 1].balance) {
        printf("Insufficient balance.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount;
    printf("Withdrawal successful! New balance: %.2f\n", accounts[accountNumber - 1].balance);
}

void displayAccountDetails() {
    int accountNumber;
    
    printf("Enter account number: ");
    scanf("%d", &accountNumber);
    
    if (accountNumber < 1 || accountNumber > accountCount) {
        printf("Invalid account number.\n");
        return;
    }
    
    struct Account acc = accounts[accountNumber - 1];
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Owner's Name: %s\n", acc.ownerName);
    printf("Balance: %.2f\n", acc.balance);
}

void printMenu() {
    printf("\nBanking Record System\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Display Account Details\n");
    printf("5. Exit\n");
}

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                displayAccountDetails();
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    return 0;
}