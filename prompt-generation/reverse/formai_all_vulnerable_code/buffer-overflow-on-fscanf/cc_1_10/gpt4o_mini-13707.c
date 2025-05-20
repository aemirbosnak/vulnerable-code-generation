//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define NAME_LEN 50

typedef struct {
    char item[NAME_LEN];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

typedef struct {
    Expense expenses[MAX_ENTRIES];
    int count;
} ExpenseTracker;

void initializeTracker(ExpenseTracker *tracker) {
    tracker->count = 0;
}

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_ENTRIES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }
    Expense newExpense;

    printf("Enter item name: ");
    scanf("%s", newExpense.item);
    printf("Enter amount spent: ");
    scanf("%f", &newExpense.amount);
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    tracker->expenses[tracker->count++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses(ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded yet!\n");
        return;
    }

    printf("\n--- Expense Report ---\n");
    float total = 0.0;

    for (int i = 0; i < tracker->count; i++) {
        printf("Item: %s | Amount: $%.2f | Date: %s\n", 
               tracker->expenses[i].item, 
               tracker->expenses[i].amount, 
               tracker->expenses[i].date);
        total += tracker->expenses[i].amount;
    }

    printf("\nTotal Expenses: $%.2f\n", total);
    printf("-----------------------\n");
}

void saveToFile(ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Error opening file for writing!\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s,%.2f,%s\n", tracker->expenses[i].item, 
                tracker->expenses[i].amount, tracker->expenses[i].date);
    }

    fclose(file);
    printf("Expenses saved to %s\n", filename);
}

void loadFromFile(ExpenseTracker *tracker, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("No previous record found!\n");
        return;
    }

    while (!feof(file) && tracker->count < MAX_ENTRIES) {
        Expense loadedExpense;
        fscanf(file, "%49[^,],%f,%10s\n", loadedExpense.item, &loadedExpense.amount, loadedExpense.date);
        tracker->expenses[tracker->count++] = loadedExpense;
    }

    fclose(file);
    printf("Expenses loaded successfully from %s\n", filename);
}

int main() {
    ExpenseTracker tracker;
    initializeTracker(&tracker);

    loadFromFile(&tracker, "expenses.txt");

    int choice;
    do {
        printf("\n--- Expense Tracker Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Save Expenses to File\n");
        printf("4. Load Expenses from File\n");
        printf("5. Exit\n");
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
                saveToFile(&tracker, "expenses.txt");
                break;
            case 4:
                loadFromFile(&tracker, "expenses.txt");
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    } while (choice != 5);

    return 0;
}