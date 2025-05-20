//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_NAME_LEN 50
#define MAX_DESCRIPTION_LEN 100

typedef struct {
    char name[MAX_NAME_LEN];
    char description[MAX_DESCRIPTION_LEN];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void print_menu() {
    printf("\nExpense Tracker\n");
    printf("-----------------\n");
    printf("1. Add Expense\n");
    printf("2. View Expenses\n");
    printf("3. Delete Expense\n");
    printf("4. Quit\n");
}

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Max number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;
}

void view_expenses() {
    if (num_expenses == 0) {
        printf("No expenses to display.\n");
        return;
    }

    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s - %s - $%.2f\n", i + 1, expenses[i].name, expenses[i].description, expenses[i].amount);
    }
}

void delete_expense() {
    if (num_expenses == 0) {
        printf("Error: No expenses to delete.\n");
        return;
    }

    printf("Enter expense number to delete: ");
    int index;
    scanf("%d", &index);

    if (index < 1 || index > num_expenses) {
        printf("Error: Invalid expense number.\n");
        return;
    }

    for (int i = index - 1; i < num_expenses; i++) {
        expenses[i] = expenses[i + 1];
    }

    num_expenses--;
}

int main() {
    int choice;

    while (1) {
        print_menu();
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
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
                break;
        }
    }

    return 0;
}