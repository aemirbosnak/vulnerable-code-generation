//FormAI DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000 // maximum expenses that can be stored
#define MAX_DESCRIPTION_LEN 100 // maximum length of expense description

// Structure to represent an expense
typedef struct expense {
    char description[MAX_DESCRIPTION_LEN];
    float amount;
} Expense;

// Function to display the main menu
void displayMenu() {
    printf("\n\nExpense Tracker\n");
    printf("----------------\n");
    printf("1. Add Expense\n");
    printf("2. List All Expenses\n");
    printf("3. View Expense Total\n");
    printf("4. Exit\n");
}

// Function to add a new expense
void addExpense(Expense expenses[], int *numExpenses) {
    char description[MAX_DESCRIPTION_LEN];
    float amount;

    // Get input from user
    printf("Enter description: ");
    fgets(description, MAX_DESCRIPTION_LEN, stdin);
    description[strlen(description) - 1] = '\0'; // remove newline character
    printf("Enter amount: ");
    scanf("%f", &amount);

    // Create new expense
    Expense newExpense;
    strcpy(newExpense.description, description);
    newExpense.amount = amount;

    // Add expense to array
    expenses[*numExpenses] = newExpense;
    (*numExpenses)++;

    printf("Expense added successfully!\n");
    getchar(); // consume newline character
}

// Function to list all expenses
void listExpenses(Expense expenses[], int numExpenses) {
    // Check if there are any expenses
    if (numExpenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    printf("All Expenses\n");
    printf("------------\n");
    for (int i = 0; i < numExpenses; i++) {
        printf("%d. Description: %s, Amount: %.2f\n", i+1, expenses[i].description, expenses[i].amount);
    }
}

// Function to view expense total
void viewExpenseTotal(Expense expenses[], int numExpenses) {
    // Check if there are any expenses
    if (numExpenses == 0) {
        printf("No expenses found.\n");
        return;
    }

    float total = 0.0;

    for (int i = 0; i < numExpenses; i++) {
        total += expenses[i].amount;
    }

    printf("Expense Total: %.2f\n", total);
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int numExpenses = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // consume newline character

        switch (choice) {
            case 1:
                addExpense(expenses, &numExpenses);
                break;
            case 2:
                listExpenses(expenses, numExpenses);
                break;
            case 3:
                viewExpenseTotal(expenses, numExpenses);
                break;
            case 4:
                printf("Thank you for using Expense Tracker!\n");
                exit(0);
            default:
                printf("Invalid choice.\n");
                break;
        }
    }

    return 0;
}