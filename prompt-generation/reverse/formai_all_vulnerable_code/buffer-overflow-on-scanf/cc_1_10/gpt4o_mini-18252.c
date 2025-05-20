//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int accountNumber;
    char name[MAX_NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached!\n");
        return;
    }
  
    Account newAccount;
    
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    
    printf("Enter account holder name: ");
    scanf(" %[^\n]s", newAccount.name);
    
    newAccount.balance = 0.0;
    accounts[accountCount] = newAccount;
    accountCount++;
    
    printf("Account created successfully!\n");
}

void deposit() {
    int accNumber;
    float amount;
    printf("Enter account number for deposit: ");
    scanf("%d", &accNumber);
  
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                accounts[i].balance += amount;
                printf("Deposited %.2f to account %d. New balance: %.2f\n", amount, accNumber, accounts[i].balance);
            } else {
                printf("Invalid deposit amount!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void withdraw() {
    int accNumber;
    float amount;
    printf("Enter account number for withdrawal: ");
    scanf("%d", &accNumber);
  
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= accounts[i].balance) {
                accounts[i].balance -= amount;
                printf("Withdrawn %.2f from account %d. New balance: %.2f\n", amount, accNumber, accounts[i].balance);
            } else {
                printf("Invalid withdrawal amount!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void displayAccountDetails() {
    int accNumber;
    printf("Enter account number to view details: ");
    scanf("%d", &accNumber);
  
    for (int i = 0; i < accountCount; i++) {
        if (accounts[i].accountNumber == accNumber) {
            printf("Account Number: %d\n", accounts[i].accountNumber);
            printf("Account Holder: %s\n", accounts[i].name);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found!\n");
}

void listAllAccounts() {
    printf("List of all accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %d, Holder: %s, Balance: %.2f\n",
               accounts[i].accountNumber,
               accounts[i].name,
               accounts[i].balance);
    }
}

void menu() {
    int choice;
    do {
        printf("\nBanking Record System Menu:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Display Account Details\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
      
        switch (choice) {
            case 1: createAccount(); break;
            case 2: deposit(); break;
            case 3: withdraw(); break;
            case 4: displayAccountDetails(); break;
            case 5: listAllAccounts(); break;
            case 6: printf("Exiting the system. Goodbye!\n"); break;
            default: printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);
}

int main() {
    menu();
    return 0;
}