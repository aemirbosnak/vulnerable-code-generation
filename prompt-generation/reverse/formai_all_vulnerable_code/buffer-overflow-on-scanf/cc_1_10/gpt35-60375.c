//FormAI DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100  // Maximum number of expenses that can be tracked

// Structure to store an expense record
struct Expense {
    char category[20];
    float amount;
    char date[11];
};

// Function to add a new expense record
void addExpense(struct Expense expenses[], int *numExpenses) {
    if (*numExpenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached!\n");
        return;
    }

    struct Expense newExpense;
    printf("Enter the category of the expense: ");
    scanf("%s", newExpense.category);
    printf("Enter the amount of the expense: ");
    scanf("%f", &newExpense.amount);
    printf("Enter the date of the expense (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    expenses[*numExpenses] = newExpense;
    (*numExpenses)++;
    printf("Expense added successfully!\n");
}

// Function to display all expense records
void displayExpenses(struct Expense expenses[], int numExpenses) {
    if (numExpenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("%-20s %-10s %-10s\n", "Category", "Amount", "Date");
    printf("----------------------------------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-20s $%-9.2f %-10s\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

// Function to calculate the total amount of expenses
float calculateTotal(struct Expense expenses[], int numExpenses) {
    float total = 0;
    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }
    return total;
}

// Main function
int main() {
    struct Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;

    printf("Expense Tracker\n");
    printf("---------------\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                displayExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Total expenses: $%.2f\n", calculateTotal(expenses, numExpenses));
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}