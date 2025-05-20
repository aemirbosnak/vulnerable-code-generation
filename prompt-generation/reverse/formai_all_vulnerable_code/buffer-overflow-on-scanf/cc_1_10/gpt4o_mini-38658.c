//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_EXPENSES) {
        strncpy(tracker->expenses[tracker->count].description, description, DESCRIPTION_LENGTH);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
        printf("Expense added: %s - $%.2f\n", description, amount);
    } else {
        printf("Error: Cannot add more expenses, limit reached.\n");
    }
}

void displayExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("--------------------\n");
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. View Total Expenses\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    int choice;
    
    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char description[DESCRIPTION_LENGTH];
                float amount;
                printf("Enter expense description: ");
                scanf(" %[^\n]", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(&tracker, description, amount);
                break;
            }
            case 2:
                displayExpenses(&tracker);
                break;
            case 3: {
                float total = calculateTotal(&tracker);
                printf("Total Expenses: $%.2f\n", total);
                break;
            }
            case 4:
                printf("Exiting Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}