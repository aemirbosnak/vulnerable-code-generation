//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create a struct to store financial data
typedef struct FinancialData {
    char name[50];
    int income;
    int expenses;
    int savings;
} FinancialData;

// Function to calculate total spending
int calculateTotalSpending(FinancialData data) {
    return data.expenses + data.savings;
}

// Function to calculate total savings
int calculateTotalSavings(FinancialData data) {
    return data.savings;
}

int main() {
    // Create a financial data structure
    FinancialData data;

    // Get the user's name, income, expenses, and savings
    printf("Enter your name: ");
    scanf("%s", data.name);

    printf("Enter your income: ");
    scanf("%d", &data.income);

    printf("Enter your expenses: ");
    scanf("%d", &data.expenses);

    printf("Enter your savings: ");
    scanf("%d", &data.savings);

    // Calculate the total spending and savings
    int totalSpending = calculateTotalSpending(data);
    int totalSavings = calculateTotalSavings(data);

    // Print the results
    printf("Your name: %s\n", data.name);
    printf("Your income: %d\n", data.income);
    printf("Your expenses: %d\n", data.expenses);
    printf("Your savings: %d\n", data.savings);
    printf("Your total spending: %d\n", totalSpending);
    printf("Your total savings: %d\n", totalSavings);

    return 0;
}