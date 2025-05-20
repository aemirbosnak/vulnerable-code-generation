//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_CATEGORIES 10
#define MAX_BUDGET_ITEMS 100
#define MAX_TRANSACTION_ITEMS 1000

typedef struct {
    char name[50];
    float budget;
} BudgetCategory;

typedef struct {
    char name[50];
    float budget;
    float spent;
} BudgetItem;

typedef struct {
    char description[100];
    char category[50];
    float amount;
    int isExpense;
} Transaction;

int main() {
    BudgetCategory categories[MAX_BUDGET_CATEGORIES];
    int numCategories = 0;
    BudgetItem items[MAX_BUDGET_ITEMS];
    int numItems = 0;
    Transaction transactions[MAX_TRANSACTION_ITEMS];
    int numTransactions = 0;

    while (numCategories < MAX_BUDGET_CATEGORIES) {
        printf("Enter budget category name: ");
        scanf("%s", categories[numCategories].name);
        printf("Enter budget amount: ");
        scanf("%f", &categories[numCategories].budget);
        numCategories++;
    }

    while (numItems < MAX_BUDGET_ITEMS) {
        printf("Enter budget item name: ");
        scanf("%s", items[numItems].name);
        printf("Enter budget amount: ");
        scanf("%f", &items[numItems].budget);
        printf("Enter spent amount: ");
        scanf("%f", &items[numItems].spent);
        numItems++;
    }

    while (numTransactions < MAX_TRANSACTION_ITEMS) {
        printf("Enter transaction description: ");
        scanf("%s", transactions[numTransactions].description);
        printf("Enter category: ");
        scanf("%s", transactions[numTransactions].category);
        printf("Enter amount: ");
        scanf("%f", &transactions[numTransactions].amount);
        printf("Is expense? (y/n): ");
        scanf("%s", transactions[numTransactions].isExpense);
        numTransactions++;
    }

    // TODO: implement budget planner logic

    return 0;
}