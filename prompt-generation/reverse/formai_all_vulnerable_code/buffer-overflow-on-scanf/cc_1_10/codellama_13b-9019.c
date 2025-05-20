//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
/*
 * Unique C Personal Finance Planner Example Program
 *
 * This program allows the user to input their financial information and
 * receive a personalized financial plan based on their goals and
 * expenses.
 */

#include <stdio.h>

// Function to get user input
void get_input(int *, float *, float *, float *);

// Function to calculate savings rate
float calculate_savings_rate(float, float);

// Function to calculate retirement savings
float calculate_retirement_savings(float, float, float);

int main() {
    // Declare variables
    int age, retirement_age;
    float income, expenses, savings;

    // Get user input
    get_input(&age, &income, &expenses, &savings);

    // Calculate savings rate
    float savings_rate = calculate_savings_rate(income, expenses);

    // Calculate retirement savings
    float retirement_savings = calculate_retirement_savings(income, expenses, savings);

    // Print output
    printf("Savings Rate: %.2f%%\n", savings_rate);
    printf("Retirement Savings: $%.2f\n", retirement_savings);

    return 0;
}

// Function to get user input
void get_input(int *age, float *income, float *expenses, float *savings) {
    printf("Enter your age: ");
    scanf("%d", age);
    printf("Enter your annual income: ");
    scanf("%f", income);
    printf("Enter your annual expenses: ");
    scanf("%f", expenses);
    printf("Enter your current savings: ");
    scanf("%f", savings);
}

// Function to calculate savings rate
float calculate_savings_rate(float income, float expenses) {
    return (income - expenses) / income;
}

// Function to calculate retirement savings
float calculate_retirement_savings(float income, float expenses, float savings) {
    return (income - expenses) * 0.04;
}