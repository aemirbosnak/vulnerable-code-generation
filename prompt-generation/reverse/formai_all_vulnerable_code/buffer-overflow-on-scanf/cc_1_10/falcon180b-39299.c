//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_ACCOUNT_NAME_LENGTH 50
#define MAX_TRANSACTION_AMOUNT_LENGTH 10

struct Account {
    char name[MAX_ACCOUNT_NAME_LENGTH];
    int accountNumber;
    double balance;
};

struct Transaction {
    char type[10];
    int accountNumber;
    double amount;
    char date[20];
};

int main() {
    int numAccounts = 0;
    struct Account accounts[MAX_ACCOUNTS];
    struct Transaction transactions[MAX_ACCOUNTS];

    printf("Welcome to the Banking Record System\n");

    while (numAccounts < MAX_ACCOUNTS) {
        printf("Enter account name (max %d characters): ", MAX_ACCOUNT_NAME_LENGTH - 1);
        scanf("%s", accounts[numAccounts].name);
        printf("Enter account number: ");
        scanf("%d", &accounts[numAccounts].accountNumber);
        printf("Enter initial balance: ");
        scanf("%lf", &accounts[numAccounts].balance);
        numAccounts++;
    }

    int choice = 0;

    while (choice!= 4) {
        printf("\n1. Deposit\n2. Withdraw\n3. Transfer\n4. View transactions\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter account number: ");
                scanf("%d", &accounts[numAccounts - 1].accountNumber);
                printf("Enter deposit amount: ");
                scanf("%lf", &transactions[numAccounts - 1].amount);
                strcpy(transactions[numAccounts - 1].type, "Deposit");
                strcpy(transactions[numAccounts - 1].date, "Today");
                break;

            case 2:
                printf("Enter account number: ");
                scanf("%d", &accounts[numAccounts - 1].accountNumber);
                printf("Enter withdrawal amount: ");
                scanf("%lf", &transactions[numAccounts - 1].amount);
                strcpy(transactions[numAccounts - 1].type, "Withdrawal");
                strcpy(transactions[numAccounts - 1].date, "Today");
                break;

            case 3:
                printf("Enter source account number: ");
                scanf("%d", &transactions[numAccounts - 1].accountNumber);
                printf("Enter destination account number: ");
                scanf("%d", &accounts[numAccounts - 1].accountNumber);
                printf("Enter transfer amount: ");
                scanf("%lf", &transactions[numAccounts - 1].amount);
                strcpy(transactions[numAccounts - 1].type, "Transfer");
                strcpy(transactions[numAccounts - 1].date, "Today");
                break;

            case 4:
                printf("\nAccount Name\tAccount Number\tBalance\n");
                printf("--------------------------------------------------------\n");
                for (int i = 0; i < numAccounts; i++) {
                    printf("%-20s\t%d\t\t%.2lf\n", accounts[i].name, accounts[i].accountNumber, accounts[i].balance);
                }

                printf("\nTransaction Type\tAccount Number\tAmount\tDate\n");
                printf("------------------------------------------------------------------------\n");
                for (int i = 0; i < numAccounts; i++) {
                    printf("%-20s\t%d\t\t%.2lf\t%s\n", transactions[i].type, transactions[i].accountNumber, transactions[i].amount, transactions[i].date);
                }
                break;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}