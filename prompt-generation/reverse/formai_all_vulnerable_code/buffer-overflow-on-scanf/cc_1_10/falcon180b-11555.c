//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
} expense_t;

typedef struct {
    char name[50];
    int num_expenses;
    expense_t expenses[MAX_EXPENSES];
} category_t;

void add_expense(category_t* category, expense_t expense) {
    category->expenses[category->num_expenses++] = expense;
}

void print_expenses(category_t* category) {
    printf("Category: %s\n", category->name);
    for (int i = 0; i < category->num_expenses; i++) {
        printf("Expense %d: %s - $%.2f\n", i+1, category->expenses[i].name, category->expenses[i].amount);
    }
}

void main() {
    category_t categories[MAX_CATEGORIES];
    int num_categories = 0;

    while (num_categories < MAX_CATEGORIES) {
        printf("Enter category name: ");
        scanf("%s", categories[num_categories].name);
        categories[num_categories].num_expenses = 0;
        num_categories++;
    }

    int category_index = 0;
    while (1) {
        printf("\nSelect an option:\n");
        printf("1. Add expense\n");
        printf("2. View expenses by category\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter category name: ");
            scanf("%s", categories[category_index].name);

            float amount;
            printf("Enter expense amount: $");
            scanf("%f", &amount);

            char expense_name[50];
            printf("Enter expense name: ");
            scanf("%s", expense_name);

            add_expense(&categories[category_index], (expense_t) {.name = expense_name,.amount = amount});
            break;

        case 2:
            printf("Select category:\n");
            for (int i = 0; i < num_categories; i++) {
                printf("%d. %s\n", i+1, categories[i].name);
            }

            int category_choice;
            scanf("%d", &category_choice);

            print_expenses(&categories[category_choice - 1]);
            break;

        case 3:
            exit(0);

        default:
            printf("Invalid choice.\n");
        }
    }
}