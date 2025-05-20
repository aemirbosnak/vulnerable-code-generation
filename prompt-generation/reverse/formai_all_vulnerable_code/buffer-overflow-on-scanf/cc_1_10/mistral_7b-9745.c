//MISTRAL-7B DATASET v1.0 Category: Banking Record System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100

typedef struct {
    char name[50];
    char accountNumber[20];
    float balance;
} Account;

Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

void addAccount(char *name, char *accountNumber, float initialBalance) {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    strcpy(accounts[numAccounts].name, name);
    strcpy(accounts[numAccounts].accountNumber, accountNumber);
    accounts[numAccounts].balance = initialBalance;

    numAccounts++;
}

void deposit(int accountIndex, float amount) {
    if (accountIndex < 0 || accountIndex >= numAccounts) {
        printf("Error: Invalid account index.\n");
        return;
    }

    accounts[accountIndex].balance += amount;
}

void withdraw(int accountIndex, float amount) {
    if (accountIndex < 0 || accountIndex >= numAccounts) {
        printf("Error: Invalid account index.\n");
        return;
    }

    if (accounts[accountIndex].balance < amount) {
        printf("Error: Insufficient balance.\n");
        return;
    }

    accounts[accountIndex].balance -= amount;
}

void printAccount(int accountIndex) {
    if (accountIndex < 0 || accountIndex >= numAccounts) {
        printf("Error: Invalid account index.\n");
        return;
    }

    printf("Account Index: %d\n", accountIndex);
    printf("Name: %s\n", accounts[accountIndex].name);
    printf("Account Number: %s\n", accounts[accountIndex].accountNumber);
    printf("Balance: %.2f\n", accounts[accountIndex].balance);
}

int main() {
    char name[50];
    char accountNumber[20];
    float initialBalance;
    int choice, accountIndex;
    float amount;

    printf("Welcome to C Banking System!\n");

    while (1) {
        printf("\n1. Add Account\n2. Deposit\n3. Withdraw\n4. Print Account\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter account number: ");
                scanf("%s", accountNumber);
                printf("Enter initial balance: ");
                scanf("%f", &initialBalance);

                addAccount(name, accountNumber, initialBalance);
                break;
            case 2:
                printf("Enter account index: ");
                scanf("%d", &accountIndex);
                printf("Enter deposit amount: ");
                scanf("%f", &amount);

                deposit(accountIndex, amount);
                break;
            case 3:
                printf("Enter account index: ");
                scanf("%d", &accountIndex);
                printf("Enter withdrawal amount: ");
                scanf("%f", &amount);

                withdraw(accountIndex, amount);
                break;
            case 4:
                printf("Enter account index: ");
                scanf("%d", &accountIndex);

                printAccount(accountIndex);
                break;
            case 5:
                printf("Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}