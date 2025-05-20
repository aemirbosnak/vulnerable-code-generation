//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION 100

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Entry;

typedef struct {
    Entry income[MAX_ENTRIES];
    Entry expenses[MAX_ENTRIES];
    int income_count;
    int expenses_count;
} FinanceTracker;

void add_income(FinanceTracker* tracker, const char* description, float amount) {
    if (tracker->income_count < MAX_ENTRIES) {
        strcpy(tracker->income[tracker->income_count].description, description);
        tracker->income[tracker->income_count].amount = amount;
        tracker->income_count++;
        printf("Income added successfully.\n");
    } else {
        printf("Income entries limit reached!\n");
    }
}

void add_expense(FinanceTracker* tracker, const char* description, float amount) {
    if (tracker->expenses_count < MAX_ENTRIES) {
        strcpy(tracker->expenses[tracker->expenses_count].description, description);
        tracker->expenses[tracker->expenses_count].amount = amount;
        tracker->expenses_count++;
        printf("Expense added successfully.\n");
    } else {
        printf("Expense entries limit reached!\n");
    }
}

void display_summary(FinanceTracker* tracker) {
    float total_income = 0.0f;
    float total_expenses = 0.0f;

    printf("\n--- Personal Finance Summary ---\n");
    
    printf("\nIncome:\n");
    for (int i = 0; i < tracker->income_count; i++) {
        printf("%s: $%.2f\n", tracker->income[i].description, tracker->income[i].amount);
        total_income += tracker->income[i].amount;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < tracker->expenses_count; i++) {
        printf("%s: $%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
        total_expenses += tracker->expenses[i].amount;
    }

    printf("\nTotal Income: $%.2f\n", total_income);
    printf("Total Expenses: $%.2f\n", total_expenses);
    printf("Net Savings: $%.2f\n", total_income - total_expenses);
}

int main() {
    FinanceTracker tracker = { .income_count = 0, .expenses_count = 0 };
    int choice;
    char description[MAX_DESCRIPTION];
    float amount;

    do {
        printf("\n--- Personal Finance Planner ---\n");
        printf("1. Add Income\n");
        printf("2. Add Expense\n");
        printf("3. Display Summary\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter income description: ");
                scanf(" %[^\n]", description);
                printf("Enter income amount: ");
                scanf("%f", &amount);
                add_income(&tracker, description, amount);
                break;
            case 2:
                printf("Enter expense description: ");
                scanf(" %[^\n]", description);
                printf("Enter expense amount: ");
                scanf("%f", &amount);
                add_expense(&tracker, description, amount);
                break;
            case 3:
                display_summary(&tracker);
                break;
            case 4:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}