//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

// function prototype
float calcIncome();
float calcExpenses();
void calcSavings(float income, float expenses);
float calcTax(float income);

int main()
{
    float income, expenses;

    printf("Personal Finance Planner\n\n");

    // calculate income and expenses
    income = calcIncome();
    expenses = calcExpenses();

    // calculate savings and tax
    calcSavings(income, expenses);
    float tax = calcTax(income);

    // display results
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("Savings: $%.2f\n", income - expenses);
    printf("Tax: $%.2f\n", tax);

    return 0;
}

// calculate income
float calcIncome()
{
    float income;
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    return income;
}

// calculate expenses
float calcExpenses()
{
    float expenses;
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);
    return expenses;
}

// calculate savings
void calcSavings(float income, float expenses)
{
    float savings = income - expenses;

    if (savings >= 0)
    {
        printf("You are saving $%.2f per month.\n", savings);
    }
    else
    {
        printf("You are in debt by $%.2f per month.\n", -savings);
    }
}

// calculate tax
float calcTax(float income)
{
    float tax;

    if (income <= 9875)
    {
        tax = 0.10 * income;
    }
    else if (income > 9875 && income <= 40125)
    {
        tax = 987.5 + 0.12 * (income - 9875);
    }
    else if (income > 40125 && income <= 85525)
    {
        tax = 4617.5 + 0.22 * (income - 40125);
    }
    else if (income > 85525 && income <= 163300)
    {
        tax = 14605.5 + 0.24 * (income - 85525);
    }
    else if (income > 163300 && income <= 207350)
    {
        tax = 33271.5 + 0.32 * (income - 163300);
    }
    else if (income > 207350 && income <= 518400)
    {
        tax = 47367.5 + 0.35 * (income - 207350);
    }
    else if (income > 518400)
    {
        tax = 156235 + 0.37 * (income - 518400);
    }

    return tax / 12; // return monthly tax
}