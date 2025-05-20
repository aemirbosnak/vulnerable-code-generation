//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Define a structure to store financial data
typedef struct FinancialData {
    char name[20];
    int age;
    double income;
    double expenses;
    double savings;
} FinancialData;

// Function to calculate financial data
void calculateFinancialData(FinancialData *data) {
    data->savings = data->income - data->expenses;
}

// Function to save financial data to a file
void saveFinancialData(FinancialData *data) {
    FILE *file = fopen("financial_data.txt", "w");
    fprintf(file, "Name: %s\n", data->name);
    fprintf(file, "Age: %d\n", data->age);
    fprintf(file, "Income: %.2lf\n", data->income);
    fprintf(file, "Expenses: %.2lf\n", data->expenses);
    fprintf(file, "Savings: %.2lf\n", data->savings);
    fclose(file);
}

// Main function
int main() {
    // Create a financial data structure
    FinancialData data;

    // Get the user's name, age, income, and expenses
    printf("Enter your name: ");
    scanf("%s", data.name);

    printf("Enter your age: ");
    scanf("%d", &data.age);

    printf("Enter your income: ");
    scanf("%lf", &data.income);

    printf("Enter your expenses: ");
    scanf("%lf", &data.expenses);

    // Calculate the financial data
    calculateFinancialData(&data);

    // Save the financial data to a file
    saveFinancialData(&data);

    // Print the financial data
    printf("Your name: %s\n", data.name);
    printf("Your age: %d\n", data.age);
    printf("Your income: %.2lf\n", data.income);
    printf("Your expenses: %.2lf\n", data.expenses);
    printf("Your savings: %.2lf\n", data.savings);

    return 0;
}