//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CATEGORIES 20
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
    char date[20];
} expense;

int num_expenses = 0;
expense expenses[MAX_EXPENSES];

int num_categories = 0;
char categories[MAX_CATEGORIES][50];

void add_category() {
    char input[50];
    printf("Enter category name: ");
    scanf("%s", input);
    strcpy(categories[num_categories], input);
    num_categories++;
}

void add_expense() {
    char input[50];
    float amount;
    char category[50];
    char date[20];

    printf("Enter expense name: ");
    scanf("%s", input);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    printf("Enter expense category: ");
    scanf("%s", category);

    printf("Enter expense date: ");
    scanf("%s", date);

    strcpy(expenses[num_expenses].name, input);
    expenses[num_expenses].amount = amount;
    strcpy(expenses[num_expenses].category, category);
    strcpy(expenses[num_expenses].date, date);

    num_expenses++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

void display_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Name: %s\nAmount: %.2f\nCategory: %s\nDate: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
    }
}

void search_expenses_by_category() {
    char input[50];
    printf("Enter category to search: ");
    scanf("%s", input);

    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, input) == 0) {
            printf("Name: %s\nAmount: %.2f\nCategory: %s\nDate: %s\n", expenses[i].name, expenses[i].amount, expenses[i].category, expenses[i].date);
        }
    }
}

int main() {
    printf("Expense Tracker\n");

    add_category();
    add_category();

    add_expense();
    add_expense();

    display_categories();
    display_expenses();

    search_expenses_by_category();

    return 0;
}