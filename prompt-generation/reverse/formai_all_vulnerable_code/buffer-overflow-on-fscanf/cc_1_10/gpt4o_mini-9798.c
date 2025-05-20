//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

typedef struct {
    Expense entries[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker* tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker* tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Error: Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter a description of the expense: ");
    fgets(newExpense.description, DESCRIPTION_LENGTH, stdin);
    // Remove newline character from the input
    newExpense.description[strcspn(newExpense.description, "\n")] = 0;

    printf("Enter the amount of the expense: ");
    scanf("%f", &newExpense.amount);
    getchar(); // Clear the newline left in the buffer

    tracker->entries[tracker->count] = newExpense;
    tracker->count++;
    printf("Expense added successfully.\n");
}

void displayExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d: %s - %.2f\n", i + 1, tracker->entries[i].description, tracker->entries[i].amount);
    }
    printf("---------------------\n");
}

float calculateTotal(const ExpenseTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    return total;
}

void displayTotal(const ExpenseTracker* tracker) {
    float total = calculateTotal(tracker);
    printf("Total expenses: %.2f\n", total);
}

void saveExpensesToFile(const ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error: Could not open file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%.2f\n", tracker->entries[i].description, tracker->entries[i].amount);
    }

    fclose(file);
    printf("Expenses saved to %s\n", filename);
}

void loadExpensesFromFile(ExpenseTracker* tracker, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    while (!feof(file) && tracker->count < MAX_ENTRIES) {
        Expense newExpense;
        fscanf(file, " %[^\n],%f\n", newExpense.description, &newExpense.amount);
        tracker->entries[tracker->count] = newExpense;
        tracker->count++;
    }

    fclose(file);
    printf("Expenses loaded from %s\n", filename);
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    int choice;
    const char* filename = "expenses.txt";

    do {
        printf("\n--- Expense Tracker Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total Expense\n");
        printf("4. Save Expenses to File\n");
        printf("5. Load Expenses from File\n");
        printf("6. Exit\n");
        printf("Choose an option (1-6): ");
        scanf("%d", &choice);
        getchar(); // Clear the newline from the input buffer

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                displayExpenses(&tracker);
                break;
            case 3:
                displayTotal(&tracker);
                break;
            case 4:
                saveExpensesToFile(&tracker, filename);
                break;
            case 5:
                loadExpensesFromFile(&tracker, filename);
                break;
            case 6:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}