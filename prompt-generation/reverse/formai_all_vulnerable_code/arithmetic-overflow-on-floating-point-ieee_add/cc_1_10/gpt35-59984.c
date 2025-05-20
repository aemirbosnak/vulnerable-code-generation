//FormAI DATASET v1.0 Category: Expense Tracker ; Style: configurable
// A simple C Expense Tracker program with configuration settings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSE_ITEMS 50
#define MAX_EXPENSE_NAME_LENGTH 50

typedef struct {
    char name[MAX_EXPENSE_NAME_LENGTH];
    float amount;
} ExpenseItem;

typedef struct {
    float budget;
    float expenses;
    int num_items;
    ExpenseItem items[MAX_EXPENSE_ITEMS];
} ExpenseTracker;

void print_menu() {
    printf("1. Add expense\n");
    printf("2. Print expenses\n");
    printf("3. Print budget and expenses\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
}

void add_expense(ExpenseTracker *tracker) {
    char name[MAX_EXPENSE_NAME_LENGTH];
    float amount;

    printf("Enter expense name: ");
    scanf("%s", name);
    printf("Enter expense amount: ");
    scanf("%f", &amount);

    if (tracker->num_items >= MAX_EXPENSE_ITEMS) {
        printf("Maximum number of expense items reached.\n");
        return;
    }

    // Add expense item to tracker and update total expenses
    strcpy(tracker->items[tracker->num_items].name, name);
    tracker->items[tracker->num_items].amount = amount;
    tracker->expenses += amount;
    tracker->num_items++;
}

void print_expenses(ExpenseTracker tracker) {
    printf("Expenses:\n");
    for (int i = 0; i < tracker.num_items; i++) {
        printf("%s: $%.2f\n", tracker.items[i].name, tracker.items[i].amount);
    }
}

void print_budget(ExpenseTracker tracker) {
    printf("Budget: $%.2f\n", tracker.budget);
    printf("Expenses: $%.2f\n", tracker.expenses);
    printf("Remaining budget: $%.2f\n", tracker.budget - tracker.expenses);
}

int main() {
    ExpenseTracker tracker;
    memset(&tracker, 0, sizeof(tracker));

    // Configure budget
    printf("Enter budget: ");
    scanf("%f", &tracker.budget);

    int choice = 0;
    do {
        print_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(&tracker);
                break;
            case 2:
                print_expenses(tracker);
                break;
            case 3:
                print_budget(tracker);
                break;
            case 4:
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 4);

    printf("Goodbye!\n");
    return 0;
}