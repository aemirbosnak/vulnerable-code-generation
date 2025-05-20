//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinanceTracker;

void initTracker(FinanceTracker *tracker) {
    tracker->count = 0;
}

void addTransaction(FinanceTracker *tracker) {
    if (tracker->count < MAX_TRANSACTIONS) {
        Transaction newTransaction;
        printf("Enter description of transaction: ");
        scanf(" %[^\n]s", newTransaction.description);
        printf("Enter amount (use negative for expense): ");
        scanf("%f", &newTransaction.amount);
        tracker->transactions[tracker->count] = newTransaction;
        tracker->count++;
        printf("Transaction added successfully!\n");
    } else {
        printf("Cannot add more transactions, maximum limit reached.\n");
    }
}

void viewTransactions(const FinanceTracker *tracker) {
    printf("\nTransaction History:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: %.2f\n", i + 1, tracker->transactions[i].description, tracker->transactions[i].amount);
    }
}

float calculateTotal(const FinanceTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->transactions[i].amount;
    }
    return total;
}

void budgetSummary(const FinanceTracker *tracker) {
    float totalIncome = 0.0;
    float totalExpenses = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].amount > 0) {
            totalIncome += tracker->transactions[i].amount;
        } else {
            totalExpenses += tracker->transactions[i].amount;
        }
    }

    printf("\nBudget Summary:\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Savings: %.2f\n", totalIncome + totalExpenses);
}

int main() {
    FinanceTracker tracker;
    initTracker(&tracker);
    int choice;

    do {
        printf("\nPersonal Finance Planner Menu:\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Budget Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(&tracker);
                break;
            case 2:
                viewTransactions(&tracker);
                break;
            case 3:
                budgetSummary(&tracker);
                break;
            case 4:
                printf("Exiting program. Stay financially savvy!\n");
                break;
            default:
                printf("Invalid choice! Please choose again.\n");
        }
    } while (choice != 4);

    return 0;
}