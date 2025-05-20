//MISTRAL-7B DATASET v1.0 Category: Personal Finance Planner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    float amount;
    int type; // 1 for income, -1 for expense
} Item;

Item items[MAX_ITEMS];
int num_items = 0;

void add_item(char *name, float amount, int type) {
    if (num_items >= MAX_ITEMS) {
        printf("Error: Cannot add item. Maximum items reached.\n");
        return;
    }

    strcpy(items[num_items].name, name);
    items[num_items].amount = amount;
    items[num_items].type = type;

    num_items++;
}

void print_summary() {
    float total_income = 0, total_expense = 0;

    printf("\nCurrent Financial Situation:\n");
    printf("-----------------------------\n");

    for (int i = 0; i < num_items; i++) {
        printf("%s: %.2f\n", items[i].name, items[i].amount * (items[i].type > 0 ? 1 : -1));

        if (items[i].type > 0)
            total_income += items[i].amount;
        else
            total_expense += items[i].amount;
    }

    printf("\nTotal Income: %.2f\n", total_income);
    printf("Total Expense: %.2f\n", total_expense);
    printf("Current Balance: %.2f\n", total_income - total_expense);
}

int main() {
    char name[50];
    float amount;
    int type;

    while (1) {
        printf("\nPersonal Finance Planner\n");
        printf("--------------------------\n");
        printf("1. Add income\n");
        printf("2. Add expense\n");
        printf("3. View summary\n");
        printf("4. Exit\n");

        scanf("%d", &type);

        if (type == 1) {
            printf("Enter income name: ");
            scanf("%s", name);
            printf("Enter income amount: ");
            scanf("%f", &amount);

            add_item(name, amount, 1);
        } else if (type == 2) {
            printf("Enter expense name: ");
            scanf("%s", name);
            printf("Enter expense amount: ");
            scanf("%f", &amount);

            add_item(name, amount, -1);
        } else if (type == 3) {
            print_summary();
        } else if (type != 4) {
            printf("Invalid option. Please try again.\n");
        } else {
            break;
        }
    }

    return 0;
}