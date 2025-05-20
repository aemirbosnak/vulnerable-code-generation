//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {

    // Print welcome message
    printf("Welcome to the Personal Finance Planner!\n\n");

    // Declare variables
    float initial_balance, current_balance, total_income = 0, total_expenses = 0;
    char user_input, expense_choice, continue_input;

    // Ask user for initial balance
    printf("Please enter your initial balance: $");
    scanf("%f", &initial_balance);

    // Set current balance to initial balance
    current_balance = initial_balance;

    // Loop for user input
    do {
        // Ask user for income or expense
        printf("\nWould you like to enter an income or expense? (I/E): ");
        scanf(" %c", &user_input);

        // Convert input to uppercase
        user_input = toupper(user_input);

        // Check if input is valid
        while (user_input != 'I' && user_input != 'E') {
            printf("\nInvalid input! Please enter 'I' for income or 'E' for expense: ");
            scanf(" %c", &user_input);
            user_input = toupper(user_input);
        }

        // If input is income
        if (user_input == 'I') {
            float income_amount;

            // Ask user for income amount
            printf("\nPlease enter the amount of the income: $");
            scanf("%f", &income_amount);

            // Add income amount to total income
            total_income += income_amount;

            // Update current balance
            current_balance += income_amount;

            // Print success message
            printf("\nIncome of $%.2f added to your balance.\n", income_amount);
            printf("Current Balance: $%.2f\n", current_balance);
        }

        // If input is expense
        if (user_input == 'E') {
            do {
                float expense_amount;

                // Ask user for expense amount
                printf("\nPlease enter the amount of the expense: $");
                scanf("%f", &expense_amount);

                // Add expense amount to total expenses
                total_expenses += expense_amount;

                // Update current balance
                current_balance -= expense_amount;

                // Print success message
                printf("\nExpense of $%.2f subtracted from your balance.\n", expense_amount);
                printf("Current Balance: $%.2f\n", current_balance);

                // Ask user if they want to add more expenses
                printf("\nWould you like to add another expense? (Y/N): ");
                scanf(" %c", &continue_input);

                // Convert input to uppercase
                continue_input = toupper(continue_input);

                // Check if input is valid
                while (continue_input != 'Y' && continue_input != 'N') {
                    printf("\nInvalid input! Please enter 'Y' to add another expense or 'N' to stop: ");
                    scanf(" %c", &continue_input);
                    continue_input = toupper(continue_input);
                }

            } while (continue_input == 'Y');

        }

        // Ask user if they want to add more income or expenses
        printf("\nWould you like to add another income or expense? (Y/N): ");
        scanf(" %c", &expense_choice);

        // Convert input to uppercase
        expense_choice = toupper(expense_choice);

        // Check if input is valid
        while (expense_choice != 'Y' && expense_choice != 'N') {
            printf("\nInvalid input! Please enter 'Y' to add another income or expense or 'N' to stop: ");
            scanf(" %c", &expense_choice);
            expense_choice = toupper(expense_choice);
        }

    } while (expense_choice == 'Y');

    // Print final report
    printf("\n*** Personal Finance Report ***\n");
    printf("Initial Balance: $%.2f\n", initial_balance);
    printf("Income: $%.2f\n", total_income);
    printf("Expenses: $%.2f\n", total_expenses);
    printf("Current Balance: $%.2f\n\n", current_balance);
    printf("Thank you for using the Personal Finance Planner!\n");

    return 0;
}