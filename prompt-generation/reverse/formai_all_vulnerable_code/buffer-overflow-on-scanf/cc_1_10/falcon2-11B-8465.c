//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int accountNumber;
    char accountHolder[50];
    double balance;
} Account;

void createAccount(Account* accounts, int numAccounts) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        printf("Enter account number: ");
        scanf("%d", &accounts[i].accountNumber);
        printf("Enter account holder name: ");
        scanf("%s", accounts[i].accountHolder);
        printf("Enter initial balance: ");
        scanf("%lf", &accounts[i].balance);
    }
}

void displayAccounts(Account* accounts, int numAccounts) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        printf("Account %d: %s, Balance: $%.2lf\n", accounts[i].accountNumber, accounts[i].accountHolder, accounts[i].balance);
    }
}

void deposit(Account* accounts, int numAccounts) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        printf("Enter deposit amount for account %d: ", accounts[i].accountNumber);
        scanf("%lf", &accounts[i].balance);
    }
}

void withdraw(Account* accounts, int numAccounts) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        printf("Enter withdrawal amount for account %d: ", accounts[i].accountNumber);
        scanf("%lf", &accounts[i].balance);
    }
}

void updateAccount(Account* accounts, int numAccounts) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        printf("Enter updated account number for account %d: ", accounts[i].accountNumber);
        scanf("%d", &accounts[i].accountNumber);
        printf("Enter updated account holder name for account %d: ", accounts[i].accountNumber);
        scanf("%s", accounts[i].accountHolder);
        printf("Enter updated balance for account %d: ", accounts[i].accountNumber);
        scanf("%lf", &accounts[i].balance);
    }
}

void sortAccounts(Account* accounts, int numAccounts) {
    int i, j;
    for (i = 0; i < numAccounts; i++) {
        for (j = i + 1; j < numAccounts; j++) {
            if (accounts[i].balance > accounts[j].balance) {
                Account temp = accounts[i];
                accounts[i] = accounts[j];
                accounts[j] = temp;
            }
        }
    }
}

void main() {
    Account accounts[10];
    int numAccounts = 10;
    createAccount(accounts, numAccounts);
    displayAccounts(accounts, numAccounts);
    deposit(accounts, numAccounts);
    withdraw(accounts, numAccounts);
    updateAccount(accounts, numAccounts);
    sortAccounts(accounts, numAccounts);
    displayAccounts(accounts, numAccounts);
}