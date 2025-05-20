//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("🚨 Expense Tracker Initialized! Ready to blow your mind! 🚨\n");
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("⚠️ Oh no! You cannot add more expenses - limit reached! ⚠️\n");
        return;
    }
    
    Expense new_expense;
    printf("😱 Enter the description of the expense: ");
    scanf(" %[^\n]", new_expense.description);
    printf("😱 Enter the amount of the expense: ");
    scanf("%f", &new_expense.amount);
    
    tracker->expenses[tracker->count] = new_expense;
    tracker->count++;
    
    printf("✨ Expense Added: %s - $%.2f ✨\n", new_expense.description, new_expense.amount);
}

void displayExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("😱 No expenses recorded! How can this be? 😱\n");
        return;
    }
    
    printf("😱 Here are your recorded expenses: 😱\n");
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
        total += tracker->expenses[i].amount;
    }
    printf("💰 Total Expenses: $%.2f 💰\n", total);
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("🧹 All expenses cleared! Can you believe it?! 🧹\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    
    int choice;
    while (1) {
        printf("\n😲 Expense Tracker Menu: 😲\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Clear All Expenses\n");
        printf("4. Exit\n");
        printf("Choose an option (1-4): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                clearExpenses(&tracker);
                break;
            case 4:
                printf("🚪 Exiting! Don’t forget your expenses! 🚪\n");
                exit(0);
            default:
                printf("😨 Invalid choice! You caught me off guard! 😨\n");
        }
    }
    
    return 0;
}