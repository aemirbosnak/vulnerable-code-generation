//FormAI DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be recorded
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char date[11];          // Date of expense (format: YYYY/MM/DD)
    char category[21];      // Category of expense (e.g. food, transportation)
    double amount;          // Amount paid for the expense
} Expense;

// Define a function to add an expense to the array of expenses
void addExpense(Expense expenses[], int *numExpenses, char date[], char category[], double amount) {

    // Check if we have reached the maximum number of expenses
    if (*numExpenses >= MAX_EXPENSES) {
        printf("You have reached the maximum number of expenses that can be recorded.\n");
        return;
    }

    // Add the new expense to the array
    strcpy(expenses[*numExpenses].date, date);
    strcpy(expenses[*numExpenses].category, category);
    expenses[*numExpenses].amount = amount;

    // Increment the number of expenses
    (*numExpenses)++;

    printf("Expense added!\n");
}

// Define a function to display all expenses in the array of expenses
void displayExpenses(Expense expenses[], int numExpenses) {
    printf("\n--- List of Expenses ---\n");

    // Loop through each expense in the array and display its details
    for (int i = 0; i < numExpenses; i++) {
        printf("Date: %s | Category: %s | Amount: %.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }

    printf("------------------------\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];     // Array of expenses
    int numExpenses = 0;                // Number of expenses in the array

    // Display instructions to the user
    printf("Welcome to the Expense Tracker!\n");
    printf("To add an expense: add <date> <category> <amount>\n");
    printf("To display all expenses: display\n");
    printf("To exit: exit\n");

    // Loop until the user enters "exit"
    while (1) {
        char command[10];
        char date[11];
        char category[21];
        double amount;

        // Get the user's command
        printf("\nEnter command: ");
        scanf("%s", command);

        // Perform the appropriate action based on the user's command
        if (strcmp(command, "add") == 0) {
            scanf("%s %s %lf", date, category, &amount);
            addExpense(expenses, &numExpenses, date, category, amount);
        }
        else if (strcmp(command, "display") == 0) {
            displayExpenses(expenses, numExpenses);
        }
        else if (strcmp(command, "exit") == 0) {
            printf("Thank you for using the Expense Tracker!\n");
            break;
        }
        else {
            printf("Invalid command.\n");
        }
    }

    return 0;
}