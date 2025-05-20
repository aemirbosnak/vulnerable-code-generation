//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[30];
    double amount;
} expense;

typedef struct {
    char name[30];
    int num_expenses;
    expense expenses[MAX_EXPENSES];
} category;

category categories[MAX_CATEGORIES];
int num_categories;

void add_category() {
    num_categories++;
    printf("Enter category name: ");
    scanf("%s", categories[num_categories-1].name);
    categories[num_categories-1].num_expenses = 0;
}

void add_expense(int category_index) {
    categories[category_index].num_expenses++;
    printf("Enter expense name: ");
    scanf("%s", categories[category_index].expenses[categories[category_index].num_expenses-1].name);
    printf("Enter expense amount: ");
    scanf("%lf", &categories[category_index].expenses[categories[category_index].num_expenses-1].amount);
}

void print_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i].name);
    }
}

void print_expenses(int category_index) {
    printf("\nExpenses for %s:\n", categories[category_index].name);
    for (int i = 0; i < categories[category_index].num_expenses; i++) {
        printf("%s: $%.2lf\n", categories[category_index].expenses[i].name, categories[category_index].expenses[i].amount);
    }
}

void print_total_expenses(int category_index) {
    double total_expenses = 0.0;
    for (int i = 0; i < categories[category_index].num_expenses; i++) {
        total_expenses += categories[category_index].expenses[i].amount;
    }
    printf("\nTotal expenses for %s: $%.2lf\n", categories[category_index].name, total_expenses);
}

int main() {
    num_categories = 0;
    categories[num_categories].name[0] = '\0';
    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. Print categories\n");
        printf("4. Print expenses\n");
        printf("5. Print total expenses\n");
        printf("6. Quit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                printf("Enter category index: ");
                scanf("%d", &num_categories);
                add_expense(num_categories-1);
                break;
            case 3:
                print_categories();
                break;
            case 4:
                printf("Enter category index: ");
                scanf("%d", &num_categories);
                print_expenses(num_categories-1);
                break;
            case 5:
                printf("Enter category index: ");
                scanf("%d", &num_categories);
                print_total_expenses(num_categories-1);
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}