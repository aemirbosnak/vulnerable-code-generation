//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} Expense;

void add_expense(Expense* expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    printf("Enter expense amount: ");
    scanf("%s", expenses[num_expenses].amount);
}

void display_expenses(Expense* expenses, int num_expenses) {
    printf("Expense Name\tExpense Category\tExpense Amount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void delete_expense(Expense* expenses, int num_expenses) {
    printf("Enter expense name to delete: ");
    char name[MAX_NAME_LENGTH];
    scanf("%s", name);

    int expense_index = -1;
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].name, name) == 0) {
            expense_index = i;
            break;
        }
    }

    if (expense_index == -1) {
        printf("Expense not found.\n");
    } else {
        for (int i = expense_index; i < num_expenses - 1; i++) {
            memcpy(&expenses[i], &expenses[i + 1], sizeof(Expense));
        }
        num_expenses--;
        printf("Expense deleted.\n");
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        printf("1. Add expense\n2. Display expenses\n3. Delete expense\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense(expenses, num_expenses);
            num_expenses++;
            break;
        case 2:
            display_expenses(expenses, num_expenses);
            break;
        case 3:
            delete_expense(expenses, num_expenses);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}