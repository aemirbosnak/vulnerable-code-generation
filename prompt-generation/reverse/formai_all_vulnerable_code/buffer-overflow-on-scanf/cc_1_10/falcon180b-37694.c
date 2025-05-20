//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
    char category[50];
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

char categories[MAX_CATEGORIES][50];
int num_categories = 0;

void add_category() {
    char input[50];
    printf("Enter category name: ");
    scanf("%s", input);
    strcpy(categories[num_categories], input);
    num_categories++;
}

int get_category_index(char* category) {
    for (int i = 0; i < num_categories; i++) {
        if (strcmp(category, categories[i]) == 0) {
            return i;
        }
    }
    return -1;
}

void add_expense() {
    char input[50];
    printf("Enter expense name: ");
    scanf("%s", input);
    strcpy(expenses[num_expenses].name, input);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%s", input);
    int category_index = get_category_index(input);

    if (category_index == -1) {
        add_category();
        category_index = num_categories - 1;
    }

    strcpy(expenses[num_expenses].category, categories[category_index]);
    num_expenses++;
}

void print_expenses() {
    printf("Expense Tracker\n");
    printf("================\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2lf - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    add_category();
    add_expense();
    add_expense();
    print_expenses();

    return 0;
}