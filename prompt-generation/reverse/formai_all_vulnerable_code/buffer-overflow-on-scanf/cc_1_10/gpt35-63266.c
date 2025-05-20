//FormAI DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Declare variables
    int choice;
    float amount;
    float totalExpenses = 0.0;
    char category[20];

    // Define the expense struct
    struct Expense {
        char category[20];
        float amount;
    };

    // Initialize array of expenses
    struct Expense expenses[100];
    int numExpenses = 0;

    printf("---Expense Tracker---\n");

    do {
        printf("\n1. Add an Expense\n2. View Expenses\n3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Prompt user for expense details
                printf("\nEnter the category of the expense: ");
                scanf("%s", category);
                printf("Enter the amount: ");
                scanf("%f", &amount);

                // Add expense to array
                struct Expense newExpense;
                strcpy(newExpense.category, category);
                newExpense.amount = amount;
                expenses[numExpenses++] = newExpense;

                // Add amount to total expenses
                totalExpenses += amount;
                break;
            case 2:
                if (numExpenses == 0) {
                    printf("\nNo expenses to display.\n");
                } else {
                    printf("\n---Expenses---\n");
                    for (int i = 0; i < numExpenses; i++) {
                        printf("%d. %s - $%.2f\n", i+1, expenses[i].category, expenses[i].amount);
                    }
                    printf("Total Expenses: $%.2f\n", totalExpenses);
                }
                break;
            case 3:
                printf("\nExiting program.\n");
                break;
            default:
                printf("\nInvalid choice. Please enter a choice between 1-3.\n");
        }

    } while (choice != 3);

    return 0;
}