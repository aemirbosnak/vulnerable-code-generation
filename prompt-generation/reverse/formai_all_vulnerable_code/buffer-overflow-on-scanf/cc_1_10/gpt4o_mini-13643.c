//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_DESC_LENGTH 50

typedef struct {
    char description[MAX_DESC_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached! Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[*count].description); // Read string with spaces
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);

    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
}

float totalExpenses(Expense expenses[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    return total;
}

void clearExpenses(Expense expenses[], int *count) {
    *count = 0; // Resets expense count
    printf("All expenses cleared successfully!\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        printf("\n--- Expense Tracker Menu ---\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Total Expenses\n");
        printf("4. Clear All Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                printf("\n");
                break;
            case 3:
                printf("Total Expenses: $%.2f\n", totalExpenses(expenses, count));
                break;
            case 4:
                clearExpenses(expenses, &count);
                break;
            case 5:
                printf("Exiting Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please select again.\n");
        }
    } while (choice != 5);

    return 0;
}