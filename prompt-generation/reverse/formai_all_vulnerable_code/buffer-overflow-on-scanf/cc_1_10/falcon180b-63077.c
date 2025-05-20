//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
    int category;
} expense;

void add_expense(expense* expenses, int num_expenses, char* name, float amount, int category) {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    strcpy(expenses[num_expenses].name, name);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].category = category;
    num_expenses++;
}

void print_expenses(expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - Category %d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void add_category(char* categories[], int num_categories) {
    if (num_categories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }
    char category_name[MAX_NAME_LENGTH];
    printf("Enter category name: ");
    scanf("%s", category_name);
    strcpy(categories[num_categories], category_name);
    num_categories++;
}

int main() {
    expense expenses[MAX_EXPENSES];
    char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
    int num_expenses = 0;
    int num_categories = 0;

    add_category(categories, num_categories);
    add_category(categories, num_categories);
    add_category(categories, num_categories);

    add_expense(expenses, num_expenses, "Groceries", 50.00, 0);
    add_expense(expenses, num_expenses, "Gas", 25.50, 1);
    add_expense(expenses, num_expenses, "Dining Out", 75.00, 2);

    print_expenses(expenses, num_expenses);

    return 0;
}