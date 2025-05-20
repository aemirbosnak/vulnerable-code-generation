//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store financial data
typedef struct FinanceData {
    char name[50];
    int age;
    double income;
    double expenses;
    double netWorth;
} FinanceData;

// Function to calculate net worth
double calculateNetWorth(double income, double expenses) {
    return income - expenses;
}

// Function to update financial data
void updateFinanceData(FinanceData *data) {
    printf("Enter your name: ");
    scanf("%s", data->name);

    printf("Enter your age: ");
    scanf("%d", &data->age);

    printf("Enter your income: ");
    scanf("%lf", &data->income);

    printf("Enter your expenses: ");
    scanf("%lf", &data->expenses);

    data->netWorth = calculateNetWorth(data->income, data->expenses);
}

int main() {
    // Create a structure to store financial data
    FinanceData data;

    // Update financial data
    updateFinanceData(&data);

    // Display financial data
    printf("Name: %s\n", data.name);
    printf("Age: %d\n", data.age);
    printf("Income: %.2lf\n", data.income);
    printf("Expenses: %.2lf\n", data.expenses);
    printf("Net Worth: %.2lf\n", data.netWorth);

    return 0;
}