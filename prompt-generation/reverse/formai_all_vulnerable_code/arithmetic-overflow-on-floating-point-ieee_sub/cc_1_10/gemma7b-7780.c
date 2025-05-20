//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store financial data
typedef struct FinanceData
{
    char name[20];
    int age;
    double income;
    double expenses;
    double savings;
} FinanceData;

// Function to calculate total savings
double calculateSavings(FinanceData *data)
{
    return data->savings;
}

// Function to calculate total expenses
double calculateExpenses(FinanceData *data)
{
    return data->expenses;
}

// Function to calculate net worth
double calculateNetWorth(FinanceData *data)
{
    return data->income - calculateExpenses(data) - calculateSavings(data);
}

int main()
{
    // Create a structure instance
    FinanceData data;

    // Get the user's name, age, income, and expenses
    printf("Enter your name: ");
    scanf("%s", data.name);

    printf("Enter your age: ");
    scanf("%d", &data.age);

    printf("Enter your income: ");
    scanf("%lf", &data.income);

    printf("Enter your expenses: ");
    scanf("%lf", &data.expenses);

    // Calculate the user's savings
    data.savings = calculateSavings(&data);

    // Calculate the user's net worth
    double netWorth = calculateNetWorth(&data);

    // Print the user's net worth
    printf("Your net worth is: $%lf", netWorth);

    return 0;
}