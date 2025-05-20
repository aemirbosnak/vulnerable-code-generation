//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPENSES 100
#define MAX_CATEGORIES 10
#define MAX_NAME_LENGTH 50
#define MAX_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];
} expense;

expense expenses[MAX_EXPENSES];
int num_expenses = 0;

void add_expense() {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    char amount[MAX_AMOUNT_LENGTH];

    printf("Enter the name of the expense: ");
    scanf("%s", name);

    printf("Enter the category of the expense: ");
    scanf("%s", category);

    printf("Enter the amount of the expense: ");
    scanf("%s", amount);

    strcpy(expenses[num_expenses].name, name);
    strcpy(expenses[num_expenses].category, category);
    strcpy(expenses[num_expenses].amount, amount);

    num_expenses++;
}

void view_expenses() {
    printf("Name\tCategory\tAmount\n");
    for (int i = 0; i < num_expenses; i++) {
        printf("%s\t%s\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
    }
}

void view_expenses_by_category(char category[MAX_NAME_LENGTH]) {
    printf("Name\tCategory\tAmount\n");
    for (int i = 0; i < num_expenses; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("%s\t%s\t%s\n", expenses[i].name, expenses[i].category, expenses[i].amount);
        }
    }
}

int main() {
    int choice;
    char category[MAX_NAME_LENGTH];

    while (1) {
        printf("1. Add Expense\n2. View Expenses\n3. View Expenses by Category\n4. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_expense();
                break;
            case 2:
                view_expenses();
                break;
            case 3:
                printf("Enter the category to view expenses by: ");
                scanf("%s", category);
                view_expenses_by_category(category);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}