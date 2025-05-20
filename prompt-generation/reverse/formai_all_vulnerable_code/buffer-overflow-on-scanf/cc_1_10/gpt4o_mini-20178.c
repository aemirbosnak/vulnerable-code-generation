//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define NAME_LENGTH 30

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached!\n");
        return;
    }

    char name[NAME_LENGTH];
    float amount;

    printf("Enter expense name: ");
    scanf("%s", name);
    printf("Enter expense amount: ");
    scanf("%f", &amount);

    strcpy(tracker->expenses[tracker->count].name, name);
    tracker->expenses[tracker->count].amount = amount;
    tracker->count++;

    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker->expenses[i].name, tracker->expenses[i].amount);
    }
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared.\n");
}

void displayMenu() {
    printf("\nExpense Tracker Menu:\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Clear Expenses\n");
    printf("5. Exit\n");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;

    do {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", calculateTotal(&tracker));
                break;
            case 4:
                clearExpenses(&tracker);
                break;
            case 5:
                printf("Exiting Expense Tracker. Have a great day!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}