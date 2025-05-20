//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store financial data
typedef struct FinancialData {
    char name[50];
    int income;
    int expenses;
    int savings;
} FinancialData;

// Function to calculate total savings
int calculateTotalSavings(FinancialData data) {
    return data.savings + data.income - data.expenses;
}

// Function to display financial data
void displayFinancialData(FinancialData data) {
    printf("Name: %s\n", data.name);
    printf("Income: %d\n", data.income);
    printf("Expenses: %d\n", data.expenses);
    printf("Savings: %d\n", data.savings);
    printf("Total Savings: %d\n", calculateTotalSavings(data));
}

int main() {
    // Create a financial data structure
    FinancialData data;

    // Get the user's name, income, expenses, and savings
    printf("What is your name? ");
    scanf("%s", data.name);

    printf("What is your income? ");
    scanf("%d", &data.income);

    printf("What are your expenses? ");
    scanf("%d", &data.expenses);

    printf("What are your savings? ");
    scanf("%d", &data.savings);

    // Calculate the total savings
    int totalSavings = calculateTotalSavings(data);

    // Display the financial data
    displayFinancialData(data);

    // Print the total savings
    printf("Total Savings: %d\n", totalSavings);

    return 0;
}