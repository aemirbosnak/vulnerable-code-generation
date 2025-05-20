//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100

struct expense {
    char date[11];
    char category[31];
    char description[101];
    double amount;
};

void add_expense(struct expense *expenses, int num_expenses) {
    printf("Enter date (YYYY-MM-DD): ");
    scanf("%s", expenses[num_expenses].date);

    printf("Enter category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter description: ");
    scanf("%[^\n]", expenses[num_expenses].description);

    printf("Enter amount: ");
    scanf("%lf", &expenses[num_expenses].amount);

    num_expenses++;
}

void print_expenses(struct expense *expenses, int num_expenses) {
    printf("\nExpenses:\n");
    printf("Date\tCategory\tDescription\tAmount\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%s\t%.2lf\n", expenses[i].date, expenses[i].category, expenses[i].description, expenses[i].amount);
    }
}

void sort_expenses(struct expense *expenses, int num_expenses) {
    for (int i = 0; i < num_expenses - 1; i++) {
        for (int j = i + 1; j < num_expenses; j++) {
            if (strcmp(expenses[i].date, expenses[j].date) > 0) {
                struct expense temp = expenses[i];
                expenses[i] = expenses[j];
                expenses[j] = temp;
            }
        }
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    printf("Enter expenses:\n");

    while (num_expenses < MAX_EXPENSES) {
        add_expense(expenses, num_expenses);

        if (num_expenses == MAX_EXPENSES - 1) {
            printf("No more expenses can be added.\n");
        }
    }

    sort_expenses(expenses, num_expenses);
    print_expenses(expenses, num_expenses);

    return 0;
}