//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: excited
#include <stdio.h>
#include <stdlib.h>

#define MAX_TRANSACTIONS 100

typedef struct {
    char description[50];
    float amount;
    char type; // 'I' for income, 'E' for expense
} Transaction;

typedef struct {
    Transaction transactions[MAX_TRANSACTIONS];
    int count;
    float balance;
} FinanceTracker;

// Function prototypes
void initializeTracker(FinanceTracker *tracker);
void addTransaction(FinanceTracker *tracker, char *description, float amount, char type);
void displaySummary(FinanceTracker *tracker);
void displayTransactions(FinanceTracker *tracker);

int main() {
    FinanceTracker tracker;
    initializeTracker(&tracker);

    int choice;
    char description[50];
    float amount;
    char type;

    printf("Welcome to the Exciting Personal Finance Planner!\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. View Summary\n");
        printf("4. View Transactions\n");
        printf("5. Exit\n");
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf(" %[^\n]", description);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                addTransaction(&tracker, description, amount, 'I');
                break;
            case 2:
                printf("Enter expense description: ");
                scanf(" %[^\n]", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                addTransaction(&tracker, description, amount, 'E');
                break;
            case 3:
                displaySummary(&tracker);
                break;
            case 4:
                displayTransactions(&tracker);
                break;
            case 5:
                printf("Thank you for using the Personal Finance Planner! Keep saving!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

void initializeTracker(FinanceTracker *tracker) {
    tracker->count = 0;
    tracker->balance = 0.0;
}

void addTransaction(FinanceTracker *tracker, char *description, float amount, char type) {
    if (tracker->count < MAX_TRANSACTIONS) {
        Transaction newTransaction;
        snprintf(newTransaction.description, sizeof(newTransaction.description), "%s", description);
        newTransaction.amount = amount;
        newTransaction.type = type;
        
        tracker->transactions[tracker->count] = newTransaction;
        
        if (type == 'I') {
            tracker->balance += amount;
            printf("🎉 Income of $%.2f added! 🎉\n", amount);
        } else if (type == 'E') {
            tracker->balance -= amount;
            printf("💸 Expense of $%.2f subtracted! 💸\n", amount);
        }
        
        tracker->count++;
    } else {
        printf("🚫 Can't add more transactions! Limit reached! 🚫\n");
    }
}

void displaySummary(FinanceTracker *tracker) {
    printf("\n--- Financial Summary ---\n");
    printf("Total Transactions: %d\n", tracker->count);
    printf("Current Balance: $%.2f\n", tracker->balance);
    printf("--------------------------\n");
}

void displayTransactions(FinanceTracker *tracker) {
    printf("\n--- Transactions List ---\n");

    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: $%.2f [%c]\n", 
               i + 1, 
               tracker->transactions[i].description, 
               tracker->transactions[i].amount, 
               tracker->transactions[i].type);
    }

    printf("--------------------------\n");
}