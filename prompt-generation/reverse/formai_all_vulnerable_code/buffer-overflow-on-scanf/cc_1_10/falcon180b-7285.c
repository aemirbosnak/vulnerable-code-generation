//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    double amount;
    char category[MAX_NAME_LENGTH];
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
int num_categories = 0;

void add_category() {
    char input[MAX_NAME_LENGTH];
    printf("Enter category name: ");
    scanf("%s", input);
    strcpy(categories[num_categories], input);
    num_categories++;
}

void add_expense() {
    char input[MAX_NAME_LENGTH];
    printf("Enter expense name: ");
    scanf("%s", input);
    strcpy(expenses[num_expenses].name, input);

    printf("Enter expense amount: ");
    scanf("%lf", &expenses[num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%s", input);
    strcpy(expenses[num_expenses].category, input);

    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s - %.2lf - %s\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

void view_categories() {
    printf("\nCategories:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s\n", categories[i]);
    }
}

int main() {
    printf("Welcome to the Expense Tracker!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Add category\n");
        printf("4. View categories\n");
        printf("5. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_expense();
            break;
        case 2:
            view_expenses();
            break;
        case 3:
            add_category();
            break;
        case 4:
            view_categories();
            break;
        case 5:
            printf("Goodbye!\n");
            return 0;
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}