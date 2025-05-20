//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>

int main()
{
    // Welcome message
    printf("Welcome to Personal Finance Planner!\n");

    // Declare user's salary and expenses variables
    float salary, rent, groceries, transportation, utilities, other_expenses;
    float total_expenses;

    // Get user inputs for various expenses
    printf("Please enter your monthly salary: ");
    scanf("%f", &salary);

    printf("Please enter your monthly rent: ");
    scanf("%f", &rent);

    printf("Please enter your monthly groceries expenses: ");
    scanf("%f", &groceries);

    printf("Please enter your monthly transportation expenses: ");
    scanf("%f", &transportation);

    printf("Please enter your monthly utilities expenses: ");
    scanf("%f", &utilities);

    printf("Please enter your monthly other expenses: ");
    scanf("%f", &other_expenses);

    // Calculate the total monthly expenses
    total_expenses = rent + groceries + transportation + utilities + other_expenses;

    // Calculate the monthly savings
    float savings = salary - total_expenses;

    // Display the results to the user
    printf("\n<=============== Personal Finance Summary ===============>\n");
    printf("Total Monthly Income: $%.2f\n", salary);
    printf("Total Monthly Expenses: $%.2f\n", total_expenses);
    printf("Monthly Savings: $%.2f\n", savings);

    // Check if the user has a surplus or deficit
    if (savings > 0)
    {
        printf("Congrats! You have a surplus of $%.2f this month.\n", savings);
    }
    else if (savings == 0)
    {
        printf("You have exactly nothing left this month. You should plan accordingly.\n");
    }
    else
    {
        printf("Oops! You have a deficit of $%.2f this month. Time to revise your expenses.\n", -savings);
    }

    return 0;
}