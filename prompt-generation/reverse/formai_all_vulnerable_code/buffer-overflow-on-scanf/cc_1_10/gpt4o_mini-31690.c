//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: unmistakable
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
} FinanceTracker;

void initializeTracker(FinanceTracker *tracker) {
    tracker->count = 0;
}

void addTransaction(FinanceTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_TRANSACTIONS) {
        strncpy(tracker->transactions[tracker->count].description, description, MAX_DESC_LENGTH);
        tracker->transactions[tracker->count].amount = amount;
        tracker->count++;
    } else {
        printf("Transaction limit reached! Cannot add more transactions.\n");
    }
}

void viewTransactions(const FinanceTracker *tracker) {
    printf("\n--- Your Transactions ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker->transactions[i].description, tracker->transactions[i].amount);
    }
    printf("------------------------\n");
}

float calculateTotalIncome(const FinanceTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].amount >= 0) {
            total += tracker->transactions[i].amount;
        }
    }
    return total;
}

float calculateTotalExpenses(const FinanceTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].amount < 0) {
            total += -tracker->transactions[i].amount;
        }
    }
    return total;
}

void saveTransactionsToFile(const FinanceTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s: %.2f\n", tracker->transactions[i].description, tracker->transactions[i].amount);
    }
    fclose(file);
    printf("Transactions saved to %s.\n", filename);
}

void loadTransactionsFromFile(FinanceTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file for reading.\n");
        return;
    }
    char description[MAX_DESC_LENGTH];
    float amount;
    while (fscanf(file, "%49[^:]: %f\n", description, &amount) != EOF) {
        addTransaction(tracker, description, amount);
    }
    fclose(file);
    printf("Transactions loaded from %s.\n", filename);
}

int main() {
    FinanceTracker tracker;
    initializeTracker(&tracker);
    int choice;
    char description[MAX_DESC_LENGTH];
    float amount;

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Transactions\n");
        printf("4. Calculate Total Income\n");
        printf("5. Calculate Total Expenses\n");
        printf("6. Save Transactions to File\n");
        printf("7. Load Transactions from File\n");
        printf("8. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf(" %[^\n]s", description);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addTransaction(&tracker, description, amount);
                break;

            case 2:
                printf("Enter expense description: ");
                scanf(" %[^\n]s", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addTransaction(&tracker, description, -amount);
                break;

            case 3:
                viewTransactions(&tracker);
                break;

            case 4:
                printf("Total Income: $%.2f\n", calculateTotalIncome(&tracker));
                break;

            case 5:
                printf("Total Expenses: $%.2f\n", calculateTotalExpenses(&tracker));
                break;

            case 6:
                saveTransactionsToFile(&tracker, "transactions.txt");
                break;

            case 7:
                loadTransactionsFromFile(&tracker, "transactions.txt");
                break;

            case 8:
                printf("Exiting. Have a great day!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 8);

    return 0;
}