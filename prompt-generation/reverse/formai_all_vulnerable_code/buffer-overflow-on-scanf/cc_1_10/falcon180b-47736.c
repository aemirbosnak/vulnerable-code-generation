//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
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

expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][50];
int num_categories = 0;
int num_expenses = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void view_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    add_category();
    add_category();
    add_category();
    view_categories();
    add_expense();
    add_expense();
    view_expenses();
    return 0;
}