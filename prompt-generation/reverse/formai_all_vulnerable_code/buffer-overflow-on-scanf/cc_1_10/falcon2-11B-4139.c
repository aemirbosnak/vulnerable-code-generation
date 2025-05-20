//Falcon2-11B DATASET v1.0 Category: Expense Tracker ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    int amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses;

void add_expense(const char *name, int amount) {
    Expense new_expense;
    strcpy(new_expense.name, name);
    new_expense.amount = amount;

    if (num_expenses >= MAX_EXPENSES) {
        fprintf(stderr, "Too many expenses\n");
        return;
    }

    expenses[num_expenses] = new_expense;
    num_expenses++;
}

void print_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%d\n", expenses[i].name, expenses[i].amount);
    }
}

int main() {
    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);

    for (int i = 0; i < num_expenses; i++) {
        printf("Enter expense name: ");
        fgets(expenses[i].name, 50, stdin);

        printf("Enter expense amount: ");
        scanf("%d", &expenses[i].amount);
    }

    print_expenses();

    return 0;
}