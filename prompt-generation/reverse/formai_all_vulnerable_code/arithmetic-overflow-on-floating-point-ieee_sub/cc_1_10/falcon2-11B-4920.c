//Falcon2-11B DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the data structures
typedef struct {
    char name[50];
    double income;
    double expenses;
    double savings;
} Finance;

// Function to calculate the net income
double calculateNetIncome(Finance* finance) {
    return finance->income - finance->expenses;
}

// Function to calculate the net savings
double calculateNetSavings(Finance* finance) {
    return finance->savings - finance->expenses;
}

// Function to print the finance details
void printFinance(Finance* finance) {
    printf("Name: %s\n", finance->name);
    printf("Income: %.2f\n", finance->income);
    printf("Expenses: %.2f\n", finance->expenses);
    printf("Savings: %.2f\n", finance->savings);
}

// Main function
int main() {
    Finance finance;

    // Input the finance details
    printf("Enter the name: ");
    scanf("%s", finance.name);
    printf("Enter the income: ");
    scanf("%lf", &finance.income);
    printf("Enter the expenses: ");
    scanf("%lf", &finance.expenses);
    printf("Enter the savings: ");
    scanf("%lf", &finance.savings);

    // Calculate the net income and savings
    double netIncome = calculateNetIncome(&finance);
    double netSavings = calculateNetSavings(&finance);

    // Print the finance details
    printf("Finance Details:\n");
    printFinance(&finance);
    printf("Net Income: %.2f\n", netIncome);
    printf("Net Savings: %.2f\n", netSavings);

    return 0;
}