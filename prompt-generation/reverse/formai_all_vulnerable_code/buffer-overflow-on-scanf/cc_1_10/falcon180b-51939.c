//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} expense;

void add_expense(expense* expenses, int* num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    (*num_expenses)++;
}

void view_expenses(expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void delete_expense(expense* expenses, int* num_expenses) {
    printf("Enter expense name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);
    for (int i = 0; i < *num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            memmove(&expenses[i], &expenses[i+1], (*num_expenses - i - 1) * sizeof(expense));
            (*num_expenses)--;
            return;
        }
    }
    printf("Expense not found.\n");
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Delete expense\n");
        printf("4. Quit\n");
        printf("\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses);
                break;
            case 2:
                view_expenses(expenses, num_expenses);
                break;
            case 3:
                delete_expense(expenses, &num_expenses);
                break;
            case 4:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}