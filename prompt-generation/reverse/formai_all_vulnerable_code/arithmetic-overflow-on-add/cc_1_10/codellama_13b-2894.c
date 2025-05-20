//Code Llama-13B DATASET v1.0 Category: Personal Finance Planner ; Style: beginner-friendly
// Beginner-friendly C Personal Finance Planner example program

#include <stdio.h>
#include <stdlib.h>

// Define constants for input and output
#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

// Define structure for user input
typedef struct {
    int income;
    int savings;
    int expenses;
} UserInput;

// Define structure for calculated data
typedef struct {
    int savingsGoal;
    int savingsRate;
    int savingsBalance;
    int savingsGoalBalance;
} CalculatedData;

// Function to calculate savings rate
void calculateSavingsRate(UserInput *input, CalculatedData *data) {
    data->savingsRate = (input->income * 0.10) / 12;
    data->savingsBalance = input->savings + data->savingsRate;
}

// Function to calculate savings goal
void calculateSavingsGoal(UserInput *input, CalculatedData *data) {
    data->savingsGoal = (input->income * 0.15) / 12;
    data->savingsGoalBalance = data->savingsBalance - data->savingsGoal;
}

// Function to print results
void printResults(UserInput *input, CalculatedData *data) {
    printf("Income: $%.2f\n", input->income);
    printf("Savings: $%.2f\n", input->savings);
    printf("Expenses: $%.2f\n", input->expenses);
    printf("Savings Rate: $%.2f\n", data->savingsRate);
    printf("Savings Balance: $%.2f\n", data->savingsBalance);
    printf("Savings Goal: $%.2f\n", data->savingsGoal);
    printf("Savings Goal Balance: $%.2f\n", data->savingsGoalBalance);
}

int main() {
    // Initialize variables
    UserInput input;
    CalculatedData data;

    // Get input from user
    printf("Enter your income: ");
    scanf("%d", &input.income);
    printf("Enter your savings: ");
    scanf("%d", &input.savings);
    printf("Enter your expenses: ");
    scanf("%d", &input.expenses);

    // Calculate savings rate and balance
    calculateSavingsRate(&input, &data);
    calculateSavingsGoal(&input, &data);

    // Print results
    printResults(&input, &data);

    return 0;
}