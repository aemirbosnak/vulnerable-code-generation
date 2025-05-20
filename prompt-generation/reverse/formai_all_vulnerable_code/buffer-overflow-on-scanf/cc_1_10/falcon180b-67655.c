//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

// Define the structure for each item in the expense tracker
typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} ExpenseItem;

// Function to add an expense item to the tracker
void addExpense(ExpenseItem *expenses, int *numExpenses) {
    printf("Enter the name of the expense: ");
    scanf("%s", expenses[*numExpenses].name);
    printf("Enter the amount of the expense: ");
    scanf("%s", expenses[*numExpenses].amount);
    (*numExpenses)++;
}

// Function to display the total amount spent on each category of expenses
void displayExpenses(ExpenseItem *expenses, int numExpenses) {
    int i;
    for (i = 0; i < numExpenses; i++) {
        printf("Name: %s, Amount: %s\n", expenses[i].name, expenses[i].amount);
    }
}

// Function to calculate the total amount spent on all expenses
double calculateTotalExpenses(ExpenseItem *expenses, int numExpenses) {
    int i;
    double totalExpenses = 0.0;
    for (i = 0; i < numExpenses; i++) {
        totalExpenses += atof(expenses[i].amount);
    }
    return totalExpenses;
}

int main() {
    ExpenseItem expenses[MAX_ITEMS];
    int numExpenses = 0;

    // Initialize the expense tracker with some sample data
    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);
    addExpense(expenses, &numExpenses);

    // Display the expenses
    printf("Expenses:\n");
    displayExpenses(expenses, numExpenses);

    // Calculate the total expenses
    double totalExpenses = calculateTotalExpenses(expenses, numExpenses);
    printf("\nTotal expenses: $%.2f\n", totalExpenses);

    return 0;
}