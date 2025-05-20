//FormAI DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 20

int expense_count = 0;

struct Expense {
    char name[30];
    float amount;
};

struct Expense expenses[MAX_EXPENSES];

void add_expense() {
    if (expense_count >= MAX_EXPENSES) {
        printf("Cannot add more expenses. Maximum limit reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[expense_count].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[expense_count].amount);

    expense_count++;
}

void display_expenses() {
    if (expense_count == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("| %-30s | %10s |\n", "Expense Name", "Amount");
    printf("+--------------------------------+------------+\n");
    for (int i = 0; i < expense_count; i++) {
        printf("| %-30s | %10.2f |\n", expenses[i].name, expenses[i].amount);
    }
}

void calculate_total() {
    float total = 0;
    for (int i = 0; i < expense_count; i++) {
        total += expenses[i].amount;
    }

    printf("Total expenses: $%.2f\n", total);
}

int main() {
    int choice;

    do {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. Display Expenses\n");
        printf("3. Calculate Total\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                calculate_total();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}