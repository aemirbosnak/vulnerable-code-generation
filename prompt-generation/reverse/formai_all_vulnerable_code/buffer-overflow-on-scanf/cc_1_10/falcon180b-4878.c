//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 10
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES 20

typedef struct {
    char name[100];
    int accountNumber;
    float balance;
} Account;

typedef struct {
    int accountNumber;
    char category[100];
    float amount;
    char date[20];
} Transaction;

typedef struct {
    char name[100];
    int numTransactions;
    Transaction transactions[MAX_TRANSACTIONS];
} Category;

int main() {
    int numAccounts, numTransactions, numCategories;
    Account accounts[MAX_ACCOUNTS];
    Transaction transactions[MAX_TRANSACTIONS];
    Category categories[MAX_CATEGORIES];

    printf("Welcome to the Personal Finance Planner!\n");

    // Get number of accounts
    printf("How many accounts do you have? ");
    scanf("%d", &numAccounts);

    // Get account information
    for (int i = 0; i < numAccounts; i++) {
        printf("Enter account %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", accounts[i].name);
        printf("Account number: ");
        scanf("%d", &accounts[i].accountNumber);
        printf("Balance: ");
        scanf("%f", &accounts[i].balance);
    }

    // Get number of transactions
    printf("\nHow many transactions do you have? ");
    scanf("%d", &numTransactions);

    // Get transaction information
    for (int i = 0; i < numTransactions; i++) {
        printf("\nEnter transaction %d information:\n", i+1);
        printf("Account number: ");
        scanf("%d", &transactions[i].accountNumber);
        printf("Category: ");
        scanf("%s", transactions[i].category);
        printf("Amount: ");
        scanf("%f", &transactions[i].amount);
        printf("Date: ");
        scanf("%s", transactions[i].date);
    }

    // Get number of categories
    printf("\nHow many categories do you have? ");
    scanf("%d", &numCategories);

    // Get category information
    for (int i = 0; i < numCategories; i++) {
        printf("\nEnter category %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", categories[i].name);
        printf("Number of transactions: ");
        scanf("%d", &categories[i].numTransactions);
    }

    // TODO: Add functionality to view account balances and transaction history by category

    // Exit program
    return 0;
}