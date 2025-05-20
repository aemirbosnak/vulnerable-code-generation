//Code Llama-13B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
/*
 * Expense Tracker
 *
 * This program is an example of a simple expense tracker that allows the user
 * to input and view expenses. It is written in the C programming language.
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

struct expense {
    char category[30];
    double amount;
};

void add_expense(struct expense *expenses, int *num_expenses) {
    printf("Enter the category of the expense: ");
    scanf("%s", expenses[*num_expenses].category);
    printf("Enter the amount of the expense: ");
    scanf("%lf", &expenses[*num_expenses].amount);
    (*num_expenses)++;
}

void view_expenses(struct expense *expenses, int num_expenses) {
    printf("Category\tAmount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\n", expenses[i].category, expenses[i].amount);
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    while (1) {
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
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
            return 0;
        default:
            printf("Invalid choice\n");
            break;
        }
    }

    return 0;
}