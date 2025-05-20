//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: careful
/*
 * Expense Tracker
 *
 * This program allows users to track their expenses and save them in a file.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an expense
struct Expense {
    char date[11];
    char category[21];
    float amount;
};

// Define the file name for the expenses file
#define EXPENSES_FILE "expenses.txt"

// Function to add an expense to the file
void add_expense(struct Expense expense) {
    FILE *fp = fopen(EXPENSES_FILE, "a");
    fprintf(fp, "%s %s %.2f\n", expense.date, expense.category, expense.amount);
    fclose(fp);
}

// Function to print the expenses from the file
void print_expenses() {
    FILE *fp = fopen(EXPENSES_FILE, "r");
    char line[1024];
    while (fgets(line, 1024, fp) != NULL) {
        struct Expense expense;
        sscanf(line, "%s %s %f", expense.date, expense.category, &expense.amount);
        printf("%s - %s - %.2f\n", expense.date, expense.category, expense.amount);
    }
    fclose(fp);
}

int main() {
    // Add some expenses to the file
    struct Expense expense1 = {"2022-01-01", "Groceries", 100.00};
    add_expense(expense1);
    struct Expense expense2 = {"2022-01-02", "Rent", 1500.00};
    add_expense(expense2);
    struct Expense expense3 = {"2022-01-03", "Gas", 25.00};
    add_expense(expense3);

    // Print the expenses from the file
    print_expenses();

    return 0;
}