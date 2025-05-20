//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int accountNumber;
    char name[100];
    double balance;
} Account;

void createAccount(Account* account) {
    srand(time(NULL));
    account->accountNumber = rand() % 10000;
    sprintf(account->name, "Account %d", account->accountNumber);
    account->balance = 0.0;
}

void deposit(Account* account, double amount) {
    account->balance += amount;
}

void withdraw(Account* account, double amount) {
    if (account->balance >= amount) {
        account->balance -= amount;
    } else {
        printf("Insufficient funds.\n");
    }
}

int main() {
    Account accounts[100];
    int accountNumber = 0;

    srand(time(NULL));

    printf("Welcome to the Bank of Randomness!\n");
    printf("Enter the number of accounts you want to create: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < accountNumber; i++) {
        Account* account = &accounts[i];
        createAccount(account);
        printf("Account %d: %s\n", account->accountNumber, account->name);
    }

    printf("Enter the action you want to perform:\n");
    printf("1. Deposit\n");
    printf("2. Withdraw\n");
    printf("3. View Balance\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    int choice;
    scanf("%d", &choice);

    while (choice!= 4) {
        switch (choice) {
            case 1:
                printf("Enter the amount to deposit: ");
                double depositAmount;
                scanf("%lf", &depositAmount);
                deposit(&accounts[accountNumber - 1], depositAmount);
                break;
            case 2:
                printf("Enter the amount to withdraw: ");
                double withdrawAmount;
                scanf("%lf", &withdrawAmount);
                withdraw(&accounts[accountNumber - 1], withdrawAmount);
                break;
            case 3:
                printf("Balance for Account %d: %.2f\n", accounts[accountNumber - 1].accountNumber, accounts[accountNumber - 1].balance);
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }

        printf("Enter the action you want to perform:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. View Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}