//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 100

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void addExpense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Error: Cannot add more expenses. Max limit reached.\n");
        return;
    }
    printf("Enter expense description: ");
    scanf(" %[^\n]", expenses[*count].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);
    (*count)++;
    printf("Expense added successfully.\n");
}

void viewExpenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\n--- Expense List ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s - $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("------------------------\n");
}

void calculateTotalExpenses(Expense expenses[], int count) {
    float total = 0;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void sortExpenses(Expense expenses[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (expenses[j].amount > expenses[j + 1].amount) {
                Expense temp = expenses[j];
                expenses[j] = expenses[j + 1];
                expenses[j + 1] = temp;
            }
        }
    }
    printf("Expenses sorted by amount.\n");
}

void deleteExpense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to delete.\n");
        return;
    }
    int index;
    printf("Enter the expense number to delete: ");
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid expense number.\n");
        return;
    }
    index--; // Convert to zero based index
    for (int i = index; i < *count - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--;
    printf("Expense deleted successfully.\n");
}

void menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Sort Expenses by Amount\n");
    printf("5. Delete Expense\n");
    printf("6. Exit\n");
    printf("-----------------------------\n");
    printf("Choose an option: ");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addExpense(expenses, &count);
                break;
            case 2:
                viewExpenses(expenses, count);
                break;
            case 3:
                calculateTotalExpenses(expenses, count);
                break;
            case 4:
                sortExpenses(expenses, count);
                break;
            case 5:
                deleteExpense(expenses, &count);
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}