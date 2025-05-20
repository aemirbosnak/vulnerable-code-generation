//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
    char category[20];
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker);
void viewExpenses(const ExpenseTracker *tracker);
void analyzeExpenses(const ExpenseTracker *tracker);
void clearExpenses(ExpenseTracker *tracker);
void displayMenu();

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    int choice;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                analyzeExpenses(&tracker);
                break;
            case 4:
                clearExpenses(&tracker);
                break;
            case 5:
                printf("Exiting the Expense Tracker. Have a productive day!\n");
                return 0;
            default:
                printf("Invalid choice! Please select from the menu.\n");
        }
    }
}

void displayMenu() {
    printf("\n--- Expense Tracker ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Analyze Expenses\n");
    printf("4. Clear All Expenses\n");
    printf("5. Exit\n");
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense tracker is full! Can't add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter description (max %d characters): ", MAX_DESC_LENGTH - 1);
    getchar(); // to consume the leftover newline
    fgets(newExpense.description, MAX_DESC_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // remove newline

    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    
    printf("Enter category: ");
    getchar(); // to consume the leftover newline
    fgets(newExpense.category, sizeof(newExpense.category), stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = 0; // remove newline

    tracker->expenses[tracker->count++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n--- List of Expenses ---\n");
    for (int i = 0; i < tracker->count; ++i) {
        printf("Description: %s | Amount: %.2f | Category: %s\n", 
               tracker->expenses[i].description, 
               tracker->expenses[i].amount, 
               tracker->expenses[i].category);
    }
}

void analyzeExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses to analyze.\n");
        return;
    }

    float total = 0;
    int categoryCount = 0;
    char categories[10][20] = {0};
    float categoryTotals[10] = {0};

    for (int i = 0; i < tracker->count; ++i) {
        total += tracker->expenses[i].amount;

        int found = 0;
        for (int j = 0; j < categoryCount; ++j) {
            if (strcmp(categories[j], tracker->expenses[i].category) == 0) {
                categoryTotals[j] += tracker->expenses[i].amount;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(categories[categoryCount], tracker->expenses[i].category);
            categoryTotals[categoryCount] += tracker->expenses[i].amount;
            categoryCount++;
        }
    }

    printf("\n--- Expense Analysis ---\n");
    printf("Total Expenses: %.2f\n", total);
    for (int i = 0; i < categoryCount; ++i) {
        printf("Category: %s | Total: %.2f\n", categories[i], categoryTotals[i]);
    }
}

void clearExpenses(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("All expenses cleared successfully!\n");
}