//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold expense details
typedef struct {
    char description[50];
    float amount;
    char date[11]; // format: YYYY-MM-DD
} Expense;

// Function prototypes
void addExpense(Expense *expenses, int *expenseCount);
void viewExpenses(Expense *expenses, int expenseCount);
void totalExpenses(Expense *expenses, int expenseCount);

int main() {
    Expense *expenses = malloc(100 * sizeof(Expense)); // Dynamic array for expenses
    int expenseCount = 0;
    int choice;

    printf("🎉 Welcome to the Amazing Expense Tracker! 🎊\n");

    // Main menu loop
    do {
        printf("\nPlease choose an option:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Exit\n");
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
                totalExpenses(expenses, expenseCount);
                break;
            case 4:
                printf("Thanks for using the Expense Tracker! See you soon! 😊\n");
                break;
            default:
                printf("Oops! Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    free(expenses); // Free dynamically allocated memory
    return 0;
}

// Function to add a new expense
void addExpense(Expense *expenses, int *expenseCount) {
    printf("🏷️ Enter the description of the expense: ");
    scanf(" %[^\n]", expenses[*expenseCount].description);
    printf("💰 Enter the amount of the expense: ");
    scanf("%f", &expenses[*expenseCount].amount);
    printf("📅 Enter the date (YYYY-MM-DD): ");
    scanf(" %s", expenses[*expenseCount].date);
    
    (*expenseCount)++;
    printf("🎉 Expense added successfully! 🎉\n");
}

// Function to view all expenses
void viewExpenses(Expense *expenses, int expenseCount) {
    if (expenseCount == 0) {
        printf("❌ No expenses recorded yet! Please add some expenses first.\n");
        return;
    }

    printf("\n📋 Your Expenses:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("❗ Expense %d:\n", i + 1);
        printf("   Description: %s\n", expenses[i].description);
        printf("   Amount: $%.2f\n", expenses[i].amount);
        printf("   Date: %s\n", expenses[i].date);
    }
}

// Function to calculate total expenses
void totalExpenses(Expense *expenses, int expenseCount) {
    if (expenseCount == 0) {
        printf("❌ No expenses recorded yet! Can't calculate total expenses.\n");
        return;
    }

    float total = 0.0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }
    printf("🎊 Total Expenses: $%.2f 🎊\n", total);
}