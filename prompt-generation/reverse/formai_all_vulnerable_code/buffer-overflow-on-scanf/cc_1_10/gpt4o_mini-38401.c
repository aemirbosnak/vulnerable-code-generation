//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    int accountNumber;
    char name[50];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount();
void viewAccount();
void deposit();
void withdraw();
void displayMenu();
int findAccount(int accountNumber);

int main() {
    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                viewAccount();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n=== Banking Record System ===\n");
    printf("1. Create Account\n");
    printf("2. View Account\n");
    printf("3. Deposit\n");
    printf("4. Withdraw\n");
    printf("5. Exit\n");
}

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached. Cannot create new account.\n");
        return;
    }
    
    Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter name: ");
    scanf("%s", newAccount.name);
    newAccount.balance = 0.0f;

    accounts[accountCount] = newAccount;
    accountCount++;
    printf("Account created successfully!\n");
}

void viewAccount() {
    int accountNumber;
    printf("Enter account number to view: ");
    scanf("%d", &accountNumber);
    
    int foundIndex = findAccount(accountNumber);
    if (foundIndex == -1) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Account Number: %d\n", accounts[foundIndex].accountNumber);
    printf("Name: %s\n", accounts[foundIndex].name);
    printf("Balance: %.2f\n", accounts[foundIndex].balance);
}

void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number to deposit: ");
    scanf("%d", &accountNumber);
    
    int foundIndex = findAccount(accountNumber);
    if (foundIndex == -1) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    
    if (amount <= 0) {
        printf("Invalid deposit amount!\n");
        return;
    }
    
    accounts[foundIndex].balance += amount;
    printf("Amount deposited successfully! New balance: %.2f\n", accounts[foundIndex].balance);
}

void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter account number to withdraw: ");
    scanf("%d", &accountNumber);
    
    int foundIndex = findAccount(accountNumber);
    if (foundIndex == -1) {
        printf("Account not found!\n");
        return;
    }
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);
    
    if (amount <= 0 || amount > accounts[foundIndex].balance) {
        printf("Invalid withdrawal amount!\n");
        return;
    }
    
    accounts[foundIndex].balance -= amount;
    printf("Amount withdrawn successfully! New balance: %.2f\n", accounts[foundIndex].balance);
}

int findAccount(int accountNumber) {
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            return i;
        }
    }
    return -1;
}