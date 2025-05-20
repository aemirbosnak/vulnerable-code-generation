//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

float income, expenses, savings, taxPercentage, moneySaved, taxPaid;

void getIncome() {
    printf("Enter your monthly income: ");
    scanf("%f", &income);
}

void getExpenses() {
    printf("Enter your monthly expenses: ");
    scanf("%f", &expenses);
}

void getTaxPercentage() {
    printf("Enter your tax percentage: ");
    scanf("%f", &taxPercentage);
}

float calculateMoneySaved() {
    return income - expenses - taxPaid;
}

float calculateTaxPaid() {
    return (income * taxPercentage) / 100;
}

float calculateSavings() {
    return (moneySaved / income) * 100;
}

int main() {
    printf("Welcome to the Personal Finance Planner program.\n");
    printf("------------------------------------------------\n");
    getIncome();
    getExpenses();
    getTaxPercentage();
    taxPaid = calculateTaxPaid();
    moneySaved = calculateMoneySaved();

    printf("\nMonthly Income: $%.2f\n", income);
    printf("Monthly Expenses: $%.2f\n", expenses);
    printf("Tax Percentage: %.2f%%\n", taxPercentage);
    printf("Tax Paid: $%.2f\n", taxPaid);
    printf("Money Saved: $%.2f\n", moneySaved);
    printf("Savings Rate: %.2f%%\n", calculateSavings());

    printf("\nThank you for using Personal Finance Planner program.\n");

    return 0;
}