//GEMINI-pro DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold income and expense items
typedef struct {
    char* name;
    double amount;
} Item;

// Initialize the program
void init(Item* income, Item* expenses, int* numIncome, int* numExpenses) {
    printf("Welcome to your personal finance planner!\n");

    *numIncome = 0;
    *numExpenses = 0;

    printf("How many sources of income do you have? ");
    scanf("%d", numIncome);

    printf("How many categories of expenses do you have? ");
    scanf("%d", numExpenses);

    // Allocate memory for the arrays
    income = malloc(*numIncome * sizeof(Item));
    expenses = malloc(*numExpenses * sizeof(Item));
}

// Add an income item
void addIncome(Item* income, int* numIncome) {
    printf("Enter the name of the income source: ");
    scanf(" %s", income[*numIncome].name);

    printf("Enter the amount of income: ");
    scanf("%lf", &income[*numIncome].amount);

    (*numIncome)++;
}

// Add an expense item
void addExpense(Item* expenses, int* numExpenses) {
    printf("Enter the name of the expense category: ");
    scanf(" %s", expenses[*numExpenses].name);

    printf("Enter the amount of expense: ");
    scanf("%lf", &expenses[*numExpenses].amount);

    (*numExpenses)++;
}

// Print the income and expense items
void printItems(Item* items, int numItems) {
    printf("\n%-20s%-10s\n", "Name", "Amount");
    printf("------------------------\n");
    for (int i = 0; i < numItems; i++) {
        printf("%-20s$%.2f\n", items[i].name, items[i].amount);
    }
}

// Calculate the total income and expenses
double calculateTotal(Item* items, int numItems) {
    double total = 0;
    for (int i = 0; i < numItems; i++) {
        total += items[i].amount;
    }
    return total;
}

// Print the summary
void printSummary(Item* income, int numIncome, Item* expenses, int numExpenses) {
    double totalIncome = calculateTotal(income, numIncome);
    double totalExpenses = calculateTotal(expenses, numExpenses);
    double netIncome = totalIncome - totalExpenses;

    printf("\nSummary:\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Income: $%.2f\n", netIncome);
}

// Main function
int main() {
    // Initialize the program
    Item* income;
    Item* expenses;
    int numIncome;
    int numExpenses;
    init(income, expenses, &numIncome, &numExpenses);

    // Add income and expense items
    for (int i = 0; i < numIncome; i++) {
        addIncome(income, &numIncome);
    }
    for (int i = 0; i < numExpenses; i++) {
        addExpense(expenses, &numExpenses);
    }

    // Print the items
    printf("\nIncome:\n");
    printItems(income, numIncome);
    printf("\nExpenses:\n");
    printItems(expenses, numExpenses);

    // Print the summary
    printSummary(income, numIncome, expenses, numExpenses);

    // Free the allocated memory
    free(income);
    free(expenses);

    return 0;
}