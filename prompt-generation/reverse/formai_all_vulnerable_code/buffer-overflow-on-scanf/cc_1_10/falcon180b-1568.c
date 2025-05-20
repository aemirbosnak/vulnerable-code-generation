//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_EXPENSE_NAME_LEN 50
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_NAME_LEN 50
#define MAX_BUDGET 1000000

typedef struct {
    char name[MAX_EXPENSE_NAME_LEN];
    float amount;
} expense;

typedef struct {
    char name[MAX_CATEGORY_NAME_LEN];
    float budget;
} category;

int num_expenses = 0;
int num_categories = 0;

expense expenses[MAX_EXPENSES];
category categories[MAX_CATEGORIES];

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Cannot add any more expenses.\n");
        return;
    }

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: $");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;
}

void add_category() {
    if (num_categories >= MAX_CATEGORIES) {
        printf("Cannot add any more categories.\n");
        return;
    }

    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);

    printf("Enter category budget: $");
    scanf("%f", &categories[num_categories].budget);

    num_categories++;
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f\n", expenses[i].name, expenses[i].amount);
    }
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s - $%.2f\n", categories[i].name, categories[i].budget);
    }
}

void main() {
    add_category();
    add_category();
    add_expense();
    add_expense();
    add_category();

    view_categories();
    view_expenses();
}