//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Structure to hold personal finance data
typedef struct {
    double income;
    double expenses;
    double savings;
    double net_worth;
} finance_data;

// Function to calculate net worth
double calculate_net_worth(finance_data *data) {
    return data->income - data->expenses + data->savings;
}

// Function to print personal finance data
void print_finance_data(finance_data *data) {
    printf("Income: $%.2f\n", data->income);
    printf("Expenses: $%.2f\n", data->expenses);
    printf("Savings: $%.2f\n", data->savings);
    printf("Net worth: $%.2f\n", calculate_net_worth(data));
}

// Function to get user input for personal finance data
void get_user_input(finance_data *data) {
    printf("Enter your income: $");
    scanf("%lf", &data->income);

    printf("Enter your expenses: $");
    scanf("%lf", &data->expenses);

    printf("Enter your savings: $");
    scanf("%lf", &data->savings);
}

// Function to create a new personal finance planner
finance_data *create_finance_planner() {
    finance_data *data = malloc(sizeof(finance_data));
    get_user_input(data);
    return data;
}

// Function to update personal finance data
void update_finance_data(finance_data *data) {
    get_user_input(data);
}

// Function to delete personal finance data
void delete_finance_planner(finance_data *data) {
    free(data);
}

// Main function
int main() {
    // Create a new personal finance planner
    finance_data *data = create_finance_planner();

    // Print the personal finance data
    print_finance_data(data);

    // Update the personal finance data
    update_finance_data(data);

    // Print the updated personal finance data
    print_finance_data(data);

    // Delete the personal finance planner
    delete_finance_planner(data);

    return 0;
}