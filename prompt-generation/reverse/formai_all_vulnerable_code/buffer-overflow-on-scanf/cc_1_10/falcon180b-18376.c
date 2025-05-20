//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} expense;

typedef struct {
    char name[50];
    int num_expenses;
    expense expenses[MAX_EXPENSES];
} category;

void add_expense(expense* e, int* num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", e->name);
    printf("Enter expense amount: ");
    scanf("%f", &e->amount);
    printf("Enter expense category: ");
    scanf("%s", e->category);

    (*num_expenses)++;
}

void add_category(category* c, int* num_categories) {
    printf("Enter category name: ");
    scanf("%s", c->name);

    (*num_categories)++;
}

void display_expenses(expense* expenses, int num_expenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Name: %s\nAmount: $%.2f\nCategory: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void display_categories(category* categories, int num_categories) {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("Name: %s\n", categories[i].name);
        printf("Number of expenses: %d\n", categories[i].num_expenses);
        display_expenses(categories[i].expenses, categories[i].num_expenses);
        printf("\n");
    }
}

int main() {
    int num_categories = 0;
    category categories[MAX_CATEGORIES];

    int num_expenses = 0;
    expense expenses[MAX_EXPENSES];

    while (num_categories < MAX_CATEGORIES && num_expenses < MAX_EXPENSES) {
        printf("\nEnter 1 to add an expense or 2 to add a category: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_expense(&expenses[num_expenses], &num_expenses);
        } else {
            add_category(&categories[num_categories], &num_categories);
        }
    }

    display_categories(categories, num_categories);

    return 0;
}