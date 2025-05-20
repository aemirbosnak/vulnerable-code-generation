//Gemma-7B DATASET v1.0 Category: Personal Finance Planner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store financial data
struct financial_data {
    char name[50];
    int age;
    double income;
    double expenses;
    double savings;
    double investments;
};

// Function to calculate total assets
double calculate_total_assets(struct financial_data *data) {
    return data->savings + data->investments;
}

// Function to calculate total liabilities
double calculate_total_liabilities(struct financial_data *data) {
    return 0; // Assuming there are no liabilities
}

// Function to calculate net worth
double calculate_net_worth(struct financial_data *data) {
    return calculate_total_assets(data) - calculate_total_liabilities(data);
}

int main() {
    // Create a structure instance
    struct financial_data data;

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

    // Calculate the total assets, total liabilities, and net worth
    double total_assets = calculate_total_assets(&data);
    double total_liabilities = calculate_total_liabilities(&data);
    double net_worth = calculate_net_worth(&data);

    // Print the results
    printf("Your total assets are: $%.2lf\n", total_assets);
    printf("Your total liabilities are: $%.2lf\n", total_liabilities);
    printf("Your net worth is: $%.2lf\n", net_worth);

    return 0;
}