//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>

float calculateMonthlySavings(float income, float expenses);
float calculateSavingsGoal(float monthlySavings, float targetSavings);
void printFinancialPlan(float income, float expenses, float monthlySavings, float targetSavings);

int main()
{
    float income, expenses, targetSavings;
    
    printf("Welcome to your Personal Finance Planner\n\n");
    
    printf("Please enter your monthly income: ");
    scanf("%f", &income);
    
    printf("Please enter your monthly expenses: ");
    scanf("%f", &expenses);
    
    printf("Please enter your target monthly savings: ");
    scanf("%f", &targetSavings);
    
    float monthlySavings = calculateMonthlySavings(income, expenses);
    float totalSavings = calculateSavingsGoal(monthlySavings, targetSavings);
    
    printFinancialPlan(income, expenses, monthlySavings, totalSavings);
    
    return 0;
}

float calculateMonthlySavings(float income, float expenses)
{
    return income - expenses;
}

float calculateSavingsGoal(float monthlySavings, float targetSavings)
{
    return targetSavings / monthlySavings;
}

void printFinancialPlan(float income, float expenses, float monthlySavings, float targetSavings)
{
    printf("\n\n**************\n");
    printf("Your Financial Plan\n");
    printf("**************\n\n");
    
    printf("Monthly Income: $%.2f\n", income);
    printf("Monthly Expenses: $%.2f\n", expenses);
    printf("Monthly Savings: $%.2f\n", monthlySavings);
    printf("Target Monthly Savings Goal: $%.2f\n", targetSavings);
    
    if (monthlySavings < targetSavings) {
        printf("\nYou need to increase your monthly savings by $%.2f to reach your savings goals.", 
                targetSavings - monthlySavings);
    } else {
        printf("\nCongratulations! You are on track to reach your savings goals.");
    }
}