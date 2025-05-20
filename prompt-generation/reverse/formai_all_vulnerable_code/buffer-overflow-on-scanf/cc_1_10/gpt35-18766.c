//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>

#define MONTHS 12

struct Budget {
    double income;
    double rent;
    double utilities;
    double groceries;
    double transportation;
    double entertainment;
};

void display_budget(struct Budget budget) {
    printf("Income: $%.2f\n", budget.income);
    printf("Rent: $%.2f\n", budget.rent);
    printf("Utilities: $%.2f\n", budget.utilities);
    printf("Groceries: $%.2f\n", budget.groceries);
    printf("Transportation: $%.2f\n", budget.transportation);
    printf("Entertainment: $%.2f\n", budget.entertainment);
}

int main() {
    int month;
    double total_income = 0.0, total_expenses = 0.0, total_budgeted = 0.0;
    struct Budget budgets[MONTHS];

    // Get monthly budget for each month
    for (month = 0; month < MONTHS; month++) {
        printf("Enter the budget for month %d:\n", month + 1);

        printf("Income: ");
        scanf("%lf", &budgets[month].income);

        printf("Rent: ");
        scanf("%lf", &budgets[month].rent);

        printf("Utilities: ");
        scanf("%lf", &budgets[month].utilities);

        printf("Groceries: ");
        scanf("%lf", &budgets[month].groceries);

        printf("Transportation: ");
        scanf("%lf", &budgets[month].transportation);

        printf("Entertainment: ");
        scanf("%lf", &budgets[month].entertainment);

        total_budgeted += budgets[month].rent + budgets[month].utilities + budgets[month].groceries + budgets[month].transportation + budgets[month].entertainment;
        total_income += budgets[month].income;
    }

    // Display monthly budgets and totals
    printf("\nMonthly budget:\n");
    for (month = 0; month < MONTHS; month++) {
        printf("Month %d:\n", month + 1);
        display_budget(budgets[month]);
        printf("\n");
    }

    printf("Total budgeted: $%.2f\n", total_budgeted);
    printf("Total income: $%.2f\n", total_income);
    printf("Total expenses: $%.2f\n", total_budgeted - total_income);

    return 0;
}