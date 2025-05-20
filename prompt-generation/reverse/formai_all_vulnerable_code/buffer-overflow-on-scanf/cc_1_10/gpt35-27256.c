//FormAI DATASET v1.0 Category: Expense Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRY 100 // Maximum number of entries that can be stored
#define MAX_DESC_LENGTH 50 // Maximum length of description for each entry

struct Expense {
    float amount;
    char description[MAX_DESC_LENGTH];
};

struct ExpenseTracker {
    struct Expense entries[MAX_ENTRY];
    int num_entries;
    float total_expenses;
};

void addExpense(struct ExpenseTracker *tracker, float amount, char *description) {
    if (tracker->num_entries < MAX_ENTRY) {
        struct Expense new_expense;
        new_expense.amount = amount;
        strncpy(new_expense.description, description, MAX_DESC_LENGTH);
        tracker->entries[tracker->num_entries++] = new_expense;
        tracker->total_expenses += amount;
        printf("Expense of $%.2f for %s added successfully!\n", amount, description);
    } else {
        printf("Cannot add any more expenses. Maximum limit reached.\n");
    }
}

void viewExpenses(struct ExpenseTracker *tracker) {
    printf("------------------------\n");
    printf("|   Expense  |  Amount  |\n");
    printf("------------------------\n");
    for (int i = 0; i < tracker->num_entries; i++) {
        printf("| %10s | $%7.2f |\n", tracker->entries[i].description, tracker->entries[i].amount);
    }
    printf("------------------------\n");
    printf("Total Expenses: $%.2f\n", tracker->total_expenses);
}

int main() {
    struct ExpenseTracker tracker = { .num_entries = 0, .total_expenses = 0 };
    int menu_choice;

    printf("WELCOME TO EXPENSE TRACKER\n\n");

    do {
        printf("\n\nMENU:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Exit\n");
        printf("\nEnter your choice (1-3): ");

        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1: {
                float amount;
                char description[MAX_DESC_LENGTH];

                printf("\nEnter the expense amount: $");
                scanf("%f", &amount);
                printf("Enter the expense description (Max %d characters): ", MAX_DESC_LENGTH - 1);
                fflush(stdin);
                scanf("%49[^\n]", description);

                addExpense(&tracker, amount, description);

                break;
            }

            case 2: {
                if (tracker.num_entries == 0) {
                    printf("\nNo expenses recorded yet.\n");
                } else {
                    viewExpenses(&tracker);
                }

                break;
            }

            case 3: {
                printf("\nExiting Expense Tracker...\n");
                break;
            }

            default: {
                printf("\nInvalid input. Please select a valid option.\n");
            }
        }
    } while (menu_choice != 3);

    return 0;
}