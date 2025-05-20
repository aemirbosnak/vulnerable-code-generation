//GPT-4o-mini DATASET v1.0 Category: Personal Finance Planner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];
} Entry;

typedef struct {
    Entry entries[MAX_ENTRIES];
    int count;
    float total_income;
    float total_expenses;
} FinanceTracker;

void displayMenu() {
    printf("\n=========================\n");
    printf("     Personal Finance     \n");
    printf("=========================\n");
    printf("1. Add Income\n");
    printf("2. Add Expense\n");
    printf("3. View Summary\n");
    printf("4. Exit\n");
    printf("=========================\n");
    printf("Choose an option: ");
}

void addEntry(FinanceTracker *tracker, const char *name, float amount, const char *category, int is_income) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Error: Cannot add more entries!\n");
        return;
    }

    Entry new_entry;
    strncpy(new_entry.name, name, MAX_NAME_LENGTH - 1);
    new_entry.amount = amount;
    strncpy(new_entry.category, category, MAX_NAME_LENGTH - 1);

    tracker->entries[tracker->count] = new_entry;

    if (is_income) {
        tracker->total_income += amount;
    } else {
        tracker->total_expenses += amount;
    }

    tracker->count++;
    printf("Entry added successfully!\n");
}

void viewSummary(FinanceTracker *tracker) {
    printf("\n=========================\n");
    printf("     Financial Summary    \n");
    printf("=========================\n");
    printf("Total Income: $%.2f\n", tracker->total_income);
    printf("Total Expenses: $%.2f\n", tracker->total_expenses);
    printf("Net Balance: $%.2f\n", tracker->total_income - tracker->total_expenses);
    printf("=========================\n");
}

int main() {
    FinanceTracker tracker = {0}; // Initialize tracker
    int option;
    char name[MAX_NAME_LENGTH];
    float amount;
    char category[MAX_NAME_LENGTH];

    do {
        displayMenu();
        scanf("%d", &option);
        switch (option) {
            case 1:
                printf("Enter Income Name: ");
                scanf(" %[^\n]s", name); // Read string with spaces
                printf("Enter Income Amount: ");
                scanf("%f", &amount);
                printf("Enter Income Category: ");
                scanf(" %[^\n]s", category); // Read string with spaces
                addEntry(&tracker, name, amount, category, 1);
                break;

            case 2:
                printf("Enter Expense Name: ");
                scanf(" %[^\n]s", name); // Read string with spaces
                printf("Enter Expense Amount: ");
                scanf("%f", &amount);
                printf("Enter Expense Category: ");
                scanf(" %[^\n]s", category); // Read string with spaces
                addEntry(&tracker, name, amount, category, 0);
                break;

            case 3:
                viewSummary(&tracker);
                break;

            case 4:
                printf("Exiting the program! Bye!\n");
                break;

            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (option != 4);

    return 0;
}