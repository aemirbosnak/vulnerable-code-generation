//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_CATEGORY_LENGTH 20

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_CATEGORY_LENGTH];
    float amount;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

char categories[MAX_CATEGORIES][MAX_CATEGORY_LENGTH];
int num_categories = 0;

void add_category() {
    printf("Enter category name (up to %d characters): ", MAX_CATEGORY_LENGTH - 1);
    scanf("%s", categories[num_categories]);
    num_categories++;
}

void add_expense() {
    printf("Enter expense name (up to %d characters): ", MAX_NAME_LENGTH - 1);
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s (%s) - $%.2f\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void view_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    add_category();
    add_category();
    add_category();
    add_category();
    add_category();

    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();

    view_categories();
    view_expenses();

    return 0;
}