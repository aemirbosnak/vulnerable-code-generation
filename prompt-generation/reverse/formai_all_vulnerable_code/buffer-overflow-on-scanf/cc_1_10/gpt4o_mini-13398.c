//GPT-4o-mini DATASET v1.0 Category: Banking Record System ; Style: Alan Turing
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
} BankAccount;

BankAccount accounts[MAX_ACCOUNTS];
int accountCount = 0;

void createAccount() {
    if (accountCount >= MAX_ACCOUNTS) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    printf("Enter account holder's name: ");
    scanf(" %[^\n]", accounts[accountCount].name);
    printf("Enter account number: ");
    scanf(" %[^\n]", accounts[accountCount].accountNumber);
    accounts[accountCount].balance = 0.0;
    accountCount++;
    printf("Account created successfully!\n");
}

void displayAccounts() {
    if (accountCount == 0) {
        printf("No accounts available.\n");
        return;
    }
    printf("List of accounts:\n");
    for (int i = 0; i < accountCount; i++) {
        printf("Account Holder: %s, Account Number: %s, Balance: %.2f\n",
               accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
    }
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
            printf("Deposited %.2f to account number %s. New balance: %.2f\n",
                   amount, accountNumber, accounts[i].balance);
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
                printf("Withdrew %.2f from account number %s. New balance: %.2f\n",
                       amount, accountNumber, accounts[i].balance);
            } else {
                printf("Insufficient funds!\n");
            }
            return;
        }
    }
    printf("Account not found!\n");
}

void menu() {
    int choice;

    while (1) {
        printf("\n--- Banking Record System ---\n");
        printf("1. Create Account\n");
        printf("2. Display All Accounts\n");
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
                printf("Exiting the Banking Record System. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Banking Record System!\n");
    menu();
    return 0;
}