//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];
    float amount;
    char category[20];
    char date[11];
} Expense;

// Define the array of expenses
Expense expenses[MAX_EXPENSES];

// Define the number of expenses
int num_expenses = 0;

// Get the user's input
void get_input() {
    int i;

    printf("Welcome to the Expense Tracker 3000!\n");
    printf("How many expenses would you like to track? (max %d)\n", MAX_EXPENSES);
    scanf("%d", &num_expenses);

    // Get the details of each expense
    for (i = 0; i < num_expenses; i++) {
        printf("Enter the description of expense %d: ", i + 1);
        scanf("%s", expenses[i].description);

        printf("Enter the amount of expense %d: ", i + 1);
        scanf("%f", &expenses[i].amount);

        printf("Enter the category of expense %d: ", i + 1);
        scanf("%s", expenses[i].category);

        printf("Enter the date of expense %d (YYYY-MM-DD): ", i + 1);
        scanf("%s", expenses[i].date);
    }
}

// Print the expenses
void print_expenses() {
    int i;

    printf("\nYour expenses are:\n");
    printf("| %-5s | %-20s | %-10s | %-15s |\n", "ID", "Description", "Amount", "Date");
    for (i = 0; i < num_expenses; i++) {
        printf("| %-5d | %-20s | %-10.2f | %-15s |\n", i + 1, expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

// Calculate the total expenses
float calculate_total_expenses() {
    int i;
    float total = 0.0;

    for (i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }

    return total;
}

// Calculate the average expense
float calculate_average_expense() {
    float average = 0.0;

    if (num_expenses > 0) {
        average = calculate_total_expenses() / num_expenses;
    }

    return average;
}

// Find the most expensive category
char* find_most_expensive_category() {
    int i;
    char* most_expensive_category = NULL;
    float max_amount = 0.0;

    for (i = 0; i < num_expenses; i++) {
        if (expenses[i].amount > max_amount) {
            max_amount = expenses[i].amount;
            most_expensive_category = expenses[i].category;
        }
    }

    return most_expensive_category;
}

// Main function
int main() {
    // Get the user's input
    get_input();

    // Print the expenses
    print_expenses();

    // Calculate the total expenses
    float total_expenses = calculate_total_expenses();
    printf("\nTotal expenses: %.2f\n", total_expenses);

    // Calculate the average expense
    float average_expense = calculate_average_expense();
    printf("Average expense: %.2f\n", average_expense);

    // Find the most expensive category
    char* most_expensive_category = find_most_expensive_category();
    printf("Most expensive category: %s\n", most_expensive_category);

    return 0;
}