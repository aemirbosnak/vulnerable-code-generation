//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000
#define MAX_CATEGORIES 100

typedef struct {
    char name[50];
    double amount;
} expense;

typedef struct {
    char name[50];
    int count;
} category;

void add_expense(expense* expenses, int* num_expenses, category* categories, int* num_categories) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter expense amount: $");
    scanf("%lf", &expenses[*num_expenses].amount);

    int category_index = -1;
    for (int i = 0; i < *num_categories; i++) {
        if (strcmp(categories[i].name, expenses[*num_expenses].name) == 0) {
            category_index = i;
            break;
        }
    }

    if (category_index == -1) {
        category_index = *num_categories;
        (*num_categories)++;
        strcpy(categories[category_index].name, expenses[*num_expenses].name);
        categories[category_index].count = 1;
    } else {
        categories[category_index].count++;
    }

    (*num_expenses)++;
}

void print_expenses(expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2lf\n", expenses[i].name, expenses[i].amount);
    }
}

void print_categories(category* categories, int num_categories) {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d expenses\n", categories[i].name, categories[i].count);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    category categories[MAX_CATEGORIES];
    int num_expenses = 0;
    int num_categories = 0;

    add_expense(expenses, &num_expenses, categories, &num_categories);
    add_expense(expenses, &num_expenses, categories, &num_categories);
    add_expense(expenses, &num_expenses, categories, &num_categories);

    print_expenses(expenses, num_expenses);
    print_categories(categories, num_categories);

    return 0;
}