//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    float balance;
} account;

typedef struct {
    char name[50];
    float amount;
    char category[50];
} transaction;

int main() {
    int num_accounts, num_categories, num_transactions;
    account accounts[MAX_BUDGET_CATEGORIES];
    char categories[MAX_BUDGET_CATEGORIES][50];
    transaction transactions[MAX_TRANSACTIONS];

    printf("Enter the number of accounts: ");
    scanf("%d", &num_accounts);

    for (int i = 0; i < num_accounts; i++) {
        printf("Enter account name: ");
        scanf("%s", accounts[i].name);
        printf("Enter account balance: ");
        scanf("%f", &accounts[i].balance);
    }

    printf("Enter the number of budget categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter budget category name: ");
        scanf("%s", categories[i]);
    }

    printf("Enter the number of transactions: ");
    scanf("%d", &num_transactions);

    for (int i = 0; i < num_transactions; i++) {
        printf("Enter transaction name: ");
        scanf("%s", transactions[i].name);
        printf("Enter transaction amount: ");
        scanf("%f", &transactions[i].amount);
        printf("Enter transaction category: ");
        scanf("%s", transactions[i].category);
    }

    // TODO: Implement budget planner logic

    return 0;
}