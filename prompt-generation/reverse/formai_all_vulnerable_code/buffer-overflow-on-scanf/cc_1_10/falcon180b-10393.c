//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 100
#define MAX_BUDGET_NAME_LENGTH 50
#define MAX_BUDGET_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_BUDGET_NAME_LENGTH];
    char amount[MAX_BUDGET_AMOUNT_LENGTH];
} BudgetItem;

int main() {
    int numBudgetItems;
    BudgetItem budgetItems[MAX_BUDGET_ITEMS];
    char inputString[100];
    int i;

    // Get the number of budget items from the user
    printf("Enter the number of budget items: ");
    scanf("%d", &numBudgetItems);

    // Get the budget item names and amounts from the user
    for (i = 0; i < numBudgetItems; i++) {
        printf("Enter budget item %d name: ", i+1);
        scanf("%s", inputString);
        strcpy(budgetItems[i].name, inputString);

        printf("Enter budget item %d amount: ", i+1);
        scanf("%s", inputString);
        strcpy(budgetItems[i].amount, inputString);
    }

    // Calculate the total income and expenses
    int totalIncome = 0;
    int totalExpenses = 0;
    for (i = 0; i < numBudgetItems; i++) {
        if (strcmp(budgetItems[i].name, "Income") == 0) {
            totalIncome += atoi(budgetItems[i].amount);
        } else {
            totalExpenses += atoi(budgetItems[i].amount);
        }
    }

    // Calculate the net income or loss
    int netIncome = totalIncome - totalExpenses;

    // Print the budget summary
    printf("\nBudget Summary:\n");
    printf("Total Income: $%d\n", totalIncome);
    printf("Total Expenses: $%d\n", totalExpenses);
    printf("Net Income: $%d\n", netIncome);

    return 0;
}