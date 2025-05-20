//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name;
    float amount;
    char *category;
} Expense;

int main() {
    // Create an array of expenses
    Expense expenses[] = {
        {"Rent", 1200.00, "Housing"},
        {"Groceries", 200.00, "Food"},
        {"Utilities", 150.00, "Utilities"},
        {"Transportation", 300.00, "Transportation"},
        {"Entertainment", 100.00, "Entertainment"},
        {"Other", 150.00, "Other"}
    };

    // Get the total number of expenses
    int num_expenses = sizeof(expenses) / sizeof(expenses[0]);

    // Calculate the total amount of expenses
    float total_amount = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total_amount += expenses[i].amount;
    }

    // Print a report of the expenses
    printf("Expense Report\n");
    printf("---------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s $%-10.2f %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
    printf("Total: $%-10.2f\n", total_amount);
    printf("\n");

    // Get the user's input for a new expense
    char name[256];
    float amount;
    char category[256];
    printf("Enter a new expense:\n");
    printf("Name: ");
    scanf("%s", name);
    printf("Amount: ");
    scanf("%f", &amount);
    printf("Category: ");
    scanf("%s", category);

    // Add the new expense to the array
    Expense new_expense = {name, amount, category};
    expenses[num_expenses] = new_expense;
    num_expenses++;

    // Recalculate the total amount of expenses
    total_amount = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total_amount += expenses[i].amount;
    }

    // Print a report of the expenses
    printf("\nExpense Report\n");
    printf("---------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s $%-10.2f %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
    printf("Total: $%-10.2f\n", total_amount);
    printf("\n");

    return 0;
}