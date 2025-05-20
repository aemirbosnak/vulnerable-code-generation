//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
void totalExpenses(const ExpenseTracker *tracker);
void clearExpenses(ExpenseTracker *tracker);
void displayMenu();
void pause();

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;

    int choice;

    do {
        displayMenu();
        printf("Choose an option: ");
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
                clearExpenses(&tracker);
                break;
            case 5:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
                break;
        }
        
        pause();
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    printf("\n=== Expense Tracker Menu ===\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. View Total Expenses\n");
    printf("4. Clear All Expenses\n");
    printf("5. Exit\n");
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    
    Expense newExpense;
    
    printf("Enter a description for the expense: ");
    scanf(" %[^\n]", newExpense.description);
    printf("Enter the amount for the expense: ");
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
    
    printf("\n### Expenses ###\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d: %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

void totalExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded. Total is $0.00\n");
        return;
    }
    
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    
    printf("Total Expenses: $%.2f\n", total);
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared.\n");
}

void pause() {
    printf("Press Enter to continue...");
    while (getchar() != '\n'); // Clear the input buffer
    getchar(); // Wait for user to press Enter
}