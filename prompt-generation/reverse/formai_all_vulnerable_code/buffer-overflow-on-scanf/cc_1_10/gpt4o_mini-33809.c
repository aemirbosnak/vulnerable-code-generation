//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 30
#define ACCOUNT_NUMBER_LENGTH 12

typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float balance;
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Account limit reached. Cannot create more accounts.\n");
        return;
    }

    BankAccount newAccount;
    
    printf("Enter your name: ");
    scanf(" %[^\n]", newAccount.name);
    
    printf("Enter your account number: ");
    scanf(" %[^\n]", newAccount.accountNumber);
    
    newAccount.balance = 0.0;
    accounts[accountCount++] = newAccount;

    printf("Account created successfully!\n");
}

void displayAccounts() {
    printf("\nList of Bank Accounts:\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Name: %s | Account Number: %s | Balance: %.2f\n",
               accounts[i].name,
               accounts[i].accountNumber,
               accounts[i].balance);
    }
    printf("-----------------------------------------------------\n");
}

void deposit() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for deposit: ");
    scanf(" %[^\n]", accountNumber);
    
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            accounts[i].balance += amount;
            printf("Deposit successful! New Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void withdraw() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;

    printf("Enter account number for withdrawal: ");
    scanf(" %[^\n]", accountNumber);
    
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New Balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient funds. Current Balance: %.2f\n", accounts[i].balance);
            }
            return;
        }
    }
    
    printf("Account not found!\n");
}

void menu() {
    int choice;
    
    do {
        printf("\n=== Banking System Menu ===\n");
        printf("1. Create Account\n");
        printf("2. Display Accounts\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting the system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}