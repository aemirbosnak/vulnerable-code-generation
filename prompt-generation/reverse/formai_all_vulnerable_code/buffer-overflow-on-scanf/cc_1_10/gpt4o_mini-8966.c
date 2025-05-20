//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addTransaction(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_TRANSACTIONS) {
        strncpy(tracker->transactions[tracker->count].description, description, MAX_DESC_LENGTH - 1);
        tracker->transactions[tracker->count].description[MAX_DESC_LENGTH - 1] = '\0'; // Null-terminate
        tracker->transactions[tracker->count].amount = amount;
        tracker->count++;
    } else {
        printf("Transaction limit reached! Cannot add more transactions.\n");
    }
}

void displayTransactions(const ExpenseTracker *tracker) {
    printf("\nTransaction History:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Transaction %d: %s - $%.2f\n", i + 1, tracker->transactions[i].description, tracker->transactions[i].amount);
    }
    printf("\n");
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->transactions[i].amount;
    }
    return total;
}

void displayMenu() {
    printf("Expense Tracker Menu:\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    int choice;
    
    do {
        displayMenu();
        printf("Choose an option: ");
        scanf("%d", &choice);
        getchar(); // Clear newline character from buffer

        switch (choice) {
            case 1: {
                char description[MAX_DESC_LENGTH];
                float amount;

                printf("Enter transaction description: ");
                fgets(description, MAX_DESC_LENGTH, stdin);
                description[strcspn(description, "\n")] = '\0'; // Remove newline

                printf("Enter transaction amount: $");
                scanf("%f", &amount);
                addTransaction(&tracker, description, amount);
                break;
            }
            case 2:
                displayTransactions(&tracker);
                break;
            case 3: {
                float total = calculateTotal(&tracker);
                printf("Total Expenses: $%.2f\n\n", total);
                break;
            }
            case 4:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}