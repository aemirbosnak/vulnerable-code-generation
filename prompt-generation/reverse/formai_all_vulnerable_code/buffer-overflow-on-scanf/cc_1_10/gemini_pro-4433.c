//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];
    float amount;
    char category[20];
    char date[11];
} Expense;

// Define the array of expenses
Expense expenses[MAX_EXPENSES];

// Define the number of expenses
int num_expenses = 0;

// Define the main function
int main() {
    // Create a new expense
    Expense new_expense;

    // Get the description of the expense
    printf("Enter the description of the expense: ");
    scanf("%s", new_expense.description);

    // Get the amount of the expense
    printf("Enter the amount of the expense: ");
    scanf("%f", &new_expense.amount);

    // Get the category of the expense
    printf("Enter the category of the expense: ");
    scanf("%s", new_expense.category);

    // Get the date of the expense
    printf("Enter the date of the expense (YYYY-MM-DD): ");
    scanf("%s", new_expense.date);

    // Add the new expense to the array of expenses
    expenses[num_expenses] = new_expense;
    num_expenses++;

    // Print the array of expenses
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s %f %s %s\n", expenses[i].description, expenses[i].amount, expenses[i].category, expenses[i].date);
    }

    return 0;
}