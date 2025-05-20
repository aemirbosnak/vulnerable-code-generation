//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_SIZE 50

typedef struct {
    char name[NAME_SIZE];
    float amount;
} Entry;

typedef struct {
    Entry incomeEntries[MAX_ENTRIES];
    Entry expenseEntries[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} FinanceTracker;

void initializeTracker(FinanceTracker* tracker) {
    tracker->incomeCount = 0;
    tracker->expenseCount = 0;
}

void addIncome(FinanceTracker* tracker) {
    if (tracker->incomeCount < MAX_ENTRIES) {
        Entry newIncome;
        printf("Enter income source name: ");
        scanf(" %[^\n]", newIncome.name);
        printf("Enter income amount: ");
        scanf("%f", &newIncome.amount);
        tracker->incomeEntries[tracker->incomeCount++] = newIncome;
        printf("Income added successfully!\n");
    } else {
        printf("Income entries limit reached!\n");
    }
}

void addExpense(FinanceTracker* tracker) {
    if (tracker->expenseCount < MAX_ENTRIES) {
        Entry newExpense;
        printf("Enter expense name: ");
        scanf(" %[^\n]", newExpense.name);
        printf("Enter expense amount: ");
        scanf("%f", &newExpense.amount);
        tracker->expenseEntries[tracker->expenseCount++] = newExpense;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense entries limit reached!\n");
    }
}

void viewFinances(const FinanceTracker* tracker) {
    float totalIncome = 0.0, totalExpense = 0.0;

    printf("\n\n*** Income Entries ***\n");
    for (int i = 0; i < tracker->incomeCount; i++) {
        printf("Source: %s, Amount: %.2f\n", tracker->incomeEntries[i].name, tracker->incomeEntries[i].amount);
        totalIncome += tracker->incomeEntries[i].amount;
    }
    
    printf("\n*** Expense Entries ***\n");
    for (int i = 0; i < tracker->expenseCount; i++) {
        printf("Expense: %s, Amount: %.2f\n", tracker->expenseEntries[i].name, tracker->expenseEntries[i].amount);
        totalExpense += tracker->expenseEntries[i].amount;
    }

    printf("\nTotal Income: %.2f\n", totalIncome);
    printf("Total Expense: %.2f\n", totalExpense);
    printf("Net Savings: %.2f\n", totalIncome - totalExpense);
}

void clearEntries(FinanceTracker* tracker) {
    tracker->incomeCount = 0;
    tracker->expenseCount = 0;
    printf("All entries cleared!\n");
}

int main() {
    FinanceTracker tracker;
    initializeTracker(&tracker);

    int choice;
    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Finances\n");
        printf("4. Clear All Entries\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&tracker);
                break;
            case 2:
                addExpense(&tracker);
                break;
            case 3:
                viewFinances(&tracker);
                break;
            case 4:
                clearEntries(&tracker);
                break;
            case 5:
                printf("Exiting the program. Happy budgeting!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);

    return 0;
}