//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 50
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    char category[50];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

char categories[MAX_CATEGORIES][50];
int num_categories = 0;

void add_category() {
    char input[50];
    printf("Enter new category: ");
    scanf("%s", input);
    strcpy(categories[num_categories], input);
    num_categories++;
}

void add_expense() {
    char input[50];
    printf("Enter expense name: ");
    scanf("%s", input);
    strcpy(expenses[num_expenses].name, input);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%s", input);

    for (int i = 0; i < num_categories; i++) {
        if (strcmp(input, categories[i]) == 0) {
            strcpy(expenses[num_expenses].category, categories[i]);
            break;
        }
    }

    num_expenses++;
}

void view_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
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

    view_categories();
    view_expenses();

    return 0;
}