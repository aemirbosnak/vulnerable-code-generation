//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LENGTH 50

typedef struct {
    char category[MAX_LENGTH];
    float amount;
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} FinanceTracker;

void add_entry(FinanceTracker *tracker, const char *category, float amount) {
    if (tracker->count < MAX_ENTRIES) {
        strcpy(tracker->entries[tracker->count].category, category);
        tracker->entries[tracker->count].amount = amount;
        tracker->count++;
        printf("Entry added: %s - %.2f\n", category, amount);
    } else {
        printf("Error: Maximum entries reached.\n");
    }
}

void view_summary(FinanceTracker *tracker) {
    float totalIncome = 0.0;
    float totalExpenses = 0.0;

    printf("\nFinancial Summary:\n");
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->entries[i].amount > 0) {
            totalIncome += tracker->entries[i].amount;
            printf("Income - %s: %.2f\n", tracker->entries[i].category, tracker->entries[i].amount);
        } else {
            totalExpenses += -tracker->entries[i].amount;
            printf("Expense - %s: %.2f\n", tracker->entries[i].category, -tracker->entries[i].amount);
        }
    }
    
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Savings: %.2f\n", totalIncome - totalExpenses);
}

void clear_entries(FinanceTracker *tracker) {
    tracker->count = 0;
    printf("All entries cleared.\n");
}

int main() {
    FinanceTracker tracker = { .count = 0 };
    int choice;
    char category[MAX_LENGTH];
    float amount;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. Clear Entries\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income category: ");
                scanf("%s", category);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                add_entry(&tracker, category, amount);
                break;
            case 2:
                printf("Enter expense category: ");
                scanf("%s", category);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_entry(&tracker, category, -amount);
                break;
            case 3:
                view_summary(&tracker);
                break;
            case 4:
                clear_entries(&tracker);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}