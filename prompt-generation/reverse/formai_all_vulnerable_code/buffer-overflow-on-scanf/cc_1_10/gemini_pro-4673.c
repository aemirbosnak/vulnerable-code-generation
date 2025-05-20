//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <string.h>

// Declare a struct to represent an expense item
typedef struct Expense {
    char description[100];
    float amount;
    char category[50];
} Expense;

// Declare an array of expenses
Expense expenses[100];

// Index of the current expense
int expenseIndex = 0;

// Get user input for an expense
void getExpenseInput(Expense *expense) {
    printf("Enter a description for the expense: ");
    scanf("%s", expense->description);

    printf("Enter the amount of the expense: ");
    scanf("%f", &expense->amount);

    printf("Enter the category of the expense: ");
    scanf("%s", expense->category);
}

// Add an expense to the array
void addExpense(Expense expense) {
    expenses[expenseIndex++] = expense;
}

// Print all expenses
void printExpenses() {
    printf("\nYour expenses are:\n");
    for (int i = 0; i < expenseIndex; i++) {
        printf("%s: $%.2f (%s)\n", expenses[i].description, expenses[i].amount, expenses[i].category);
    }
}

// Main function
int main() {
    // Welcome the user
    printf("Welcome to the Expense Tracker! :D\n");

    // Get user input for expenses
    char input[10];
    do {
        Expense expense;
        getExpenseInput(&expense);
        addExpense(expense);

        // Ask the user if they want to add another expense
        printf("Do you want to add another expense? (y/n) ");
        scanf("%s", input);
    } while (strcmp(input, "y") == 0);

    // Print all expenses
    printExpenses();

    // Thank the user and exit
    printf("\nThank you for using the Expense Tracker! :)\n");
    return 0;
}