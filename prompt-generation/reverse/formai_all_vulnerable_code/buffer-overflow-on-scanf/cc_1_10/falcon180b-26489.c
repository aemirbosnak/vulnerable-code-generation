//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_CATEGORY_NAME 20

struct expense {
    char name[MAX_CATEGORY_NAME];
    double amount;
    int id;
};

struct category {
    char name[MAX_CATEGORY_NAME];
    int num_expenses;
    struct expense expenses[MAX_EXPENSES];
};

void add_expense(struct category* category) {
    int num_expenses = category->num_expenses;
    printf("Enter expense name: ");
    scanf("%s", category->expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%lf", &category->expenses[num_expenses].amount);
    category->num_expenses++;
}

void print_expenses(struct category* category) {
    int num_expenses = category->num_expenses;
    printf("Category: %s\n", category->name);
    printf("Expenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2lf\n", category->expenses[i].name, category->expenses[i].amount);
    }
}

void add_category(struct category* categories, int num_categories) {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories].name);
    categories[num_categories].num_expenses = 0;
    num_categories++;
}

int main() {
    struct category categories[MAX_CATEGORIES];
    int num_categories = 0;

    printf("Welcome to the Expense Tracker!\n");
    while (1) {
        printf("1. Add category\n2. Add expense\n3. Print expenses\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_categories == MAX_CATEGORIES) {
                printf("Maximum number of categories reached.\n");
            } else {
                add_category(categories, num_categories);
                num_categories++;
            }
            break;
        case 2:
            printf("Enter category ID: ");
            int category_id;
            scanf("%d", &category_id);

            if (category_id < 0 || category_id >= num_categories) {
                printf("Invalid category ID.\n");
            } else {
                printf("Enter category name: ");
                scanf("%s", categories[category_id].name);
                printf("Enter category name: ");
                scanf("%s", categories[category_id].name);
                categories[category_id].num_expenses = 0;
            }
            break;
        case 3:
            printf("Enter category ID: ");
            int category_id_print;
            scanf("%d", &category_id_print);

            if (category_id_print < 0 || category_id_print >= num_categories) {
                printf("Invalid category ID.\n");
            } else {
                print_expenses(&categories[category_id_print]);
            }
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}