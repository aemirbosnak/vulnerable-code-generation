//FormAI DATASET v1.0 Category: Expense Tracker ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a MAX value for expenses array
#define MAX_EXPENSES 10

// Define a struct for an expense
struct Expense {
    char name[20];
    double cost;
};

// Declare variables for total expenses and number of expenses
double totalExpenses = 0;
int numExpenses = 0;

// Declare an array of expenses
struct Expense expenses[MAX_EXPENSES];

int main() {
    int option = 0;
    int i;

    // Welcome message
    printf("Welcome to the Expense Tracker!\n");

    // Loop through menu options until user quits
    while (option != 4) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add an expense\n");
        printf("2. View all expenses\n");
        printf("3. View total expenses\n");
        printf("4. Quit\n");
        printf("Option: ");

        // Get user input for menu option
        scanf("%d", &option);

        switch(option) {
            case 1:
                // Add an expense
                if (numExpenses >= MAX_EXPENSES) {
                    printf("Max expenses reached. Cannot add more.\n");
                    break;
                }

                printf("\nEnter the expense name: ");
                scanf("%s", expenses[numExpenses].name);

                printf("Enter the expense cost: ");
                scanf("%lf", &expenses[numExpenses].cost);

                // Update total expenses and numExpenses
                totalExpenses += expenses[numExpenses].cost;
                numExpenses++;

                printf("\nExpense added successfully.\n");
                break;
            case 2:
                // View all expenses
                if (numExpenses == 0) {
                    printf("\nNo expenses added yet.\n");
                    break;
                }

                printf("\nALL EXPENSES:\n");
                printf("--------------------------------------------------\n");

                for (i = 0; i < numExpenses; i++) {
                    printf("%s - $%.2lf\n", expenses[i].name, expenses[i].cost);
                }

                printf("\n");
                break;
            case 3:
                // View total expenses
                printf("\nTOTAL EXPENSES: $%.2lf\n", totalExpenses);
                break;
            case 4:
                // Quit
                printf("\nThank you for using the Expense Tracker!\n");
                break;
            default:
                printf("\nInvalid option. Please try again.\n");
                break;
        }
    }

    return 0;
}