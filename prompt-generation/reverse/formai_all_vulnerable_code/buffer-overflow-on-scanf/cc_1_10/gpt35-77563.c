//FormAI DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct to hold the information for each expense
struct Expense {
    int id;
    char name[50];
    double amount;
    char category[50];
};

// Define a function to add an expense to the array
void addExpense(struct Expense expenses[], int *index) {
    struct Expense expense;

    // Get the name of the expense
    printf("Expense Name: ");
    scanf("%s", expense.name);

    // Get the amount of the expense
    printf("Expense Amount: ");
    scanf("%lf", &expense.amount);

    // Get the category of the expense
    printf("Expense Category: ");
    scanf("%s", expense.category);

    // Set the ID of the expense
    expense.id = *index + 1;

    // Add the expense to the array
    expenses[*index] = expense;

    // Increment the index
    *index += 1;

    printf("Expense added successfully!\n");
}

// Define a function to list all expenses in the array
void listExpenses(struct Expense expenses[], int *index) {
    // Print the header for the table
    printf("+----+------------------------+---------+------------------------+\n");
    printf("| ID | Name                   | Amount  | Category               |\n");
    printf("+----+------------------------+---------+------------------------+\n");

    // Loop through the expenses and print each one
    for (int i = 0; i < *index; i++) {
        printf("| %2d | %-23s | $%7.2lf | %-23s |\n", expenses[i].id, expenses[i].name, expenses[i].amount, expenses[i].category);
    }

    // Print the footer for the table
    printf("+----+------------------------+---------+------------------------+\n");
}

// Define a function to calculate the total amount of expenses
double calculateTotal(struct Expense expenses[], int *index) {
    double total = 0;

    // Loop through the expenses and add up the amounts
    for (int i = 0; i < *index; i++) {
        total += expenses[i].amount;
    }

    return total;
}

int main() {
    struct Expense expenses[100];
    int index = 0;
    char option[10];

    // Loop through the program until the user chooses to quit
    while (1) {
        // Print the options menu
        printf("\nOptions:\n");
        printf("  1. Add Expense\n");
        printf("  2. List Expenses\n");
        printf("  3. Calculate Total\n");
        printf("  4. Quit\n");
        printf("Enter an option: ");

        // Get the user's choice
        scanf("%s", option);

        // Process the user's choice
        if (strcmp(option, "1") == 0) {
            addExpense(expenses, &index);
        } else if (strcmp(option, "2") == 0) {
            listExpenses(expenses, &index);
        } else if (strcmp(option, "3") == 0) {
            double total = calculateTotal(expenses, &index);
            printf("Total Expenses: $%.2lf\n", total);
        } else if (strcmp(option, "4") == 0) {
            printf("Quitting program...\n");
            break;
        } else {
            printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}