//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_ACCOUNTS 10
#define MAX_CATEGORIES 10
#define MAX_TRANSACTIONS 100

struct account {
    char name[50];
    int balance;
};

struct category {
    char name[50];
    int budget;
};

struct transaction {
    char description[100];
    int amount;
    char account_name[50];
    char category_name[50];
};

int main() {
    int num_accounts, num_categories, num_transactions;
    struct account accounts[MAX_ACCOUNTS];
    struct category categories[MAX_CATEGORIES];
    struct transaction transactions[MAX_TRANSACTIONS];

    printf("Enter the number of accounts: ");
    scanf("%d", &num_accounts);

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_accounts; i++) {
        printf("Enter account name: ");
        scanf("%s", accounts[i].name);
        printf("Enter account balance: ");
        scanf("%d", &accounts[i].balance);
    }

    for (int i = 0; i < num_categories; i++) {
        printf("Enter category name: ");
        scanf("%s", categories[i].name);
        printf("Enter category budget: ");
        scanf("%d", &categories[i].budget);
    }

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction description: ");
        scanf("%[^\n]", transactions[i].description);
        printf("Enter transaction amount: ");
        scanf("%d", &transactions[i].amount);
        printf("Enter account name: ");
        scanf("%s", transactions[i].account_name);
        printf("Enter category name: ");
        scanf("%s", transactions[i].category_name);
    }

    // Print account balances
    printf("\nAccount Balances:\n");
    for (int i = 0; i < num_accounts; i++) {
        printf("%s: $%d\n", accounts[i].name, accounts[i].balance);
    }

    // Print category budgets
    printf("\nCategory Budgets:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: $%d\n", categories[i].name, categories[i].budget);
    }

    // Print transactions
    printf("\nTransactions:\n");
    for (int i = 0; i < num_transactions; i++) {
        printf("%s - $%d - %s - %s\n", transactions[i].description, transactions[i].amount, transactions[i].account_name, transactions[i].category_name);
    }

    return 0;
}