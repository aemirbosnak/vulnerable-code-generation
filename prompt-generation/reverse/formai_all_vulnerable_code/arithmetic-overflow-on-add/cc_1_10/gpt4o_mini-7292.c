//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION_LEN 50

typedef struct {
    char description[MAX_DESCRIPTION_LEN];
    float amount;
} Transaction;

typedef struct {
    Transaction income[MAX_ENTRIES];
    Transaction expenses[MAX_ENTRIES];
    int income_count;
    int expenses_count;
} FinanceTracker;

void initializeTracker(FinanceTracker *tracker) {
    tracker->income_count = 0;
    tracker->expenses_count = 0;
}

void addIncome(FinanceTracker *tracker) {
    if (tracker->income_count < MAX_ENTRIES) {
        printf("Enter income description: ");
        scanf(" %[^\n]s", tracker->income[tracker->income_count].description);
        printf("Enter income amount: ");
        scanf("%f", &tracker->income[tracker->income_count].amount);
        tracker->income_count++;
        printf("Income added successfully!\n");
    } else {
        printf("Income entries limit reached!\n");
    }
}

void addExpense(FinanceTracker *tracker) {
    if (tracker->expenses_count < MAX_ENTRIES) {
        printf("Enter expense description: ");
        scanf(" %[^\n]s", tracker->expenses[tracker->expenses_count].description);
        printf("Enter expense amount: ");
        scanf("%f", &tracker->expenses[tracker->expenses_count].amount);
        tracker->expenses_count++;
        printf("Expense added successfully!\n");
    } else {
        printf("Expense entries limit reached!\n");
    }
}

float totalIncome(FinanceTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->income_count; i++) {
        total += tracker->income[i].amount;
    }
    return total;
}

float totalExpenses(FinanceTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->expenses_count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void displaySummary(FinanceTracker *tracker) {
    float income = totalIncome(tracker);
    float expenses = totalExpenses(tracker);
    float savings = income - expenses;

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", income);
    printf("Total Expenses: $%.2f\n", expenses);
    printf("Net Balance (Income - Expenses): $%.2f\n", savings);
    printf("--------------------------\n");
}

void listTransactions(FinanceTracker *tracker) {
    printf("\n--- Income Transactions ---\n");
    for (int i = 0; i < tracker->income_count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker->income[i].description, tracker->income[i].amount);
    }

    printf("\n--- Expense Transactions ---\n");
    for (int i = 0; i < tracker->expenses_count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

int main() {
    FinanceTracker tracker;
    initializeTracker(&tracker);
    int choice;

    while (1) {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Summary\n");
        printf("4. List Transactions\n");
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
                displaySummary(&tracker);
                break;
            case 4:
                listTransactions(&tracker);
                break;
            case 5:
                printf("Exiting program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}