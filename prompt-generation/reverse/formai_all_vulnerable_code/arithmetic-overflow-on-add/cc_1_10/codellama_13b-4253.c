//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: safe
/*
 * Personal Finance Planner
 *
 * This program allows the user to input their income, expenses, and savings, and
 * calculates the user's net worth and investment returns over time.
 */

#include <stdio.h>
#include <stdlib.h>

// Define the struct for storing user input
struct user_input {
    int income;
    int expenses;
    int savings;
};

// Define the struct for storing investment data
struct investment_data {
    double initial_amount;
    double interest_rate;
    double years;
};

// Define the struct for storing the calculated values
struct calculated_values {
    double net_worth;
    double investment_returns;
};

// Function to calculate the net worth
void calculate_net_worth(struct user_input user_input, struct calculated_values *calculated_values) {
    calculated_values->net_worth = user_input.income + user_input.savings - user_input.expenses;
}

// Function to calculate the investment returns
void calculate_investment_returns(struct investment_data investment_data, struct calculated_values *calculated_values) {
    calculated_values->investment_returns = investment_data.initial_amount * (1 + investment_data.interest_rate * investment_data.years);
}

// Function to print the results
void print_results(struct calculated_values calculated_values) {
    printf("Net Worth: %f\n", calculated_values.net_worth);
    printf("Investment Returns: %f\n", calculated_values.investment_returns);
}

int main() {
    // Get user input
    struct user_input user_input;
    printf("Enter your income: ");
    scanf("%d", &user_input.income);
    printf("Enter your expenses: ");
    scanf("%d", &user_input.expenses);
    printf("Enter your savings: ");
    scanf("%d", &user_input.savings);

    // Get investment data
    struct investment_data investment_data;
    printf("Enter the initial amount: ");
    scanf("%lf", &investment_data.initial_amount);
    printf("Enter the interest rate: ");
    scanf("%lf", &investment_data.interest_rate);
    printf("Enter the number of years: ");
    scanf("%lf", &investment_data.years);

    // Calculate the net worth and investment returns
    struct calculated_values calculated_values;
    calculate_net_worth(user_input, &calculated_values);
    calculate_investment_returns(investment_data, &calculated_values);

    // Print the results
    print_results(calculated_values);

    return 0;
}