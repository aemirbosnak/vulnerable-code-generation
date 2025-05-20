//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

struct expense {
    char name[MAX_NAME_LENGTH];
    float amount;
    int category;
};

struct category {
    char name[MAX_NAME_LENGTH];
    int count;
};

void add_expense(struct expense *expenses, int *num_expenses, int category) {
    printf("Enter expense name: ");
    scanf("%s", expenses[*num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[*num_expenses].amount);
    expenses[*num_expenses].category = category;
    (*num_expenses)++;
}

void print_expenses(struct expense *expenses, int num_expenses) {
    printf("Expense Name\tAmount\tCategory\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%.2f\t%d\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void add_category(struct category *categories, int *num_categories) {
    printf("Enter category name: ");
    scanf("%s", categories[*num_categories].name);
    categories[*num_categories].count = 0;
    (*num_categories)++;
}

void print_categories(struct category *categories, int num_categories) {
    printf("Category Name\tCount\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\t%d\n", categories[i].name, categories[i].count);
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    struct category categories[MAX_CATEGORIES];
    int num_categories = 0;

    int choice;
    do {
        printf("1. Add expense\n");
        printf("2. Print expenses\n");
        printf("3. Add category\n");
        printf("4. Print categories\n");
        printf("5. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses, 1);
                break;
            case 2:
                print_expenses(expenses, num_expenses);
                break;
            case 3:
                add_category(categories, &num_categories);
                break;
            case 4:
                print_categories(categories, num_categories);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}