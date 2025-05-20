//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ACCOUNT_NUMBER_LENGTH 10
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_HISTORY_LENGTH 20

typedef struct {
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    char name[MAX_NAME_LENGTH];
    char transactionHistory[MAX_TRANSACTION_HISTORY_LENGTH];
} BankAccount;

void createAccount(BankAccount* account) {
    printf("Enter your account number: ");
    scanf("%s", account->accountNumber);
    printf("Enter your name: ");
    scanf("%s", account->name);
    strcpy(account->transactionHistory, "");
}

void deposit(BankAccount* account, double amount) {
    strcat(account->transactionHistory, "Deposit: $");
    char amountStr[20];
    sprintf(amountStr, "%0.2f", amount);
    strcat(account->transactionHistory, amountStr);
    strcat(account->transactionHistory, "\n");
}

void withdraw(BankAccount* account, double amount) {
    strcat(account->transactionHistory, "Withdrawal: $");
    char amountStr[20];
    sprintf(amountStr, "%0.2f", amount);
    strcat(account->transactionHistory, amountStr);
    strcat(account->transactionHistory, "\n");
}

void checkBalance(BankAccount* account) {
    printf("Account Balance for %s:\n", account->name);
    printf("%s", account->transactionHistory);
}

int main() {
    BankAccount account;
    createAccount(&account);

    int choice;
    do {
        printf("\nBanking System Menu:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Check Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
        case 1:
            printf("Enter amount to deposit: ");
            double depositAmount;
            scanf("%lf", &depositAmount);
            deposit(&account, depositAmount);
            break;
        case 2:
            printf("Enter amount to withdraw: ");
            double withdrawAmount;
            scanf("%lf", &withdrawAmount);
            withdraw(&account, withdrawAmount);
            break;
        case 3:
            checkBalance(&account);
            break;
        case 4:
            printf("Thank you for using our banking system. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }

    } while(choice!= 4);

    return 0;
}