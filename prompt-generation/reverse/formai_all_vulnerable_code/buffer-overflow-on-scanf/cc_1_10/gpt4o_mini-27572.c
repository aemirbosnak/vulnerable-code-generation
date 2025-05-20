//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100

typedef struct {
    char description[50];
    float amount;
    char type; // 'I' for income, 'E' for expense
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
} FinanceTracker;

void initializeTracker(FinanceTracker *tracker) {
    tracker->count = 0;
}

void addEntry(FinanceTracker *tracker, const char *description, float amount, char type) {
    if (tracker->count < MAX_ENTRIES) {
        Entry *newEntry = &tracker->entries[tracker->count++];
        snprintf(newEntry->description, sizeof(newEntry->description), "%s", description);
        newEntry->amount = amount;
        newEntry->type = type;
    } else {
        printf("Cannot add more entries, limit reached.\n");
    }
}

void displayEntries(const FinanceTracker *tracker) {
    printf("Your Financial Entries:\n");
    for (int i = 0; i < tracker->count; i++) {
        Entry entry = tracker->entries[i];
        printf("%d: %s - %.2f (%c)\n", i + 1, entry.description, entry.amount, entry.type);
    }
}

float calculateTotalIncome(const FinanceTracker *tracker) {
    float totalIncome = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->entries[i].type == 'I') {
            totalIncome += tracker->entries[i].amount;
        }
    }
    return totalIncome;
}

float calculateTotalExpenses(const FinanceTracker *tracker) {
    float totalExpenses = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->entries[i].type == 'E') {
            totalExpenses += tracker->entries[i].amount;
        }
    }
    return totalExpenses;
}

float calculateNetWorth(const FinanceTracker *tracker) {
    return calculateTotalIncome(tracker) - calculateTotalExpenses(tracker);
}

void displaySummary(const FinanceTracker *tracker) {
    float totalIncome = calculateTotalIncome(tracker);
    float totalExpenses = calculateTotalExpenses(tracker);
    printf("Financial Summary:\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Worth: %.2f\n", calculateNetWorth(tracker));
}

int main() {
    FinanceTracker tracker;
    initializeTracker(&tracker);

    int choice;
    char description[50];
    float amount;
    char type;

    do {
        printf("Personal Finance Planner Menu:\n");
        printf("1. Add Income Entry\n");
        printf("2. Add Expense Entry\n");
        printf("3. Display All Entries\n");
        printf("4. Display Financial Summary\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // To clear the newline character from input buffer

        switch (choice) {
            case 1:
                printf("Enter income description: ");
                fgets(description, sizeof(description), stdin);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                type = 'I';
                addEntry(&tracker, description, amount, type);
                break;

            case 2:
                printf("Enter expense description: ");
                fgets(description, sizeof(description), stdin);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                type = 'E';
                addEntry(&tracker, description, amount, type);
                break;

            case 3:
                displayEntries(&tracker);
                break;

            case 4:
                displaySummary(&tracker);
                break;

            case 5:
                printf("Exiting the Personal Finance Planner. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");

    } while (choice != 5);

    return 0;
}