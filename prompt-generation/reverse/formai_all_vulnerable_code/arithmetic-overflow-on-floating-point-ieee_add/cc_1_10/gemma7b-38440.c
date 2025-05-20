//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a struct to store financial data
typedef struct FinancialData {
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
    double investments;
    double netWorth;
} FinancialData;

// Create a function to calculate net worth
double calculateNetWorth(FinancialData *data) {
    data->netWorth = data->savings + data->investments - data->expenses;
    return data->netWorth;
}

// Main function
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

    // Calculate the user's net worth
    calculateNetWorth(&data);

    // Print the user's net worth
    printf("Your net worth is: $%.2lf", data.netWorth);

    return 0;
}