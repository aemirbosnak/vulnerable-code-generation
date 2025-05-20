//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_NAME_LENGTH 50
#define MAX_BALANCE 9999999.99

typedef struct {
    char name[MAX_NAME_LENGTH];
    double balance;
} Account;

int numAccounts = 0;
Account accounts[MAX_ACCOUNTS];

void createAccount(char* name) {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Sorry, too many accounts already!\n");
        return;
    }

    Account newAccount;
    strcpy(newAccount.name, name);
    newAccount.balance = 0.0;

    accounts[numAccounts++] = newAccount;
    printf("Account created successfully!\n");
}

void deposit(char* name, double amount) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            accounts[i].balance += amount;
            printf("Deposit successful!\n");
            return;
        }
    }

    printf("Account not found!\n");
}

void withdraw(char* name, double amount) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful!\n");
                return;
            } else {
                printf("Insufficient balance!\n");
            }
        }
    }

    printf("Account not found!\n");
}

void checkBalance(char* name) {
    int i;
    for (i = 0; i < numAccounts; i++) {
        if (strcmp(accounts[i].name, name) == 0) {
            printf("Balance: $%.2f\n", accounts[i].balance);
            return;
        }
    }

    printf("Account not found!\n");
}

int main() {
    printf("Welcome to the Cheerful Banking System!\n");

    char choice;
    do {
        printf("\nEnter your choice:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter account name:\n");
            char name[MAX_NAME_LENGTH];
            scanf("%s", name);
            createAccount(name);
            break;

        case '2':
            printf("Enter account name:\n");
            char depositName[MAX_NAME_LENGTH];
            scanf("%s", depositName);
            printf("Enter deposit amount:\n");
            double depositAmount;
            scanf("%lf", &depositAmount);
            deposit(depositName, depositAmount);
            break;

        case '3':
            printf("Enter account name:\n");
            char withdrawName[MAX_NAME_LENGTH];
            scanf("%s", withdrawName);
            printf("Enter withdrawal amount:\n");
            double withdrawAmount;
            scanf("%lf", &withdrawAmount);
            withdraw(withdrawName, withdrawAmount);
            break;

        case '4':
            printf("Enter account name:\n");
            char balanceName[MAX_NAME_LENGTH];
            scanf("%s", balanceName);
            checkBalance(balanceName);
            break;

        case '5':
            printf("Thank you for using Cheerful Banking System!\n");
            break;

        default:
            printf("Invalid choice!\n");
        }
    } while (choice!= '5');

    return 0;
}