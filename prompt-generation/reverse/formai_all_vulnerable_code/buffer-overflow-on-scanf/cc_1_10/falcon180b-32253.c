//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    double amount;
} Expense;

typedef struct {
    char name[50];
    int num_expenses;
    Expense expenses[MAX_EXPENSES];
} Category;

Category categories[MAX_CATEGORIES];
int num_categories = 0;

void add_category() {
    num_categories++;
    printf("Enter category name: ");
    scanf("%s", categories[num_categories - 1].name);
    categories[num_categories - 1].num_expenses = 0;
}

void add_expense() {
    int category_index;
    printf("Enter category: ");
    scanf("%d", &category_index);
    if (category_index >= 0 && category_index < num_categories) {
        printf("Enter expense name: ");
        scanf("%s", categories[category_index].expenses[categories[category_index].num_expenses].name);
        printf("Enter expense amount: ");
        scanf("%lf", &categories[category_index].expenses[categories[category_index].num_expenses].amount);
        categories[category_index].num_expenses++;
    } else {
        printf("Invalid category.\n");
    }
}

void view_expenses() {
    int category_index;
    printf("Enter category: ");
    scanf("%d", &category_index);
    if (category_index >= 0 && category_index < num_categories) {
        printf("Category: %s\n", categories[category_index].name);
        for (int i = 0; i < categories[category_index].num_expenses; i++) {
            printf("Expense %d: %s - $%.2lf\n", i + 1, categories[category_index].expenses[i].name, categories[category_index].expenses[i].amount);
        }
    } else {
        printf("Invalid category.\n");
    }
}

void main() {
    int choice;
    while (1) {
        printf("1. Add category\n2. Add expense\n3. View expenses\n4. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                printf("Enter category: ");
                scanf("%d", &choice);
                view_expenses();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
}