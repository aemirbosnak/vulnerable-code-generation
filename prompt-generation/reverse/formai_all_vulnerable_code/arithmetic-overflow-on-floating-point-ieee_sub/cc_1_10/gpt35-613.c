//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float monthly_income, monthly_expenses, savings_goal;
    float total_savings, remaining_money;
    int months_to_reach_goal, months_to_become_bankrupt;

    printf("Welcome to the Personal Finance Planner!\n\n");

    printf("Please enter your monthly income: ");
    scanf("%f", &monthly_income);

    printf("Please enter your monthly expenses: ");
    scanf("%f", &monthly_expenses);

    printf("Please enter your desired savings goal: ");
    scanf("%f", &savings_goal);

    total_savings = 0.0;
    remaining_money = monthly_income - monthly_expenses;
    months_to_reach_goal = 0;
    months_to_become_bankrupt = 0;

    while(total_savings < savings_goal)
    {
        if(remaining_money <= 0)
        {
            printf("Oops! You've run out of money!\n");
            break;
        }

        total_savings += remaining_money;
        months_to_reach_goal++;

        if(total_savings >= savings_goal)
        {
            printf("\nCongratulations! You've reached your savings goal in %d months!\n", months_to_reach_goal);
            break;
        }

        printf("\nEnd of month %d:\n", months_to_reach_goal);

        printf("Starting balance: $%.2f\n", total_savings);
        printf("Income: $%.2f\n", monthly_income);
        printf("Expenses: $%.2f\n", monthly_expenses);
        printf("Remaining money: $%.2f\n", remaining_money);

        total_savings -= monthly_expenses; // deduct monthly expenses from savings
        remaining_money = monthly_income - monthly_expenses; // reset remaining money variable
    }

    if(total_savings < savings_goal && remaining_money <= 0)
    {
        printf("\nUh oh! Looks like you're going bankrupt soon!\n");

        while(total_savings > 0)
        {
            total_savings -= monthly_expenses * 2; // try to save money by cutting expenses in half
            months_to_become_bankrupt++;
        }

        printf("You'll become bankrupt in %d months if you don't take action!\n", months_to_become_bankrupt);
    }

    printf("\nThank you for using the Personal Finance Planner!\n");

    return 0;
}