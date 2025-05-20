//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_MONTHS 12
#define MAX_YEARS 5

int main() {
    int monthly_income, monthly_expenses, monthly_savings;
    int yearly_income, yearly_expenses, yearly_savings;
    int monthly_income_after_expenses, monthly_savings_after_expenses;
    int years_to_retire;
    int i, j;

    // Get user input
    printf("Enter your monthly income: ");
    scanf("%d", &monthly_income);
    printf("Enter your monthly expenses: ");
    scanf("%d", &monthly_expenses);
    printf("Enter your monthly savings: ");
    scanf("%d", &monthly_savings);

    // Calculate yearly income and expenses
    yearly_income = monthly_income * 12;
    yearly_expenses = monthly_expenses * 12;
    yearly_savings = monthly_savings * 12;

    // Calculate monthly income after expenses
    monthly_income_after_expenses = monthly_income - monthly_expenses;

    // Calculate monthly savings after expenses
    monthly_savings_after_expenses = monthly_savings - monthly_expenses;

    // Calculate years to retire
    years_to_retire = 0;
    for (i = 0; i < MAX_YEARS; i++) {
        for (j = 0; j < MAX_MONTHS; j++) {
            if (yearly_savings >= yearly_expenses) {
                years_to_retire++;
                yearly_savings -= yearly_expenses;
            }
        }
    }

    // Print results
    printf("Years to retire: %d\n", years_to_retire);
    printf("Monthly income after expenses: %d\n", monthly_income_after_expenses);
    printf("Monthly savings after expenses: %d\n", monthly_savings_after_expenses);

    return 0;
}