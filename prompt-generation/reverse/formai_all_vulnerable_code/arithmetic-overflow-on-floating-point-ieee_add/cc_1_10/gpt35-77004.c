//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct expense {
    char item_name[50];
    float cost;
};

struct budget {
    float income;
    float savings;
    float expenses_total;
    struct expense expenses[10];
};

struct budget budgets[5];

int main() {

    int num_budgets;
    printf("Welcome to the Personal Finance Planner\n");
    printf("--------------------------------------\n");
    printf("Please enter the number of budgets you wish to create (1-5): ");
    scanf("%d", &num_budgets);

    while (num_budgets < 1 || num_budgets > 5) {
        printf("Invalid number of budgets. Please enter a number between 1 and 5: ");
        scanf("%d", &num_budgets);
    }

    for (int i = 0; i < num_budgets; i++) {
        printf("\nEnter details for Budget #%d:\n", i+1);
        printf("------------------------\n");

        printf("Please enter your monthly income: ");
        scanf("%f", &budgets[i].income);

        printf("Please enter your desired monthly savings: ");
        scanf("%f", &budgets[i].savings);

        printf("Please enter total number of monthly expenses (1-10): ");
        int num_expenses;
        scanf("%d", &num_expenses);

        while (num_expenses < 1 || num_expenses > 10) {
            printf("Invalid number of expenses. Please enter a number between 1 and 10: ");
            scanf("%d", &num_expenses);
        }

        for (int j = 0; j < num_expenses; j++) {
            printf("\nEnter details for Expense #%d:\n", j+1);
            printf("--------------------------\n");

            printf("Please enter the name of the expense: ");
            scanf("%s", budgets[i].expenses[j].item_name);

            printf("Please enter the cost of the expense: ");
            scanf("%f", &budgets[i].expenses[j].cost);

            budgets[i].expenses_total += budgets[i].expenses[j].cost;
        }
    }

    printf("\n\nSummary of Budgets Created:\n");
    printf("------------------------------\n");

    for (int i = 0; i < num_budgets; i++) {
        printf("\nBudget #%d:\n", i+1);
        printf("-----------\n");
        printf("Monthly Income: $%.2f\n", budgets[i].income);
        printf("Desired Monthly Savings: $%.2f\n", budgets[i].savings);
        printf("Monthly Expenses: $%.2f\n", budgets[i].expenses_total);
        float remaining = budgets[i].income - budgets[i].savings - budgets[i].expenses_total;
        printf("Remaining Balance: $%.2f\n", remaining);
    }

    return 0;
}