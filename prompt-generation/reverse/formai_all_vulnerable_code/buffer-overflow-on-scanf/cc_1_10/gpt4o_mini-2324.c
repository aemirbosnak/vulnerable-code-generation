//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    
    printf("Enter expense description: ");
    getchar(); // to consume newline left by previous input
    fgets(newExpense.description, MAX_DESCRIPTION, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // remove newline
    
    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    
    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\n--- Expense History ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d: %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("-----------------------\n");
}

void totalExpenses(const ExpenseTracker *tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                totalExpenses(&tracker);
                break;
            case 4:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid option, please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}