//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

// Define the main struct for holding financial data
typedef struct Finance {
    float income;
    float expenses[10];
    float savings;
    float investments;
    float debt;
} Finance;

// Function to print the financial data
void printFinance(Finance *finance) {
    printf("Income: $%.2f\n", finance->income);
    printf("Expenses:\n");
    for (int i = 0; i < 10; i++) {
        printf(" - $%.2f\n", finance->expenses[i]);
    }
    printf("Savings: $%.2f\n", finance->savings);
    printf("Investments: $%.2f\n", finance->investments);
    printf("Debt: $%.2f\n", finance->debt);
}

// Function to update the financial data
void updateFinance(Finance *finance) {
    // Get the new income
    printf("Enter your new income: ");
    scanf("%f", &finance->income);

    // Get the new expenses
    printf("Enter your new expenses (up to 10):\n");
    for (int i = 0; i < 10; i++) {
        printf(" - $");
        scanf("%f", &finance->expenses[i]);
    }

    // Get the new savings
    printf("Enter your new savings: ");
    scanf("%f", &finance->savings);

    // Get the new investments
    printf("Enter your new investments: ");
    scanf("%f", &finance->investments);

    // Get the new debt
    printf("Enter your new debt: ");
    scanf("%f", &finance->debt);
}

// Main function
int main() {
    // Create a new Finance struct
    Finance finance;

    // Initialize the Finance struct with some sample data
    finance.income = 5000.00;
    finance.expenses[0] = 1000.00; // Rent
    finance.expenses[1] = 500.00; // Groceries
    finance.expenses[2] = 200.00; // Utilities
    finance.expenses[3] = 100.00; // Transportation
    finance.expenses[4] = 50.00; // Entertainment
    finance.savings = 1000.00;
    finance.investments = 500.00;
    finance.debt = 2000.00;

    // Print the financial data
    printFinance(&finance);

    // Update the financial data
    updateFinance(&finance);

    // Print the updated financial data
    printf("\nUpdated financial data:\n");
    printFinance(&finance);

    return 0;
}