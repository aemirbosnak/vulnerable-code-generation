//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

float monthly_income() //function to get user's monthly income
{
    float income;

    printf("Enter your monthly income: ");
    scanf("%f", &income);

    return income;
}

float monthly_expenses() //function to get user's monthly expenses
{
    float expenses;

    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);

    return expenses;
}

float calculate_savings(float income, float expenses) //function to calculate user's monthly savings
{
    float savings;

    savings = income - expenses;

    return savings;
}

void display_savings(float savings) //function to display user's monthly savings
{
    printf("Your monthly savings is $%.2f\n", savings);
}

void investment_plan(float savings) //function to suggest an investment plan based on user's monthly savings
{
    if(savings >= 1000 && savings < 3000)
    {
        printf("You can consider investing in mutual funds.\n");
    }
    else if(savings >= 3000 && savings < 5000)
    {
        printf("You can consider investing in index funds.\n");
    }
    else if(savings >= 5000)
    {
        printf("You can consider investing in stocks.\n");
    }
    else
    {
        printf("You may not have enough savings to invest at the moment.\n");
    }
}

void budget_plan(float income, float expenses) //function to suggest a budget plan based on user's monthly income and expenses
{
    float budget_percentage = (expenses / income) * 100;

    if(budget_percentage <= 50)
    {
        printf("You are spending within budget. Keep it up!\n");
    }
    else if(budget_percentage > 50 && budget_percentage <= 70)
    {
        printf("You are spending a bit over budget. Consider cutting back on some expenses.\n");
    }
    else
    {
        printf("You are spending significantly over budget. You need to take a closer look at your expenses and make some changes.\n");
    }
}

int main()
{
    float income, expenses, savings; //declaring variables to store user's input

    income = monthly_income(); //calling function to get user's monthly income
    expenses = monthly_expenses(); //calling function to get user's monthly expenses
    savings = calculate_savings(income, expenses); //calling function to calculate user's monthly savings
    display_savings(savings); //calling function to display user's monthly savings
    investment_plan(savings); //calling function to suggest an investment plan based on user's monthly savings
    budget_plan(income, expenses); //calling function to suggest a budget plan based on user's monthly income and expenses

    return 0;
}