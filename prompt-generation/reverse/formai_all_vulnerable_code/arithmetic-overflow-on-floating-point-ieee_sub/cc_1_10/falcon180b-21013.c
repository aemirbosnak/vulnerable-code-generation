//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>

// Function to calculate monthly expenses
float calculate_monthly_expenses(float income, float savings, float debt_repayment) {
    float monthly_expenses = 0;

    // Calculate monthly expenses based on income, savings, and debt repayment
    monthly_expenses = income - savings - debt_repayment;

    return monthly_expenses;
}

// Function to calculate monthly income
float calculate_monthly_income(float salary, float bonus, float overtime) {
    float monthly_income = 0;

    // Calculate monthly income based on salary, bonus, and overtime
    monthly_income = salary + bonus + overtime;

    return monthly_income;
}

// Function to calculate monthly savings
float calculate_monthly_savings(float income, float savings_percentage) {
    float monthly_savings = 0;

    // Calculate monthly savings based on income and savings percentage
    monthly_savings = (income * savings_percentage) / 100;

    return monthly_savings;
}

// Function to calculate monthly debt repayment
float calculate_monthly_debt_repayment(float debt, float interest_rate, float repayment_period) {
    float monthly_debt_repayment = 0;

    // Calculate monthly debt repayment based on debt, interest rate, and repayment period
    monthly_debt_repayment = debt * (interest_rate / 1200) * (1 + (interest_rate / 1200)) * repayment_period;

    return monthly_debt_repayment;
}

int main() {
    // User input for income, savings percentage, debt, and repayment period
    float income, savings_percentage, debt, repayment_period;
    printf("Enter your monthly income: ");
    scanf("%f", &income);
    printf("Enter your monthly savings percentage: ");
    scanf("%f", &savings_percentage);
    printf("Enter your total debt: ");
    scanf("%f", &debt);
    printf("Enter your repayment period in months: ");
    scanf("%f", &repayment_period);

    // Calculate monthly income, savings, and debt repayment
    float monthly_income = calculate_monthly_income(income, 0, 0);
    float monthly_savings = calculate_monthly_savings(income, savings_percentage);
    float monthly_debt_repayment = calculate_monthly_debt_repayment(debt, 0, repayment_period);

    // Calculate monthly expenses
    float monthly_expenses = calculate_monthly_expenses(monthly_income, monthly_savings, monthly_debt_repayment);

    // Print monthly expenses
    printf("Your monthly expenses are: $%.2f\n", monthly_expenses);

    return 0;
}