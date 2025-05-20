//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ACCOUNTS 10
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100
#define MAX_CATEGORIES_PER_TRANSACTION 5

typedef struct {
    char name[50];
    int balance;
} Account;

typedef struct {
    char name[50];
    int category_count;
    int categories[MAX_CATEGORIES];
} Category;

typedef struct {
    char description[100];
    char category[50];
    int amount;
} Transaction;

int main() {
    int num_accounts = 0;
    int num_categories = 0;
    int num_transactions = 0;

    Account accounts[MAX_ACCOUNTS];
    Category categories[MAX_CATEGORIES];
    Transaction transactions[MAX_TRANSACTIONS];

    char input[100];

    // Read in accounts
    do {
        printf("Enter account name: ");
        scanf("%s", input);
        strcpy(accounts[num_accounts].name, input);
        printf("Enter account balance: ");
        scanf("%d", &accounts[num_accounts].balance);
        num_accounts++;
    } while (num_accounts < MAX_ACCOUNTS);

    // Read in categories
    do {
        printf("Enter category name: ");
        scanf("%s", input);
        strcpy(categories[num_categories].name, input);
        num_categories++;
    } while (num_categories < MAX_CATEGORIES);

    // Read in transactions
    do {
        printf("Enter transaction description: ");
        scanf("%s", input);
        strcpy(transactions[num_transactions].description, input);
        printf("Enter transaction category: ");
        scanf("%s", input);
        strcpy(transactions[num_transactions].category, input);
        printf("Enter transaction amount: ");
        scanf("%d", &transactions[num_transactions].amount);
        num_transactions++;
    } while (num_transactions < MAX_TRANSACTIONS);

    // Print out accounts
    for (int i = 0; i < num_accounts; i++) {
        printf("Account %d: %s, Balance: %d\n", i+1, accounts[i].name, accounts[i].balance);
    }

    // Print out categories
    for (int i = 0; i < num_categories; i++) {
        printf("Category %d: %s\n", i+1, categories[i].name);
    }

    // Print out transactions
    for (int i = 0; i < num_transactions; i++) {
        printf("Transaction %d: Description: %s, Category: %s, Amount: %d\n", i+1, transactions[i].description, transactions[i].category, transactions[i].amount);
    }

    return 0;
}