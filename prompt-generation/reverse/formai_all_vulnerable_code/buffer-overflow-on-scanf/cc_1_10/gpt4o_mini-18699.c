//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 20

typedef struct {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    char name[NAME_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum accounts reached. Cannot create new account.\n");
        return;
    }
    
    Account newAccount;
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    
    printf("Enter account holder's name: ");
    scanf(" %[^\n]%*c", newAccount.name);
    
    newAccount.balance = 0.0;
    
    accounts[accountCount++] = newAccount;
    printf("Account created successfully!\n");
}

void depositMoney() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;
    
    printf("Enter account number to deposit money: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter deposit amount: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposited %.2f to account %s. New balance: %.2f\n", amount, accountNumber, accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void withdrawMoney() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float amount;
    
    printf("Enter account number to withdraw money: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter withdrawal amount: ");
            scanf("%f", &amount);
            if (amount > accounts[i].balance) {
                printf("Insufficient funds!\n");
            } else {
                accounts[i].balance -= amount;
                printf("Withdrew %.2f from account %s. New balance: %.2f\n", amount, accountNumber, accounts[i].balance);
            }
            return;
        }
    }
    
    printf("Account not found!\n");
}

void viewAccountDetails() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    
    printf("Enter account number to view details: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Account Holder's Name: %s\n", accounts[i].name);
            printf("Current Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    
    printf("Account not found!\n");
}

void listAllAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("List of all accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Number: %s, Name: %s, Balance: %.2f\n",
            accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

int main() {
    int choice;
    
    while (1) {
        printf("\n=== Banking Record System ===\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. View Account Details\n");
        printf("5. List All Accounts\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
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
                viewAccountDetails();
                break;
            case 5:
                listAllAccounts();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}