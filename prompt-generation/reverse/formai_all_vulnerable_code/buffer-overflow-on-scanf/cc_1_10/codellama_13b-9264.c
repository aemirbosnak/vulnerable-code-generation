//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: creative
/*
 * Expense Tracker
 *
 * A simple program to track expenses in C.
 */

#include <stdio.h>
#include <stdlib.h>

// Struct to represent an expense
struct expense {
    char category[30];
    char description[50];
    double amount;
};

// Function to add an expense
void add_expense(struct expense *expenses, int *num_expenses) {
    // Prompt for category and description
    printf("Enter category: ");
    scanf("%s", expenses[*num_expenses].category);
    printf("Enter description: ");
    scanf("%s", expenses[*num_expenses].description);
    // Prompt for amount
    printf("Enter amount: ");
    scanf("%lf", &expenses[*num_expenses].amount);
    // Increment number of expenses
    *num_expenses += 1;
}

// Function to display expenses
void display_expenses(struct expense *expenses, int num_expenses) {
    // Print expenses
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\n", expenses[i].category);
        printf("%s\n", expenses[i].description);
        printf("%.2f\n", expenses[i].amount);
        printf("\n");
    }
}

int main() {
    // Initialize array of expenses
    struct expense expenses[10];
    int num_expenses = 0;

    // Add expenses
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);

    // Display expenses
    display_expenses(expenses, num_expenses);

    return 0;
}