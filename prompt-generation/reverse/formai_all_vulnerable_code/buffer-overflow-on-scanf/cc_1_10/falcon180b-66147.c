//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 100
#define MAX_EXPENSES 1000
#define MAX_NAME_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int category;
} expense_t;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int color;
} category_t;

category_t categories[MAX_CATEGORIES];
expense_t expenses[MAX_EXPENSES];
int num_categories = 0;
int num_expenses = 0;

void add_category() {
    if (num_categories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }

    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);

    printf("Enter category color (0-9): ");
    scanf("%d", &categories[num_categories].color);

    num_categories++;
}

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }

    int category_index;
    printf("Select a category: ");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
    scanf("%d", &category_index);

    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    expenses[num_expenses].category = category_index;
    num_expenses++;
}

void view_expenses_by_category() {
    int category_index;
    printf("Select a category: ");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", i+1, categories[i].name);
    }
    scanf("%d", &category_index);

    printf("Category: %s\n", categories[category_index].name);
    printf("Color: %d\n", categories[category_index].color);

    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        if (expenses[i].category == category_index) {
            printf("%s: $%.2f\n", expenses[i].name, expenses[i].amount);
        }
    }
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f (%d)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    add_category();
    add_category();

    add_expense();
    add_expense();

    view_expenses();
    view_expenses_by_category();

    return 0;
}