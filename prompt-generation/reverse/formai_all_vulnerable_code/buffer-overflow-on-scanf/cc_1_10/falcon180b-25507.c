//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100

typedef struct {
    char name[50];
    float amount;
    int category;
} expense;

expense expenses[MAX_EXPENSES];
char categories[MAX_CATEGORIES][50];
int num_categories;
int num_expenses;

void add_category() {
    printf("Enter category name: ");
    scanf("%s", categories[num_categories]);
    num_categories++;
}

void add_expense() {
    printf("Enter expense name: ");
    scanf("%s", expenses[num_expenses].name);
    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);
    printf("Enter expense category (0-%d): ", num_categories-1);
    scanf("%d", &expenses[num_expenses].category);
    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - $%.2f - %s\n", expenses[i].name, expenses[i].amount, categories[expenses[i].category]);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");
    num_categories = 0;
    add_category();
    num_expenses = 0;
    add_expense();

    int choice;
    do {
        printf("\nChoose an option:\n1. Add category\n2. Add expense\n3. View expenses\n4. Quit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_category();
                break;
            case 2:
                add_expense();
                break;
            case 3:
                view_expenses();
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 4);

    return 0;
}