//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DESCRIPTION 100
#define MAX_EXPENSES 100

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

typedef struct {
    Expense *expenses;
    int count;
} ExpenseTracker;

// Function Declarations
void initializeTracker(ExpenseTracker *tracker);
void addExpense(ExpenseTracker *tracker);
void viewExpenses(ExpenseTracker *tracker);
void deleteExpense(ExpenseTracker *tracker);
void freeTracker(ExpenseTracker *tracker);
void displayMenu();

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    int choice;

    do {
        displayMenu();
        printf("Enter your choice: ");
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
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    freeTracker(&tracker);
    return 0;
}

void initializeTracker(ExpenseTracker *tracker) {
    tracker->expenses = (Expense *)malloc(MAX_EXPENSES * sizeof(Expense));
    if (tracker->expenses == NULL) {
        printf("Failed to allocate memory for expenses.\n");
        exit(1);
    }
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    getchar(); // to consume newline character left by previous input
    fgets(newExpense.description, MAX_DESCRIPTION, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n=== Expense List ===\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("====================\n");
}

void deleteExpense(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    viewExpenses(tracker);
    int index;

    printf("Enter the index of the expense to delete: ");
    scanf("%d", &index);
    
    if (index < 1 || index > tracker->count) {
        printf("Invalid index. No expense deleted.\n");
        return;
    }

    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->count--;
    printf("Expense deleted successfully!\n");
}

void freeTracker(ExpenseTracker *tracker) {
    free(tracker->expenses);
}

void displayMenu() {
    printf("\n=== Expense Tracker Menu ===\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Exit\n");
    printf("============================\n");
}