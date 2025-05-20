//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 20

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    double amount;
    int date;
} Expense;

int num_expenses = 0;
Expense expenses[MAX_EXPENSES];

int num_categories = 0;
char categories[MAX_CATEGORIES][MAX_CATEGORY_LEN];

void add_category() {
    char category[MAX_CATEGORY_LEN];
    printf("Enter category name: ");
    scanf("%s", category);
    strcpy(categories[num_categories], category);
    num_categories++;
}

void add_expense() {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    double amount;
    int date;

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter category: ");
    scanf("%s", category);

    printf("Enter amount: ");
    scanf("%lf", &amount);

    printf("Enter date (YYYY-MM-DD): ");
    scanf("%d", &date);

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].category, category);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].date = date;

    num_expenses++;
}

void view_expenses() {
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %s - %.2lf - %d\n", expenses[i].name, expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void view_categories() {
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
    add_category();
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