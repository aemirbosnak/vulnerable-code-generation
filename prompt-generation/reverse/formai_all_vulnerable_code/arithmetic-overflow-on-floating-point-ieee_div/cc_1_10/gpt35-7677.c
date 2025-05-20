//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MONTHS_IN_YEAR 12
#define PERCENTAGE_FACTOR 100

int main() {
    // Initialize variables
    float salary, rent, groceries, utilities, transportation, entertainment, other_expenses, total_expenses, monthly_savings;
    int goal_savings, years_to_reach_goal;

    // Get user input
    printf("Enter your monthly salary: ");
    scanf("%f", &salary);

    printf("Enter your monthly rent: ");
    scanf("%f", &rent);

    printf("Enter your monthly groceries expenses: ");
    scanf("%f", &groceries);

    printf("Enter your monthly utilities expenses: ");
    scanf("%f", &utilities);

    printf("Enter your monthly transportation expenses: ");
    scanf("%f", &transportation);

    printf("Enter your monthly entertainment expenses: ");
    scanf("%f", &entertainment);

    printf("Enter any other monthly expenses: ");
    scanf("%f", &other_expenses);

    printf("Enter your goal savings amount: ");
    scanf("%d", &goal_savings);

    printf("Enter the number of years you want to reach your savings goal: ");
    scanf("%d", &years_to_reach_goal);

    // Calculate total monthly expenses
    total_expenses = rent + groceries + utilities + transportation + entertainment + other_expenses;

    // Calculate monthly savings needed to reach goal
    monthly_savings = (goal_savings / years_to_reach_goal) / MONTHS_IN_YEAR;

    // Calculate percentage of salary saved
    float percentage_saved = (monthly_savings / salary) * PERCENTAGE_FACTOR;

    // Output results to user
    printf("\nTotal monthly expenses: %.2f\n", total_expenses);
    printf("Monthly savings needed to reach goal: %.2f\n", monthly_savings);
    printf("Percentage of salary saved: %.2f%%\n", percentage_saved);

    return 0;
}