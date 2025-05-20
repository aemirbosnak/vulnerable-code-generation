//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: secure
/*
* Personal Finance Planner Example Program
*
* This program allows the user to input their financial information, such as income, expenses, and savings, and provides a breakdown of their financial status.
*
* Author: [Your Name]
* Date: [Current Date]
*/

#include <stdio.h>

// Define constants for the financial information
#define INCOME 0
#define EXPENSES 1
#define SAVINGS 2
#define TAXES 3

// Define a struct to hold the financial information
typedef struct {
    double income;
    double expenses;
    double savings;
    double taxes;
} FinancialInfo;

// Define a function to calculate the net income
double calculateNetIncome(FinancialInfo *financialInfo) {
    return financialInfo->income - financialInfo->expenses;
}

// Define a function to calculate the taxes paid
double calculateTaxesPaid(FinancialInfo *financialInfo) {
    return financialInfo->taxes * financialInfo->income;
}

// Define a function to calculate the savings
double calculateSavings(FinancialInfo *financialInfo) {
    return financialInfo->savings - financialInfo->expenses;
}

// Define a function to calculate the total income
double calculateTotalIncome(FinancialInfo *financialInfo) {
    return financialInfo->income + financialInfo->taxes;
}

// Define a function to print the financial information
void printFinancialInfo(FinancialInfo *financialInfo) {
    printf("Income: %.2f\n", financialInfo->income);
    printf("Expenses: %.2f\n", financialInfo->expenses);
    printf("Savings: %.2f\n", financialInfo->savings);
    printf("Taxes: %.2f\n", financialInfo->taxes);
}

int main() {
    // Initialize the financial information
    FinancialInfo financialInfo;
    financialInfo.income = 0;
    financialInfo.expenses = 0;
    financialInfo.savings = 0;
    financialInfo.taxes = 0;

    // Ask the user for their financial information
    printf("Enter your income: ");
    scanf("%lf", &financialInfo.income);
    printf("Enter your expenses: ");
    scanf("%lf", &financialInfo.expenses);
    printf("Enter your savings: ");
    scanf("%lf", &financialInfo.savings);
    printf("Enter your taxes: ");
    scanf("%lf", &financialInfo.taxes);

    // Calculate the net income
    double netIncome = calculateNetIncome(&financialInfo);

    // Calculate the taxes paid
    double taxesPaid = calculateTaxesPaid(&financialInfo);

    // Calculate the savings
    double savings = calculateSavings(&financialInfo);

    // Calculate the total income
    double totalIncome = calculateTotalIncome(&financialInfo);

    // Print the financial information
    printFinancialInfo(&financialInfo);

    // Print the net income
    printf("Net Income: %.2f\n", netIncome);

    // Print the taxes paid
    printf("Taxes Paid: %.2f\n", taxesPaid);

    // Print the savings
    printf("Savings: %.2f\n", savings);

    // Print the total income
    printf("Total Income: %.2f\n", totalIncome);

    return 0;
}