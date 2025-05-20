//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int incomeCount;
    int expenseCount;
} FinanceTracker;

void initFinanceTracker(FinanceTracker *tracker) {
    tracker->incomeCount = 0;
    tracker->expenseCount = 0;
}

void addIncome(FinanceTracker *tracker) {
    if (tracker->incomeCount >= MAX_ENTRIES) {
        printf("Unable to add income; maximum entries reached.\n");
        return;
    }
    printf("Enter income description: ");
    scanf(" %[^\n]", tracker->income[tracker->incomeCount].description);
    printf("Enter income amount: ");
    scanf("%f", &tracker->income[tracker->incomeCount].amount);
    tracker->incomeCount++;
    printf("Income added successfully!\n");
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expenseCount >= MAX_ENTRIES) {
        printf("Unable to add expense; maximum entries reached.\n");
        return;
    }
    printf("Enter expense description: ");
    scanf(" %[^\n]", tracker->expenses[tracker->expenseCount].description);
    printf("Enter expense amount: ");
    scanf("%f", &tracker->expenses[tracker->expenseCount].amount);
    tracker->expenseCount++;
    printf("Expense added successfully!\n");
}

void displayFinances(const FinanceTracker *tracker) {
    float totalIncome = 0.0;
    float totalExpenses = 0.0;

    printf("\nFinancial Overview:\n");
    printf("Income:\n");
    for (int i = 0; i < tracker->incomeCount; i++) {
        printf(" - %s: $%.2f\n", tracker->income[i].description, tracker->income[i].amount);
        totalIncome += tracker->income[i].amount;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->expenseCount; i++) {
        printf(" - %s: $%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
        totalExpenses += tracker->expenses[i].amount;
    }

    printf("\nTotal Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Savings: $%.2f\n", totalIncome - totalExpenses);
}

void projectFutureSavings(const FinanceTracker *tracker, int years) {
    float totalIncome = 0.0;
    float totalExpenses = 0.0;
    
    for (int i = 0; i < tracker->incomeCount; i++) {
        totalIncome += tracker->income[i].amount;
    }

    for (int i = 0; i < tracker->expenseCount; i++) {
        totalExpenses += tracker->expenses[i].amount;
    }

    float annualSavings = totalIncome - totalExpenses;
    float futureSavings = annualSavings * years;

    printf("\nProjected future savings in %d years: $%.2f\n", years, futureSavings);
}

int main() {
    FinanceTracker tracker;
    int choice, years;

    initFinanceTracker(&tracker);

    while (1) {
        printf("\n--- Futuristic Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Finances\n");
        printf("4. Project Future Savings\n");
        printf("5. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&tracker);
                break;
            case 2:
                addExpense(&tracker);
                break;
            case 3:
                displayFinances(&tracker);
                break;
            case 4:
                printf("Enter number of years to project: ");
                scanf("%d", &years);
                projectFutureSavings(&tracker, years);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice, please select again.\n");
        }
    }

    return 0;
}