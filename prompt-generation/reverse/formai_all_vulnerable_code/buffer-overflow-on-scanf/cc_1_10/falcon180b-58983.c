//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

// Define structure for expenses
typedef struct {
    char category[50];
    char description[100];
    double amount;
} Expense;

// Function to add an expense to the list
void addExpense(Expense expenses[], int count, char category[], char description[], double amount) {
    if (count >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(expenses[count].category, category);
    strcpy(expenses[count].description, description);
    expenses[count].amount = amount;
    count++;
}

// Function to display the list of expenses
void displayExpenses(Expense expenses[], int count) {
    printf("Expenses by Category:\n");
    for (int i = 0; i < count; i++) {
        printf("%s:\n", expenses[i].category);
        printf("%s - $%.2f\n", expenses[i].description, expenses[i].amount);
    }
}

// Function to display a menu
void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add expense\n");
    printf("2. Display expenses\n");
    printf("3. Exit\n");
}

// Main function
int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    char category[50];
    char description[100];
    double amount;

    // Initialize program
    printf("Welcome to the Expense Tracker!\n");

    // Main loop
    while (1) {
        displayMenu();
        scanf("%d", &amount);

        // Add an expense
        if (amount == 1) {
            printf("Enter category: ");
            scanf("%s", category);
            printf("Enter description: ");
            scanf("%s", description);
            printf("Enter amount: ");
            scanf("%lf", &amount);
            addExpense(expenses, count, category, description, amount);
        }
        // Display expenses
        else if (amount == 2) {
            if (count == 0) {
                printf("No expenses to display.\n");
            } else {
                displayExpenses(expenses, count);
            }
        }
        // Exit program
        else if (amount == 3) {
            printf("Thank you for using the Expense Tracker!\n");
            return 0;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}