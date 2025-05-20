//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char category[50];
    char description[100];
    float amount;
    char date[11]; // Format: YYYY-MM-DD
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    Expense newExpense;

    printf("Enter expense category: ");
    scanf("%s", newExpense.category);
    printf("Enter expense description: ");
    scanf(" %[^\n]%*c", newExpense.description);
    printf("Enter expense amount: ");
    scanf("%f", &newExpense.amount);
    printf("Enter expense date (YYYY-MM-DD): ");
    scanf("%s", newExpense.date);

    expenses[*count] = newExpense;
    (*count)++;
    printf("Expense added successfully!\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }

    printf("\n--- Expense List ---\n");
    printf("Category\tDescription\tAmount\tDate\n");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%s\t%.2f\t%s\n", expenses[i].category,
               expenses[i].description, expenses[i].amount, expenses[i].date);
    }
    printf("-------------------------------------------------\n");
}

void getTotalExpense(Expense expenses[], int count) {
    float total = 0.0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("Total expenses: %.2f\n", total);
}

void clearExpenses(Expense expenses[], int *count) {
    *count = 0;
    printf("All expenses cleared.\n");
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
        printf("4. Clear Expenses\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                getTotalExpense(expenses, count);
                break;
            case 4:
                clearExpenses(expenses, &count);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    return 0;
}