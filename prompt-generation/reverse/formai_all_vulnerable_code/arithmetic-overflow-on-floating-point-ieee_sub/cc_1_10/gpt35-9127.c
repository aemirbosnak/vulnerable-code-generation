//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

struct budget {
    float income;
    float expenses;
    float net_savings;
};

int main() {
    int num_months;
    struct budget *monthly_budget;

    printf("Enter the number of months to plan for: ");
    scanf("%d", &num_months);

    monthly_budget = (struct budget *)malloc(num_months * sizeof(struct budget));

    for (int i = 0; i < num_months; i++) {
        printf("Enter the income for month %d: ", i+1);
        scanf("%f", &monthly_budget[i].income);

        printf("Enter the total expenses for month %d: ", i+1);
        scanf("%f", &monthly_budget[i].expenses);

        monthly_budget[i].net_savings = monthly_budget[i].income - monthly_budget[i].expenses;
    }

    printf("\n\n");

    printf("Monthly Budget Planner\n\n");
    printf("Month \t Income \t Expenses \t Net Savings\n");
    for (int i = 0; i < num_months; i++) {
        printf("%d \t %.2f \t\t %.2f \t\t %.2f\n", i+1, monthly_budget[i].income, monthly_budget[i].expenses, monthly_budget[i].net_savings);
    }

    float total_income = 0;
    float total_expenses = 0;
    float total_savings = 0;

    for (int i = 0; i < num_months; i++) {
        total_income += monthly_budget[i].income;
        total_expenses += monthly_budget[i].expenses;
        total_savings += monthly_budget[i].net_savings;
    }

    float avg_income = total_income / num_months;
    float avg_expenses = total_expenses / num_months;
    float avg_savings = total_savings / num_months;

    printf("\n\n");
    printf("Averages\n\n");
    printf("Average Income: %.2f\n", avg_income);
    printf("Average Expenses: %.2f\n", avg_expenses);
    printf("Average Net Savings: %.2f\n", avg_savings);

    free(monthly_budget);

    return 0;
}