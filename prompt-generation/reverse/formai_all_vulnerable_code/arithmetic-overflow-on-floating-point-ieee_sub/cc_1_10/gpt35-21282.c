//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum length of input string
#define MAX_INPUT 50

// Define the struct for storing financial details
typedef struct {
    float salary;
    float rent;
    float utilities;
    float groceries;
    float entertainment;
    float savings;
} finance;

// Define function to prompt user for financial details and store it in struct
void get_financial_details(finance *f) {
    char input[MAX_INPUT];

    printf("Enter your monthly salary: $");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%f", &f->salary);

    printf("Enter your monthly rent/mortgage payments: $");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%f", &f->rent);

    printf("Enter your monthly utilities bills: $");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%f", &f->utilities);

    printf("Enter your monthly groceries expenses: $");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%f", &f->groceries);

    printf("Enter your monthly entertainment expenses: $");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%f", &f->entertainment);

    printf("Enter your monthly savings amount: $");
    fgets(input, MAX_INPUT, stdin);
    sscanf(input, "%f", &f->savings);
}

// Define function to display financial details
void display_financial_details(finance f) {
    printf("\nYour Monthly Financial Details:\n");
    printf("\tSalary: $%.2f\n", f.salary);
    printf("\tRent/Mortgage: $%.2f\n", f.rent);
    printf("\tUtilities Bills: $%.2f\n", f.utilities);
    printf("\tGroceries Expenses: $%.2f\n", f.groceries);
    printf("\tEntertainment Expenses: $%.2f\n", f.entertainment);
    printf("\tSavings: $%.2f\n", f.savings);
    printf("\n");
}

// Define function to calculate monthly expenses
float calculate_monthly_expenses(finance f) {
    float total_expenses = f.rent + f.utilities + f.groceries + f.entertainment;

    return total_expenses;
}

// Define function to calculate remaining income after expenses and savings
float calculate_remaining_income(finance f) {
    float total_income = f.salary;
    float total_expenses = calculate_monthly_expenses(f);
    float total_savings = f.savings;

    float remaining_income = total_income - total_expenses - total_savings;

    return remaining_income;
}

// Define main function
int main(void) {
    finance f;

    printf("Welcome to the Personal Finance Planner!\n\n");

    // Prompts user for financial details
    get_financial_details(&f);

    // Displays financial details
    display_financial_details(f);

    // Calculate monthly expenses
    float monthly_expenses = calculate_monthly_expenses(f);
    printf("Total Monthly Expenses: $%.2f\n", monthly_expenses);

    // Calculate remaining income after expenses and savings
    float remaining_income = calculate_remaining_income(f);
    printf("Remaining Income after Expenses and Savings: $%.2f\n", remaining_income);

    return 0;
}