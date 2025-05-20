//FormAI DATASET v1.0 Category: Expense Tracker ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of expenses
#define MAX_EXPENSES 100

// Structure to hold expense information
typedef struct Expense {
    char name[50];
    float amount;
    char category[50];
} Expense;

// Function to add a new expense
void addExpense(Expense *expenses, int *count) {
    Expense newExpense;

    // Get expense name, amount and category from user
    printf("\nEnter expense name: ");
    scanf("%s", newExpense.name);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    printf("Enter expense category: ");
    scanf("%s", newExpense.category);

    // Add the new expense to the expenses array
    expenses[*count] = newExpense;
    *count += 1;

    printf("\nExpense added successfully!\n");
}

// Function to display all expenses
void displayExpenses(Expense *expenses, int count) {
    printf("\nAll expenses:\n");
    printf("---------------------------\n");
    printf("|Name\t|Amount\t|Category\t|\n");
    printf("---------------------------\n");

    // Loop through all expenses and print their details
    for (int i = 0; i < count; i++) {
        printf("|%s\t|%.2f\t|%s\t\t|\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }

    printf("---------------------------\n");
}

// Function to display expense by category
void displayExpensesByCategory(Expense *expenses, int count) {
    char category[50];

    // Get category name from user
    printf("\nEnter category name: ");
    scanf("%s", category);

    printf("\nExpenses in %s category:\n", category);
    printf("---------------------------\n");
    printf("|Name\t|Amount\t|Category\t|\n");
    printf("---------------------------\n");

    // Loop through all expenses and print details of expenses in the specified category
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("|%s\t|%.2f\t|%s\t\t|\n", expenses[i].name, expenses[i].amount, expenses[i].category);
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses in %s category\n", category);
    }

    printf("---------------------------\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;

    printf("\nWelcome to the Expense Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add new expense\n");
        printf("2. Display all expenses\n");
        printf("3. Display expenses by category\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                displayExpenses(expenses, count);
                break;
            case 3:
                displayExpensesByCategory(expenses, count);
                break;
            case 4:
                printf("\nThank you for using Expense Tracker!\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
                break;
        }
    }
}