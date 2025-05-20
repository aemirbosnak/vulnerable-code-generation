//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char description[100];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }

    printf("Enter the description of the expense: ");
    scanf(" %[^\n]", tracker->expenses[tracker->count].description);

    printf("Enter the amount of the expense: ");
    scanf("%f", &tracker->expenses[tracker->count].amount);

    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n----- Expenses -----\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("---------------------\n");
}

void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the number of the expense to delete (1-%d): ", tracker->count);
    scanf("%d", &index);
    
    if (index < 1 || index > tracker->count) {
        printf("Invalid index! No expense deleted.\n");
        return;
    }

    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully!\n");
}

void totalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void displayMenu() {
    printf("\n----- Expense Tracker Menu -----\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Calculate Total Expenses\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    
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
                deleteExpense(&tracker);
                break;
            case 4:
                totalExpenses(&tracker);
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}