//GEMINI-pro DATASET v1.0 Category: Banking Record System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ACCOUNTS 100

typedef struct {
    char name[50];
    char address[100];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS];

int numAccounts = 0;

void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Sorry, the maximum number of accounts has been reached.\n");
        return;
    }

    char name[50];
    char address[100];
    double balance;

    printf("Enter the account holder's name: ");
    scanf("%s", name);

    printf("Enter the account holder's address: ");
    scanf("%s", address);

    printf("Enter the initial balance: ");
    scanf("%lf", &balance);

    strcpy(accounts[numAccounts].name, name);
    strcpy(accounts[numAccounts].address, address);
    accounts[numAccounts].balance = balance;

    numAccounts++;

    printf("Account created successfully.\n");
}

void deposit() {
    int accountNumber;
    double amount;

    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 0 || accountNumber >= numAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter the amount to deposit: ");
    scanf("%lf", &amount);

    accounts[accountNumber].balance += amount;

    printf("Deposit successful.\n");
}

void withdraw() {
    int accountNumber;
    double amount;

    printf("Enter the account number: ");
    scanf("%d", &accountNumber);

    if (accountNumber < 0 || accountNumber >= numAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter the amount to withdraw: ");
    scanf("%lf", &amount);

    if (amount > accounts[accountNumber].balance) {
        printf("Insufficient funds.\n");
        return;
    }

    accounts[accountNumber].balance -= amount;

    printf("Withdrawal successful.\n");
}

void transfer() {
    int fromAccountNumber;
    int toAccountNumber;
    double amount;

    printf("Enter the account number to transfer from: ");
    scanf("%d", &fromAccountNumber);

    if (fromAccountNumber < 0 || fromAccountNumber >= numAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter the account number to transfer to: ");
    scanf("%d", &toAccountNumber);

    if (toAccountNumber < 0 || toAccountNumber >= numAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter the amount to transfer: ");
    scanf("%lf", &amount);

    if (amount > accounts[fromAccountNumber].balance) {
        printf("Insufficient funds.\n");
        return;
    }

    accounts[fromAccountNumber].balance -= amount;
    accounts[toAccountNumber].balance += amount;

    printf("Transfer successful.\n");
}

void printAccounts() {
    for (int i = 0; i < numAccounts; i++) {
        printf("Account %d:\n", i);
        printf("    Name: %s\n", accounts[i].name);
        printf("    Address: %s\n", accounts[i].address);
        printf("    Balance: %.2f\n", accounts[i].balance);
    }
}

int main() {
    int choice;

    do {
        printf("1. Create an account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Transfer\n");
        printf("5. Print accounts\n");
        printf("6. Exit\n");

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
                transfer();
                break;
            case 5:
                printAccounts();
                break;
            case 6:
                printf("Thank you for using the banking record system.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 6);

    return 0;
}