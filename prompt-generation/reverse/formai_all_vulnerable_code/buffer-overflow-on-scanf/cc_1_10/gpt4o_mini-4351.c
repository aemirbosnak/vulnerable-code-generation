//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: creative
#include <stdio.h>
#include <stdlib.h>  
#include <stdbool.h>
#include <string.h>

#define MAX_EXPENSES 100
#define EXPENSE_DESC_LEN 50

typedef struct {
    char description[EXPENSE_DESC_LEN];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
    float total;
} ExpenseTracker;

void initTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
    tracker->total = 0.0f;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count < MAX_EXPENSES) {
        Expense newExpense;

        printf("Enter expense description: ");
        scanf("%s", newExpense.description);
        printf("Enter expense amount: ");
        scanf("%f", &newExpense.amount);

        tracker->expenses[tracker->count] = newExpense;
        tracker->total += newExpense.amount;
        tracker->count++;

        printf("Expense added successfully!\n");
    } else {
        printf("Maximum expense limit reached! Cannot add more expenses.\n");
    }
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to show.\n");
        return;
    }

    printf("\n--- Expense Report ---\n");
    printf("| %-20s | %-10s |\n", "Description", "Amount");
    printf("-----------------------|-----------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("| %-20s | %-10.2f |\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("-----------------------|-----------\n");
    printf("Total Expenses: %.2f\n", tracker->total);
}

void saveExpenses(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Error opening file for writing!\n");
        return;
    }
    
    fprintf(file, "Expense Report\n");
    fprintf(file, "====================\n");
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s: %.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    fprintf(file, "Total: %.2f\n", tracker->total);
    fclose(file);

    printf("Expenses saved to expenses.txt successfully!\n");
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Save Expenses\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    initTracker(&tracker);
    int choice;

    while (true) {
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
                saveExpenses(&tracker);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}