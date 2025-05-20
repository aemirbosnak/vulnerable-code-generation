//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define DESCRIPTION_LEN 50

typedef struct {
    char description[DESCRIPTION_LEN];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_ENTRIES) {
        strncpy(tracker->expenses[tracker->count].description, description, DESCRIPTION_LEN - 1);
        tracker->expenses[tracker->count].description[DESCRIPTION_LEN - 1] = '\0'; // Ensures null termination
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
        printf("Added expense: %s - $%.2f\n", description, amount);
    } else {
        printf("Expense tracker is full!\n");
    }
}

void printExpenses(const ExpenseTracker *tracker) {
    printf("\n--- Expense Report ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    printf("----------------------\n");
}

float calculateTotal(const ExpenseTracker *tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    return total;
}

void resetTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
    printf("Expense tracker has been reset.\n");
}

void menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. Print Expenses\n");
    printf("3. Calculate Total\n");
    printf("4. Reset Tracker\n");
    printf("5. Exit\n");
    printf("---------------------------\n");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    int choice;
    char description[DESCRIPTION_LEN];
    float amount;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter description: ");
                getchar();  // Consume newline from previous input
                fgets(description, DESCRIPTION_LEN, stdin);
                description[strcspn(description, "\n")] = '\0';  // Remove newline character
                printf("Enter amount: ");
                scanf("%f", &amount);
                addExpense(&tracker, description, amount);
                break;

            case 2:
                printExpenses(&tracker);
                break;

            case 3:
                {
                    float total = calculateTotal(&tracker);
                    printf("Total expenses: $%.2f\n", total);
                }
                break;

            case 4:
                resetTracker(&tracker);
                break;

            case 5:
                printf("Exiting the program...\n");
                exit(0);
                break;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }

    return 0;
}