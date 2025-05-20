//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

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
    if (tracker->incomeCount < MAX_ENTRIES) {
        printf("Enter income description: ");
        scanf("%s", tracker->income[tracker->incomeCount].description);
        printf("Enter income amount: ");
        scanf("%f", &tracker->income[tracker->incomeCount].amount);
        tracker->incomeCount++;
        printf("Income added successfully!\n");
    } else {
        printf("Maximum income entries reached!\n");
    }
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expenseCount < MAX_ENTRIES) {
        printf("Enter expense description: ");
        scanf("%s", tracker->expenses[tracker->expenseCount].description);
        printf("Enter expense amount: ");
        scanf("%f", &tracker->expenses[tracker->expenseCount].amount);
        tracker->expenseCount++;
        printf("Expense added successfully!\n");
    } else {
        printf("Maximum expense entries reached!\n");
    }
}

void showSummary(FinanceTracker *tracker) {
    float totalIncome = 0;
    float totalExpense = 0;

    printf("\n----- Financial Summary -----\n");

    for (int i = 0; i < tracker->incomeCount; i++) {
        printf("Income %d: %s - $%.2f\n", i + 1, tracker->income[i].description, tracker->income[i].amount);
        totalIncome += tracker->income[i].amount;
    }

    for (int i = 0; i < tracker->expenseCount; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
        totalExpense += tracker->expenses[i].amount;
    }

    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpense);
    printf("Net Income: $%.2f\n", totalIncome - totalExpense);
    printf("------------------------------\n");
}

int main() {
    FinanceTracker tracker;
    tracker.incomeCount = 0;
    tracker.expenseCount = 0;
    int choice;

    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Show Summary\n");
        printf("4. Exit\n");
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
                showSummary(&tracker);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}