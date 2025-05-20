//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int cost;
} Expense;

typedef struct {
    char knight[NAME_LENGTH];
    Expense expenses[MAX_EXPENSES];
    int totalExpenses;
    int totalCost;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->totalExpenses >= MAX_EXPENSES) {
        printf("Alas! Thou hast reached the limit of expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter the name of the expense (e.g., 'Dragon Slaying'): ");
    scanf("%s", newExpense.name);
    printf("Enter the cost of the expense (in gold coins): ");
    scanf("%d", &newExpense.cost);

    tracker->expenses[tracker->totalExpenses++] = newExpense;
    tracker->totalCost += newExpense.cost;

    printf("Thou hast successfully added the expense of %d gold coins for %s.\n",
           newExpense.cost, newExpense.name);
}

void viewExpenses(ExpenseTracker *tracker) {
    printf("\nExpenses of Sir %s:\n", tracker->knight);
    printf("--------------------------------------------------\n");
    for (int i = 0; i < tracker->totalExpenses; i++) {
        printf("Expense %d: %s - %d gold coins\n", i + 1, 
               tracker->expenses[i].name, 
               tracker->expenses[i].cost);
    }
    printf("--------------------------------------------------\n");
    printf("Total Expenses: %d gold coins\n", tracker->totalCost);
}

void initializeTracker(ExpenseTracker *tracker) {
    printf("Enter the name of the knight: ");
    scanf("%s", tracker->knight);
    tracker->totalExpenses = 0;
    tracker->totalCost = 0;
    
    printf("Huzzah! The expense tracker for Sir %s hath been initialized!\n", tracker->knight);
}

void displayMenu() {
    printf("\n---------------------\n");
    printf(" Medieval Expense Tracker\n");
    printf("---------------------\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Exit\n");
    printf("---------------------\n");
    printf("Select thy option (1-3): ");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);

    int choice;
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
                printf("Fare thee well, brave knight!\n");
                return 0;
            default:
                printf("Thou hast made an unwise choice! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}