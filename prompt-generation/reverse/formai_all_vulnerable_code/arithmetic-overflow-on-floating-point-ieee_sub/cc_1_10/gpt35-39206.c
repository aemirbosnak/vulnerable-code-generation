//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>

float calculateSavings(float, float);
float calculateBudget(float, float);
float calculateInvestment(float, float, float);

int main() {
    float income, expenses, savingsRate, savingsAmount, budget, investments, interestRate, years;
    printf("Enter your monthly income: $");
    scanf("%f", &income);
    printf("Enter your monthly expenses: $");
    scanf("%f", &expenses);
    printf("Enter your desired savings rate (as a percentage): ");
    scanf("%f", &savingsRate);
    printf("Enter the interest rate (as a decimal): ");
    scanf("%f", &interestRate);
    printf("Enter the number of years you plan to invest: ");
    scanf("%f", &years);

    savingsAmount = calculateSavings(income, savingsRate);
    printf("\nBased on your monthly income of $%.2f and desired savings rate of %.2f%%, you should save $%.2f per month.\n", income, savingsRate, savingsAmount);

    budget = calculateBudget(income, expenses);
    printf("\nBased on your monthly income of $%.2f and expenses of $%.2f, your monthly budget is $%.2f.\n", income, expenses, budget);

    investments = calculateInvestment(income, budget, interestRate);
    printf("\nBased on your monthly income of $%.2f, monthly budget of $%.2f, and interest rate of %.2f%%, after %.1f years you will have $%.2f in investments.\n", income, budget, interestRate*100, years, investments);

    return 0;
}

float calculateSavings(float income, float savingsRate) {
    float savingsAmount = (income * (savingsRate/100));
    return savingsAmount;
}

float calculateBudget(float income, float expenses) {
    float budget = income - expenses;
    return budget;
}

float calculateInvestment(float income, float budget, float interestRate) {
    float totalInvestment = 0;
    for (int i = 0; i < 12; i++) {
        totalInvestment += budget;
        totalInvestment += (totalInvestment * interestRate)/12;
    }
    return totalInvestment;
}