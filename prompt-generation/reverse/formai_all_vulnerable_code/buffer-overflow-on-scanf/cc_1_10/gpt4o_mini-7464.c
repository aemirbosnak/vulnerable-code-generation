//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense entries[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void initTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker* tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense tracker is full! Cannot add more entries.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense description: ");
    fgets(newExpense.description, MAX_DESCRIPTION_LENGTH, stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove trailing newline

    printf("Enter expense amount: ");
    while (1) {
        if (scanf("%f", &newExpense.amount) != 1 || newExpense.amount < 0) {
            printf("Invalid amount. Please enter a positive number: ");
            // Clear invalid input
            while (getchar() != '\n');
        } else {
            break;
        }
    }
    while (getchar() != '\n'); // Clear remaining newline from buffer

    tracker->entries[tracker->count++] = newExpense;
    printf("Expense added successfully.\n");
}

void viewExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    
    printf("\n--- Expense Report ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Description: %s, Amount: %.2f\n", tracker->entries[i].description, tracker->entries[i].amount);
    }
    printf("----------------------\n");
}

void totalExpenses(const ExpenseTracker* tracker) {
    float total = 0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void showMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Total Expenses\n");
    printf("4. Exit\n");
    printf("----------------------------\n");
}

int main() {
    ExpenseTracker tracker;
    initTracker(&tracker);
    int choice;

    do {
        showMenu();
        printf("Choose an option: ");
        while (1) {
            if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
                printf("Invalid option. Please choose again: ");
                // Clear invalid input
                while (getchar() != '\n');
            } else {
                break;
            }
        }
        while (getchar() != '\n'); // Clear the newline character from the buffer

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
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Unexpected option! Please try again.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}