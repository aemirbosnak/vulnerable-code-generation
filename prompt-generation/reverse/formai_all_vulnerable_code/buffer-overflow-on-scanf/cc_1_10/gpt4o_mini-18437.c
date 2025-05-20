//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char description[100];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense *expenses;
    int count;
    int capacity;
} ExpenseTracker;

void initTracker(ExpenseTracker *tracker, int capacity) {
    tracker->expenses = (Expense *) malloc(sizeof(Expense) * capacity);
    tracker->count = 0;
    tracker->capacity = capacity;
}

void addExpense(ExpenseTracker *tracker, const char *description, float amount, const char *date) {
    if (tracker->count == tracker->capacity) {
        tracker->capacity *= 2;
        tracker->expenses = (Expense *) realloc(tracker->expenses, sizeof(Expense) * tracker->capacity);
    }

    strcpy(tracker->expenses[tracker->count].description, description);
    tracker->expenses[tracker->count].amount = amount;
    strcpy(tracker->expenses[tracker->count].date, date);
    tracker->count++;
}

void displayExpenses(const ExpenseTracker *tracker) {
    printf("\nExpense Tracker:\n");
    printf("----------------------------------------------------------\n");
    printf("| %-20s | %-10s | %-10s |\n", "Description", "Amount", "Date");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("| %-20s | $%-9.2f | %-10s |\n", tracker->expenses[i].description,
               tracker->expenses[i].amount, tracker->expenses[i].date);
    }
    printf("----------------------------------------------------------\n");
}

float totalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void freeTracker(ExpenseTracker *tracker) {
    free(tracker->expenses);
    tracker->expenses = NULL;
    tracker->count = 0;
    tracker->capacity = 0;
}

int main() {
    ExpenseTracker tracker;
    initTracker(&tracker, 5); // Start with a capacity of 5

    int choice;
    do {
        printf("\n=== Expense Tracker Menu ===\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. View Total Expenses\n");
        printf("4. Exit\n");
        printf("===========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            char description[100];
            float amount;
            char date[11];

            printf("Enter expense description: ");
            getchar();  // Consume newline left in the buffer
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0; // Remove newline

            printf("Enter amount: ");
            scanf("%f", &amount);

            printf("Enter date (YYYY-MM-DD): ");
            scanf("%s", date);

            addExpense(&tracker, description, amount, date);
            printf("Expense added successfully!\n");
        } else if (choice == 2) {
            displayExpenses(&tracker);
        } else if (choice == 3) {
            printf("Total Expenses: $%.2f\n", totalExpenses(&tracker));
        } else if (choice == 4) {
            printf("Exiting the program. Goodbye!\n");
        } else {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    freeTracker(&tracker);
    return 0;
}