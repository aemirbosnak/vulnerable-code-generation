//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: creative
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    float amount;
    char date[11]; // format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
void reportSummary(const ExpenseTracker *tracker);
void displayMenu();

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;

    while (1) {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                reportSummary(&tracker);
                break;
            case 4:
                printf("Exiting the Personal Finance Planner. Have a great day!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter description: ");
    scanf(" %[^\n]", newExpense.description);
    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;

    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n*** List of Expenses ***\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d: %s - $%.2f on %s\n", 
               i + 1, tracker->expenses[i].description, 
               tracker->expenses[i].amount, tracker->expenses[i].date);
    }
    printf("\n");
}

void reportSummary(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }

    printf("\n*** Expense Summary ***\n");
    printf("Total expenses: $%.2f\n", total);
    printf("Number of expenses recorded: %d\n", tracker->count);
    printf("\n");
}

void displayMenu() {
    printf("\n=== Personal Finance Planner ===\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Report Summary\n");
    printf("4. Exit\n");
}