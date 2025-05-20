//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: multivariable
#include <stdio.h>

void displayMenu();
void calculateSavings(double income, double expenses, double investment);
void calculateExpenses(double income, double expenses, double investment);
void calculateInvestment(double income, double expenses, double investment);

int main() {
    double income, expenses, investment;
    displayMenu();

    // Get input values
    printf("Enter your monthly income: ");
    scanf("%lf", &income);
    printf("Enter your monthly expenses: ");
    scanf("%lf", &expenses);
    printf("Enter your monthly investment: ");
    scanf("%lf", &investment);

    calculateSavings(income, expenses, investment);

    return 0;
}

void displayMenu() {
    printf("\n--------------------------\n");
    printf("| Personal Finance Planner |\n");
    printf("--------------------------\n\n");
    printf("What would you like to calculate?\n");
    printf("1 - Savings\n");
    printf("2 - Expenses\n");
    printf("3 - Investment\n");
}

void calculateSavings(double income, double expenses, double investment) {
    double savings = income - expenses - investment;

    printf("\n--------------------------------\n");
    printf("|          Savings             |\n");
    printf("--------------------------------\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("Investment: $%.2f\n", investment);
    printf("Savings: $%.2f\n", savings);
}

void calculateExpenses(double income, double expenses, double investment) {
    double newExpenses = income - investment;

    printf("\n--------------------------------\n");
    printf("|          Expenses            |\n");
    printf("--------------------------------\n");
    printf("Income: $%.2f\n", income);
    printf("Current Expenses: $%.2f\n", expenses);
    printf("New Expenses: $%.2f\n", newExpenses);
    printf("Investment: $%.2f\n", investment);
}

void calculateInvestment(double income, double expenses, double investment) {
    double newInvestment = income - expenses;

    printf("\n--------------------------------\n");
    printf("|         Investment           |\n");
    printf("--------------------------------\n");
    printf("Income: $%.2f\n", income);
    printf("Expenses: $%.2f\n", expenses);
    printf("Current Investment: $%.2f\n", investment);
    printf("New Investment: $%.2f\n", newInvestment);
}