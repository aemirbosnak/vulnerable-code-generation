//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: relaxed
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

void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
float calculateTotal(const ExpenseTracker *tracker);
void clearScreen();

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    int choice;

    do {
        clearScreen();
        printf("==== Expense Tracker ====\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total\n");
        printf("4. Exit\n");
        printf("=========================\n");
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
                printf("Total Expenses: $%.2f\n", calculateTotal(&tracker));
                printf("Press Enter to continue...\n");
                getchar();  // Clear buffer
                getchar();  // Wait for the user to press Enter
                break;
            case 4:
                printf("Thanks for using the Expense Tracker! Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                printf("Press Enter to continue...\n");
                getchar();  // Clear buffer
                getchar();  // Wait for the user to press Enter
                break;
        }
    } while (choice != 4);

    return 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        printf("Press Enter to continue...\n");
        getchar();  // Clear buffer
        getchar();  // Wait for the user to press Enter
        return;
    }

    Expense newExpense;
    
    printf("Enter description: ");
    getchar();  // Clear buffer
    fgets(newExpense.description, DESCRIPTION_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0;  // Remove newline

    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count++] = newExpense;
    printf("Expense added successfully! Press Enter to continue...\n");
    getchar();  // Clear buffer
    getchar();  // Wait for the user to press Enter
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
    } else {
        printf("==== Your Expenses ====\n");
        for (int i = 0; i < tracker->count; i++) {
            printf("%d. %s: $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
        }
    }
    printf("Press Enter to continue...\n");
    getchar();  // Clear buffer
    getchar();  // Wait for the user to press Enter
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void clearScreen() {
    system("clear");  // Use "cls" if you're on Windows
}