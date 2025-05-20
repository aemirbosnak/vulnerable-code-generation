//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    char category[50];
    float amount;
    time_t date;
} expense;

void add_expense(expense* expenses, int num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    time_t now = time(0);
    expenses[num_expenses].date = now;
    printf("Expense added.\n");
}

void view_expenses(expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s (%s) - $%.2f - %s\n", expenses[i].name, expenses[i].category, expenses[i].amount, ctime(&expenses[i].date));
    }
}

void sort_expenses(expense* expenses, int num_expenses, int (*compare)(const void*, const void*)) {
    qsort(expenses, num_expenses, sizeof(expense), compare);
}

int compare_date(const void* a, const void* b) {
    expense* expense_a = (expense*)a;
    expense* expense_b = (expense*)b;
    return difftime(expense_a->date, expense_b->date);
}

int compare_amount(const void* a, const void* b) {
    expense* expense_a = (expense*)a;
    expense* expense_b = (expense*)b;
    return expense_a->amount - expense_b->amount;
}

int main() {
    expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        add_expense(expenses, num_expenses);
    }

    view_expenses(expenses, num_expenses);

    sort_expenses(expenses, num_expenses, compare_date);
    view_expenses(expenses, num_expenses);

    sort_expenses(expenses, num_expenses, compare_amount);
    view_expenses(expenses, num_expenses);

    return 0;
}