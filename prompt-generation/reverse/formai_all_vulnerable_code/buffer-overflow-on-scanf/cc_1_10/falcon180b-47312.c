//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_CATEGORIES 10
#define MAX_TRANSACTIONS 100

typedef struct {
    char name[50];
    float budget;
    float spent;
} BudgetCategory;

typedef struct {
    char description[100];
    char category[50];
    float amount;
    char date[20];
} Transaction;

int main() {
    BudgetCategory budgetCategories[MAX_BUDGET_CATEGORIES];
    Transaction transactions[MAX_TRANSACTIONS];
    int numBudgetCategories = 0;
    int numTransactions = 0;

    printf("Welcome to the Personal Finance Planner!\n\n");

    // Initialize budget categories
    printf("Enter budget categories (up to %d):\n", MAX_BUDGET_CATEGORIES - 1);
    while (numBudgetCategories < MAX_BUDGET_CATEGORIES && scanf("%s", budgetCategories[numBudgetCategories].name)!= EOF) {
        printf("Enter budget for %s: ", budgetCategories[numBudgetCategories].name);
        scanf("%f", &budgetCategories[numBudgetCategories].budget);
        numBudgetCategories++;
    }

    // Initialize transactions
    printf("\nEnter transactions:\n");
    while (numTransactions < MAX_TRANSACTIONS && scanf("%s", transactions[numTransactions].description)!= EOF) {
        printf("Enter category for %s: ", transactions[numTransactions].description);
        scanf("%s", transactions[numTransactions].category);
        printf("Enter amount for %s: ", transactions[numTransactions].description);
        scanf("%f", &transactions[numTransactions].amount);
        printf("Enter date for %s (YYYY-MM-DD): ", transactions[numTransactions].description);
        scanf("%s", transactions[numTransactions].date);
        numTransactions++;
    }

    // Calculate total spent in each budget category
    for (int i = 0; i < numBudgetCategories; i++) {
        float totalSpent = 0;
        for (int j = 0; j < numTransactions; j++) {
            if (strcmp(transactions[j].category, budgetCategories[i].name) == 0) {
                totalSpent += transactions[j].amount;
            }
        }
        printf("\n%s:\n", budgetCategories[i].name);
        printf("Budget: $%.2f\n", budgetCategories[i].budget);
        printf("Total spent: $%.2f\n", totalSpent);
    }

    return 0;
}