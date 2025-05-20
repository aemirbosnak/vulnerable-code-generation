//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

// Define the Personal Finance Planner structure
typedef struct PersonalFinancePlanner
{
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
    double investments;
} PersonalFinancePlanner;

// Function to calculate the total net worth
double calculateTotalNetWorth(PersonalFinancePlanner planner)
{
    double totalNetWorth = planner.savings + planner.investments - planner.expenses;
    return totalNetWorth;
}

// Function to calculate the monthly savings
double calculateMonthlySavings(PersonalFinancePlanner planner)
{
    double monthlySavings = planner.income * 0.1;
    return monthlySavings;
}

// Function to calculate the investment returns
double calculateInvestmentReturns(PersonalFinancePlanner planner)
{
    double investmentReturns = 0.05 * planner.investments;
    return investmentReturns;
}

int main()
{
    // Create a personal finance planner
    PersonalFinancePlanner planner;

    // Get the planner's name, age, income, expenses, savings, and investments
    printf("Enter your name: ");
    scanf("%s", planner.name);

    printf("Enter your age: ");
    scanf("%d", &planner.age);

    printf("Enter your income: ");
    scanf("%lf", &planner.income);

    printf("Enter your expenses: ");
    scanf("%lf", &planner.expenses);

    printf("Enter your savings: ");
    scanf("%lf", &planner.savings);

    printf("Enter your investments: ");
    scanf("%lf", &planner.investments);

    // Calculate the total net worth, monthly savings, and investment returns
    double totalNetWorth = calculateTotalNetWorth(planner);
    double monthlySavings = calculateMonthlySavings(planner);
    double investmentReturns = calculateInvestmentReturns(planner);

    // Print the results
    printf("Your total net worth is: $%.2lf", totalNetWorth);

    printf("\nYour monthly savings are: $%.2lf", monthlySavings);

    printf("\nYour investment returns are: $%.2lf", investmentReturns);

    return 0;
}