//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRANSACTIONS 100
#define MAX_CATEGORY_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef enum {
    INCOME,
    EXPENSE
} TransactionType;

typedef struct {
    char date[11]; // Format: YYYY-MM-DD
    TransactionType type;
    char category[MAX_CATEGORY_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
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

    Transaction t;
    printf("\nEnter date (YYYY-MM-DD): ");
    scanf("%10s", t.date);
    printf("Enter transaction type (1 for Income, 2 for Expense): ");
    int typeInput;
    scanf("%d", &typeInput);
    t.type = (typeInput == 1) ? INCOME : EXPENSE;

    printf("Enter category: ");
    scanf("%s", t.category);
    printf("Enter description: ");
    scanf(" %[^\n]", t.description);
    printf("Enter amount: ");
    scanf("%f", &t.amount);

    tracker->transactions[tracker->count] = t;
    tracker->count++;
    printf("Transaction added successfully!\n");
}

void viewTransactions(FinanceTracker *tracker) {
    if (tracker->count == 0) {
        printf("No transactions recorded.\n");
        return;
    }

    printf("\nTransactions:\n");
    printf("-------------------------------------------------------------------\n");
    printf("| Date       | Type     | Category    | Description           | Amount   |\n");
    printf("-------------------------------------------------------------------\n");
    
    for (int i = 0; i < tracker->count; i++) {
        Transaction t = tracker->transactions[i];
        printf("| %-10s | %-8s | %-10s | %-20s | $%.2f |\n",
               t.date,
               (t.type == INCOME) ? "Income" : "Expense",
               t.category,
               t.description,
               t.amount);
    }

    printf("-------------------------------------------------------------------\n");
}

float calculateTotal(FinanceTracker *tracker, TransactionType type) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        if (tracker->transactions[i].type == type) {
            total += tracker->transactions[i].amount;
        }
    }
    return total;
}

void viewSummary(FinanceTracker *tracker) {
    float totalIncome = calculateTotal(tracker, INCOME);
    float totalExpense = calculateTotal(tracker, EXPENSE);
    float balance = totalIncome - totalExpense;

    printf("\nFinancial Summary:\n");
    printf("----------------------------------------------------------\n");
    printf("Total Income:  $%.2f\n", totalIncome);
    printf("Total Expense: $%.2f\n", totalExpense);
    printf("Balance:      $%.2f\n", balance);
    printf("----------------------------------------------------------\n");
}

void displayMenu() {
    printf("\nPersonal Finance Planner\n");
    printf("1. Add Transaction\n");
    printf("2. View Transactions\n");
    printf("3. View Summary\n");
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
                viewTransactions(&tracker);
                break;
            case 3:
                viewSummary(&tracker);
                break;
            case 4:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}