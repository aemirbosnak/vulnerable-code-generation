//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 1000
#define MAX_CATEGORIES 100

struct expense {
    char category[50];
    double amount;
    char date[20];
};

struct category {
    char name[50];
    double total_expense;
};

void add_expense(struct expense expenses[], int *num_expenses) {
    printf("Enter the category: ");
    scanf("%s", expenses[*num_expenses].category);

    printf("Enter the amount: ");
    scanf("%lf", &expenses[*num_expenses].amount);

    printf("Enter the date (DD/MM/YYYY): ");
    scanf("%s", expenses[*num_expenses].date);

    (*num_expenses)++;
}

void display_expenses(struct expense expenses[], int num_expenses) {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("Category: %s\nAmount: %.2lf\nDate: %s\n\n", expenses[i].category, expenses[i].amount, expenses[i].date);
    }
}

void calculate_total_expense(struct expense expenses[], int num_expenses, struct category categories[], int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        categories[i].total_expense = 0;
    }

    for (int i = 0; i < num_expenses; i++) {
        for (int j = 0; j < num_categories; j++) {
            if (strcmp(expenses[i].category, categories[j].name) == 0) {
                categories[j].total_expense += expenses[i].amount;
                break;
            }
        }
    }
}

void display_categories(struct category categories[], int num_categories) {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("Category: %s\nTotal Expense: %.2lf\n\n", categories[i].name, categories[i].total_expense);
    }
}

int main() {
    struct expense expenses[MAX_EXPENSES];
    int num_expenses = 0;

    struct category categories[MAX_CATEGORIES];
    int num_categories = 0;

    while (1) {
        printf("\nEnter 1 to add expense\nEnter 2 to display expenses\nEnter 3 to display categories\nEnter 4 to exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (num_expenses >= MAX_EXPENSES) {
                printf("Maximum number of expenses reached.\n");
            } else {
                add_expense(expenses, &num_expenses);
            }
            break;

        case 2:
            if (num_expenses == 0) {
                printf("No expenses added yet.\n");
            } else {
                display_expenses(expenses, num_expenses);
            }
            break;

        case 3:
            if (num_categories == 0) {
                printf("No categories added yet.\n");
            } else {
                calculate_total_expense(expenses, num_expenses, categories, num_categories);
                display_categories(categories, num_categories);
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