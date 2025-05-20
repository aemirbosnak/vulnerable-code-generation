//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_SIZE 50

typedef struct {
    char description[DESCRIPTION_SIZE];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_EXPENSES) {
        strcpy(tracker->expenses[tracker->count].description, description);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
        printf("Expense added: %s - $%.2f\n", description, amount);
    } else {
        printf("Expense limit reached! Cannot add more expenses.\n");
    }
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\nExpense Report:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("\n");
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void deleteExpense(ExpenseTracker *tracker, int index) {
    if (index < 0 || index >= tracker->count) {
        printf("Invalid index! No expense deleted.\n");
        return;
    }

    // Shift expenses to the left
    for (int i = index; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully.\n");
}

void displayMenu() {
    printf("Expense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Delete Expense\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    char description[DESCRIPTION_SIZE];
    float amount;
    int deleteIndex;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense description: ");
                scanf(" %[^\n]", description); // Read string with spaces
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(&tracker, description, amount);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                printf("Total expenses: $%.2f\n", calculateTotal(&tracker));
                break;
            case 4:
                printf("Enter index of expense to delete (1 to %d): ", tracker.count);
                scanf("%d", &deleteIndex);
                deleteExpense(&tracker, deleteIndex - 1); // Adjusting for zero-based index
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option! Please try again.\n");
        }
    }

    return 0;
}