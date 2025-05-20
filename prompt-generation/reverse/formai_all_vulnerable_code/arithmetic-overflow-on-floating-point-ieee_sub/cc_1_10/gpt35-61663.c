//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: complex
#include <stdio.h>
#include <stdbool.h>

// Defining constants for user inputs
#define INITIAL_BALANCE_PROMPT "Enter your initial balance: "
#define MONTHLY_INCOME_PROMPT "Enter your monthly income: "
#define MONTHLY_EXPENSE_PROMPT "Enter your monthly expense: "

// Defining constants for program outputs
#define MONTHLY_REPORT_TITLE "Monthly Finance Report:\n"
#define MONTHLY_INCOME_TEXT "Monthly income: %.2lf\n"
#define MONTHLY_EXPENSE_TEXT "Monthly expenses: %.2lf\n"
#define MONTHLY_SAVINGS_TEXT "Monthly savings: %.2lf\n"
#define TOTAL_SAVINGS_TEXT "Total savings: %.2lf\n"

int main() {
    // Initializing variables
    double initial_balance, monthly_income, monthly_expense, monthly_savings, total_savings = 0.00;
    int month = 1;

    printf(INITIAL_BALANCE_PROMPT);
    scanf("%lf", &initial_balance);

    // Starting a loop to generate monthly reports and calculate savings
    while (true) {
        printf(MONTHLY_REPORT_TITLE);

        printf(MONTHLY_INCOME_PROMPT);
        scanf("%lf", &monthly_income);

        printf(MONTHLY_EXPENSE_PROMPT);
        scanf("%lf", &monthly_expense);

        monthly_savings = monthly_income - monthly_expense;
        total_savings += monthly_savings;

        printf(MONTHLY_INCOME_TEXT, monthly_income);
        printf(MONTHLY_EXPENSE_TEXT, monthly_expense);
        printf(MONTHLY_SAVINGS_TEXT, monthly_savings);
        printf(TOTAL_SAVINGS_TEXT, total_savings);

        // Prompting the user to continue generating monthly reports or exit the program
        printf("\n\nDo you want to continue? Enter 0 to exit or 1 to continue.\n");
        int user_input;
        scanf("%d", &user_input);

        if (user_input == 0) {
            break;
        }
        month++;
    }
    return 0;
}