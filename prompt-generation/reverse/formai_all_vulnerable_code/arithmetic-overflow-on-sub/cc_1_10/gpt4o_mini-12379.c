//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LEN 50

typedef struct {
    char description[MAX_DESC_LEN];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int total_expenses;
} ExpenseTracker;

void initialize_tracker(ExpenseTracker *tracker) {
    tracker->total_expenses = 0;
}

void add_expense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->total_expenses >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    strcpy(tracker->expenses[tracker->total_expenses].description, description);
    tracker->expenses[tracker->total_expenses].amount = amount;
    tracker->total_expenses++;
    printf("Expense added: %s - $%.2f\n", description, amount);
}

void view_expenses(const ExpenseTracker *tracker) {
    if (tracker->total_expenses == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\n--- Expenses ---\n");
    for (int i = 0; i < tracker->total_expenses; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("----------------\n");
}

float calculate_total(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->total_expenses; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void remove_expense(ExpenseTracker *tracker, int index) {
    if (index < 0 || index >= tracker->total_expenses) {
        printf("Invalid index! Please enter a valid index.\n");
        return;
    }
    for (int i = index; i < tracker->total_expenses - 1; i++) {
        tracker->expenses[i] = tracker->expenses[i + 1];
    }
    tracker->total_expenses--;
    printf("Expense removed from index %d.\n", index + 1);
}

void clear_expenses(ExpenseTracker *tracker) {
    tracker->total_expenses = 0;
    printf("All expenses cleared!\n");
}

void display_menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Remove Expense\n");
    printf("5. Clear All Expenses\n");
    printf("6. Exit\n");
    printf("---------------------------\n");
}

int main() {
    ExpenseTracker tracker;
    initialize_tracker(&tracker);
    int choice;
    char description[MAX_DESC_LEN];
    float amount;
    int index;

    while (1) {
        display_menu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter description: ");
                getchar(); // Clear newline
                fgets(description, MAX_DESC_LEN, stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline
                printf("Enter amount: ");
                scanf("%f", &amount);
                add_expense(&tracker, description, amount);
                break;

            case 2:
                view_expenses(&tracker);
                break;

            case 3:
                printf("Total Expenses: $%.2f\n", calculate_total(&tracker));
                break;

            case 4:
                printf("Enter index of expense to remove: ");
                scanf("%d", &index);
                remove_expense(&tracker, index - 1);
                break;

            case 5:
                clear_expenses(&tracker);
                break;

            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);

            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    }

    return 0;
}