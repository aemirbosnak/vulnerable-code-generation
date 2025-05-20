//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_NAME_LEN 100
#define MAX_ACCOUNT_NUMBER_LEN 20
#define MAX_TRANSACTION_HISTORY_LEN 1000

typedef struct {
    char name[MAX_NAME_LEN];
    char accountNumber[MAX_ACCOUNT_NUMBER_LEN];
    float balance;
    char transactionHistory[MAX_TRANSACTION_HISTORY_LEN];
} BankAccount;

void printAccountDetails(BankAccount account) {
    printf("Name: %s\n", account.name);
    printf("Account Number: %s\n", account.accountNumber);
    printf("Balance: $%.2f\n", account.balance);
    printf("Transaction History: %s\n", account.transactionHistory);
}

void printMenu() {
    printf("\nBanking System Menu:\n");
    printf("1. Create Account\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. View Account Details\n");
    printf("5. Exit\n");
}

int main() {
    BankAccount account;
    int choice;
    char input[MAX_NAME_LEN];
    char accountNumber[MAX_ACCOUNT_NUMBER_LEN];
    float amount;
    char transaction[MAX_TRANSACTION_HISTORY_LEN];

    strcpy(account.name, "");
    strcpy(account.accountNumber, "");
    account.balance = 0;
    strcpy(account.transactionHistory, "");

    int i = 0;
    while(1) {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter your name: ");
                scanf("%s", input);
                strcpy(account.name, input);

                printf("Enter your account number: ");
                scanf("%s", accountNumber);
                strcpy(account.accountNumber, accountNumber);

                printf("Account created successfully!\n");
                break;

            case 2:
                printf("Enter the amount to deposit: ");
                scanf("%f", &amount);

                sprintf(transaction, "Deposit: $%.2f", amount);
                strcat(account.transactionHistory, transaction);

                account.balance += amount;

                printf("Deposit successful!\n");
                break;

            case 3:
                printf("Enter the amount to withdraw: ");
                scanf("%f", &amount);

                if(account.balance >= amount) {
                    account.balance -= amount;

                    sprintf(transaction, "Withdrawal: $%.2f", amount);
                    strcat(account.transactionHistory, transaction);

                    printf("Withdrawal successful!\n");
                } else {
                    printf("Insufficient balance.\n");
                }

                break;

            case 4:
                printAccountDetails(account);
                break;

            case 5:
                printf("Thank you for using our banking system.\n");
                exit(0);

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}