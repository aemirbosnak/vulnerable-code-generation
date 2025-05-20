//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses that can be tracked
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];
    float amount;
    char date[11];
} Expense;

// Function to add an expense to the expense tracker
void add_expense(Expense expenses[], int *num_expenses) {
    // Get the expense details from the user
    printf("Enter expense description: ");
    scanf(" %[^\n]%*c", expenses[*num_expenses].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    printf("Enter expense date (dd/mm/yyyy): ");
    scanf(" %[^\n]%*c", expenses[*num_expenses].date);

    // Increment the number of expenses
    (*num_expenses)++;
}

// Function to print the expense tracker
void print_expense_tracker(Expense expenses[], int num_expenses) {
    // Print the header
    printf("\nExpense Tracker\n");
    printf("=================\n");
    printf("%-50s %-10s %-10s\n", "Description", "Amount", "Date");

    // Print each expense
    for (int i = 0; i < num_expenses; i++) {
        printf("%-50s %-10.2f %-10s\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }

    // Print the total expenses
    float total_expenses = 0;
    for (int i = 0; i < num_expenses; i++) {
        total_expenses += expenses[i].amount;
    }
    printf("\nTotal Expenses: %.2f\n", total_expenses);
}

// Function to sort the expense tracker by date
void sort_expenses_by_date(Expense expenses[], int num_expenses) {
    // Bubble sort the expenses by date
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = 0; j < num_expenses - i - 1; j++) {
            if (strcmp(expenses[j].date, expenses[j + 1].date) > 0) {
                // Swap the expenses
                Expense temp = expenses[j];
                expenses[j] = expenses[j + 1];
                expenses[j + 1] = temp;
            }
        }
    }
}

// Function to sort the expense tracker by amount
void sort_expenses_by_amount(Expense expenses[], int num_expenses) {
    // Bubble sort the expenses by amount
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = 0; j < num_expenses - i - 1; j++) {
            if (expenses[j].amount > expenses[j + 1].amount) {
                // Swap the expenses
                Expense temp = expenses[j];
                expenses[j] = expenses[j + 1];
                expenses[j + 1] = temp;
            }
        }
    }
}

// Main function
int main() {
    // Create an array of expenses
    Expense expenses[MAX_EXPENSES];

    // Initialize the number of expenses to 0
    int num_expenses = 0;

    // Add some sample expenses to the expense tracker
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);

    // Print the expense tracker
    print_expense_tracker(expenses, num_expenses);

    // Sort the expense tracker by date
    sort_expenses_by_date(expenses, num_expenses);

    // Print the sorted expense tracker
    printf("\nExpense Tracker (Sorted by Date)\n");
    printf("=====================================\n");
    print_expense_tracker(expenses, num_expenses);

    // Sort the expense tracker by amount
    sort_expenses_by_amount(expenses, num_expenses);

    // Print the sorted expense tracker
    printf("\nExpense Tracker (Sorted by Amount)\n");
    printf("=======================================\n");
    print_expense_tracker(expenses, num_expenses);

    return 0;
}