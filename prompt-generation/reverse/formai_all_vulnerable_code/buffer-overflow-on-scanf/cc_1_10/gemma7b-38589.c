//Gemma-7B DATASET v1.0 Category: Expense Tracker ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define an array to store expense details
struct Expense {
    char name[50];
    int amount;
    char category[50];
};

// Function to add an expense
void addExpense(struct Expense *expense) {
    printf("Enter expense name: ");
    scanf("%s", expense->name);

    printf("Enter expense amount: ");
    scanf("%d", &expense->amount);

    printf("Enter expense category: ");
    scanf("%s", expense->category);
}

// Function to display expenses
void displayExpenses(struct Expense *expenses, int numExpenses) {
    for (int i = 0; i < numExpenses; i++) {
        printf("Name: %s\n", expenses[i].name);
        printf("Amount: %d\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("\n");
    }
}

int main() {
    // Create an array of expenses
    struct Expense expenses[100];

    // Initialize the number of expenses to 0
    int numExpenses = 0;

    // Add an expense
    addExpense(&expenses[numExpenses]);

    // Increment the number of expenses
    numExpenses++;

    // Add another expense
    addExpense(&expenses[numExpenses]);

    // Increment the number of expenses
    numExpenses++;

    // Display the expenses
    displayExpenses(expenses, numExpenses);

    return 0;
}