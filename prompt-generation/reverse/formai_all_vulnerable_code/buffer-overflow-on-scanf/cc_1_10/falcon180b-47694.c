//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LEN 50
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN+1];
    char amount[MAX_AMOUNT_LEN+1];
} expense;

void add_expense(expense *expenses, int *num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%s", expenses[*num_expenses].amount);

    (*num_expenses)++;
}

void display_expenses(expense *expenses, int num_expenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%s\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (num_expenses < MAX_EXPENSES) {
        printf("\nAdd expense? (y/n): ");
        char choice;
        scanf(" %c", &choice);

        if (choice == 'y' || choice == 'Y') {
            add_expense(expenses, &num_expenses);
        } else {
            printf("\nTotal expenses: $%.2f\n", 0);
            break;
        }
    }

    display_expenses(expenses, num_expenses);

    return 0;
}