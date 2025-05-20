//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declarations
    float income, expenses, savings;
    float total_income = 0, total_expenses = 0;
    int choice, count = 0;

    // Loop to get income and expenses
    do
    {

        printf("Enter your income for month %d: ", count + 1);
        scanf("%f", &income);

        printf("Enter your expenses for month %d: ", count + 1);
        scanf("%f", &expenses);

        // Check if expenses are greater than income
        if (expenses > income)
        {
            printf("Your expenses cannot be greater than your income!\n");
            continue;
        }

        // Calculate savings
        savings = income - expenses;

        // Add to total income and total expenses
        total_income += income;
        total_expenses += expenses;

        printf("\nTotal income for month %d: %.2f\n", count + 1, income);
        printf("Total expenses for month %d: %.2f\n", count + 1, expenses);
        printf("Savings for month %d: %.2f\n", count + 1, savings);
        count++;

        // Ask if user wants to add more income/expenses
        printf("\nDo you want to add income/expenses for another month? (1 for Yes, 0 for No): ");
        scanf("%d", &choice);

    } while (choice != 0);

    // Calculate monthly average income and expenses
    float monthly_avg_income = total_income / count;
    float monthly_avg_expenses = total_expenses / count;

    // Calculate difference between monthly average income and expenses
    float monthly_avg_diff = monthly_avg_income - monthly_avg_expenses;

    // Calculate yearly income and expenses
    float yearly_income = total_income * 12;
    float yearly_expenses = total_expenses * 12;

    // Calculate yearly savings
    float yearly_savings = yearly_income - yearly_expenses;

    // Calculate percent saved
    float percent_saved = (yearly_savings / yearly_income) * 100;

    // Print summary of finances
    printf("\n\n******* Financial Summary *******\n");
    printf("Total income: %.2f\n", total_income);
    printf("Total expenses: %.2f\n", total_expenses);
    printf("Monthly average income: %.2f\n", monthly_avg_income);
    printf("Monthly average expenses: %.2f\n", monthly_avg_expenses);
    printf("Monthly average difference: %.2f\n", monthly_avg_diff);
    printf("Yearly income: %.2f\n", yearly_income);
    printf("Yearly expenses: %.2f\n", yearly_expenses);
    printf("Yearly savings: %.2f\n", yearly_savings);
    printf("Percent saved yearly: %.2f%%\n", percent_saved);

    return 0;
}