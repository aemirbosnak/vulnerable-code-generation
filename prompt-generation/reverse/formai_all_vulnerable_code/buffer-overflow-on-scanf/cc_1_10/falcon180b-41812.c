//Falcon-180B DATASET v1.0 Category: Banking Record System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACCOUNTS 100
#define MAX_TRANSACTIONS 1000

// Define the structure of an account
typedef struct {
    int accountNumber;
    char name[50];
    double balance;
} Account;

// Define the structure of a transaction
typedef struct {
    int accountNumber;
    char type[10];
    double amount;
    char date[20];
} Transaction;

// Function to add a new account to the system
void addAccount(Account accounts[], int numAccounts) {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Error: Maximum number of accounts reached.\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &accounts[numAccounts].accountNumber);

    printf("Enter account holder's name: ");
    scanf("%s", accounts[numAccounts].name);

    printf("Enter initial balance: ");
    scanf("%lf", &accounts[numAccounts].balance);

    printf("Account added successfully.\n");
    numAccounts++;
}

// Function to display all accounts in the system
void displayAccounts(Account accounts[], int numAccounts) {
    printf("\nAccounts:\n");
    for (int i = 0; i < numAccounts; i++) {
        printf("%d. %s - %.2lf\n", accounts[i].accountNumber, accounts[i].name, accounts[i].balance);
    }
}

// Function to add a new transaction to an account
void addTransaction(Transaction transactions[], int numTransactions, int accountNumber) {
    if (numTransactions >= MAX_TRANSACTIONS) {
        printf("Error: Maximum number of transactions reached.\n");
        return;
    }

    printf("Enter transaction type (deposit/withdrawal): ");
    scanf("%s", transactions[numTransactions].type);

    printf("Enter transaction amount: ");
    scanf("%lf", &transactions[numTransactions].amount);

    printf("Enter transaction date (YYYY-MM-DD): ");
    scanf("%s", transactions[numTransactions].date);

    printf("Transaction added successfully.\n");
    numTransactions++;
}

// Function to display all transactions for a specific account
void displayTransactions(Transaction transactions[], int numTransactions, int accountNumber) {
    printf("\nTransactions for account %d:\n", accountNumber);
    for (int i = 0; i < numTransactions; i++) {
        if (transactions[i].accountNumber == accountNumber) {
            printf("%s - %.2lf - %s\n", transactions[i].type, transactions[i].amount, transactions[i].date);
        }
    }
}

int main() {
    Account accounts[MAX_ACCOUNTS];
    int numAccounts = 0;

    Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions = 0;

    int choice;
    while (1) {
        printf("\n1. Add account\n2. Display accounts\n3. Add transaction\n4. Display transactions\n5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            addAccount(accounts, numAccounts);
            break;
        case 2:
            displayAccounts(accounts, numAccounts);
            break;
        case 3:
            printf("Enter account number: ");
            scanf("%d", &choice);
            addTransaction(transactions, numTransactions, choice);
            break;
        case 4:
            printf("Enter account number: ");
            scanf("%d", &choice);
            displayTransactions(transactions, numTransactions, choice);
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}