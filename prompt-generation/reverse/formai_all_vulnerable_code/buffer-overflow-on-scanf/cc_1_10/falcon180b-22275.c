//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: visionary
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

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
int num_categories = 0;

void add_category() {
    num_categories++;
    printf("Enter category name: ");
    scanf("%s", categories[num_categories-1]);
}

void add_expense() {
    num_expenses++;
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses-1].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses-1].amount);
    printf("Enter expense category (1-%d): ", num_categories);
    scanf("%d", &expenses[num_expenses-1].category);
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - Category: %d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void view_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", "John");
    printf("Hello, %s! Let's get started.\n", "John");

    add_category();
    add_category();
    add_category();

    add_expense();
    add_expense();
    add_expense();

    view_categories();
    view_expenses();

    return 0;
}