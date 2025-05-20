//Falcon2-11B DATASET v1.0 Category: Banking Record System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_NUMBER_LENGTH 10
#define MAX_ACCOUNT_TYPE_LENGTH 10
#define MAX_ACCOUNT_BALANCE_LENGTH 10

typedef struct {
    char account_number[MAX_ACCOUNT_NUMBER_LENGTH];
    char account_type[MAX_ACCOUNT_TYPE_LENGTH];
    char account_balance[MAX_ACCOUNT_BALANCE_LENGTH];
} Account;

Account customerAccounts[100];
int numAccounts = 0;

void createAccount(char account_number[], char account_type[], char account_balance[]) {
    if (numAccounts >= 100) {
        printf("Maximum number of accounts reached.\n");
        return;
    }

    strncpy(customerAccounts[numAccounts].account_number, account_number, MAX_ACCOUNT_NUMBER_LENGTH);
    strncpy(customerAccounts[numAccounts].account_type, account_type, MAX_ACCOUNT_TYPE_LENGTH);
    strncpy(customerAccounts[numAccounts].account_balance, account_balance, MAX_ACCOUNT_BALANCE_LENGTH);

    numAccounts++;
}

void depositFunds(int accountNumber) {
    if (accountNumber >= numAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    int amount = 0;
    printf("Enter the amount to deposit: ");
    scanf("%d", &amount);

    customerAccounts[accountNumber].account_balance[0] += amount;
    printf("Funds deposited successfully.\n");
}

void withdrawFunds(int accountNumber) {
    if (accountNumber >= numAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    int amount = 0;
    printf("Enter the amount to withdraw: ");
    scanf("%d", &amount);

    if (amount > atoi(customerAccounts[accountNumber].account_balance)) {
        printf("Insufficient funds.\n");
        return;
    }

    customerAccounts[accountNumber].account_balance[0] -= amount;
    printf("Funds withdrawn successfully.\n");
}

void checkBalance(int accountNumber) {
    if (accountNumber >= numAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Account balance: %s\n", customerAccounts[accountNumber].account_balance);
}

void closeAccount(int accountNumber) {
    if (accountNumber >= numAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    strncpy(customerAccounts[accountNumber].account_number, "", 0);
    strncpy(customerAccounts[accountNumber].account_type, "", 0);
    strncpy(customerAccounts[accountNumber].account_balance, "", 0);

    numAccounts--;
}

int main() {
    int choice = 0;

    do {
        printf("\nBanking Record System\n");
        printf("1. Create account\n");
        printf("2. Deposit funds\n");
        printf("3. Withdraw funds\n");
        printf("4. Check balance\n");
        printf("5. Close account\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%s", customerAccounts[numAccounts].account_number);

                printf("Enter account type: ");
                scanf("%s", customerAccounts[numAccounts].account_type);

                printf("Enter account balance: ");
                scanf("%s", customerAccounts[numAccounts].account_balance);

                createAccount(customerAccounts[numAccounts].account_number, customerAccounts[numAccounts].account_type, customerAccounts[numAccounts].account_balance);

                printf("Account created successfully.\n");
                break;

            case 2:
                printf("Enter account number: ");
                scanf("%s", customerAccounts[numAccounts].account_number);

                depositFunds(numAccounts);
                break;

            case 3:
                printf("Enter account number: ");
                scanf("%s", customerAccounts[numAccounts].account_number);

                withdrawFunds(numAccounts);
                break;

            case 4:
                printf("Enter account number: ");
                scanf("%s", customerAccounts[numAccounts].account_number);

                checkBalance(numAccounts);
                break;

            case 5:
                printf("Enter account number: ");
                scanf("%s", customerAccounts[numAccounts].account_number);

                closeAccount(numAccounts);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 0);

    return 0;
}