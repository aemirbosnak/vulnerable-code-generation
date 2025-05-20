//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
    char category[50];
} expense;

typedef struct {
    char name[50];
    int count;
} category;

category categories[MAX_CATEGORIES];
expense expenses[MAX_EXPENSES];

int num_categories = 0;
int num_expenses = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].count = 0;
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);
    printf("Enter expense category: ");
    scanf("%s", expenses[num_expenses].category);
    for (int i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, expenses[num_expenses].category) == 0) {
            categories[i].count++;
            break;
        }
    }
    num_expenses++;
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d expenses\n", categories[i].name, categories[i].count);
    }
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2lf (%s)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
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
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    add_expense();
    display_categories();
    display_expenses();
    return 0;
}