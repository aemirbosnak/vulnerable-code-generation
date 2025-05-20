//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_ACCOUNT_NUMBER_LENGTH 10
#define MAX_NAME_LENGTH 50
#define MAX_TRANSACTION_LENGTH 100

typedef struct {
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    char name[MAX_NAME_LENGTH];
    int balance;
} Account;

void createAccount(Account* account, char* accountNumber, char* name) {
    strcpy(account->accountNumber, accountNumber);
    strcpy(account->name, name);
    account->balance = 0;
}

void deposit(Account* account, int amount) {
    account->balance += amount;
}

int withdraw(Account* account, int amount) {
    if (amount > account->balance) {
        return -1;
    }
    account->balance -= amount;
    return 0;
}

void printTransaction(char* accountNumber, char* name, int amount, char* transactionType) {
    printf("Account Number: %s\n", accountNumber);
    printf("Name: %s\n", name);
    printf("Amount: %d\n", amount);
    printf("Transaction Type: %s\n", transactionType);
}

int main() {
    Account accounts[MAX_RECORDS];
    int recordCount = 0;
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    char name[MAX_NAME_LENGTH];
    int amount;
    char transactionType[MAX_TRANSACTION_LENGTH];

    while (recordCount < MAX_RECORDS) {
        printf("Enter account number (up to %d characters): ", MAX_ACCOUNT_NUMBER_LENGTH - 1);
        scanf("%s", accountNumber);

        if (recordCount > 0) {
            printf("Enter name (up to %d characters): ", MAX_NAME_LENGTH - 1);
            scanf("%s", name);
        }

        createAccount(&accounts[recordCount], accountNumber, name);
        recordCount++;

        while (1) {
            printf("Enter transaction type (deposit/withdraw): ");
            scanf("%s", transactionType);

            if (strcmp(transactionType, "deposit") == 0) {
                printf("Enter amount: ");
                scanf("%d", &amount);
                deposit(&accounts[recordCount - 1], amount);
                printTransaction(accounts[recordCount - 1].accountNumber, accounts[recordCount - 1].name, amount, "deposit");
            }
            else if (strcmp(transactionType, "withdraw") == 0) {
                printf("Enter amount: ");
                scanf("%d", &amount);
                int result = withdraw(&accounts[recordCount - 1], amount);
                if (result == 0) {
                    printTransaction(accounts[recordCount - 1].accountNumber, accounts[recordCount - 1].name, amount, "withdraw");
                }
            }
            else {
                printf("Invalid transaction type.\n");
            }

            printf("\nDo you want to enter another transaction? (y/n): ");
            char choice;
            scanf("%c", &choice);
            if (choice!= 'y') {
                break;
            }
        }
    }

    return 0;
}