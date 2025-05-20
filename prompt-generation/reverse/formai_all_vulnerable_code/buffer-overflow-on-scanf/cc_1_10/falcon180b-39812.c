//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUDGET_ITEMS 50
#define MAX_ITEM_NAME_LENGTH 50
#define MAX_ITEM_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    char amount[MAX_ITEM_AMOUNT_LENGTH];
} budget_item_t;

typedef struct {
    budget_item_t items[MAX_BUDGET_ITEMS];
    int num_items;
} budget_t;

void add_item(budget_t* budget) {
    char name[MAX_ITEM_NAME_LENGTH];
    char amount[MAX_ITEM_AMOUNT_LENGTH];

    printf("Enter item name: ");
    scanf("%s", name);

    printf("Enter item amount: ");
    scanf("%s", amount);

    strcpy(budget->items[budget->num_items].name, name);
    strcpy(budget->items[budget->num_items].amount, amount);

    budget->num_items++;
}

void print_budget(budget_t* budget) {
    printf("Budget:\n");
    for (int i = 0; i < budget->num_items; i++) {
        printf("%s - $%s\n", budget->items[i].name, budget->items[i].amount);
    }
}

int main() {
    budget_t budget;
    budget.num_items = 0;

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add item\n");
        printf("2. Print budget\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_item(&budget);
            break;
        case 2:
            print_budget(&budget);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }

    return 0;
}