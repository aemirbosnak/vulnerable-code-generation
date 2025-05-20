//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EVENTS 100
#define MAX_DESC_LENGTH 100

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    char type; // 'e' for expense, 'i' for income
} Transaction;

typedef struct {
    Transaction transactions[MAX_EVENTS];
    int count;
} FinanceTracker;

void initializeTracker(FinanceTracker *tracker) {
    tracker->count = 0;
}

void addTransaction(FinanceTracker *tracker, const char *description, float amount, char type) {
    if (tracker->count < MAX_EVENTS) {
        strncpy(tracker->transactions[tracker->count].description, description, MAX_DESC_LENGTH);
        tracker->transactions[tracker->count].amount = amount;
        tracker->transactions[tracker->count].type = type;
        tracker->count++;
    } else {
        printf("Maximum transaction limit reached!\n");
    }
}

void displayTransactions(const FinanceTracker *tracker) {
    printf("\nTransactions:\n");
    printf("%-25s %-10s %-10s\n", "Description", "Amount", "Type");
    for (int i = 0; i < tracker->count; i++) {
        printf("%-25s %-10.2f %-10c\n", tracker->transactions[i].description,
               tracker->transactions[i].amount, tracker->transactions[i].type);
    }
}

float calculateTotal(const FinanceTracker *tracker, char type) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].type == type) {
            total += tracker->transactions[i].amount;
        }
    }
    return total;
}

void displaySummary(const FinanceTracker *tracker) {
    float totalIncome = calculateTotal(tracker, 'i');
    float totalExpense = calculateTotal(tracker, 'e');
    float balance = totalIncome - totalExpense;

    printf("\nFinancial Summary:\n");
    printf("Total Income: $%.2f\n", totalIncome);
    printf("Total Expenses: $%.2f\n", totalExpense);
    printf("Balance: $%.2f\n", balance);
}

int main() {
    FinanceTracker myTracker;
    initializeTracker(&myTracker);
    
    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Transactions\n");
        printf("4. Display Summary\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            char description[MAX_DESC_LENGTH];
            float amount;
            printf("Enter income description: ");
            getchar(); // to consume newline left by scanf
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0; // Remove newline character
            printf("Enter income amount: ");
            scanf("%f", &amount);
            addTransaction(&myTracker, description, amount, 'i');
            printf("Income added successfully!\n");
        } else if (choice == 2) {
            char description[MAX_DESC_LENGTH];
            float amount;
            printf("Enter expense description: ");
            getchar(); // to consume newline left by scanf
            fgets(description, sizeof(description), stdin);
            description[strcspn(description, "\n")] = 0; // Remove newline character
            printf("Enter expense amount: ");
            scanf("%f", &amount);
            addTransaction(&myTracker, description, amount, 'e');
            printf("Expense added successfully!\n");
        } else if (choice == 3) {
            displayTransactions(&myTracker);
        } else if (choice == 4) {
            displaySummary(&myTracker);
        } else if (choice != 5) {
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);
    
    printf("Exiting the program. Thank you for using the Personal Finance Planner!\n");
    return 0;
}