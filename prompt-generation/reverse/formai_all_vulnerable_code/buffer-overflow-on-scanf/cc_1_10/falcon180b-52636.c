//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 100
#define MAX_EXPENSES 1000
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    float amount;
} expense;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int num_expenses;
    expense expenses[MAX_EXPENSES];
} category;

category categories[MAX_CATEGORIES];
int num_categories;

void add_category(char* name) {
    int i;
    for (i = 0; i < num_categories; i++) {
        if (strcmp(categories[i].name, name) == 0) {
            printf("Category already exists.\n");
            return;
        }
    }
    strcpy(categories[num_categories].name, name);
    categories[num_categories].num_expenses = 0;
    num_categories++;
}

void add_expense(int category_index, char* name, float amount) {
    int i;
    for (i = 0; i < categories[category_index].num_expenses; i++) {
        if (strcmp(categories[category_index].expenses[i].name, name) == 0) {
            categories[category_index].expenses[i].amount += amount;
            return;
        }
    }
    strcpy(categories[category_index].expenses[categories[category_index].num_expenses].name, name);
    categories[category_index].expenses[categories[category_index].num_expenses].amount = amount;
    categories[category_index].num_expenses++;
}

void view_expenses(int category_index) {
    int i;
    if (categories[category_index].num_expenses == 0) {
        printf("No expenses in this category.\n");
        return;
    }
    printf("Expenses in %s:\n", categories[category_index].name);
    for (i = 0; i < categories[category_index].num_expenses; i++) {
        printf("%s: $%.2f\n", categories[category_index].expenses[i].name, categories[category_index].expenses[i].amount);
    }
}

void view_categories() {
    int i;
    printf("Categories:\n");
    for (i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

int main() {
    int choice;
    char input[MAX_NAME_LENGTH];
    while (1) {
        printf("1. Add category\n2. Add expense\n3. View expenses\n4. View categories\n5. Exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter category name: ");
                scanf("%s", input);
                add_category(input);
                break;
            case 2:
                printf("Enter category name: ");
                scanf("%s", input);
                printf("Enter expense name: ");
                scanf("%s", input);
                printf("Enter expense amount: $");
                scanf("%f", &categories[atoi(input) - 1].expenses[categories[atoi(input) - 1].num_expenses - 1].amount);
                break;
            case 3:
                printf("Enter category name: ");
                scanf("%s", input);
                view_expenses(atoi(input) - 1);
                break;
            case 4:
                view_categories();
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}