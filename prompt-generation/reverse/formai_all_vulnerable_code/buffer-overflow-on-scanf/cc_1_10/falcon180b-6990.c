//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNT_NUMBER_LENGTH 10
#define MAX_ACCOUNT_HOLDER_LENGTH 50
#define MAX_TRANSACTION_HISTORY_LENGTH 100
#define MAX_NUMBER_OF_TRANSACTIONS 100
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char accountNumber[MAX_ACCOUNT_NUMBER_LENGTH];
    char accountHolder[MAX_ACCOUNT_HOLDER_LENGTH];
    char transactionHistory[MAX_TRANSACTION_HISTORY_LENGTH];
    int numberOfTransactions;
    char amount[MAX_AMOUNT_LENGTH];
} Account;

void createAccount(Account *account) {
    printf("Enter account number: ");
    scanf("%s", account->accountNumber);
    printf("Enter account holder's name: ");
    scanf("%s", account->accountHolder);
    strcpy(account->transactionHistory, "");
    account->numberOfTransactions = 0;
    strcpy(account->amount, "");
}

void depositMoney(Account *account) {
    printf("Enter amount to deposit: ");
    scanf("%s", account->amount);
    strcat(account->transactionHistory, "Deposit: ");
    strcat(account->transactionHistory, account->amount);
    strcat(account->transactionHistory, "\n");
    account->numberOfTransactions++;
}

void withdrawMoney(Account *account) {
    printf("Enter amount to withdraw: ");
    scanf("%s", account->amount);
    strcat(account->transactionHistory, "Withdrawal: ");
    strcat(account->transactionHistory, account->amount);
    strcat(account->transactionHistory, "\n");
    account->numberOfTransactions++;
}

void printAccountDetails(Account account) {
    printf("Account Number: %s\n", account.accountNumber);
    printf("Account Holder's Name: %s\n", account.accountHolder);
    printf("Transaction History:\n%s", account.transactionHistory);
    printf("Number of Transactions: %d\n", account.numberOfTransactions);
}

int main() {
    Account account;
    createAccount(&account);

    int choice;
    do {
        printf("\n1. Deposit Money\n2. Withdraw Money\n3. Print Account Details\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                depositMoney(&account);
                break;
            case 2:
                withdrawMoney(&account);
                break;
            case 3:
                printAccountDetails(account);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    } while(choice!= 4);

    return 0;
}