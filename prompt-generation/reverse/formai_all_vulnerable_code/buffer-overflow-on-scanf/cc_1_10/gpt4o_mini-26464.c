//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100
#define NAME_LEN 50

typedef struct {
    char name[NAME_LEN];
    float amount;
    char type; // 'i' for income, 'e' for expense
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
} FinanceTracker;

void addTransaction(FinanceTracker *tracker) {
    if (tracker->count >= MAX_TRANSACTIONS) {
        printf("Transaction limit reached!\n");
        return;
    }

    Transaction newTransaction;
    printf("Enter transaction name: ");
    scanf("%s", newTransaction.name);
    printf("Enter transaction amount: ");
    scanf("%f", &newTransaction.amount);
    printf("Enter transaction type (i for income, e for expense): ");
    scanf(" %c", &newTransaction.type);

    tracker->transactions[tracker->count] = newTransaction;
    tracker->count++;
    printf("Transaction added successfully!\n");
}

void displayTransactions(const FinanceTracker *tracker) {
    printf("\nTransaction List:\n");
    printf("------------------\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: %.2f (%s)\n", i + 1, tracker->transactions[i].name, 
               tracker->transactions[i].amount, 
               tracker->transactions[i].type == 'i' ? "Income" : "Expense");
    }
}

float calculateBalance(const FinanceTracker *tracker) {
    float balance = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].type == 'i') {
            balance += tracker->transactions[i].amount;
        } else {
            balance -= tracker->transactions[i].amount;
        }
    }
    return balance;
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Transaction\n");
    printf("2. Display Transactions\n");
    printf("3. Show Current Balance\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
}

int main() {
    FinanceTracker tracker;
    tracker.count = 0;

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTransaction(&tracker);
                break;
            case 2:
                displayTransactions(&tracker);
                break;
            case 3:
                printf("Current Balance: %.2f\n", calculateBalance(&tracker));
                break;
            case 4:
                printf("Exiting the program. Thank you for using the finance planner!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}