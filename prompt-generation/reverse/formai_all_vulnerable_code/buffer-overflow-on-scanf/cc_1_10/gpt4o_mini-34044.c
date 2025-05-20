//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define CATEGORY_LENGTH 30
#define DESCRIPTION_LENGTH 50

typedef struct {
    char category[CATEGORY_LENGTH];
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker* tracker);
void displayExpenses(const ExpenseTracker* tracker);
void displayMenu();
void clearInputBuffer();

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Exit\n");
}

void addExpense(ExpenseTracker* tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Can't add more expenses.\n");
        return;
    }

    Expense newExpense;
    
    printf("Enter category: ");
    fgets(newExpense.category, CATEGORY_LENGTH, stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = '\0'; // Remove newline character
    
    printf("Enter description: ");
    fgets(newExpense.description, DESCRIPTION_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = '\0'; // Remove newline character
    
    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    clearInputBuffer();

    tracker->expenses[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void displayExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d:\n", i + 1);
        printf("  Category: %s\n", tracker->expenses[i].category);
        printf("  Description: %s\n", tracker->expenses[i].description);
        printf("  Amount: $%.2f\n", tracker->expenses[i].amount);
    }
}

void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}