//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure for an expense
typedef struct {
    char description[50];
    double amount;
    char category[30];
} Expense;

// Function prototypes
void displayMenu();
void addExpense(Expense* expenses, int* count);
void viewExpenses(Expense* expenses, int count);
void calculateTotal(Expense* expenses, int count);

int main() {
    Expense expenses[100]; // Array to hold expenses
    int expenseCount = 0;  // Counter for expenses
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
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
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to display the main menu
void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expense\n");
    printf("4. Exit\n");
}

// Function to add an expense
void addExpense(Expense* expenses, int* count) {
    if (*count < 100) {
        printf("Enter expense description: ");
        scanf(" %[^\n]", expenses[*count].description);
        printf("Enter expense amount: ");
        scanf("%lf", &expenses[*count].amount);
        printf("Enter expense category: ");
        scanf(" %[^\n]", expenses[*count].category);
        
        (*count)++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense limit reached. Cannot add more expenses.\n");
    }
}

// Function to view all expenses
void viewExpenses(Expense* expenses, int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. Description: %s, Amount: %.2f, Category: %s\n",
               i + 1, expenses[i].description, expenses[i].amount, expenses[i].category);
    }
}

// Function to calculate and display the total of expenses
void calculateTotal(Expense* expenses, int count) {
    double total = 0.0;

    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }

    if (count > 0) {
        printf("Total Expenses: %.2f\n", total);
    } else {
        printf("No expenses to calculate.\n");
    }
}