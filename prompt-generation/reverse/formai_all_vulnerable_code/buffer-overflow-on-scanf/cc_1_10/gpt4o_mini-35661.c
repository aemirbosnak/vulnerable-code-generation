//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

// Function to add a new expense
void addExpense(Expense *expenses, int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Oops! Maximum expense limit reached. Can't add more expenses.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[*count].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("🎉 Expense added successfully! 🎉\n");
}

// Function to view all expenses
void viewExpenses(Expense *expenses, int count) {
    if (count == 0) {
        printf("No expenses recorded! 🌟\n");
        return;
    }

    printf("\n--- Your Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("----------------------\n");
}

// Function to calculate total expenses
void calculateTotal(Expense *expenses, int count) {
    float total = 0.0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    printf("💰 Total Expenses: $%.2f 💰\n", total);
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

// Main function to run the program
int main() {
    Expense expenses[MAX_EXPENSES];
    int expenseCount = 0;
    int choice;

    printf("Welcome to the 🎉 Expense Tracker! 🎉\n");

    while (1) {
        displayMenu();

        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &expenseCount);
                break;
            case 2:
                viewExpenses(expenses, expenseCount);
                break;
            case 3:
                calculateTotal(expenses, expenseCount);
                break;
            case 4:
                printf("Thank you for using the Expense Tracker! Goodbye! 👋\n");
                return 0;
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }

    return 0;
}