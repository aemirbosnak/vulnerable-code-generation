//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: portable
/*
 * Expense Tracker
 *
 * A simple expense tracker program that allows users to input and store
 * expenses in a portable way.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store expense data
struct expense {
    char description[80];
    double amount;
};

// Function to add an expense
void add_expense(struct expense* expenses, int* count) {
    // Ask user for description and amount
    printf("Enter expense description: ");
    fgets(expenses[*count].description, 80, stdin);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[*count].amount);

    // Increment count
    (*count)++;
}

// Function to display expenses
void display_expenses(struct expense* expenses, int count) {
    // Print header
    printf("Expense Tracker\n");
    printf("--------------\n");

    // Print each expense
    for (int i = 0; i < count; i++) {
        printf("%s: %.2lf\n", expenses[i].description, expenses[i].amount);
    }
}

// Function to save expenses to a file
void save_expenses(struct expense* expenses, int count) {
    // Open file for writing
    FILE* file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Write each expense to the file
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s:%.2lf\n", expenses[i].description, expenses[i].amount);
    }

    // Close the file
    fclose(file);
}

// Function to load expenses from a file
void load_expenses(struct expense* expenses, int* count) {
    // Open file for reading
    FILE* file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }

    // Read each expense from the file
    while (fscanf(file, "%s:%.2lf\n", expenses[*count].description, &expenses[*count].amount) == 2) {
        (*count)++;
    }

    // Close the file
    fclose(file);
}

int main() {
    // Initialize expenses and count
    struct expense expenses[10];
    int count = 0;

    // Load expenses from file
    load_expenses(expenses, &count);

    // Add some expenses
    add_expense(expenses, &count);
    add_expense(expenses, &count);

    // Display expenses
    display_expenses(expenses, count);

    // Save expenses to file
    save_expenses(expenses, count);

    return 0;
}