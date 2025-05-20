//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 10
#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    char category[50];
} expense_t;

expense_t expenses[MAX_ITEMS];
char categories[MAX_CATEGORIES][50];
int num_categories;
int num_expenses;

void add_category() {
    char input[50];
    printf("Enter category name: ");
    scanf("%s", input);
    strcpy(categories[num_categories], input);
    num_categories++;
}

void add_expense() {
    char input[50];
    printf("Enter expense name: ");
    scanf("%s", input);
    strcpy(expenses[num_expenses].name, input);

    printf("Enter expense amount: ");
    scanf("%f", &expenses[num_expenses].amount);

    printf("Enter expense category: ");
    scanf("%s", input);

    int i;
    for (i = 0; i < num_categories; i++) {
        if (strcmp(input, categories[i]) == 0) {
            strcpy(expenses[num_expenses].category, input);
            break;
        }
    }

    num_expenses++;
}

void view_expenses() {
    printf("\nExpenses:\n");
    printf("----------------------------------------------------\n");
    printf("| Name        | Amount ($) | Category       |\n");
    printf("----------------------------------------------------\n");

    int i;
    for (i = 0; i < num_expenses; i++) {
        printf("| %-20s | %10.2f | %-20s |\n", expenses[i].name, expenses[i].amount, expenses[i].category);
    }
}

int main() {
    int choice;

    printf("Welcome to the Expense Tracker!\n");
    printf("----------------------------------------------------\n");

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add category\n");
        printf("2. Add expense\n");
        printf("3. View expenses\n");
        printf("4. Exit\n");
        printf("----------------------------------------------------\n");

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
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}