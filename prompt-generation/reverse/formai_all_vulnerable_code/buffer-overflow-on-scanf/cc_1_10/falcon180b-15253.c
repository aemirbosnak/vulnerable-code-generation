//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    float amount;
    int category;
} Expense;

Expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][50];
int num_expenses = 0;
int num_categories = 0;

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense category (0-9): ");
    scanf("%d", &expenses[num_expenses].category);
    num_expenses++;
}

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);
    num_categories++;
}

void display_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f (Category: %d)\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void display_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    add_category();
    add_category();
    add_category();
    add_category();
    add_category();
    add_category();
    add_category();
    add_category();
    add_category();

    int choice;
    while (1) {
        printf("\n1. Add expense\n2. Display expenses\n3. Display categories\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                display_expenses();
                break;
            case 3:
                display_categories();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}