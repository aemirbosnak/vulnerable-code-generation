//GEMINI-pro DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of expenses
#define MAX_EXPENSES 100

// Define the structure of an expense
typedef struct {
    char description[50];
    float amount;
    char date[11];
} Expense;

// Declare the array of expenses
Expense expenses[MAX_EXPENSES];

// Get the number of expenses from the user
int get_num_expenses() {
    int num_expenses;
    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);
    return num_expenses;
}

// Get the details of an expense from the user
void get_expense_details(Expense *expense) {
    printf("Enter the description of the expense: ");
    scanf("%s", expense->description);
    printf("Enter the amount of the expense: ");
    scanf("%f", &expense->amount);
    printf("Enter the date of the expense (YYYY-MM-DD): ");
    scanf("%s", expense->date);
}

// Print the details of an expense
void print_expense_details(Expense *expense) {
    printf("Description: %s\n", expense->description);
    printf("Amount: %.2f\n", expense->amount);
    printf("Date: %s\n", expense->date);
}

// Add an expense to the array of expenses
void add_expense(Expense *expense, int num_expenses) {
    expenses[num_expenses] = *expense;
}

// Print the total amount of expenses
void print_total_expenses(int num_expenses) {
    float total = 0;
    for (int i = 0; i < num_expenses; i++) {
        total += expenses[i].amount;
    }
    printf("Total amount of expenses: %.2f\n", total);
}

// Main function
int main() {
    // Get the number of expenses from the user
    int num_expenses = get_num_expenses();

    // Get the details of each expense from the user
    for (int i = 0; i < num_expenses; i++) {
        Expense expense;
        get_expense_details(&expense);
        add_expense(&expense, i);
    }

    // Print the details of each expense
    for (int i = 0; i < num_expenses; i++) {
        print_expense_details(&expenses[i]);
    }

    // Print the total amount of expenses
    print_total_expenses(num_expenses);

    return 0;
}