//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 20
#define MAX_CATEGORY_NAME_LENGTH 50
#define MAX_EXPENSE_NAME_LENGTH 50

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int num_expenses;
    float total_expenses;
} Category;

typedef struct {
    char name[MAX_EXPENSE_NAME_LENGTH];
    float amount;
    char category[MAX_CATEGORY_NAME_LENGTH];
} Expense;

Category categories[MAX_CATEGORIES];
Expense expenses[MAX_EXPENSES];
int num_categories;
int num_expenses;

void add_category() {
    printf("Enter the name of the category: ");
    scanf("%s", categories[num_categories].name);
    strcpy(categories[num_categories].name, toupper(categories[num_categories].name));
    categories[num_categories].num_expenses = 0;
    categories[num_categories].total_expenses = 0.0;
    num_categories++;
}

void add_expense() {
    printf("Enter the name of the expense: ");
    scanf("%s", expenses[num_expenses].name);
    strcpy(expenses[num_expenses].name, toupper(expenses[num_expenses].name));
    printf("Enter the category: ");
    scanf("%s", expenses[num_expenses].category);
    strcpy(expenses[num_expenses].category, toupper(expenses[num_expenses].category));
    printf("Enter the amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    int category_index = -1;
    for (int i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, expenses[num_expenses].category) == 0) {
            category_index = i;
            break;
        }
    }
    if (category_index == -1) {
        printf("Category not found.\n");
        return;
    }
    categories[category_index].num_expenses++;
    categories[category_index].total_expenses += expenses[num_expenses].amount;
    num_expenses++;
}

void display_categories() {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s (%d expenses, $%.2f total)\n", categories[i].name, categories[i].num_expenses, categories[i].total_expenses);
    }
}

void display_expenses() {
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s ($%.2f) - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    num_categories = 0;
    num_expenses = 0;
    add_category();
    while (1) {
        printf("1. Add category\n2. Add expense\n3. Display categories\n4. Display expenses\n5. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                display_categories();
                break;
            case 4:
                display_expenses();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}