//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: romantic
/*
 * Personal Finance Planner Example Program in a Romantic Style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure to store the financial data of a person
struct FinancialData {
    char name[50];
    float income;
    float expenses;
    float savings;
};

// Function to get the financial data of a person
void getFinancialData(struct FinancialData *financialData) {
    printf("Enter your name: ");
    scanf("%s", financialData->name);

    printf("Enter your monthly income: ");
    scanf("%f", &financialData->income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &financialData->expenses);

    printf("Enter your savings: ");
    scanf("%f", &financialData->savings);
}

// Function to calculate the financial goals of a person
void calculateFinancialGoals(struct FinancialData financialData) {
    float income = financialData.income;
    float expenses = financialData.expenses;
    float savings = financialData.savings;

    // Calculate the total expenses
    float totalExpenses = expenses + savings;

    // Calculate the available income
    float availableIncome = income - totalExpenses;

    // Calculate the financial goal
    float financialGoal = 100000;

    // Calculate the percentage of the financial goal achieved
    float percentage = (availableIncome / financialGoal) * 100;

    // Print the results
    printf("Name: %s\n", financialData.name);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Available Income: %.2f\n", availableIncome);
    printf("Financial Goal: %.2f\n", financialGoal);
    printf("Percentage of Financial Goal Achieved: %.2f%%\n", percentage);
}

int main() {
    // Create a financialData structure
    struct FinancialData financialData;

    // Get the financial data of a person
    getFinancialData(&financialData);

    // Calculate the financial goals of a person
    calculateFinancialGoals(financialData);

    return 0;
}