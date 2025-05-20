//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Linus Torvalds
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
    int amount;
    int category;
} Expense;

int main() {
    int num_categories, num_expenses;
    Category categories[MAX_CATEGORIES];
    Expense expenses[MAX_EXPENSES];

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", categories[i].name);
    }

    printf("Enter the number of expenses: ");
    scanf("%d", &num_expenses);

    for (int i = 0; i < num_expenses; i++) {
        printf("Enter the name of expense %d: ", i + 1);
        scanf("%s", expenses[i].name);
        printf("Enter the amount of expense %d: ", i + 1);
        scanf("%d", &expenses[i].amount);
        printf("Enter the category of expense %d (0-%d): ", i + 1, num_categories - 1);
        scanf("%d", &expenses[i].category);
    }

    for (int i = 0; i < num_categories; i++) {
        printf("Category %s:\n", categories[i].name);
        for (int j = 0; j < num_expenses; j++) {
            if (expenses[j].category == i) {
                printf("- %s: $%d\n", expenses[j].name, expenses[j].amount);
            }
        }
        printf("\n");
    }

    return 0;
}