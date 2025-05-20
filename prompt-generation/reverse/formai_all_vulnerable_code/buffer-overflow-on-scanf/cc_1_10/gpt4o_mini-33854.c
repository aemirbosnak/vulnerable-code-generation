//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

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

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("Graciously initializing your Expense Tracker...\n");
}

void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if(tracker->count < MAX_EXPENSES) {
        snprintf(tracker->expenses[tracker->count].description, DESCRIPTION_LENGTH, "%s", description);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
        printf("Added expense: %s for amount: %.2f\n", description, amount);
    } else {
        printf("Thank you for trying to add an expense, but you have reached the limit of %d expenses!\n", MAX_EXPENSES);
    }
}

void displayExpenses(const ExpenseTracker *tracker) {
    printf("\nYour Current Expenses:\n");
    if(tracker->count == 0) {
        printf("No expenses recorded. Start adding to them!\n");
        return;
    }

    for(int i = 0; i < tracker->count; i++) {
        printf("%d: %s - %.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

float calculateTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0f;
    for(int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void displayTotal(const ExpenseTracker *tracker) {
    float total = calculateTotalExpenses(tracker);
    printf("Your total expenses are: %.2f\n", total);
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);

    char description[DESCRIPTION_LENGTH];
    float amount;
    char choice;

    do {
        printf("\nWould you like to add a new expense? (y/n): ");
        scanf(" %c", &choice);
        
        if(choice == 'y' || choice == 'Y') {
            printf("Enter the description of the expense: ");
            scanf(" %[^\n]", description);
            printf("Enter the amount of the expense: ");
            scanf("%f", &amount);
            addExpense(&tracker, description, amount);
        }
        
    } while(choice == 'y' || choice == 'Y');

    displayExpenses(&tracker);
    displayTotal(&tracker);

    printf("Thank you for using the Expense Tracker. May your budgeting journey be rewarding and enlightening!\n");

    return 0;
}