//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 30
#define CATEGORY_LENGTH 20

typedef struct {
    char name[NAME_LENGTH];
    char category[CATEGORY_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }

    Expense expense;
    printf("Enter name of expense: ");
    scanf("%s", expense.name);
    printf("Enter category of expense: ");
    scanf("%s", expense.category);
    printf("Enter amount of expense: ");
    scanf("%f", &expense.amount);

    tracker->expenses[tracker->count] = expense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n==================== Expenses ====================\n");
    printf("%-15s %-15s %-10s\n", "Name", "Category", "Amount");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%-15s %-15s $%-9.2f\n", tracker->expenses[i].name, tracker->expenses[i].category, tracker->expenses[i].amount);
    }
    printf("===================================================\n");
}

void calculateTotal(ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void displayMenu() {
    printf("\n==================== Personal Finance Planner ====================\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
    printf("===================================================================\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    int option;

    while (1) {
        displayMenu();
        scanf("%d", &option);

        switch (option) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                calculateTotal(&tracker);
                break;
            case 4:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please select a valid option.\n");
        }
    }

    return 0;
}