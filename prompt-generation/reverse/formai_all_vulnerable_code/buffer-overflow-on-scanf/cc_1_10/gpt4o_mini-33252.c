//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    float amount;
    char description[MAX_DESCRIPTION_LENGTH];
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker, float amount, const char *description) {
    if (tracker->count < MAX_EXPENSES) {
        tracker->expenses[tracker->count].amount = amount;
        strncpy(tracker->expenses[tracker->count].description, description, MAX_DESCRIPTION_LENGTH);
        tracker->count++;
        printf("Expense added: %.2f - %s\n", amount, description);
    } else {
        printf("Expense tracker is full! Cannot add more expenses.\n");
    }
}

void displayExpenses(const ExpenseTracker *tracker) {
    printf("\nExpense Tracker:\n");
    printf("======================\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %.2f - %s\n", i + 1, tracker->expenses[i].amount, tracker->expenses[i].description);
    }
    printf("======================\n");
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared.\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);

    int choice;
    float amount;
    char description[MAX_DESCRIPTION_LENGTH];

    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Clear All Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount: ");
                scanf("%f", &amount);
                printf("Enter description: ");
                getchar(); // To consume newline left by scanf
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove the trailing newline
                addExpense(&tracker, amount, description);
                break;

            case 2:
                displayExpenses(&tracker);
                break;

            case 3:
                printf("Total Expenses: %.2f\n", calculateTotal(&tracker));
                break;

            case 4:
                clearExpenses(&tracker);
                break;

            case 5:
                printf("Exiting... Thank you for using Expense Tracker!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}