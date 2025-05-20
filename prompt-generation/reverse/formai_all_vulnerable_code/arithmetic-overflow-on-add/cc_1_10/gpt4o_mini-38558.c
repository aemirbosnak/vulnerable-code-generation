//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
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
        printf("Maximum income entries reached!\n");
        return;
    }
    printf("Enter income source: ");
    scanf("%s", tracker->income[tracker->incomeCount].name);
    printf("Enter income amount: ");
    scanf("%f", &tracker->income[tracker->incomeCount].amount);
    tracker->incomeCount++;
    printf("Income added successfully!\n");
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expenseCount >= MAX_ENTRIES) {
        printf("Maximum expense entries reached!\n");
        return;
    }
    printf("Enter expense type: ");
    scanf("%s", tracker->expenses[tracker->expenseCount].name);
    printf("Enter expense amount: ");
    scanf("%f", &tracker->expenses[tracker->expenseCount].amount);
    tracker->expenseCount++;
    printf("Expense added successfully!\n");
}

void showSummary(FinanceTracker tracker) {
    float totalIncome = 0.0, totalExpenses = 0.0;
    
    printf("\n--- Financial Summary ---\n");
    printf("Income:\n");
    for (int i = 0; i < tracker.incomeCount; i++) {
        printf("%s: $%.2f\n", tracker.income[i].name, tracker.income[i].amount);
        totalIncome += tracker.income[i].amount;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < tracker.expenseCount; i++) {
        printf("%s: $%.2f\n", tracker.expenses[i].name, tracker.expenses[i].amount);
        totalExpenses += tracker.expenses[i].amount;
    }

    printf("\nTotal Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", totalIncome - totalExpenses);
}

void displayMenu() {
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. Show Summary\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FinanceTracker tracker = { .incomeCount = 0, .expenseCount = 0 };
    int choice;

    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addIncome(&tracker);
                break;
            case 2:
                addExpense(&tracker);
                break;
            case 3:
                showSummary(tracker);
                break;
            case 4:
                printf("Exiting the finance planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }
    
    return 0;
}