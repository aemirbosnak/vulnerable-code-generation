//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 50
#define MAX_ITEMS 100
#define MAX_EXPENSES 1000

typedef struct {
    char name[50];
    float amount;
    int category;
} expense;

typedef struct {
    char name[50];
    int id;
} category;

category categories[MAX_CATEGORIES];
expense expenses[MAX_EXPENSES];
int num_categories, num_expenses;

void add_category() {
    char name[50];
    printf("Enter category name: ");
    scanf("%s", name);
    strcpy(categories[num_categories].name, name);
    categories[num_categories].id = num_categories;
    num_categories++;
}

void add_expense() {
    int category_id;
    char item_name[50];
    float item_amount;
    printf("Enter category ID: ");
    scanf("%d", &category_id);
    printf("Enter item name: ");
    scanf("%s", item_name);
    printf("Enter item amount: ");
    scanf("%f", &item_amount);
    expenses[num_expenses].category = category_id;
    strcpy(expenses[num_expenses].name, item_name);
    expenses[num_expenses].amount = item_amount;
    num_expenses++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%d. %s\n", categories[i].id, categories[i].name);
    }
}

void display_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%d. %s - $%.2f (Category: %d)\n", i+1, expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    num_categories = 0;
    num_expenses = 0;
    add_category();
    add_category();
    add_category();
    add_expense();
    add_expense();
    add_expense();
    display_categories();
    display_expenses();
    return 0;
}