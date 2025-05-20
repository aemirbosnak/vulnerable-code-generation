//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: shape shifting
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

void initTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker, char *description, float amount) {
    if (tracker->count < MAX_EXPENSES) {
        strcpy(tracker->expenses[tracker->count].description, description);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
        printf("Expense added: %s - $%.2f\n", description, amount);
    } else {
        printf("Maximum expense limit reached!\n");
    }
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    
    printf("Expenses Recorded:\n");
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses have been cleared!\n");
}

void menu() {
    printf("\n--- Expense Tracker ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Clear Expenses\n");
    printf("4. Exit\n");
    printf("-----------------------\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker;
    initTracker(&tracker);
    int choice;
    
    while (1) {
        menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: {
                char description[DESCRIPTION_LENGTH];
                float amount;
                
                printf("Enter Description: ");
                getchar(); // to consume newline left in buffer
                fgets(description, sizeof(description), stdin);
                description[strcspn(description, "\n")] = 0; // Remove newline character
                
                printf("Enter Amount: ");
                scanf("%f", &amount);
                
                addExpense(&tracker, description, amount);
                break;
            }
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                clearExpenses(&tracker);
                break;
            case 4:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    
    return 0;
}