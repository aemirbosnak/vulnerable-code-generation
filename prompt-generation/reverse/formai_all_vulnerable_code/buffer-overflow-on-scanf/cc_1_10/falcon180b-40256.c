//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CATEGORIES 20
#define MAX_EXPENSES 100

struct expense {
    char category[50];
    char description[100];
    double amount;
    time_t date;
};

struct category {
    char name[50];
    double total;
};

void add_expense(struct expense *expenses, int *num_expenses, char category[50]) {
    printf("Enter expense description: ");
    scanf("%s", expenses[*num_expenses].description);
    printf("Enter expense amount: ");
    scanf("%lf", &expenses[*num_expenses].amount);
    strcpy(expenses[*num_expenses].category, category);
    expenses[*num_expenses].date = time(NULL);
    (*num_expenses)++;
}

void add_category(struct category *categories, int *num_categories, char name[50]) {
    strcpy(categories[*num_categories].name, name);
    categories[*num_categories].total = 0;
    (*num_categories)++;
}

void display_expenses(struct expense *expenses, int num_expenses) {
    printf("\nExpenses:\n");
    printf("---------------------------------------------------\n");
    printf("| Date    | Category | Description | Amount     |\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("| %s     | %s       | %s         | %.2lf      |\n",
                ctime(&expenses[i].date),
                expenses[i].category,
                expenses[i].description,
                expenses[i].amount);
    }
    printf("---------------------------------------------------\n");
}

void display_categories(struct category *categories, int num_categories) {
    printf("\nCategories:\n");
    printf("--------------------\n");
    for (int i = 0; i < num_categories; i++) {
        printf("| %s | %.2lf |\n", categories[i].name, categories[i].total);
    }
    printf("--------------------\n");
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    struct category categories[MAX_CATEGORIES];
    int num_categories = 0;

    char category[50];
    printf("Enter category name: ");
    scanf("%s", category);
    add_category(categories, &num_categories, category);

    while (1) {
        printf("\n1. Add expense\n2. Display expenses\n3. Display categories\n4. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense(expenses, &num_expenses, category);
                break;
            case 2:
                display_expenses(expenses, num_expenses);
                break;
            case 3:
                display_categories(categories, num_categories);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}