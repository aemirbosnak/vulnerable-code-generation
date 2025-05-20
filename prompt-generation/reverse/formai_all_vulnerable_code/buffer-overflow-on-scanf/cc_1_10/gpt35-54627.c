//FormAI DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct Transaction {
    char date[20];
    char description[50];
    float amount;
};

struct ExpenseTracker {
    struct Transaction transactions[MAX_EXPENSES];
    int count;
    float total;
};

void addTransaction(struct ExpenseTracker* tracker, char* date, char* description, float amount) {
    if (tracker->count == MAX_EXPENSES) {
        printf("Cannot add more transactions, maximum limit reached!\n");
        return;
    }

    struct Transaction transaction;
    strcpy(transaction.date, date);
    strcpy(transaction.description, description);
    transaction.amount = amount;

    tracker->transactions[tracker->count++] = transaction;
    tracker->total += amount;
}

void printExpenses(struct ExpenseTracker tracker) {
    printf("Date\t\t\tDescription\t\tAmount\n");
    printf("--------------------------------------------------------\n");
    
    for (int i = 0; i < tracker.count; i++) {
        printf("%s\t%s\t\t%.2f\n", tracker.transactions[i].date, tracker.transactions[i].description, tracker.transactions[i].amount);
    }
    
    printf("--------------------------------------------------------\n");
    printf("Total:\t\t\t\t\t%.2f\n\n", tracker.total);
}

int main() {
    struct ExpenseTracker tracker;
    tracker.count = 0;
    tracker.total = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("Enter 1 to add a transaction, 2 to display expenses, or 3 to exit: ");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char date[20], description[50];
                float amount;

                printf("Enter date (DD-MM-YYYY): ");
                scanf("%s", date);

                printf("Enter description: ");
                scanf("%s", description);

                printf("Enter amount: ");
                scanf("%f", &amount);

                addTransaction(&tracker, date, description, amount);

                printf("Transaction added successfully!\n");
                break;
            }
            case 2: {
                printExpenses(tracker);
                break;
            }
            case 3: {
                printf("Thank you for using the Expense Tracker. Goodbye!\n");
                exit(0);
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    }

    return 0;
}