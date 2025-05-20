//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_STRING_LENGTH 100

typedef struct {
    char description[MAX_STRING_LENGTH];
    float amount;
    char date[MAX_STRING_LENGTH];
} Expense;

typedef struct {
    Expense entries[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense tracker is full! Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    getchar(); // Consume the newline character left by previous input
    fgets(newExpense.description, MAX_STRING_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = '\0'; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    printf("Enter expense date (YYYY-MM-DD): ");
    getchar(); // Consume the newline character left by previous input
    fgets(newExpense.date, MAX_STRING_LENGTH, stdin);
    newExpense.date[strcspn(newExpense.date, "\n")] = '\0'; // Remove newline

    tracker->entries[tracker->count] = newExpense;
    tracker->count++;

    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\nExpense List:\n");
    printf("%-20s %-10s %-15s\n", "Description", "Amount", "Date");
    printf("-----------------------------------------------------\n");

    for (int i = 0; i < tracker->count; i++) {
        printf("%-20s $%-9.2f %-15s\n", tracker->entries[i].description, tracker->entries[i].amount, tracker->entries[i].date);
    }

    printf("-----------------------------------------------------\n");
}

void calculateTotalExpense(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void deleteExpenses(ExpenseTracker *tracker) {
    int index;
    viewExpenses(tracker);
    if (tracker->count == 0) {
        return;
    }

    printf("Enter the index of the expense to delete (0-%d): ", tracker->count - 1);
    scanf("%d", &index);
    
    if (index < 0 || index >= tracker->count) {
        printf("Invalid index!\n");
        return;
    }

    for (int i = index; i < tracker->count - 1; i++) {
        tracker->entries[i] = tracker->entries[i + 1];
    }
    tracker->count--;

    printf("Expense deleted successfully!\n");
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared!\n");
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;

    int choice;
    do {
        printf("\n====== Expense Tracker ======\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expense\n");
        printf("4. Delete an Expense\n");
        printf("5. Clear All Expenses\n");
        printf("0. Exit\n");
        printf("=============================\n");
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
                calculateTotalExpense(&tracker);
                break;
            case 4:
                deleteExpenses(&tracker);
                break;
            case 5:
                clearExpenses(&tracker);
                break;
            case 0:
                printf("Exiting. Have a great day!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}