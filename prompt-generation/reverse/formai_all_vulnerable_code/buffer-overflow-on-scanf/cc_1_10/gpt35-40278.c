//FormAI DATASET v1.0 Category: Personal Finance Planner ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// Define the structure for holding financial information
struct finance {
    float income;
    float expenses;
    float savings;
    float investments;
};

int main() {
    // Declare a variable to hold the user's input
    int choice;
    // Create a finance structure for the user
    struct finance financePlanner;

    // Set the values of the finance structure to 0
    financePlanner.income = 0;
    financePlanner.expenses = 0;
    financePlanner.savings = 0;
    financePlanner.investments = 0;

    // Print out the main menu
    printf("Welcome to the Personal Finance Planner!\n");
    printf("1. Enter your income\n");
    printf("2. Enter your expenses\n");
    printf("3. Enter your savings\n");
    printf("4. Enter your investments\n");
    printf("5. Exit\n");

    // Loop until the user chooses to exit
    while (1) {
        // Ask the user to enter a choice
        printf("Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Ask the user to enter their income
                printf("Please enter your income: ");
                scanf("%f", &financePlanner.income);
                break;
            case 2:
                // Ask the user to enter their expenses
                printf("Please enter your expenses: ");
                scanf("%f", &financePlanner.expenses);
                break;
            case 3:
                // Ask the user to enter their savings
                printf("Please enter your savings: ");
                scanf("%f", &financePlanner.savings);
                break;
            case 4:
                // Ask the user to enter their investments
                printf("Please enter your investments: ");
                scanf("%f", &financePlanner.investments);
                break;
            case 5:
                // Exit the program
                printf("Thank you for using the Personal Finance Planner!\n");
                exit(0);
            default:
                // Inform the user of an invalid choice
                printf("Invalid choice! Please try again.\n");
                break;
        }

        // Calculate the user's total income, expenses, savings, and investments
        float totalIncome = financePlanner.income;
        float totalExpenses = financePlanner.expenses;
        float totalSavings = financePlanner.savings;
        float totalInvestments = financePlanner.investments;

        // Print out the user's financial information
        printf("\n");
        printf("Total Income: %.2f\n", totalIncome);
        printf("Total Expenses: %.2f\n", totalExpenses);
        printf("Total Savings: %.2f\n", totalSavings);
        printf("Total Investments: %.2f\n", totalInvestments);
        printf("\n");
    }
}