//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store financial information
typedef struct FinancialData {
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
} FinancialData;

// Function to calculate the total amount of savings
double calculateSavings(FinancialData *data) {
    return data->savings;
}

// Function to calculate the total amount of expenses
double calculateExpenses(FinancialData *data) {
    return data->expenses;
}

// Function to calculate the net worth
double calculateNetWorth(FinancialData *data) {
    return data->income - calculateExpenses(data) - calculateSavings(data);
}

int main() {
    // Create a financial data structure
    FinancialData data;

    // Get the user's name, age, income, and expenses
    printf("Enter your name: ");
    scanf("%s", data.name);

    printf("Enter your age: ");
    scanf("%d", &data.age);

    printf("Enter your income: ");
    scanf("%lf", &data.income);

    printf("Enter your expenses: ");
    scanf("%lf", &data.expenses);

    // Calculate the total amount of savings, expenses, and net worth
    double savings = calculateSavings(&data);
    double expenses = calculateExpenses(&data);
    double netWorth = calculateNetWorth(&data);

    // Print the results
    printf("Your name: %s\n", data.name);
    printf("Your age: %d\n", data.age);
    printf("Your income: %.2lf\n", data.income);
    printf("Your expenses: %.2lf\n", expenses);
    printf("Your savings: %.2lf\n", savings);
    printf("Your net worth: %.2lf\n", netWorth);

    return 0;
}