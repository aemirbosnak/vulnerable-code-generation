//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_CATEGORIES 20

typedef struct {
    char name[50];
    float amount;
    int date;
    int month;
    int year;
    int category;
} expense;

typedef struct {
    char name[50];
    int count;
} category;

void add_expense(expense* expenses, int* num_expenses) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    printf("Enter expense date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &expenses[*num_expenses].date, &expenses[*num_expenses].month, &expenses[*num_expenses].year);
    printf("Enter expense category: ");
    scanf("%d", &expenses[*num_expenses].category);
    (*num_expenses)++;
}

void add_category(category* categories, int* num_categories) {
    printf("Enter category name: ");
    scanf("%s", categories[*num_categories].name);
    categories[*num_categories].count = 0;
    (*num_categories)++;
}

void display_categories(category* categories, int num_categories) {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d expenses\n", categories[i].name, categories[i].count);
    }
}

void display_expenses(expense* expenses, int num_expenses) {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Name: %s\nAmount: %.2f\nDate: %d/%d/%d\nCategory: %d\n\n", expenses[i].name, expenses[i].amount, expenses[i].date, expenses[i].month, expenses[i].year, expenses[i].category);
    }
}

int main() {
    expense expenses[MAX_EXPENSES];
    category categories[MAX_CATEGORIES];
    int num_expenses = 0;
    int num_categories = 0;

    add_category(categories, &num_categories);
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);
    add_expense(expenses, &num_expenses);

    display_categories(categories, num_categories);
    display_expenses(expenses, num_expenses);

    return 0;
}