//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100

struct expense {
    char description[100];
    double amount;
    int date;
};

void add_expense(struct expense* expenses, int count, char* description, double amount) {
    if (count >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    strcpy(expenses[count].description, description);
    expenses[count].amount = amount;
    expenses[count].date = time(NULL);
    count++;
}

void print_expenses(struct expense* expenses, int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].description, expenses[i].amount, ctime(&expenses[i].date));
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int count = 0;

    while (1) {
        printf("Enter an expense (leave blank to quit):\n");
        scanf("%s", expenses[count].description);

        if (strcmp(expenses[count].description, "") == 0) {
            break;
        }

        printf("Enter the amount:\n");
        scanf("%lf", &expenses[count].amount);

        add_expense(expenses, count, expenses[count].description, expenses[count].amount);
        count++;
    }

    print_expenses(expenses, count);

    return 0;
}