//MISTRAL-7B DATASET v1.0 Category: Expense Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    enum { FOOD, RENT, UTILITIES, OTHER } type;
    char description[50];
    double amount;
} expense;

void get_expense(expense *exp) {
    puts("Enter expense type (1-Food, 2-Rent, 3-Utilities, 0-Other):");
    int type;
    scanf("%d", &type);
    switch (type) {
        case 1: strcpy(exp->description, "Food"); break;
        case 2: strcpy(exp->description, "Rent"); break;
        case 3: strcpy(exp->description, "Utilities"); break;
        default:
            exp->description[0] = '\0';
            puts("Invalid expense type. Please enter a valid expense type.");
            get_expense(exp);
            return;
    }

    puts("Enter expense description:");
    scanf("%s", exp->description + strlen(exp->description));
    strcpy(exp->description + strlen(exp->description) + 1, "\0");

    puts("Enter expense amount:");
    scanf("%lf", &exp->amount);
}

void add_expense(expense *expenses, expense *exp) {
    expenses = realloc(expenses, sizeof(expense) * (1 + (sizeof(expenses) / sizeof(expense))));
    *expenses++ = *exp;
}

void print_expenses(expense *expenses, int len) {
    for (int i = 0; i < len; i++) {
        printf("%s: %s, %.2lf\n", expenses[i].description, expenses[i].description, expenses[i].amount);
    }
}

void free_expenses(expense *expenses, int len) {
    free(expenses);
}

int main() {
    int num_expenses = 0;
    expense *expenses = NULL;

    while (1) {
        expense exp;

        puts("Do you want to add a new expense? (y/n)");
        char choice;
        scanf("%c", &choice);

        if (choice == 'n') {
            print_expenses(expenses, num_expenses);
            free_expenses(expenses, num_expenses);
            return 0;
        }

        get_expense(&exp);
        add_expense(expenses, &exp);
        num_expenses++;
    }

    return 0;
}