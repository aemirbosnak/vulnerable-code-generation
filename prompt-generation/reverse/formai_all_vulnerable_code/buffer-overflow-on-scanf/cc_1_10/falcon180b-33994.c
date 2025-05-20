//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
    int date;
} expense;

void add_expense(expense* expenses, int size, char* name, double amount, int date) {
    if (size >= MAX_EXPENSES) {
        printf("Sorry, you've reached the maximum number of expenses!\n");
        return;
    }
    strcpy(expenses[size].name, name);
    expenses[size].amount = amount;
    expenses[size].date = date;
    size++;
}

void view_expenses(expense* expenses, int size) {
    if (size == 0) {
        printf("No expenses yet!\n");
        return;
    }
    printf("Expenses:\n");
    for (int i = 0; i < size; i++) {
        printf("%s - $%.2f - %d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int size = 0;
    char name[50];
    double amount;
    int date;

    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Exit\n");
        scanf("%d", &date);
        switch (date) {
        case 1:
            printf("Enter expense name: ");
            scanf("%s", name);
            printf("Enter expense amount: ");
            scanf("%lf", &amount);
            add_expense(expenses, size, name, amount, date);
            break;
        case 2:
            view_expenses(expenses, size);
            break;
        case 3:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid option.\n");
        }
    }

    return 0;
}