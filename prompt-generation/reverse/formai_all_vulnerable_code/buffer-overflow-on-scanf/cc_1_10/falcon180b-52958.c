//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
} Expense;

typedef struct {
    char name[50];
    int num_expenses;
    Expense expenses[MAX_ITEMS];
} Category;

void add_expense(Category* category, Expense* expense) {
    category->num_expenses++;
    category->expenses[category->num_expenses - 1] = *expense;
}

void print_category(Category* category) {
    printf("Category: %s\n", category->name);
    printf("Number of expenses: %d\n", category->num_expenses);
    printf("Expenses:\n");
    for (int i = 0; i < category->num_expenses; i++) {
        printf("Name: %s\n", category->expenses[i].name);
        printf("Amount: $%.2f\n\n", category->expenses[i].amount);
    }
}

void print_categories(Category* categories, int num_categories) {
    printf("Categories:\n");
    for (int i = 0; i < num_categories; i++) {
        print_category(&categories[i]);
    }
}

int main() {
    Category categories[MAX_CATEGORIES];
    int num_categories = 0;
    char choice;

    do {
        printf("Expense Tracker\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. Print categories\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
        case '1':
            printf("Enter category name: ");
            scanf("%s", categories[num_categories].name);
            num_categories++;
            break;
        case '2':
            printf("Enter category name: ");
            scanf("%s", categories[num_categories].name);
            num_categories++;

            printf("Enter expense name: ");
            scanf("%s", categories[num_categories].expenses[0].name);
            printf("Enter expense amount: $");
            scanf("%f", &categories[num_categories].expenses[0].amount);

            num_categories++;
            break;
        case '3':
            print_categories(categories, num_categories);
            break;
        case '4':
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    } while (1);

    return 0;
}