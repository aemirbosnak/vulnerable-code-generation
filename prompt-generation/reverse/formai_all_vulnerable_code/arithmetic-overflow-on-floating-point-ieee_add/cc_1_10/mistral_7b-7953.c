//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the structure for an expense
typedef struct Expense {
    char description[100];
    float amount;
    time_t timestamp;
} Expense;

// Function to generate a unique ID for each expense
unsigned int generate_id() {
    static unsigned int id = 1;
    return id++;
}

// Function to add an expense to the list
void add_expense(Expense* expenses, int* num_expenses, const char* description, float amount) {
    Expense new_expense;
    strcpy(new_expense.description, description);
    new_expense.amount = amount;
    new_expense.timestamp = time(NULL);
    if (*num_expenses < 10) {
        expenses[*num_expenses] = new_expense;
        (*num_expenses)++;
    } else {
        Expense* old_expense = expenses;
        for (int i = 0; i < *num_expenses - 1; i++) {
            old_expense++;
        }
        *old_expense = new_expense;
    }
}

// Function to display all expenses
void display_expenses(Expense expenses[10], int num_expenses) {
    printf("Expenses (\"%s\")\n", __func__);
    for (int i = 0; i < num_expenses; i++) {
        printf("Expense %d:\n", i+1);
        printf("  Description: %s\n", expenses[i].description);
        printf("  Amount: %.2f\n", expenses[i].amount);
        printf("  Timestamp: %s\n", ctime(&expenses[i].timestamp));
        printf("\n");
    }
}

// Function to calculate total expenses
float total_expenses(Expense expenses[10], int num_expenses) {
    float total = 0.0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Main function
int main() {
    Expense expenses[10];
    int num_expenses = 0;

    // Add some initial expenses
    add_expense(expenses, &num_expenses, "Pizza and Beer", 25.50);
    add_expense(expenses, &num_expenses, "Groceries", 50.75);
    add_expense(expenses, &num_expenses, "Movie Tickets", 15.00);

    // Display all expenses
    display_expenses(expenses, num_expenses);

    // Add some new expenses
    add_expense(expenses, &num_expenses, "Books", 30.00);
    add_expense(expenses, &num_expenses, "Gasoline", 35.50);

    // Display all expenses again
    display_expenses(expenses, num_expenses);

    // Calculate total expenses
    float total = total_expenses(expenses, num_expenses);

    // Print total expenses
    printf("Total expenses: %.2f\n", total);

    return 0;
}