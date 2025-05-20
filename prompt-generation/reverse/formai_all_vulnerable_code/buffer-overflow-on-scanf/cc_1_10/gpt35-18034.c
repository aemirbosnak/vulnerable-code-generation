//FormAI DATASET v1.0 Category: Expense Tracker ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold expense details
typedef struct {
    char item[50];
    float amount;
} Expense;

int main(void) {
    // Initialize the array of expenses
    Expense expenses[50];
    int numExpenses = 0;

    // Print welcome message and instructions
    printf("Welcome to the Expense Tracker program!\n");
    printf("Enter 'quit' to stop adding expenses.\n\n");

    // Loop to get user input and add expenses
    char input[50];
    while (1) {
        printf("Enter expense item: ");
        fgets(input, sizeof(input), stdin);

        // Check if user wants to quit
        if (strcmp(input, "quit\n") == 0) {
            break;
        }

        // Get expense amount
        float expenseAmount;
        printf("Enter expense amount: ");
        scanf("%f", &expenseAmount);
        getchar(); // Consume newline character left in input buffer

        // Add expense to array
        Expense expense;
        strcpy(expense.item, input);
        expense.amount = expenseAmount;
        expenses[numExpenses] = expense;
        numExpenses++;
    }

    // Print all expenses
    printf("\nExpenses:\n");
    printf("Item\tAmount\n");
    printf("----\t------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s", expenses[i].item);
        printf("%.2f\n", expenses[i].amount);
    }

    // Calculate and print total expenses
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    printf("\nTotal expenses: %.2f\n", total);

    return 0;
}