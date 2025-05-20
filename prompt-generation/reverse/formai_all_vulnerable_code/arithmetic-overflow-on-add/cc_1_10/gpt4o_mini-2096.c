//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction transactions[MAX_ENTRIES];
    int count;
} FinanceTracker;

void addTransaction(FinanceTracker* tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Transaction limit reached!\n");
        return;
    }
    printf("Enter transaction name: ");
    scanf("%s", tracker->transactions[tracker->count].name);
    printf("Enter amount: ");
    scanf("%f", &tracker->transactions[tracker->count].amount);
    tracker->count++;
    printf("Transaction added successfully.\n");
}

void viewTransactions(FinanceTracker* tracker) {
    if (tracker->count == 0) {
        printf("No transactions recorded.\n");
        return;
    }
    printf("\n----- Transaction Summary -----\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Transaction %d: %s | Amount: %.2f\n", i + 1, 
        tracker->transactions[i].name, tracker->transactions[i].amount);
    }
    printf("-------------------------------\n");
}

float calculateTotal(FinanceTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->transactions[i].amount;
    }
    return total;
}

void displayMenu() {
    printf("\n----- Personal Finance Planner -----\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. Calculate Total\n");
    printf("4. Exit\n");
    printf("-------------------------------------\n");
}

int main() {
    FinanceTracker tracker;
    tracker.count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(&tracker);
                break;
            case 2:
                viewTransactions(&tracker);
                break;
            case 3:
                printf("Total Amount: %.2f\n", calculateTotal(&tracker));
                break;
            case 4:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid option, please try again.\n");
        }
    }

    return 0;
}