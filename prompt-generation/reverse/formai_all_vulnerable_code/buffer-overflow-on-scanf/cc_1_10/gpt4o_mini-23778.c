//GPT-4o-mini DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define DESCRIPTION_LENGTH 50

typedef struct {
    char description[DESCRIPTION_LENGTH];
    float amount;
} Expense;

void add_expense(Expense expenses[], int *count) {
    if (*count >= MAX_EXPENSES) {
        printf("Expense list is full!\n");
        return;
    }
    printf("Enter expense description: ");
    scanf(" %[^\n]s", expenses[*count].description);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*count].amount);
    (*count)++;
    printf("Expense added successfully!\n");
}

void view_expenses(Expense expenses[], int count) {
    if (count == 0) {
        printf("No expenses recorded.\n");
        return;
    }
    printf("\nExpense List:\n");
    printf("------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s: $%.2f\n", i + 1, expenses[i].description, expenses[i].amount);
    }
    printf("------------------------------------------------\n");
}

void calculate_total(Expense expenses[], int count) {
    float total = 0.0f;
    for (int i = 0; i < count; i++) {
        total += expenses[i].amount;
    }
    printf("Total Expenses: $%.2f\n", total);
}

void remove_expense(Expense expenses[], int *count) {
    if (*count == 0) {
        printf("No expenses to remove.\n");
        return;
    }
    int index;
    printf("Enter the index of the expense to remove (1 to %d): ", *count);
    scanf("%d", &index);
    if (index < 1 || index > *count) {
        printf("Invalid index!\n");
        return;
    }
    for (int i = index - 1; i < (*count) - 1; i++) {
        expenses[i] = expenses[i + 1];
    }
    (*count)--;
    printf("Expense removed successfully!\n");
}

void display_menu() {
    printf("\n--- Expense Tracker Menu ---\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Calculate Total Expenses\n");
    printf("4. Remove Expense\n");
    printf("5. Exit\n");
    printf("----------------------------\n");
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int count = 0;
    int choice;

    do {
        display_menu();
        printf("Choose an option (1-5): ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_expense(expenses, &count);
                break;
            case 2:
                view_expenses(expenses, count);
                break;
            case 3:
                calculate_total(expenses, count);
                break;
            case 4:
                remove_expense(expenses, &count);
                break;
            case 5:
                printf("Exiting the Expense Tracker. Goodbye!\n");
                break;
            default:
                printf("Invalid option! Please choose 1-5.\n");
        }
    } while (choice != 5);

    return 0;
}