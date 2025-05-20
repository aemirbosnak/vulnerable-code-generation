//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    
    printf("Enter description of the expense: ");
    getchar(); // Clear newline from buffer
    fgets(tracker->expenses[tracker->count].description, MAX_DESC_LENGTH, stdin);
    tracker->expenses[tracker->count].description[strcspn(tracker->expenses[tracker->count].description, "\n")] = '\0'; // Remove newline

    printf("Enter amount: ");
    scanf("%f", &tracker->expenses[tracker->count].amount);

    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded!\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("--------------------\n");
}

float calculateTotal(ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void clearAllExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared!\n");
}

void displayMenu() {
    printf("\n*** Expense Tracker ***\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expense\n");
    printf("4. Clear All Expenses\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    ExpenseTracker tracker;
    initTracker(&tracker);
    int choice = 0;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                {
                    float total = calculateTotal(&tracker);
                    printf("Total Expense: $%.2f\n", total);
                }
                break;
            case 4:
                clearAllExpenses(&tracker);
                break;
            case 5:
                printf("Exiting the Expense Tracker...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}