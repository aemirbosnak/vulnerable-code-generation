//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} expense;

void add_expense(expense *expenses, int count, char *name, char *category, float amount) {
    strncpy(expenses[count].name, name, MAX_NAME_LENGTH);
    strncpy(expenses[count].category, category, MAX_CATEGORY_LENGTH);
    expenses[count].amount = amount;
}

void display_expenses(expense *expenses, int count) {
    printf("Expenses:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\nCategory: %s\nAmount: $%.2f\n\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

int main() {
    expense expenses[MAX_ITEMS];
    int count = 0;

    printf("Welcome to the Expense Tracker!\n");

    while (count < MAX_ITEMS) {
        printf("Enter expense name: ");
        scanf("%s", expenses[count].name);

        printf("Enter expense category: ");
        scanf("%s", expenses[count].category);

        printf("Enter expense amount: ");
        scanf("%f", &expenses[count].amount);

        add_expense(expenses, count, expenses[count].name, expenses[count].category, expenses[count].amount);
        count++;
    }

    printf("\nExpenses added successfully!\n");

    display_expenses(expenses, count);

    return 0;
}