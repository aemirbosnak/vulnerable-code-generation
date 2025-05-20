//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} FinanceTracker;

void addIncome(FinanceTracker *tracker) {
    if (tracker->incomeCount >= MAX_ENTRIES) {
        printf("Income entries full!\n");
        return;
    }
    printf("Enter income description: ");
    scanf(" %[^\n]%*c", tracker->income[tracker->incomeCount].description);
    printf("Enter income amount: ");
    scanf("%f", &tracker->income[tracker->incomeCount].amount);
    tracker->incomeCount++;
    printf("Income added successfully!\n");
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expenseCount >= MAX_ENTRIES) {
        printf("Expense entries full!\n");
        return;
    }
    printf("Enter expense description: ");
    scanf(" %[^\n]%*c", tracker->expenses[tracker->expenseCount].description);
    printf("Enter expense amount: ");
    scanf("%f", &tracker->expenses[tracker->expenseCount].amount);
    tracker->expenseCount++;
    printf("Expense added successfully!\n");
}

void viewSummary(FinanceTracker tracker) {
    float totalIncome = 0.0, totalExpenses = 0.0;

    printf("\n----- Financial Summary -----\n");
    printf("Income:\n");
    for (int i = 0; i < tracker.incomeCount; i++) {
        printf("  %s: %.2f\n", tracker.income[i].description, tracker.income[i].amount);
        totalIncome += tracker.income[i].amount;
    }
    
    printf("\nExpenses:\n");
    for (int i = 0; i < tracker.expenseCount; i++) {
        printf("  %s: %.2f\n", tracker.expenses[i].description, tracker.expenses[i].amount);
        totalExpenses += tracker.expenses[i].amount;
    }
    
    printf("\nTotal Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Savings: %.2f\n", totalIncome - totalExpenses);
    printf("-----------------------------\n");
}

void clearEntries(FinanceTracker *tracker) {
    tracker->incomeCount = 0;
    tracker->expenseCount = 0;
    printf("All entries cleared successfully!\n");
}

int main() {
    FinanceTracker tracker = { .incomeCount = 0, .expenseCount = 0 };
    int choice;

    while (1) {
        printf("\n=== Personal Finance Planner ===\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Clear All Entries\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&tracker);
                break;
            case 2:
                addExpense(&tracker);
                break;
            case 3:
                viewSummary(tracker);
                break;
            case 4:
                clearEntries(&tracker);
                break;
            case 5:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                return 0;
            default:
                printf("Invalid option. Please try again.\n");
        }
    }
    return 0;
}