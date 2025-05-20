//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char accountNumber[20];
    double balance;
} Account;

int numAccounts = 0;
Account accounts[MAX_ACCOUNTS];

void init() {
    numAccounts = 0;
}

int createAccount(char *name, char *accountNumber) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            return -1; // Account already exists
        }
    }
    strcpy(accounts[numAccounts].name, name);
    strcpy(accounts[numAccounts].accountNumber, accountNumber);
    accounts[numAccounts].balance = 0.0;
    numAccounts++;
    return 0;
}

int deposit(char *accountNumber, double amount) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            accounts[i].balance += amount;
            return 0;
        }
    }
    return -1; // Account not found
}

int withdraw(char *accountNumber, double amount) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                return 0;
            } else {
                return -1; // Insufficient balance
            }
        }
    }
    return -1; // Account not found
}

int checkBalance(char *accountNumber) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].accountNumber, accountNumber) == 0) {
            printf("Balance: $%.2f\n", accounts[i].balance);
            return 0;
        }
    }
    return -1; // Account not found
}

int main() {
    init();
    while (1) {
        printf("1. Create account\n2. Deposit\n3. Withdraw\n4. Check balance\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            char name[MAX_NAME_LENGTH];
            char accountNumber[20];
            printf("Enter name: ");
            scanf("%s", name);
            printf("Enter account number: ");
            scanf("%s", accountNumber);
            createAccount(name, accountNumber);
            break;
        }
        case 2: {
            char accountNumber[20];
            double amount;
            printf("Enter account number: ");
            scanf("%s", accountNumber);
            printf("Enter amount: ");
            scanf("%lf", &amount);
            deposit(accountNumber, amount);
            break;
        }
        case 3: {
            char accountNumber[20];
            double amount;
            printf("Enter account number: ");
            scanf("%s", accountNumber);
            printf("Enter amount: ");
            scanf("%lf", &amount);
            withdraw(accountNumber, amount);
            break;
        }
        case 4: {
            char accountNumber[20];
            printf("Enter account number: ");
            scanf("%s", accountNumber);
            checkBalance(accountNumber);
            break;
        }
        case 5:
            return 0;
        default:
            printf("Invalid choice\n");
        }
    }
}