//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ITEMS 1000
#define MAX_NAME_LEN 50
#define MAX_CATEGORY_LEN 50
#define MAX_DESCRIPTION_LEN 100
#define MAX_AMOUNT_LEN 10

typedef struct {
    char name[MAX_NAME_LEN];
    char category[MAX_CATEGORY_LEN];
    char description[MAX_DESCRIPTION_LEN];
    char amount[MAX_AMOUNT_LEN];
} item_t;

typedef struct {
    int num_items;
    item_t items[MAX_ITEMS];
} budget_t;

void add_item(budget_t* budget) {
    if (budget->num_items >= MAX_ITEMS) {
        printf("Error: Budget is full.\n");
        return;
    }

    item_t new_item;
    printf("Enter item name: ");
    scanf("%s", new_item.name);

    printf("Enter item category: ");
    scanf("%s", new_item.category);

    printf("Enter item description: ");
    scanf("%s", new_item.description);

    printf("Enter item amount: ");
    scanf("%s", new_item.amount);

    budget->items[budget->num_items] = new_item;
    budget->num_items++;
}

void display_items(budget_t* budget) {
    printf("Budget:\n");
    for (int i = 0; i < budget->num_items; i++) {
        printf("%s - %s - %s - %s\n", budget->items[i].name, budget->items[i].category, budget->items[i].description, budget->items[i].amount);
    }
}

int main() {
    budget_t budget;
    budget.num_items = 0;

    while (1) {
        printf("\n1. Add item\n2. Display budget\n3. Exit\n");
        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(&budget);
                break;
            case 2:
                display_items(&budget);
                break;
            case 3:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}