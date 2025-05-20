//FormAI DATASET v1.0 Category: Expense Tracker ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} expense_t;

typedef struct {
    expense_t expenses[MAX_ITEMS];
    int count;
} expense_list_t;

void display_menu();
void add_expense(expense_list_t *list);
void delete_expense(expense_list_t *list);
void view_expenses(expense_list_t *list);

int main() {
    expense_list_t list = { .count = 0 };
    int choice = 0;

    printf("Welcome to the Expense Tracker!\n\n");

    while (choice != 4) {
        display_menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(&list);
                break;
            case 2:
                delete_expense(&list);
                break;
            case 3:
                view_expenses(&list);
                break;
            case 4:
                printf("\nThank you for using Expense Tracker!\n");
                break;
            default:
                printf("\nInvalid choice, please try again!\n");
                break;
        }
    }

    return 0;
}

void display_menu() {
    printf("Choose an option:\n");
    printf("1. Add an expense\n");
    printf("2. Delete an expense\n");
    printf("3. View expenses\n");
    printf("4. Exit\n\n");
}

void add_expense(expense_list_t *list) {
    expense_t expense;

    printf("Enter expense name: ");
    scanf("%s", expense.name);

    printf("Enter expense amount: ");
    scanf("%f", &expense.amount);

    list->expenses[list->count++] = expense;

    printf("\nExpense added successfully!\n\n");
}

void delete_expense(expense_list_t *list) {
    char name[50];

    if (list->count == 0) {
        printf("\nNo expenses to delete!\n\n");
        return;
    }

    printf("Enter expense name to delete: ");
    scanf("%s", name);

    for (int i = 0; i < list->count; i++) {
        if (strcmp(list->expenses[i].name, name) == 0) {
            for (int j = i; j < list->count - 1; j++) {
                list->expenses[j] = list->expenses[j+1];
            }

            list->count--;

            printf("\nExpense deleted successfully!\n\n");
            return;
        }
    }

    printf("\nExpense not found!\n\n");
}

void view_expenses(expense_list_t *list) {
    if (list->count == 0) {
        printf("\nNo expenses to show!\n\n");
        return;
    }

    printf("\nExpense List:\n\n");

    printf("%-30s %s\n", "Name", "Amount");
    printf("---------------------------------------------\n");

    for (int i = 0; i < list->count; i++) {
        printf("%-30s $%.2f\n", list->expenses[i].name, list->expenses[i].amount);
    }

    printf("\n");
}