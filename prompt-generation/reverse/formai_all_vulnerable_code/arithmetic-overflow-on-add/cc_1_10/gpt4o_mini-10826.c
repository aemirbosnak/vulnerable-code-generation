//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 1000
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinanceTracker;

// Function to initialize the finance tracker
void initTracker(FinanceTracker* tracker) {
    tracker->count = 0;
}

// Function to add a new transaction
void addTransaction(FinanceTracker* tracker) {
    if (tracker->count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached!\n");
        return;
    }

    printf("Enter transaction description: ");
    scanf(" %[^\n]", tracker->transactions[tracker->count].description);
    printf("Enter transaction amount: ");
    scanf("%f", &tracker->transactions[tracker->count].amount);

    tracker->count++;
    printf("Transaction added successfully!\n");
}

// Function to display all transactions
void displayTransactions(const FinanceTracker* tracker) {
    if (tracker->count == 0) {
        printf("No transactions found.\n");
        return;
    }

    printf("\n--- Transaction History ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, tracker->transactions[i].description, tracker->transactions[i].amount);
    }
}

// Function to calculate the total balance
float calculateBalance(const FinanceTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->transactions[i].amount;
    }
    return total;
}

// Function to display the menu and get user's choice
int displayMenu() {
    int choice;
    printf("\n--- Personal Finance Planner ---\n");
    printf("1. Add Transaction\n");
    printf("2. Display Transactions\n");
    printf("3. Calculate Balance\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    FinanceTracker tracker;
    initTracker(&tracker);

    int choice;
    
    while (1) {
        choice = displayMenu();

        switch (choice) {
            case 1:
                addTransaction(&tracker);
                break;
            case 2:
                displayTransactions(&tracker);
                break;
            case 3:
                printf("Total Balance: $%.2f\n", calculateBalance(&tracker));
                break;
            case 4:
                printf("Exiting the planner. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}