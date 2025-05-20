//FormAI DATASET v1.0 Category: Expense Tracker ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100 // Maximum number of expenses that can be stored
#define MAX_NAME_LENGTH 50 // Maximum length of expense name

// Define a structure to hold the expense information
struct Expense {
    char name[MAX_NAME_LENGTH];
    float cost;
};

// Define a function to prompt the user for information about a new expense
void promptForExpense(struct Expense* expense) {
    printf("Enter the name of the expense: ");
    fgets(expense->name, MAX_NAME_LENGTH, stdin);
    expense->name[strcspn(expense->name, "\n")] = 0; // Remove trailing newline from input
    printf("Enter the cost of the expense: ");
    scanf("%f", &expense->cost);
    getchar(); // Remove trailing newline from input
}

// Define a function to print out a list of all expenses
void printExpenses(struct Expense* expenses, int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%s: $%.2f\n", expenses[i].name, expenses[i].cost);
    }
}

int main() {
    // Declare variables for tracking expenses
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    
    // Keep prompting the user for new expenses until they choose to exit
    char input[10];
    while (1) {
        printf("Enter a new expense (or 'q' to quit): ");
        fgets(input, 10, stdin);
        
        if (strcmp(input, "q\n") == 0) {
            break;
        }
        
        // Make sure we don't exceed the maximum number of expenses
        if (numExpenses >= MAX_EXPENSES) {
            printf("Cannot add any more expenses!\n");
            continue;
        }
        
        // Prompt the user for information about the new expense and add it to the list
        struct Expense* newExpense = &expenses[numExpenses];
        promptForExpense(newExpense);
        numExpenses++;
    }
    
    // Print out the final list of expenses
    printExpenses(expenses, numExpenses);
    
    return 0;
}