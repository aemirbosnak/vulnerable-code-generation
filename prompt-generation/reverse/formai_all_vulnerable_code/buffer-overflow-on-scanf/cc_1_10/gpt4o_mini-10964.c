//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define NAME_LENGTH 50
#define ACCOUNT_NUMBER_LENGTH 15

typedef struct {
    char name[NAME_LENGTH];
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int accountCount = 0;

void printMenu() {
    printf("\n--- Banking Record System ---\n");
    printf("1. Open a new account\n");
    printf("2. Deposit amount\n");
    printf("3. Withdraw amount\n");
    printf("4. Show account details\n");
    printf("5. Exit\n");
    printf("------------------------------\n");
}

void openAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum account limit reached! Cannot open more accounts.\n");
        return;
    }
    
    Account newAccount;
    
    printf("Enter your name: ");
    scanf("%s", newAccount.name);
    printf("Enter account number: ");
    scanf("%s", newAccount.accountNumber);
    newAccount.balance = 0.0;

    accounts[accountCount] = newAccount;
    accountCount++;

    printf("Account successfully opened for %s with account number %s!\n", newAccount.name, newAccount.accountNumber);
}

void depositAmount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float deposit;

    printf("Enter account number to deposit: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to deposit: ");
            scanf("%f", &deposit);
            accounts[i].balance += deposit;
            printf("Successfully deposited %.2f into account number %s.\n", deposit, accounts[i].accountNumber);
            return;
        }
    }
    printf("Account number not found!\n");
}

void withdrawAmount() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];
    float withdrawal;

    printf("Enter account number to withdraw: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &withdrawal);
            if (withdrawal > accounts[i].balance) {
                printf("Insufficient funds! Your current balance is %.2f.\n", accounts[i].balance);
            } else {
                accounts[i].balance -= withdrawal;
                printf("Successfully withdrew %.2f from account number %s.\n", withdrawal, accounts[i].accountNumber);
            }
            return;
        }
    }
    printf("Account number not found!\n");
}

void showAccountDetails() {
    char accountNumber[ACCOUNT_NUMBER_LENGTH];

    printf("Enter account number to display details: ");
    scanf("%s", accountNumber);
    
    for (int i = 0; i < accountCount; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("\nAccount Details:\n");
            printf("Name: %s\n", accounts[i].name);
            printf("Account Number: %s\n", accounts[i].accountNumber);
            printf("Balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account number not found!\n");
}

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                openAccount();
                break;
            case 2:
                depositAmount();
                break;
            case 3:
                withdrawAmount();
                break;
            case 4:
                showAccountDetails();
                break;
            case 5:
                printf("Thank you for using the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}