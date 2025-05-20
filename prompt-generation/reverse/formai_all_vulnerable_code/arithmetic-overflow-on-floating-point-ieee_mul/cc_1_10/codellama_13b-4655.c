//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: realistic
/*
 * Personal Finance Planner
 * A simple program to help you manage your finances
 *
 * Author: [Your Name]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to store the data
struct finance_data {
    char name[50];
    float income;
    float expenses;
    float savings;
};

// Function to calculate the net income
float calculate_net_income(struct finance_data *data) {
    return data->income - data->expenses;
}

// Function to calculate the savings rate
float calculate_savings_rate(struct finance_data *data) {
    return (data->savings / data->income) * 100;
}

// Function to print the data
void print_data(struct finance_data *data) {
    printf("Name: %s\n", data->name);
    printf("Income: %.2f\n", data->income);
    printf("Expenses: %.2f\n", data->expenses);
    printf("Savings: %.2f\n", data->savings);
    printf("Net Income: %.2f\n", calculate_net_income(data));
    printf("Savings Rate: %.2f%%\n", calculate_savings_rate(data));
}

int main() {
    // Create a new finance data structure
    struct finance_data data;

    // Ask for the user's name
    printf("What is your name? ");
    fgets(data.name, 50, stdin);

    // Ask for the user's income
    printf("What is your income? ");
    scanf("%f", &data.income);

    // Ask for the user's expenses
    printf("What are your expenses? ");
    scanf("%f", &data.expenses);

    // Ask for the user's savings
    printf("What is your savings? ");
    scanf("%f", &data.savings);

    // Print the data
    print_data(&data);

    return 0;
}