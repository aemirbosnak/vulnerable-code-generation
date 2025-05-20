//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the expense structure
typedef struct {
    char description[100];
    float amount;
    int category;
} Expense;

// Define the category names
char *categories[] = {"Food", "Entertainment", "Transportation", "Housing", "Other"};

// Get the user's input
void get_input(Expense *expenses, int *num_expenses) {
    int i;

    // Get the number of expenses
    printf("Enter the number of expenses: ");
    scanf("%d", num_expenses);

    // Get the details of each expense
    for (i = 0; i < *num_expenses; i++) {
        printf("Enter the description of expense %d: ", i + 1);
        scanf("%s", expenses[i].description);

        printf("Enter the amount of expense %d: ", i + 1);
        scanf("%f", &expenses[i].amount);

        printf("Enter the category of expense %d: ", i + 1);
        scanf("%d", &expenses[i].category);
    }
}

// Print the expenses
void print_expenses(Expense *expenses, int num_expenses) {
    int i;

    // Print the header
    printf("%-30s %-10s %-10s\n", "Description", "Amount", "Category");

    // Print the details of each expense
    for (i = 0; i < num_expenses; i++) {
        printf("%-30s %-10.2f %-10s\n", expenses[i].description, expenses[i].amount, categories[expenses[i].category]);
    }
}

// Calculate the total expenses
float calculate_total_expenses(Expense *expenses, int num_expenses) {
    int i;
    float total = 0;

    for (i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}

// Calculate the average expenses
float calculate_average_expenses(Expense *expenses, int num_expenses) {
    float total = calculate_total_expenses(expenses, num_expenses);
    return total / num_expenses;
}

// Calculate the maximum expenses
float calculate_maximum_expenses(Expense *expenses, int num_expenses) {
    int i;
    float maximum = expenses[0].amount;

    for (i = 1; i < num_expenses; i++) {
        if (expenses[i].amount > maximum) {
            maximum = expenses[i].amount;
        }
    }

    return maximum;
}

// Calculate the minimum expenses
float calculate_minimum_expenses(Expense *expenses, int num_expenses) {
    int i;
    float minimum = expenses[0].amount;

    for (i = 1; i < num_expenses; i++) {
        if (expenses[i].amount < minimum) {
            minimum = expenses[i].amount;
        }
    }

    return minimum;
}

// Main function
int main() {
    // Declare the variables
    Expense expenses[MAX_EXPENSES];
    int num_expenses;
    float total_expenses, average_expenses, maximum_expenses, minimum_expenses;

    // Get the user's input
    get_input(expenses, &num_expenses);

    // Print the expenses
    print_expenses(expenses, num_expenses);

    // Calculate the total expenses
    total_expenses = calculate_total_expenses(expenses, num_expenses);

    // Calculate the average expenses
    average_expenses = calculate_average_expenses(expenses, num_expenses);

    // Calculate the maximum expenses
    maximum_expenses = calculate_maximum_expenses(expenses, num_expenses);

    // Calculate the minimum expenses
    minimum_expenses = calculate_minimum_expenses(expenses, num_expenses);

    // Print the summary
    printf("\nSummary:\n");
    printf("Total expenses: %.2f\n", total_expenses);
    printf("Average expenses: %.2f\n", average_expenses);
    printf("Maximum expenses: %.2f\n", maximum_expenses);
    printf("Minimum expenses: %.2f\n", minimum_expenses);

    return 0;
}