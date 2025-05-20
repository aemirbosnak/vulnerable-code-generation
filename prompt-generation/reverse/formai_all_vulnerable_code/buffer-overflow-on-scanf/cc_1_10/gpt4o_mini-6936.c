//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_ENTRIES];
    int count;
    float balance;
} FinanceTracker;

void initializeTracker(FinanceTracker *tracker) {
    tracker->count = 0;
    tracker->balance = 0.0;
}

void addTransaction(FinanceTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Transaction limit reached. Cannot add more transactions.\n");
        return;
    }
    
    Transaction newTransaction;
    printf("Enter transaction description: ");
    scanf("%s", newTransaction.description);
    printf("Enter transaction amount (positive for income, negative for expense): ");
    scanf("%f", &newTransaction.amount);
    
    tracker->transactions[tracker->count] = newTransaction;
    tracker->count++;
    tracker->balance += newTransaction.amount;
    printf("Transaction added successfully!\n");
}

void viewTransactions(const FinanceTracker *tracker) {
    printf("\nTransaction History:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - %.2f\n", i + 1, tracker->transactions[i].description, tracker->transactions[i].amount);
    }
    printf("Current Balance: %.2f\n", tracker->balance);
}

void summarizeFinance(const FinanceTracker *tracker) {
    float totalIncome = 0.0;
    float totalExpenses = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].amount > 0) {
            totalIncome += tracker->transactions[i].amount;
        } else {
            totalExpenses += tracker->transactions[i].amount;
        }
    }

    printf("\nFinancial Summary:\n");
    printf("Total Income: %.2f\n", totalIncome);
    printf("Total Expenses: %.2f\n", totalExpenses);
    printf("Net Income: %.2f\n", totalIncome + totalExpenses);
    printf("Current Balance: %.2f\n", tracker->balance);
}

void resetTracker(FinanceTracker *tracker) {
    initializeTracker(tracker);
    printf("Finance Tracker reset successfully.\n");
}

int main() {
    FinanceTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Transaction\n");
        printf("2. View Transactions\n");
        printf("3. Financial Summary\n");
        printf("4. Reset Tracker\n");
        printf("5. Exit\n");
        
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
                summarizeFinance(&tracker);
                break;
            case 4:
                resetTracker(&tracker);
                break;
            case 5:
                printf("Exiting the program. Bye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    return 0;
}