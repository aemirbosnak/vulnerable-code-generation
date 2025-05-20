//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} expense_t;

void add_expense(expense_t *expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%s", expenses[num_expenses].amount);
    num_expenses++;
}

void display_expenses(expense_t expenses[], int num_expenses) {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%s\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    expense_t expenses[MAX_ITEMS];
    int num_expenses = 0;

    add_expense(expenses, num_expenses);

    while (num_expenses < MAX_ITEMS) {
        printf("Add another expense? (y/n): ");
        char choice;
        scanf(" %c", &choice);
        if (choice == 'y') {
            add_expense(expenses, num_expenses);
        } else {
            printf("Display expenses? (y/n): ");
            scanf(" %c", &choice);
            if (choice == 'y') {
                display_expenses(expenses, num_expenses);
            }
        }
    }

    return 0;
}