//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    int expenses[MAX_EXPENSES];
    int num_expenses;
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
    if (categories[category_index].num_expenses == MAX_EXPENSES) {
        printf("Category '%s' is full.\n", categories[category_index].name);
        return;
    }
    printf("Enter expense name: ");
    scanf("%s", categories[category_index].expenses[categories[category_index].num_expenses]);
    categories[category_index].num_expenses++;
}

void view_expenses(int category_index) {
    printf("Expenses for category '%s':\n", categories[category_index].name);
    for (int i = 0; i < categories[category_index].num_expenses; i++) {
        printf("%s\n", categories[category_index].expenses[i]);
    }
}

int main() {
    int choice;
    int category_index;
    do {
        printf("\nExpense Tracker\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. View expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                printf("Enter category index: ");
                scanf("%d", &category_index);
                if (category_index >= num_categories) {
                    printf("Invalid category index.\n");
                } else {
                    add_expense(category_index);
                }
                break;
            case 3:
                printf("Enter category index: ");
                scanf("%d", &category_index);
                if (category_index >= num_categories) {
                    printf("Invalid category index.\n");
                } else {
                    view_expenses(category_index);
                }
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);
    return 0;
}