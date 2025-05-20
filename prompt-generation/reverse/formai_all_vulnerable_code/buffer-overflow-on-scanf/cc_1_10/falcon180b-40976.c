//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_CATEGORIES 10
#define MAX_BUDGET_ITEMS 100
#define MAX_TRANSACTIONS 1000

typedef struct {
    char name[50];
    double budget;
    double spent;
    double remaining;
} BudgetCategory;

typedef struct {
    char name[50];
    double amount;
    int categoryId;
} BudgetItem;

typedef struct {
    int id;
    char description[100];
    double amount;
    int categoryId;
    int isIncome;
} Transaction;

int main() {
    int numCategories, numItems, numTransactions;
    BudgetCategory categories[MAX_BUDGET_CATEGORIES];
    BudgetItem items[MAX_BUDGET_ITEMS];
    Transaction transactions[MAX_TRANSACTIONS];

    printf("Enter the number of budget categories: ");
    scanf("%d", &numCategories);

    for (int i = 0; i < numCategories; i++) {
        printf("Enter the name of budget category %d: ", i+1);
        scanf("%s", categories[i].name);
        printf("Enter the budget for category %s: ", categories[i].name);
        scanf("%lf", &categories[i].budget);
    }

    printf("\nEnter the number of budget items: ");
    scanf("%d", &numItems);

    for (int i = 0; i < numItems; i++) {
        printf("Enter the name of budget item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter the budget for item %s: ", items[i].name);
        scanf("%lf", &items[i].amount);
        printf("Enter the category ID for item %s: ", items[i].name);
        scanf("%d", &items[i].categoryId);
    }

    printf("\nEnter the number of transactions: ");
    scanf("%d", &numTransactions);

    for (int i = 0; i < numTransactions; i++) {
        printf("Enter the description for transaction %d: ", i+1);
        scanf("%s", transactions[i].description);
        printf("Enter the amount for transaction %s: ", transactions[i].description);
        scanf("%lf", &transactions[i].amount);
        printf("Enter the category ID for transaction %s: ", transactions[i].description);
        scanf("%d", &transactions[i].categoryId);
        printf("Is this an income transaction? (0 for no, 1 for yes): ");
        scanf("%d", &transactions[i].isIncome);
    }

    return 0;
}