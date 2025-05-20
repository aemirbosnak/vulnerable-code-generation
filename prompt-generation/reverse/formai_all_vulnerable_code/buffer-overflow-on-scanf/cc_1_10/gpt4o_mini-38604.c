//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESCRIPTION_LENGTH 50

typedef struct {
    char description[MAX_DESCRIPTION_LENGTH];
    double amount;
} Expense;

typedef struct {
    Expense expenses[MAX_EXPENSES];
    int count;
} ExpenseTracker;

void addExpense(ExpenseTracker *tracker) {
    if (tracker->count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }

    Expense new_expense;
    printf("Enter description: ");
    scanf(" %49[^\n]", new_expense.description); // Read a line, up to 49 characters
    printf("Enter amount: ");
    scanf("%lf", &new_expense.amount);

    tracker->expenses[tracker->count] = new_expense;
    tracker->count++;
    printf("Expense added successfully!\n");
}

void viewExpenses(const ExpenseTracker *tracker) {
    if (tracker->count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expenses ---\n");
    for (int i = 0; i < tracker->count; i++) {
        printf("%d. %s: %.2f\n", i + 1, tracker->expenses[i].description, tracker->expenses[i].amount);
    }
}

void calculateTotal(const ExpenseTracker *tracker) {
    double total = 0.0;
    for (int i = 0; i < tracker->count; i++) {
        total += tracker->expenses[i].amount;
    }
    printf("Total expenses: %.2f\n", total);
}

void saveExpensesToFile(const ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    for (int i = 0; i < tracker->count; i++) {
        fprintf(file, "%s: %.2f\n", tracker->expenses[i].description, tracker->expenses[i].amount);
    }

    fclose(file);
    printf("Expenses saved to expenses.txt\n");
}

void loadExpensesFromFile(ExpenseTracker *tracker) {
    FILE *file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("No saved expenses found. Starting fresh.\n");
        return;
    }

    while (tracker->count < MAX_EXPENSES) {
        Expense new_expense;
        if (fscanf(file, "%49[^:]: %lf\n", new_expense.description, &new_expense.amount) != 2) {
            break;
        }
        tracker->expenses[tracker->count++] = new_expense;
    }

    fclose(file);
    printf("Expenses loaded successfully.\n");
}

void displayMenu() {
    printf("\n=== Expense Tracker Menu ===\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Save Expenses to File\n");
    printf("5. Load Expenses from File\n");
    printf("6. Exit\n");
    printf("Choose an option: ");
}

int main() {
    ExpenseTracker tracker = { .count = 0 };
    loadExpensesFromFile(&tracker);

    int choice;
    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(&tracker);
                break;
            case 2:
                viewExpenses(&tracker);
                break;
            case 3:
                calculateTotal(&tracker);
                break;
            case 4:
                saveExpensesToFile(&tracker);
                break;
            case 5:
                loadExpensesFromFile(&tracker);
                break;
            case 6:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}