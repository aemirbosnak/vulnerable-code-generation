//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 10
#define MAX_EXPENSES 100
#define MAX_NAME_LENGTH 50
#define MAX_DESCRIPTION_LENGTH 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    int category;
} Expense;

Expense expenses[MAX_EXPENSES];
int num_expenses = 0;

char categories[MAX_CATEGORIES][MAX_NAME_LENGTH];
int num_categories = 0;

void add_expense() {
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    float amount;
    int category;

    printf("Enter expense name: ");
    scanf("%s", name);

    printf("Enter expense description: ");
    scanf("%s", description);

    printf("Enter expense amount: ");
    scanf("%f", &amount);

    printf("Enter expense category (1-%d): ", num_categories);
    scanf("%d", &category);

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].description, description);
    expenses[num_expenses].amount = amount;
    expenses[num_expenses].category = category;

    num_expenses++;
}

void view_expenses() {
    printf("Expense Report\n");
    printf("=================\n");
    printf("Category\tExpense Name\tDescription\tAmount\n");

    for (int i = 0; i < num_expenses; i++) {
        printf("%d\t%s\t%s\t%f\n", expenses[i].category, expenses[i].name, expenses[i].description, expenses[i].amount);
    }
}

void add_category() {
    char name[MAX_NAME_LENGTH];

    printf("Enter category name: ");
    scanf("%s", name);

    strcpy(categories[num_categories], name);
    num_categories++;
}

int main() {
    char choice;

    do {
        printf("Expense Tracker\n");
        printf("===============\n");
        printf("1. Add expense\n");
        printf("2. View expenses\n");
        printf("3. Add category\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%c", &choice);

        switch (choice) {
            case '1':
                add_expense();
                break;
            case '2':
                view_expenses();
                break;
            case '3':
                add_category();
                break;
            case '4':
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice!= '4');

    return 0;
}