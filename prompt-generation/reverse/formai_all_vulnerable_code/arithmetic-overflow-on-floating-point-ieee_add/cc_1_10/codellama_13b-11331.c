//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: enthusiastic
/*
*  Personal Finance Planner
*  By: [Your Name]
*  Date: [Date]
*
*  This program helps you plan your finances and make smart decisions.
*  It calculates your net worth, investment returns, and expenses.
*  It also provides suggestions for saving and investing.
*/

#include <stdio.h>
#include <stdlib.h>

// Struct for holding financial information
struct FinancialInfo {
    float netWorth;
    float investmentReturns;
    float expenses;
};

// Function to calculate net worth
float calculateNetWorth(struct FinancialInfo* info) {
    return info->netWorth + info->investmentReturns - info->expenses;
}

// Function to calculate investment returns
float calculateInvestmentReturns(struct FinancialInfo* info) {
    return info->netWorth * 0.05;
}

// Function to calculate expenses
float calculateExpenses(struct FinancialInfo* info) {
    return info->netWorth * 0.10;
}

// Function to print financial information
void printFinancialInfo(struct FinancialInfo* info) {
    printf("Net Worth: $%.2f\n", info->netWorth);
    printf("Investment Returns: $%.2f\n", info->investmentReturns);
    printf("Expenses: $%.2f\n", info->expenses);
    printf("Net Worth After Expenses: $%.2f\n", calculateNetWorth(info));
}

// Main function
int main() {
    // Initialize financial information
    struct FinancialInfo info;
    info.netWorth = 10000;
    info.investmentReturns = calculateInvestmentReturns(&info);
    info.expenses = calculateExpenses(&info);

    // Print financial information
    printFinancialInfo(&info);

    // Get user input for investment amount
    float investmentAmount;
    printf("Enter investment amount: ");
    scanf("%f", &investmentAmount);

    // Calculate investment returns
    info.investmentReturns += investmentAmount;
    info.netWorth += investmentAmount;

    // Calculate expenses
    info.expenses = calculateExpenses(&info);

    // Print financial information
    printFinancialInfo(&info);

    return 0;
}