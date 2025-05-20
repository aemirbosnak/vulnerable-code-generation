//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int total_expenses;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->total_expenses = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->total_expenses >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense new_expense;
    printf("Enter expense description: ");
    scanf(" %[^\n]s", new_expense.description);
    printf("Enter expense amount: ");
    scanf("%f", &new_expense.amount);

    tracker->expenses[tracker->total_expenses] = new_expense;
    tracker->total_expenses++;
    printf("Expense added successfully.\n");
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->total_expenses == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nList of Expenses:\n");
    printf("------------------------------------------------------\n");
    printf("%-30s  %s\n", "Description", "Amount");
    printf("------------------------------------------------------\n");
    for (int i = 0; i < tracker->total_expenses; i++) {
        printf("%-30s  %.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("------------------------------------------------------\n");
}

void totalExpenses(ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->total_expenses; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void averageExpense(ExpenseTracker *tracker) {
    if (tracker->total_expenses == 0) {
        printf("No expenses recorded for averaging.\n");
        return;
    }
    
    float total = 0.0;
    for (int i = 0; i < tracker->total_expenses; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Average Expense: %.2f\n", total / tracker->total_expenses);
}

void displayMenu() {
    printf("\nExpense Tracker Menu\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Average Expense\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    int choice;

    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                totalExpenses(&tracker);
                break;
            case 4:
                averageExpense(&tracker);
                break;
            case 5:
                printf("Exiting Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}