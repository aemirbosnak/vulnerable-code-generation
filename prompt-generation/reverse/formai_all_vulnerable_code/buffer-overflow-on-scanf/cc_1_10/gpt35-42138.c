//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: puzzling
#include <stdio.h>

// Define variable for income and expenses
float income, expenses;

// Function to calculate net income
float calculateNetIncome(float inc, float exp) {
    return inc - exp;
}

// Function to check if net income is positive or negative
void checkNetIncome(float net) {
    if(net < 0) {
        printf("Oh no! You have a negative net income. You need to revise your budget.\n");
    } else if(net == 0) {
        printf("Your net income is neutral. Make sure you are not overspending.\n");
    } else {
        printf("Great job! Your net income is positive. You can start saving or investing some of it.\n");
    }
}

// Function to calculate percentage of expenses
float calculatePercentExpenses(float inc, float exp) {
    return (exp/inc) * 100;
}

int main() {
    printf("Welcome to the Personal Finance Planner!\n");

    // Ask user for income and expenses
    printf("Please enter your monthly income: ");
    scanf("%f", &income);
    printf("Please enter your monthly expenses: ");
    scanf("%f", &expenses);

    // Calculate net income and print result
    float netIncome = calculateNetIncome(income, expenses);
    printf("Your net income is %.2f.\n", netIncome);

    // Check if net income is positive, negative, or neutral
    checkNetIncome(netIncome);

    // Calculate percentage of expenses and print result
    float percentExpenses = calculatePercentExpenses(income, expenses);
    printf("Your expenses make up %.2f percent of your income.\n", percentExpenses);

    // Check if expenses are too high
    if(percentExpenses >= 50) {
        printf("Your expenses are too high! You need to cut back on some expenses or find ways to increase your income.\n");
    } else {
        printf("Your expenses are within the recommended range. Keep it up!\n");
    }

    return 0;
}