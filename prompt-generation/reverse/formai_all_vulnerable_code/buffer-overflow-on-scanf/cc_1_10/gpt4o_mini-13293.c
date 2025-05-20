//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 30
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initExpenseTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Neon lights flicker. Expense limit reached. Can't record more.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense name (infiltrate your thoughts): ");
    scanf("%s", newExpense.name);
    printf("Enter expense category (cybernetic add-ons, food, etc.): ");
    scanf("%s", newExpense.category);
    printf("Enter amount (in shards): ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense recorded in the digital ether. %s: %.2f \n", newExpense.name, newExpense.amount);
}

void displayExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses documented. The streets are empty.\n");
        return;
    }

    printf("\n--- Expense Report ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Name: %s | Category: %s | Amount: %.2f shards\n", 
               tracker->expenses[i].name, 
               tracker->expenses[i].category, 
               tracker->expenses[i].amount);
    }
    printf("----------------------\n");
}

void totalExpenses(ExpenseTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses: %.2f shards\n", total);
}

void cyberpunkTheme() {
    printf("=================================\n");
    printf("       Cyberpunk Expense Tracker  \n");
    printf("=================================\n");
    printf("     Welcome to the neon underworld\n");
    printf("=================================\n");
}

int main() {
    ExpenseTracker tracker;
    initExpenseTracker(&tracker);
    
    int choice;
    cyberpunkTheme();

    do {
        printf("\nChoose your action:\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Total expenses\n");
        printf("4. Exit the Grid\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                totalExpenses(&tracker);
                break;
            case 4:
                printf("Powering down your interface...\n");
                break;
            default:
                printf("Invalid choice. The digital world is glitching!\n");
        }
    } while (choice != 4);

    return 0;
}