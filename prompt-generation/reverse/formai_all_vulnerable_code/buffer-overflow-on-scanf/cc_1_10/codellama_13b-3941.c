//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: systematic
/*
 * expense_tracker.c
 *
 * A simple C program to track expenses.
 *
 */

#include <stdio.h>

// Structure to represent an expense
struct expense {
    char description[80];
    float amount;
};

// Function to add a new expense
void add_expense(struct expense* expenses, int* num_expenses) {
    // Prompt the user for the description and amount of the expense
    printf("Enter the description of the expense: ");
    fgets(expenses[*num_expenses].description, 80, stdin);
    printf("Enter the amount of the expense: ");
    scanf("%f", &expenses[*num_expenses].amount);

    // Increment the number of expenses
    *num_expenses += 1;
}

// Function to print the total expenses
void print_expenses(struct expense* expenses, int num_expenses) {
    // Calculate the total expenses
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    // Print the total expenses
    printf("Total expenses: %f\n", total);
}

// Function to remove an expense
void remove_expense(struct expense* expenses, int* num_expenses) {
    // Prompt the user for the index of the expense to remove
    int index;
    printf("Enter the index of the expense to remove: ");
    scanf("%d", &index);

    // Check if the index is valid
    if (index < 0 || index >= *num_expenses) {
        printf("Invalid index\n");
        return;
    }

    // Remove the expense from the array
    for (int i = index; i < *num_expenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    // Decrement the number of expenses
    *num_expenses -= 1;
}

int main() {
    // Initialize the array of expenses
    struct expense expenses[100];
    int num_expenses = 0;

    // Add some expenses
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);

    // Print the total expenses
    print_expenses(expenses, num_expenses);

    // Remove an expense
    remove_expense(expenses, &num_expenses);

    // Print the total expenses again
    print_expenses(expenses, num_expenses);

    return 0;
}