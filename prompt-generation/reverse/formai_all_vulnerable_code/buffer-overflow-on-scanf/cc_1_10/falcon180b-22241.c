//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10
#define MAX_CATEGORY_NAME_LENGTH 50
#define MAX_EXPENSE_NAME_LENGTH 100

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int expenses[MAX_EXPENSES];
} Category;

typedef struct {
    char name[MAX_EXPENSE_NAME_LENGTH];
    double amount;
    int category;
} Expense;

Category categories[MAX_CATEGORIES];
Expense expenses[MAX_EXPENSES];
int num_categories = 0;
int num_expenses = 0;

void add_category() {
    if (num_categories >= MAX_CATEGORIES) {
        printf("Error: Maximum number of categories reached.\n");
        return;
    }
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void add_expense() {
    if (num_expenses >= MAX_EXPENSES) {
        printf("Error: Maximum number of expenses reached.\n");
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);
    printf("Enter expense category (0-9): ");
    scanf("%d", &expenses[num_expenses].category);
    num_expenses++;
}

void view_expenses() {
    printf("Category\tExpense\tAmount\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s:\n", categories[i].name);
        for (int j = 0; j < MAX_EXPENSES; j++) {
            if (categories[i].expenses[j]!= 0) {
                printf("%s\t%.2lf\t\t%.2lf\n", expenses[categories[i].expenses[j]].name, expenses[categories[i].expenses[j]].amount, expenses[categories[i].expenses[j]].amount);
            }
        }
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    printf("Please enter your categories:\n");
    for (int i = 0; i < MAX_CATEGORIES; i++) {
        add_category();
    }
    printf("Please enter your expenses:\n");
    for (int i = 0; i < MAX_EXPENSES; i++) {
        add_expense();
    }
    view_expenses();
    return 0;
}