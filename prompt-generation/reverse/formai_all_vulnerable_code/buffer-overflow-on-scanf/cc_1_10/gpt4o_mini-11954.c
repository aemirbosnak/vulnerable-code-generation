//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold an expense entry
typedef struct {
    char description[50];
    float amount;
} Expense;

// Function prototypes
void addExpense(Expense *expenses, int *count);
void viewExpenses(Expense *expenses, int count);
float calculateTotal(Expense *expenses, int count);
void displayMenu();

int main() {
    Expense expenses[100];
    int count = 0;  // To keep track of the number of expenses
    int choice;

    // Welcome message
    printf("Welcome to the Expense Tracker!\n");
    printf("Keep track of your expenses easily and efficiently.\n\n");

    // Main loop
    while (1) {
        displayMenu(); // Show the menu options
        printf("Enter your choice: ");
        scanf("%d", &choice);  // Get user choice

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", calculateTotal(expenses, count));
                break;
            case 4:
                printf("Exiting the Expense Tracker. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
}

// Function to add an expense
void addExpense(Expense *expenses, int *count) {
    // Check if we have space for more expenses
    if (*count >= 100) {
        printf("Expense limit reached. Unable to add more expenses.\n");
        return;
    }

    // Gather expense details from the user
    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[*count].description);  // Read string with spaces
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);

    // Increment the number of expenses
    (*count)++;
    printf("Expense added successfully!\n");
}

// Function to view all expenses
void viewExpenses(Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

// Function to calculate the total expenses
float calculateTotal(Expense *expenses, int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}