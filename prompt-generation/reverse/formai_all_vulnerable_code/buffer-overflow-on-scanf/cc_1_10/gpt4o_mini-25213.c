//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} Transaction;

typedef struct {
    Transaction incomes[MAX_TRANSACTIONS];
    Transaction expenses[MAX_TRANSACTIONS];
    int incomeCount;
    int expenseCount;
    float totalIncome;
    float totalExpense;
} FinanceTracker;

void initializeTracker(FinanceTracker* tracker) {
    tracker->incomeCount = 0;
    tracker->expenseCount = 0;
    tracker->totalIncome = 0;
    tracker->totalExpense = 0;
}

void addIncome(FinanceTracker* tracker) {
    if (tracker->incomeCount >= MAX_TRANSACTIONS) {
        printf("Income limit reached. Cannot add more incomes.\n");
        return;
    }
    
    Transaction t;
    printf("Enter income name: ");
    scanf("%s", t.name);
    printf("Enter income amount: ");
    scanf("%f", &t.amount);

    tracker->incomes[tracker->incomeCount++] = t;
    tracker->totalIncome += t.amount;
    printf("Income added successfully!\n");
}

void addExpense(FinanceTracker* tracker) {
    if (tracker->expenseCount >= MAX_TRANSACTIONS) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Transaction t;
    printf("Enter expense name: ");
    scanf("%s", t.name);
    printf("Enter expense amount: ");
    scanf("%f", &t.amount);

    tracker->expenses[tracker->expenseCount++] = t;
    tracker->totalExpense += t.amount;
    printf("Expense added successfully!\n");
}

void displaySummary(FinanceTracker* tracker) {
    printf("\n=== Finance Summary ===\n");
    printf("Total Income: $%.2f\n", tracker->totalIncome);
    printf("Total Expenses: $%.2f\n", tracker->totalExpense);
    printf("Net Savings: $%.2f\n", tracker->totalIncome - tracker->totalExpense);

    printf("\nIncomes:\n");
    for (int i = 0; i < tracker->incomeCount; i++) {
        printf("%s: $%.2f\n", tracker->incomes[i].name, tracker->incomes[i].amount);
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->expenseCount; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].name, tracker->expenses[i].amount);
    }
}

int main() {
    FinanceTracker tracker;
    initializeTracker(&tracker);

    int choice;
    do {
        printf("\nPersonal Finance Planner\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addIncome(&tracker);
                break;
            case 2:
                addExpense(&tracker);
                break;
            case 3:
                displaySummary(&tracker);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}