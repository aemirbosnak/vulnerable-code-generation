//FormAI DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>

// Define a structure to hold expense information
struct Expense {
    char date[11];
    char category[20];
    float amount;
};

int main() {
    // Welcome message
    printf("Welcome to your Expense Tracker!\n");

    // Initialize variables
    int numExpenses = 0;
    int maxExpenses = 100;
    struct Expense expenses[maxExpenses];
    char choice;

    // Main menu
    do {
        printf("\n-------------\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            // Add expense
            case '1':
                if (numExpenses == maxExpenses) {
                    printf("You have reached the maximum number of expenses.\n");
                    break;
                }
                printf("\nEnter expense date (MM/DD/YYYY): ");
                scanf("%s", expenses[numExpenses].date);
                printf("Enter expense category: ");
                scanf(" %[^\n]", expenses[numExpenses].category);
                printf("Enter expense amount: ");
                scanf("%f", &expenses[numExpenses].amount);
                numExpenses++;
                printf("\nExpense added.\n");
                break;

            // View expenses
            case '2':
                if (numExpenses == 0) {
                    printf("You have no expenses.\n");
                    break;
                }
                printf("\nExpenses:\n");
                printf("%-12s %-20s %-10s\n", "Date", "Category", "Amount");
                printf("----------------------------------------\n");
                for (int i = 0; i < numExpenses; i++) {
                    printf("%-12s %-20s $%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
                }
                break;

            // Quit
            case '3':
                printf("\nThank you for using your Expense Tracker!\n");
                break;

            // Invalid choice
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    } while (choice != '3');

    return 0;
}