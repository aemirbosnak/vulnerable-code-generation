//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

// Function declarations
void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
void calculateTotal(const ExpenseTracker *tracker);
void clearExpenses(ExpenseTracker *tracker);
void printMenu();
void handleUserChoice(int choice, ExpenseTracker *tracker);

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;

    while (1) {
        printMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        handleUserChoice(choice, &tracker);
    }

    return 0;
}

void printMenu() {
    printf("\n=== Expense Tracker ===\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Clear All Expenses\n");
    printf("5. Exit\n");
    printf("=======================\n");
}

void handleUserChoice(int choice, ExpenseTracker *tracker) {
    switch (choice) {
        case 1:
            addExpense(tracker);
            break;
        case 2:
            viewExpenses(tracker);
            break;
        case 3:
            calculateTotal(tracker);
            break;
        case 4:
            clearExpenses(tracker);
            break;
        case 5:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice! Please try again.\n");
            break;
    }
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense list is full! Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    getchar();  // Consume newline character left by scanf
    fgets(newExpense.description, DESCRIPTION_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n=== Recorded Expenses ===\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("=========================\n");
}

void calculateTotal(const ExpenseTracker *tracker) {
    float total = 0;

    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }

    printf("Total expenses: $%.2f\n", total);
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared!\n");
}