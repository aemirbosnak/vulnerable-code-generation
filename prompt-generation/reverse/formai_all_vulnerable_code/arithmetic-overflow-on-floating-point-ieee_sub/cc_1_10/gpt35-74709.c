//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>

// function for calculating total income
float calcTotalIncome(float salary, float bonus) {
    return salary + bonus;
}

// function for calculating total expenses
float calcTotalExpense(float rent, float utility, float groceries, float entertainment, float transportation) {
    return rent + utility + groceries + entertainment + transportation;
}

// function for calculating total savings
float calcTotalSavings(float income, float expense) {
    return income - expense;
}

// function for displaying monthly finance report
void displayReport(float income, float expense, float savings) {
    printf("\n************FINANCIAL REPORT************\n");
    printf("Total Income: $%.2f\n", income);
    printf("Total Expense: $%.2f\n", expense);
    printf("Total Savings: $%.2f\n", savings);
    printf("****************************************\n\n");
}

int main() {
    float salary, bonus, rent, utility, groceries, entertainment, transportation;
    float total_income, total_expense, total_savings;
    
    // input
    printf("Enter your salary: $");
    scanf("%f", &salary);
    
    printf("Enter your bonus: $");
    scanf("%f", &bonus);
    
    printf("Enter your monthly rent: $");
    scanf("%f", &rent);
    
    printf("Enter your monthly utilities: $");
    scanf("%f", &utility);
    
    printf("Enter your monthly groceries: $");
    scanf("%f", &groceries);
    
    printf("Enter your monthly entertainment expenses: $");
    scanf("%f", &entertainment);
    
    printf("Enter your monthly transportation expenses: $");
    scanf("%f", &transportation);
    
    // calculations
    total_income = calcTotalIncome(salary, bonus);
    total_expense = calcTotalExpense(rent, utility, groceries, entertainment, transportation);
    total_savings = calcTotalSavings(total_income, total_expense);
    
    // display report
    displayReport(total_income, total_expense, total_savings);
    
    return 0;
}