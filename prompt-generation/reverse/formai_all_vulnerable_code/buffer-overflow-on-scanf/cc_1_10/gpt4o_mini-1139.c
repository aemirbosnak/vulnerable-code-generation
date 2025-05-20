//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    char type; // 'i' for income, 'e' for expense
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinanceTracker;

void addTransaction(FinanceTracker *tracker, const char *description, float amount, char type) {
    if (tracker->count < MAX_TRANSACTIONS) {
        strncpy(tracker->transactions[tracker->count].description, description, MAX_DESC_LENGTH);
        tracker->transactions[tracker->count].amount = amount;
        tracker->transactions[tracker->count].type = type;
        tracker->count++;
        printf("Transaction added successfully!\n");
    } else {
        printf("Transaction limit reached. Cannot add more transactions.\n");
    }
}

void displayTransactions(const FinanceTracker *tracker) {
    if (tracker->count == 0) {
        printf("No transactions recorded.\n");
        return;
    }

    printf("\n--- Transactions List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - %c: $%.2f\n", i + 1, tracker->transactions[i].description,
               tracker->transactions[i].type, tracker->transactions[i].amount);
    }
}

float calculateTotalIncome(const FinanceTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].type == 'i') {
            total += tracker->transactions[i].amount;
        }
    }
    return total;
}

float calculateTotalExpenses(const FinanceTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].type == 'e') {
            total += tracker->transactions[i].amount;
        }
    }
    return total;
}

float calculateNetIncome(const FinanceTracker *tracker) {
    return calculateTotalIncome(tracker) - calculateTotalExpenses(tracker);
}

void displaySummary(const FinanceTracker *tracker) {
    float totalIncome = calculateTotalIncome(tracker);
    float totalExpenses = calculateTotalExpenses(tracker);
    float netIncome = calculateNetIncome(tracker);

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Income: $%.2f\n", netIncome);
}

int main() {
    FinanceTracker tracker;
    tracker.count = 0;

    int choice;
    char description[MAX_DESC_LENGTH];
    float amount;
    char type;

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Transactions\n");
        printf("4. Financial Summary\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf(" %[^\n]", description);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addTransaction(&tracker, description, amount, 'i');
                break;

            case 2:
                printf("Enter expense description: ");
                scanf(" %[^\n]", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addTransaction(&tracker, description, amount, 'e');
                break;

            case 3:
                displayTransactions(&tracker);
                break;

            case 4:
                displaySummary(&tracker);
                break;

            case 5:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}