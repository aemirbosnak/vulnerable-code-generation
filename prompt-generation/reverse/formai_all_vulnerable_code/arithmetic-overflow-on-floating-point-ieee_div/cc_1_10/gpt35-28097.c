//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: Donald Knuth
#include <stdio.h>

int main()
{
// Taking input from user
    float income, expenses, savings;

    printf("Enter Income: $");
    scanf("%f", &income);

    printf("Enter Expenses: $");
    scanf("%f", &expenses);

    // Calculating savings
    savings = income - expenses;

    // Checking if savings are positive or negative
    if (savings > 0)
    {
        printf("You are saving $%.2f per month. Congratulations!\n", savings);
    }
    else if (savings < 0)
    {
        printf("You are spending $%.2f more than your income. You need to work on your budget!\n", -savings);
    }
    else
    {
        printf("You are not saving anything. You better start planning your budget!\n");
    }

    // Calculating percentage of income saved
    float save_percentage = (savings / income) * 100;

    printf("You are saving %.2f%% of your income.\n", save_percentage);

    // Savings plan for future
    float savings_goal;
    printf("What is your savings goal? $");
    scanf("%f", &savings_goal);

    float time_to_goal = savings_goal / savings;

    if (savings > 0)
    {
        printf("At this rate, you will be able to reach your savings goal in %.2f months.\n", time_to_goal);
    }
    else if (savings < 0)
    {
        printf("You are spending more than your income. You cannot reach your savings goal!\n");
    }
    else
    {
        printf("You are not saving anything. You cannot reach your savings goal!\n");
    }

    return 0;
}