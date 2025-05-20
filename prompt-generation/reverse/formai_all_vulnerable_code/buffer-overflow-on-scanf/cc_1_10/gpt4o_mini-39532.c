//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 30
#define DESCRIPTION_LENGTH 100

typedef struct {
    char description[DESCRIPTION_LENGTH];
    char category[CATEGORY_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Alas! The record is full. Cannot add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    printf("Ah, a new expense. Pray, provide the description: ");
    getchar(); // clear newline from previous input
    fgets(newExpense.description, DESCRIPTION_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    printf("To what category shall I assign this expense?\n");
    fgets(newExpense.category, CATEGORY_LENGTH, stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = 0; // Remove newline

    printf("And how much did this expense amount to, my dear Watson? ");
    scanf("%f", &newExpense.amount);

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;

    printf("Expense recorded with the utmost care!\n");
}

void displayExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("There are no expenses recorded yet, dear Watson.\n");
        return;
    }

    printf("\nHere lie the expenses recorded in our ledger:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Description: %s\n", tracker->expenses[i].description);
        printf("Category: %s\n", tracker->expenses[i].category);
        printf("Amount: $%.2f\n", tracker->expenses[i].amount);
        printf("--------------------\n");
    }
}

void displaySummary(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to summarize, my good friend.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }

    printf("In summary, you have spent a total of $%.2f on %d expense(s).\n", total, tracker->count);
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    int choice;

    do {
        printf("\nWelcome to the Expense Tracker, dear Watson.\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("What would you like to do? ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                displaySummary(&tracker);
                break;
            case 4:
                printf("Leaving the matter of expenses, till next time!\n");
                break;
            default:
                printf("Hmm, that seems rather suspicious. Choose a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}