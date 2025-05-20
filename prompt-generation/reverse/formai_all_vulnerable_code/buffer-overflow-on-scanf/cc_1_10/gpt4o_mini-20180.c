//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} ExpenseEntry;

typedef struct {
    ExpenseEntry entries[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }
    
    ExpenseEntry newEntry;
    
    printf("Enter expense description: ");
    getchar();  // Clear the newline left by previous input
    fgets(newEntry.description, MAX_DESC_LENGTH, stdin);
    newEntry.description[strcspn(newEntry.description, "\n")] = 0; // Remove newline character

    printf("Enter expense amount: ");
    while (scanf("%f", &newEntry.amount) != 1 || newEntry.amount < 0) {
        printf("Invalid amount. Please enter a valid non-negative number: ");
        while (getchar() != '\n'); // Clear the invalid input
    }
    
    tracker->entries[tracker->count++] = newEntry;
    printf("Expense added successfully!\n");
}

void displayExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker->entries[i].description, tracker->entries[i].amount);
    }
    printf("--------------------\n");
}

void calculateTotalExpenses(const ExpenseTracker *tracker) {
    float total = 0.0f;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    printf("Total expenses: $%.2f\n", total);
}

void displayMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. Display Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Exit\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    int choice;

    do {
        displayMenu();
        printf("Choose an option (1-4): ");
        while (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
            printf("Invalid choice. Please enter a number between 1 and 4: ");
            while (getchar() != '\n'); // Clear invalid input
        }

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                calculateTotalExpenses(&tracker);
                break;
            case 4:
                printf("Exiting Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option selected. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}