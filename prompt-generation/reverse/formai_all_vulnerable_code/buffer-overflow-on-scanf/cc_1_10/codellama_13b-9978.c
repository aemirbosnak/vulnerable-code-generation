//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: optimized
// Personal Finance Planner

#include <stdio.h>
#include <stdlib.h>

// Structure to hold user input
struct UserInput {
    int income, savings, debt, investments;
};

// Structure to hold calculated values
struct CalculatedValues {
    int net_worth, debt_to_income_ratio, investment_return;
};

// Function to calculate net worth
void calculate_net_worth(struct UserInput *user_input, struct CalculatedValues *calculated_values) {
    calculated_values->net_worth = user_input->income + user_input->savings - user_input->debt - user_input->investments;
}

// Function to calculate debt-to-income ratio
void calculate_debt_to_income_ratio(struct UserInput *user_input, struct CalculatedValues *calculated_values) {
    calculated_values->debt_to_income_ratio = user_input->debt / (user_input->income * 0.3);
}

// Function to calculate investment return
void calculate_investment_return(struct UserInput *user_input, struct CalculatedValues *calculated_values) {
    calculated_values->investment_return = user_input->investments / user_input->income;
}

int main() {
    struct UserInput user_input;
    struct CalculatedValues calculated_values;

    // Get user input
    printf("Enter your income: ");
    scanf("%d", &user_input.income);
    printf("Enter your savings: ");
    scanf("%d", &user_input.savings);
    printf("Enter your debt: ");
    scanf("%d", &user_input.debt);
    printf("Enter your investments: ");
    scanf("%d", &user_input.investments);

    // Calculate net worth
    calculate_net_worth(&user_input, &calculated_values);

    // Calculate debt-to-income ratio
    calculate_debt_to_income_ratio(&user_input, &calculated_values);

    // Calculate investment return
    calculate_investment_return(&user_input, &calculated_values);

    // Print results
    printf("Net Worth: %d\n", calculated_values.net_worth);
    printf("Debt-to-Income Ratio: %d\n", calculated_values.debt_to_income_ratio);
    printf("Investment Return: %d\n", calculated_values.investment_return);

    return 0;
}