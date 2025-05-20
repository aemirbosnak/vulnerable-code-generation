//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store financial data
typedef struct FinanceData {
    char name[20];
    int income;
    int expenses;
    int savings;
} FinanceData;

// Function to calculate total spending
int calculateTotalSpending(FinanceData *data) {
    return data->expenses + data->savings;
}

// Function to calculate net worth
int calculateNetWorth(FinanceData *data) {
    return data->income - calculateTotalSpending(data);
}

int main() {
    // Create a structure of financial data
    FinanceData myData;

    // Get the user's name, income, expenses, and savings
    printf("Enter your name: ");
    scanf("%s", myData.name);

    printf("Enter your income: ");
    scanf("%d", &myData.income);

    printf("Enter your expenses: ");
    scanf("%d", &myData.expenses);

    printf("Enter your savings: ");
    scanf("%d", &myData.savings);

    // Calculate the total spending
    int totalSpending = calculateTotalSpending(&myData);

    // Calculate the net worth
    int netWorth = calculateNetWorth(&myData);

    // Display the results
    printf("Your total spending is: $%d", totalSpending);

    printf("\nYour net worth is: $%d", netWorth);

    return 0;
}