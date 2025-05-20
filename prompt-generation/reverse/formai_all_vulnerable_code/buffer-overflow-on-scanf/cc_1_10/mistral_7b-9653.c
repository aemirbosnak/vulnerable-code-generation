//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_EXPENSES 50

typedef struct {
    char description[50];
    float amount;
    int date;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);
    getchar(); // consume newline

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense date (YYYYMMDD): ");
    scanf("%d", &expenses[num_expenses].date);

    num_expenses++;
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("Error: No expenses to display.\n");
        return;
    }

    printf("\nExpense List:\n");
    printf("%-20s %-10s %-10s\n", "Description", "Amount", "Date");

    for (int i = 0; i < num_expenses; i++) {
        printf("%-20s $%.2f %06d\n", expenses[i].description, expenses[i].amount, expenses[i].date);
    }
}

void delete_expense() {
    if (num_expenses == 0) {
        printf("Error: No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter index of expense to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_expenses) {
        printf("Error: Invalid index.\n");
        return;
    }

    for (int i = index; i < num_expenses - 1; i++) {
        expenses[i] = expenses[i + 1];
    }

    num_expenses--;
}

int main() {
    int choice;

    while (true) {
        printf("\nExpense Tracker Menu:\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Delete Expense\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}