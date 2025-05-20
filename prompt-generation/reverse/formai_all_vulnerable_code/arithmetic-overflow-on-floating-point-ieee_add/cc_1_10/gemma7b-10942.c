//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a structure to store financial data
typedef struct FinancialData {
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
    double investments;
} FinancialData;

// Function to calculate total assets
double calculateTotalAssets(FinancialData data) {
    return data.savings + data.investments;
}

// Function to calculate total liabilities
double calculateTotalLiabilities(FinancialData data) {
    return data.expenses;
}

// Function to calculate net worth
double calculateNetWorth(FinancialData data) {
    return calculateTotalAssets(data) - calculateTotalLiabilities(data);
}

int main() {
    // Create a financial data structure
    FinancialData data;

    // Get the user's name, age, income, expenses, savings, and investments
    printf("Enter your name: ");
    scanf("%s", data.name);

    printf("Enter your age: ");
    scanf("%d", &data.age);

    printf("Enter your income: ");
    scanf("%lf", &data.income);

    printf("Enter your expenses: ");
    scanf("%lf", &data.expenses);

    printf("Enter your savings: ");
    scanf("%lf", &data.savings);

    printf("Enter your investments: ");
    scanf("%lf", &data.investments);

    // Calculate the total assets, total liabilities, and net worth
    double totalAssets = calculateTotalAssets(data);
    double totalLiabilities = calculateTotalLiabilities(data);
    double netWorth = calculateNetWorth(data);

    // Print the results
    printf("Total Assets: $%.2lf\n", totalAssets);
    printf("Total Liabilities: $%.2lf\n", totalLiabilities);
    printf("Net Worth: $%.2lf\n", netWorth);

    return 0;
}