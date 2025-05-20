//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float income;
    float expenses;
    float savings;
} budget;

int main() {
    printf("Welcome to your Personal Finance Planner!\n");

    budget my_budget;

    // Get user input
    printf("Enter your monthly income: ");
    scanf("%f", &my_budget.income);

    printf("Enter your monthly expenses: ");
    scanf("%f", &my_budget.expenses);

    printf("Enter your monthly savings goal: ");
    scanf("%f", &my_budget.savings);

    // Calculate remaining balance
    float remaining_balance = my_budget.income - my_budget.expenses - my_budget.savings;

    // Print budget summary
    printf("\nBudget Summary:\n");
    printf("Income: $%.2f\n", my_budget.income);
    printf("Expenses: $%.2f\n", my_budget.expenses);
    printf("Savings: $%.2f\n", my_budget.savings);
    printf("Remaining Balance: $%.2f\n", remaining_balance);

    // Analyze budget
    if (remaining_balance < 0) {
        printf("\nWarning: Your budget is not balanced. You are spending more than you are earning.\n");
    } else {
        printf("\nYour budget is balanced. Good job!\n");
    }

    // Offer suggestions for improvement
    if (remaining_balance < my_budget.savings) {
        printf("\nSuggestion: Consider increasing your savings goal or reducing your expenses.\n");
    }

    printf("\nThank you for using the Personal Finance Planner!\n");

    return 0;
}