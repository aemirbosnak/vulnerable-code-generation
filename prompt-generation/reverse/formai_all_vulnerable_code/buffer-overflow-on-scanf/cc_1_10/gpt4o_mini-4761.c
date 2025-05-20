//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char description[100];
    float amount;
} Expense;

typedef struct {
    Expense* expenses;
    int count;
    int capacity;
} ExpenseTracker;

void initializeTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
    tracker->capacity = 2;
    tracker->expenses = malloc(sizeof(Expense) * tracker->capacity);
}

void addExpense(ExpenseTracker* tracker, const char* description, float amount) {
    if (tracker->count >= tracker->capacity) {
        tracker->capacity *= 2;
        tracker->expenses = realloc(tracker->expenses, sizeof(Expense) * tracker->capacity);
    }
    strcpy(tracker->expenses[tracker->count].description, description);
    tracker->expenses[tracker->count].amount = amount;
    tracker->count++;
}

void deleteExpense(ExpenseTracker* tracker, int index) {
    if (index < 0 || index >= tracker->count) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
}

void viewExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

float calculateTotal(const ExpenseTracker* tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void freeTracker(ExpenseTracker* tracker) {
    free(tracker->expenses);
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    char description[100];
    float amount;

    do {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Calculate Total Expenses\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter expense description: ");
                scanf(" %[^\n]", description);  // Read string with spaces
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addExpense(&tracker, description, amount);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                printf("Enter the index of the expense to delete: ");
                int index;
                scanf("%d", &index);
                deleteExpense(&tracker, index - 1); // Adjust for zero-based index
                break;
            case 4:
                printf("Total Expenses: $%.2f\n", calculateTotal(&tracker));
                break;
            case 5:
                freeTracker(&tracker);
                printf("Exiting the program. Bye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}