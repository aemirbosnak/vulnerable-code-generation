//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store financial data
typedef struct FinancialData {
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
} FinancialData;

// Function to calculate total savings
double calculateTotalSavings(FinancialData data) {
    double totalSavings = data.savings;
    return totalSavings;
}

// Function to calculate total expenses
double calculateTotalExpenses(FinancialData data) {
    double totalExpenses = data.expenses;
    return totalExpenses;
}

// Function to calculate net worth
double calculateNetWorth(FinancialData data) {
    double netWorth = data.income - calculateTotalExpenses(data) - calculateTotalSavings(data);
    return netWorth;
}

int main() {
    // Create a financial data structure
    FinancialData myData;

    // Get the user's name, age, income, and expenses
    printf("What is your name? ");
    scanf("%s", myData.name);

    printf("How old are you? ");
    scanf("%d", &myData.age);

    printf("What is your income? ");
    scanf("%lf", &myData.income);

    printf("What are your expenses? ");
    scanf("%lf", &myData.expenses);

    // Calculate the user's total savings, total expenses, and net worth
    double totalSavings = calculateTotalSavings(myData);
    double totalExpenses = calculateTotalExpenses(myData);
    double netWorth = calculateNetWorth(myData);

    // Print the results
    printf("Your total savings are $%.2lf.", totalSavings);
    printf("\nYour total expenses are $%.2lf.", totalExpenses);
    printf("\nYour net worth is $%.2lf.", netWorth);

    return 0;
}