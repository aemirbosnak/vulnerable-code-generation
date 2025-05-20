//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: light-weight
/*
 * Expense Tracker
 *
 * This program allows users to track their expenses by
 * entering the date, category, and amount of each expense.
 * The program also calculates the total expenses for each category.
 *
 * Usage:
 *  - Enter the date, category, and amount of each expense
 *  - Use the "total" command to see the total expenses for each category
 *  - Use the "history" command to see the history of all expenses
 *  - Use the "exit" command to exit the program
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

// Expense structure
typedef struct {
    char date[11];
    char category[21];
    float amount;
} Expense;

// Category structure
typedef struct {
    char name[21];
    float total;
} Category;

// Global variables
Expense expenses[MAX_EXPENSES];
Category categories[MAX_CATEGORIES];
int num_expenses = 0;
int num_categories = 0;

// Function to calculate the total expenses for each category
void calculate_totals() {
    for (int i = 0; i < num_categories; i++) {
        categories[i].total = 0;
    }
    for (int i = 0; i < num_expenses; i++) {
        for (int j = 0; j < num_categories; j++) {
            if (strcmp(categories[j].name, expenses[i].category) == 0) {
                categories[j].total += expenses[i].amount;
                break;
            }
        }
    }
}

// Function to add a new expense
void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Maximum number of expenses reached.\n");
        return;
    }
    printf("Enter the date: ");
    scanf("%10s", expenses[num_expenses].date);
    printf("Enter the category: ");
    scanf("%20s", expenses[num_expenses].category);
    printf("Enter the amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    num_expenses++;
}

// Function to display the total expenses for each category
void display_totals() {
    calculate_totals();
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %.2f\n", categories[i].name, categories[i].total);
    }
}

// Function to display the history of all expenses
void display_history() {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: %s: %.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

// Function to exit the program
void exit_program() {
    printf("Exiting program...\n");
    exit(0);
}

int main() {
    char command[10];
    while (1) {
        printf("Enter a command: ");
        scanf("%9s", command);
        if (strcmp(command, "add") == 0) {
            add_expense();
        } else if (strcmp(command, "total") == 0) {
            display_totals();
        } else if (strcmp(command, "history") == 0) {
            display_history();
        } else if (strcmp(command, "exit") == 0) {
            exit_program();
        } else {
            printf("Invalid command.\n");
        }
    }
    return 0;
}