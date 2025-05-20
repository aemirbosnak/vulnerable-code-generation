//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    char category[50];
    double amount;
    time_t date;
} expense;

void add_expense(expense *list, int *num_expenses) {
    if (*num_expenses >= MAX_EXPENSES) {
        printf("Error: Cannot add more expenses.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", list[*num_expenses].name);

    printf("Enter expense category: ");
    scanf("%s", list[*num_expenses].category);

    printf("Enter expense amount: ");
    if (scanf("%lf", &list[*num_expenses].amount)!= 1) {
        printf("Error: Invalid amount.\n");
        return;
    }

    time_t now = time(NULL);
    list[*num_expenses].date = now;

    (*num_expenses)++;
}

void display_expenses(expense *list, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s (%s) - $%.2lf - %s\n", list[i].name, list[i].category, list[i].amount, ctime(&list[i].date));
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);

    display_expenses(expenses, num_expenses);

    return 0;
}