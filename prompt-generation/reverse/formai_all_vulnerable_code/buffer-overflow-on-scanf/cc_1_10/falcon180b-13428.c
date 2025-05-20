//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char amount[MAX_AMOUNT_LEN];
} expense_t;

expense_t expenses[MAX_ITEMS];
int num_expenses = 0;

void add_expense() {
    if (num_expenses >= MAX_ITEMS) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%s", expenses[num_expenses].amount);

    num_expenses++;
}

void display_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s - $%s\n", i+1, expenses[i].name, expenses[i].amount);
    }
}

void delete_expense() {
    if (num_expenses == 0) {
        printf("Error: No expenses to delete.\n");
        return;
    }

    int index;
    printf("Enter expense index to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= num_expenses) {
        printf("Error: Invalid expense index.\n");
        return;
    }

    for (int i = index; i < num_expenses-1; i++) {
        strcpy(expenses[i].name, expenses[i+1].name);
        strcpy(expenses[i].amount, expenses[i+1].amount);
    }

    num_expenses--;
}

void calculate_total_expenses() {
    double total_expenses = 0.0;

    for (int i = 0; i < num_expenses; i++) {
        total_expenses += atof(expenses[i].amount);
    }

    printf("Total expenses: $%.2f\n", total_expenses);
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nOptions:\n");
        printf("1. Add expense\n");
        printf("2. Display expenses\n");
        printf("3. Delete expense\n");
        printf("4. Calculate total expenses\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                delete_expense();
                break;
            case 4:
                calculate_total_expenses();
                break;
            case 5:
                exit(0);
            default:
                printf("Error: Invalid choice.\n");
        }
    }

    return 0;
}