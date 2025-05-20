//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100
#define MAX_LENGTH 100

typedef struct {
    char name[MAX_LENGTH];
    float amount;
    int category;
} Expense;

Expense expenses[MAX_ITEMS];
char categories[MAX_CATEGORIES][MAX_LENGTH];
int num_categories;
int num_items;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_items].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_items].amount);
    printf("Enter expense category (1-%d): ", num_categories);
    scanf("%d", &expenses[num_items].category);
    num_items++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

void display_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_items; i++) {
        printf("%s - $%.2f (Category: %d)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void search_expense() {
    printf("Enter expense name to search for: ");
    char search_name[MAX_LENGTH];
    scanf("%s", search_name);
    int found = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(expenses[i].name, search_name) == 0) {
            printf("Found expense:\n");
            printf("%s - $%.2f (Category: %d)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
            found = 1;
        }
    }
    if (!found) {
        printf("Expense not found.\n");
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    num_categories = 0;
    add_category();
    add_category();
    add_category();
    num_categories = 3;
    num_items = 0;
    add_expense();
    add_expense();
    add_expense();
    num_items = 3;
    display_categories();
    display_expenses();
    search_expense();
    return 0;
}