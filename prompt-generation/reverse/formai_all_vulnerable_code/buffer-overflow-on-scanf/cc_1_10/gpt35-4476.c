//FormAI DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of expenses to be tracked
#define MAX_EXPENSES 100

// Define structure for an expense
typedef struct {
    char date[15];
    char category[20];
    char description[50];
    float amount;
} Expense;

// Define function to add a new expense
void addExpense(Expense *expenses, int *numExpenses) {
    // Check if maximum number of expenses have been added
    if (*numExpenses >= MAX_EXPENSES) {
        printf("Maximum expenses have been exceeded. Cannot add another expense.\n");
        return;
    }
    // Prompt user for expense details
    Expense newExpense;
    printf("Enter expense date (mm/dd/yyyy): ");
    scanf("%s", newExpense.date);
    printf("Enter expense category: ");
    scanf("%s", newExpense.category);
    printf("Enter description for expense: ");
    scanf("%s", newExpense.description);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    // Add new expense to array of expenses
    expenses[*numExpenses] = newExpense;
    (*numExpenses)++;
    printf("Expense added successfully.\n");
}

// Define function to list all expenses
void listExpenses(Expense *expenses, int numExpenses) {
    // Check if any expenses have been added
    if (numExpenses == 0) {
        printf("No expenses have been added.\n");
        return;
    }
    // List all expenses
    printf("%-15s %-20s %-50s %s\n", "Date", "Category", "Description", "Amount");
    for (int i = 0; i < numExpenses; i++) {
        printf("%-15s %-20s %-50s $%.2f\n", expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

int main() {
    // Declare array of expenses and number of expenses added
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    // Loop through menu options until user chooses to exit
    while (1) {
        printf("Expense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. List Expenses\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        int choice;
        scanf("%d", &choice);
        // Switch case for chosen option
        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                listExpenses(expenses, numExpenses);
                break;
            case 3:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}