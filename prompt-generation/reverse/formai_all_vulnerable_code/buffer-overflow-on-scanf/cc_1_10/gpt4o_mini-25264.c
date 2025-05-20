//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_RECORDS];
    int count;
} FinanceTracker;

void initializeTracker(FinanceTracker* tracker) {
    tracker->count = 0;
}

void addTransaction(FinanceTracker* tracker, const char* description, float amount) {
    if (tracker->count < MAX_RECORDS) {
        strcpy(tracker->transactions[tracker->count].description, description);
        tracker->transactions[tracker->count].amount = amount;
        tracker->count++;
        printf("Added transaction: %s of $%.2f\n", description, amount);
    } else {
        printf("Error: Cannot add more transactions. Maximum limit reached.\n");
    }
}

void displayTransactions(const FinanceTracker* tracker) {
    printf("\n--- Transaction History ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, tracker->transactions[i].description, tracker->transactions[i].amount);
    }
}

float calculateTotalIncome(const FinanceTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].amount > 0) {
            total += tracker->transactions[i].amount;
        }
    }
    return total;
}

float calculateTotalExpenses(const FinanceTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].amount < 0) {
            total += tracker->transactions[i].amount;
        }
    }
    return total;
}

void displaySummary(const FinanceTracker* tracker) {
    float totalIncome = calculateTotalIncome(tracker);
    float totalExpenses = calculateTotalExpenses(tracker);
    float netIncome = totalIncome + totalExpenses;  // Since expenses are negative

    printf("\n--- Financial Summary ---\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpenses);
    printf("Net Income: $%.2f\n", netIncome);
}

int main() {
    FinanceTracker myFinance;
    initializeTracker(&myFinance);

    int choice;
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;

    printf("Welcome to the Peaceful Personal Finance Planner\n");
    printf("Where every cent matters in your journey to financial freedom.\n");

    do {
        printf("\nPlease select an option:\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. View Summary\n");
        printf("4. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter description: ");
                scanf(" %[^\n]", description);  // Read string with spaces
                printf("Enter amount (positive for income, negative for expense): ");
                scanf("%f", &amount);
                addTransaction(&myFinance, description, amount);
                break;
            case 2:
                displayTransactions(&myFinance);
                break;
            case 3:
                displaySummary(&myFinance);
                break;
            case 4:
                printf("Thank you for using the Personal Finance Planner. Have a peaceful day!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}