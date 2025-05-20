//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int date;
} Expense;

void add_expense(Expense* expenses, int num_expenses, char* name, float amount, int date) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].date = date;

    num_expenses++;
}

void display_expenses(Expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    printf("Name\tAmount\tDate\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%d\n", expenses[i].name, expenses[i].amount, expenses[i].date);
    }
}

int main() {
    Expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    char name[MAX_NAME_LENGTH];
    float amount;
    int date;

    while (1) {
        printf("Enter name of expense (leave blank to quit): ");
        scanf("%s", name);

        if (name[0] == '\0') {
            break;
        }

        printf("Enter amount of expense: ");
        scanf("%f", &amount);

        printf("Enter date of expense (YYYYMMDD): ");
        scanf("%d", &date);

        add_expense(expenses, num_expenses, name, amount, date);
    }

    display_expenses(expenses, num_expenses);

    return 0;
}