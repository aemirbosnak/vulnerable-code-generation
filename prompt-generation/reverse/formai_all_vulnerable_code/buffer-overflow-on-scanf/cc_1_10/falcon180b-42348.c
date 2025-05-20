//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

// Structure to hold each expense item
typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} expense_item;

// Function to add a new expense item
void add_expense(expense_item* expenses, int num_expenses, char* name, char* amount) {
    if (num_expenses >= MAX_ITEMS) {
        printf("Error: Maximum number of expense items reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].amount, amount);
    num_expenses++;
}

// Function to display all expense items
void display_expenses(expense_item* expenses, int num_expenses) {
    printf("Expense Items:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %s\n", expenses[i].name, expenses[i].amount);
    }
}

// Function to calculate total expenses
float calculate_total_expenses(expense_item* expenses, int num_expenses) {
    float total_expenses = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += atof(expenses[i].amount);
    }
    return total_expenses;
}

int main() {
    expense_item expenses[MAX_ITEMS];
    int num_expenses = 0;

    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];

    // Prompt user for expense items
    while (num_expenses < MAX_ITEMS) {
        printf("Enter expense name: ");
        scanf("%s", name);
        printf("Enter expense amount: ");
        scanf("%s", amount);

        add_expense(expenses, num_expenses, name, amount);
    }

    // Display all expense items
    printf("\nExpense Summary:\n");
    display_expenses(expenses, num_expenses);

    // Calculate total expenses
    float total_expenses = calculate_total_expenses(expenses, num_expenses);
    printf("\nTotal Expenses: $%.2f\n", total_expenses);

    return 0;
}