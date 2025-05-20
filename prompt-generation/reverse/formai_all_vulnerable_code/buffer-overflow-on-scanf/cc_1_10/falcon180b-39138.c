//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 100
#define MAX_EXPENSES 1000

typedef struct {
    char name[50];
    int expenses[MAX_EXPENSES];
} Category;

typedef struct {
    char description[100];
    int amount;
    char category[50];
} Expense;

Category categories[MAX_CATEGORIES];
Expense expenses[MAX_EXPENSES];
int num_categories = 0;
int num_expenses = 0;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    num_categories++;
}

void remove_category(int index) {
    printf("Removing category %s...\n", categories[index].name);
    memmove(&categories[index], &categories[index+1], (num_categories-index-1)*sizeof(Category));
    num_categories--;
}

void add_expense() {
    printf("Enter expense description: ");
    scanf("%s", expenses[num_expenses].description);
    printf("Enter amount: ");
    scanf("%d", &expenses[num_expenses].amount);
    printf("Enter category: ");
    scanf("%s", expenses[num_expenses].category);
    num_expenses++;
}

void remove_expense(int index) {
    printf("Removing expense %s...\n", expenses[index].description);
    memmove(&expenses[index], &expenses[index+1], (num_expenses-index-1)*sizeof(Expense));
    num_expenses--;
}

void print_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void print_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%d - %s\n", expenses[i].description, expenses[i].amount, expenses[i].category);
    }
}

void print_expenses_by_category(char* category) {
    printf("Expenses in category %s:\n", category);
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("%s - $%d\n", expenses[i].description, expenses[i].amount);
        }
    }
}

int main() {
    add_category();
    add_category();
    add_expense();
    add_expense();
    add_expense();
    print_categories();
    print_expenses();
    print_expenses_by_category("Food");
    remove_category(0);
    remove_expense(2);
    print_categories();
    print_expenses();
    return 0;
}