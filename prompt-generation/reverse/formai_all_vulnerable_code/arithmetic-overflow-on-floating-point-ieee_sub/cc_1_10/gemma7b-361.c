//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Define a macro for calculating compound interest
#define COMPOUND_INTEREST(amount, rate, years) amount * (1 + rate / 100) * years

// Create a struct to store financial data
typedef struct FinancialData {
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
    double investments;
} FinancialData;

// Function to calculate total net worth
double calculateTotalNetWorth(FinancialData data) {
    return data.savings + data.investments - data.expenses;
}

// Function to calculate monthly expenses
double calculateMonthlyExpenses(FinancialData data) {
    return data.expenses / 12;
}

// Function to calculate monthly savings
double calculateMonthlySavings(FinancialData data) {
    return data.income - calculateMonthlyExpenses(data);
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

    // Calculate the user's monthly savings and net worth
    double savings = calculateMonthlySavings(data);
    double totalNetWorth = calculateTotalNetWorth(data);

    // Print the user's financial data
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Income: %.2lf\n", data.income);
    printf("Expenses: %.2lf\n", data.expenses);
    printf("Savings: %.2lf\n", savings);
    printf("Total Net Worth: %.2lf\n", totalNetWorth);

    return 0;
}