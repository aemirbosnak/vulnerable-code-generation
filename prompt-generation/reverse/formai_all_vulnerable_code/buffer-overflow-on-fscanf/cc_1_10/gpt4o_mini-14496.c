//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
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
        printf("Expense tracker is full. Unable to add more expenses.\n");
        return;
    }

    Expense newExpense;
    printf("Enter expense name: ");
    scanf("%s", newExpense.name);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);

    tracker->entries[tracker->count] = newExpense;
    tracker->count++;
    printf("Added expense: %s for amount: %.2f\n", newExpense.name, newExpense.amount);
}

void listExpenses(const ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("Expense %d: %s - %.2f\n", i + 1, tracker->entries[i].name, tracker->entries[i].amount);
    }
}

void totalExpenses(const ExpenseTracker* tracker) {
    float total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->entries[i].amount;
    }
    printf("Total Expenses: %.2f\n", total);
}

void deleteExpense(ExpenseTracker* tracker) {
    if (tracker->count == 0) {
        printf("No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the expense to delete (1 to %d): ", tracker->count);
    scanf("%d", &index);

    if (index < 1 || index > tracker->count) {
        printf("Invalid index. No expense deleted.\n");
        return;
    }

    for (int i = index - 1; i < tracker->count - 1; i++) {
        tracker->entries[i] = tracker->entries[i + 1];
    }

    tracker->count--;
    printf("Deleted expense at index %d.\n", index);
}

void saveExpensesToFile(const ExpenseTracker* tracker, const char* filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s %.2f\n", tracker->entries[i].name, tracker->entries[i].amount);
    }

    fclose(file);
    printf("Expenses saved to file: %s\n", filename);
}

void loadExpensesFromFile(ExpenseTracker* tracker, const char* filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No previous records found.\n");
        return;
    }

    while (tracker->count < MAX_ENTRIES && !feof(file)) {
        Expense entry;
        fscanf(file, "%s %f", entry.name, &entry.amount);
        tracker->entries[tracker->count] = entry;
        tracker->count++;
    }

    fclose(file);
    printf("Expenses loaded from file: %s\n", filename);
}

void showMenu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. List Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Total Expenses\n");
    printf("5. Save Expenses to File\n");
    printf("6. Load Expenses from File\n");
    printf("7. Exit\n");
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);
    int choice;
    char filename[] = "expenses.txt";

    loadExpensesFromFile(&tracker, filename);

    while (1) {
        showMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                listExpenses(&tracker);
                break;
            case 3:
                deleteExpense(&tracker);
                break;
            case 4:
                totalExpenses(&tracker);
                break;
            case 5:
                saveExpensesToFile(&tracker, filename);
                break;
            case 6:
                loadExpensesFromFile(&tracker, filename);
                break;
            case 7:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}