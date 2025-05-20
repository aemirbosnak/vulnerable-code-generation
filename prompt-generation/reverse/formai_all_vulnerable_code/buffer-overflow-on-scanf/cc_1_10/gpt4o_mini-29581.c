//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: inquisitive
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
int totalAccounts = 0;

void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Please delete an existing account.\n");
        return;
    }
    
    int accNum;
    char name[100];
    printf("Enter account number: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Account number already exists. Please try again.\n");
            return;
        }
    }

    printf("Enter your name: ");
    scanf(" %[^\n]", name);
    
    accounts[totalAccounts].accountNumber = accNum;
    strcpy(accounts[totalAccounts].name, name);
    accounts[totalAccounts].balance = 0.0;

    totalAccounts++;
    printf("Account created successfully!\n");
}

void deposit() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid amount! Please enter a positive value.\n");
                return;
            }
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void withdraw() {
    int accNum;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount <= 0) {
                printf("Invalid amount! Please enter a positive value.\n");
                return;
            }
            if (amount > accounts[i].balance) {
                printf("Insufficient funds! Current balance: %.2f\n", accounts[i].balance);
                return;
            }
            accounts[i].balance -= amount;
            printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void displayAccountDetails() {
    int accNum;
    printf("Enter account number: ");
    scanf("%d", &accNum);
    
    for (int i = 0; i < totalAccounts; i++) {
        if (accounts[i].accountNumber == accNum) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

void menu() {
    while (1) {
        int choice;
        printf("\n=== Banking System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Amount\n");
        printf("3. Withdraw Amount\n");
        printf("4. Display Account Details\n");
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
                displayAccountDetails();
                break;
            case 5:
                printf("Exiting the Banking System. Goodbye!\n");
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