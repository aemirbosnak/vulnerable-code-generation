//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 50
#define MAX_EXPENSES 500

typedef struct {
    char name[50];
    float total;
} Category;

typedef struct {
    char name[50];
    float amount;
    Category* category;
} Expense;

Category categories[MAX_CATEGORIES];
Expense expenses[MAX_EXPENSES];
int num_categories = 0;
int num_expenses = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].total = 0;
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter category name: ");
    scanf("%s", expenses[num_expenses].category->name);
    expenses[num_expenses].category = &categories[get_category_index(expenses[num_expenses].category->name)];
    expenses[num_expenses].category->total += expenses[num_expenses].amount;
    num_expenses++;
}

int get_category_index(char* name) {
    for(int i = 0; i < num_categories; i++) {
        if(strcmp(name, categories[i].name) == 0) {
            return i;
        }
    }
    return -1;
}

void display_categories() {
    printf("Categories:\n");
    for(int i = 0; i < num_categories; i++) {
        printf("%s: $%.2f\n", categories[i].name, categories[i].total);
    }
}

void display_expenses() {
    printf("Expenses:\n");
    for(int i = 0; i < num_expenses; i++) {
        printf("%s: $%.2f - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category->name);
    }
}

int main() {
    printf("Welcome to the expense tracker!\n");
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