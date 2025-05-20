//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_DESCRIPTION 50

typedef struct {
    char description[MAX_DESCRIPTION];
    float amount;
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker, const char *description, float amount) {
    if (tracker->count < MAX_ENTRIES) {
        strcpy(tracker->expenses[tracker->count].description, description);
        tracker->expenses[tracker->count].amount = amount;
        tracker->count++;
        printf("Expense added: %s - $%.2f\n", description, amount);
    } else {
        printf("Expense limit reached! Cannot add more expenses.\n");
    }
}

void showExpenses(const ExpenseTracker *tracker) {
    float total = 0;
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }
    printf("\nYour Expenses:\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
        total += tracker->expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void saveToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }
    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s - $%.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }
    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void loadFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No previous expenses found.\n");
        return;
    }
    char description[MAX_DESCRIPTION];
    float amount;
    tracker->count = 0;
    while (fscanf(file, "%49[^-] - $%f\n", description, &amount) == 2) {
        addExpense(tracker, description, amount);
    }
    fclose(file);
    printf("Expenses loaded from expenses.txt\n");
}

int displayMenu() {
    int choice;
    printf("\n=== Expense Tracker ===\n");
    printf("1. Add Expense\n");
    printf("2. Show Expenses\n");
    printf("3. Save Expenses\n");
    printf("4. Load Expenses\n");
    printf("5. Exit\n");
    printf("Choose an option: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    ExpenseTracker tracker;
    tracker.count = 0;
    loadFromFile(&tracker);

    while (1) {
        int choice = displayMenu();
        char description[MAX_DESCRIPTION];
        float amount;

        switch (choice) {
            case 1:
                printf("Enter description of the expense: ");
                scanf(" %[^\n]%*c", description);
                printf("Enter amount: $");
                scanf("%f", &amount);
                addExpense(&tracker, description, amount);
                break;
            case 2:
                showExpenses(&tracker);
                break;
            case 3:
                saveToFile(&tracker);
                break;
            case 4:
                loadFromFile(&tracker);
                break;
            case 5:
                printf("Exiting the Expense Tracker. Have a wonderful day!\n");
                return 0;
            default:
                printf("Invalid option! Please try again.\n");
        }
    }
}