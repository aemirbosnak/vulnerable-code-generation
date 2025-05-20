//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_ITEM_NAME_LEN 50
#define MAX_ITEM_AMOUNT_LEN 10

typedef struct {
    char name[MAX_ITEM_NAME_LEN];
    char amount[MAX_ITEM_AMOUNT_LEN];
} BudgetItem;

int main() {
    int numItems;
    BudgetItem budget[MAX_BUDGET_ITEMS];
    char input[MAX_ITEM_NAME_LEN + MAX_ITEM_AMOUNT_LEN + 2];
    int i, j, k;
    double totalExpenses = 0.0, totalIncome = 0.0;

    printf("Enter the number of budget items: ");
    scanf("%d", &numItems);

    for (i = 0; i < numItems; i++) {
        printf("Enter budget item %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", budget[i].name);
        printf("Amount: ");
        scanf("%s", budget[i].amount);

        if (strlen(budget[i].amount) == 0) {
            printf("Invalid amount for %s.\n", budget[i].name);
            exit(1);
        }

        totalExpenses += atof(budget[i].amount);
    }

    printf("\nMonthly Budget:\n");
    printf("-----------------\n");
    for (i = 0; i < numItems; i++) {
        printf("%-20s $%-10s\n", budget[i].name, budget[i].amount);
    }

    printf("\nTotal Expenses: $%.2f\n", totalExpenses);

    printf("\nEnter your monthly income: ");
    scanf("%s", input);

    if (strlen(input) == 0) {
        printf("Invalid income.\n");
        exit(1);
    }

    totalIncome = atof(input);

    if (totalExpenses > totalIncome) {
        printf("\nYou are over budget by $%.2f.\n", totalExpenses - totalIncome);
    } else {
        printf("\nYou have $%.2f left in your budget.\n", totalIncome - totalExpenses);
    }

    return 0;
}