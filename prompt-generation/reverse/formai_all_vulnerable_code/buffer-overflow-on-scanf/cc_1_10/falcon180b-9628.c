//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    int category;
} expense;

expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][50];
int num_expenses = 0;
int num_categories = 0;

void add_category() {
    char category_name[51];
    printf("Enter category name: ");
    scanf("%s", category_name);
    strcpy(categories[num_categories], category_name);
    num_categories++;
}

void add_expense() {
    char expense_name[51];
    float expense_amount;
    int expense_category;
    printf("Enter expense name: ");
    scanf("%s", expense_name);
    printf("Enter expense amount: ");
    scanf("%f", &expense_amount);
    printf("Enter expense category: ");
    scanf("%d", &expense_category);
    strcpy(expenses[num_expenses].name, expense_name);
    expenses[num_expenses].amount = expense_amount;
    expenses[num_expenses].category = expense_category;
    num_expenses++;
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Name: %s\nAmount: %.2f\nCategory: %d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    add_category();
    add_category();
    add_category();
    add_expense();
    add_expense();
    add_expense();
    view_expenses();
    view_categories();
    return 0;
}