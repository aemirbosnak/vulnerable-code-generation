//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define the structure of an expense
typedef struct {
    char date[10];
    char category[20];
    double amount;
} Expense;

// Function to print the expenses
void printExpenses(Expense expenses[], int numExpenses) {
    printf("Expenses:\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("Date: %s\nCategory: %s\nAmount: $%.2f\n", expenses[i].date, expenses[i].category, expenses[i].amount);
    }
}

// Function to add an expense
void addExpense(Expense expenses[], int numExpenses) {
    printf("Enter the date (mm/dd/yyyy): ");
    scanf("%s", expenses[numExpenses].date);
    printf("Enter the category: ");
    scanf("%s", expenses[numExpenses].category);
    printf("Enter the amount: ");
    scanf("%lf", &expenses[numExpenses].amount);
    numExpenses++;
}

// Function to calculate the total expenses
double calculateTotalExpenses(Expense expenses[], int numExpenses) {
    double totalExpenses = 0;
    for (int i = 0; i < numExpenses; i++) {
        totalExpenses += expenses[i].amount;
    }
    return totalExpenses;
}

int main() {
    Expense expenses[100];
    int numExpenses = 0;

    // Initialize the expenses with default values
    for (int i = 0; i < 100; i++) {
        expenses[i].date[0] = '\0';
        expenses[i].category[0] = '\0';
        expenses[i].amount = 0;
    }

    // Add expenses
    addExpense(expenses, numExpenses);
    addExpense(expenses, numExpenses);
    addExpense(expenses, numExpenses);

    // Print expenses
    printExpenses(expenses, numExpenses);

    // Calculate total expenses
    double totalExpenses = calculateTotalExpenses(expenses, numExpenses);
    printf("Total expenses: $%.2f\n", totalExpenses);

    return 0;
}