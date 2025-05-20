//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: secure
// C Personal Finance Planner

#include <stdio.h>
#include <stdlib.h>

// function to calculate monthly expenses
float monthlyExpenses(float rent, float utilities, float groceries, float transportation, float entertainment) {
    float totalExpenses = rent + utilities + groceries + transportation + entertainment;
    return totalExpenses;
}

// function to calculate monthly income
float monthlyIncome(float salary, float additionalIncome) {
    float totalIncome = salary + additionalIncome;
    return totalIncome;
}

// function to calculate monthly savings
float monthlySavings(float totalIncome, float totalExpenses) {
    float totalSavings = totalIncome - totalExpenses;
    return totalSavings;
}

int main()
{
    float rent, utilities, groceries, transportation, entertainment, salary, additionalIncome, totalExpenses, totalIncome, totalSavings;

    printf("Enter your monthly rent:");
    scanf("%f", &rent);

    printf("Enter your monthly utilities expense:");
    scanf("%f", &utilities);

    printf("Enter your monthly groceries expense:");
    scanf("%f", &groceries);

    printf("Enter your monthly transportation expense:");
    scanf("%f", &transportation);

    printf("Enter your monthly entertainment expense:");
    scanf("%f", &entertainment);

    printf("Enter your monthly salary:");
    scanf("%f", &salary);

    printf("Enter your additional monthly income:");
    scanf("%f", &additionalIncome);

    totalExpenses = monthlyExpenses(rent, utilities, groceries, transportation, entertainment);
    totalIncome = monthlyIncome(salary, additionalIncome);
    totalSavings = monthlySavings(totalIncome, totalExpenses);

    printf("\nMonthly Expenses: %.2f\n", totalExpenses);
    printf("Monthly Income: %.2f\n", totalIncome);
    printf("Monthly Savings: %.2f\n", totalSavings);

    if (totalSavings > 0) {
        printf("Congratulations! You are saving money each month!\n");
    } else if (totalSavings < 0) {
        printf("Uh oh! You are spending more than you are earning each month. Consider reducing your expenses or finding additional sources of income.\n");
    } else {
        printf("You are breaking even each month. Consider finding ways to increase your income or reduce your expenses to start saving.\n");
    }

    return 0;
}