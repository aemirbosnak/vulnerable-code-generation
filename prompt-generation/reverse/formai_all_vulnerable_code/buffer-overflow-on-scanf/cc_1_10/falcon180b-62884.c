//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BUDGET_ITEMS 50
#define MAX_BUDGET_NAME_LENGTH 50
#define MAX_BUDGET_AMOUNT_LENGTH 10

typedef struct {
    char name[MAX_BUDGET_NAME_LENGTH];
    char amount[MAX_BUDGET_AMOUNT_LENGTH];
} budget_item_t;

void add_budget_item(budget_item_t *items, int count, char *name, char *amount) {
    if (count >= MAX_BUDGET_ITEMS) {
        printf("Error: Maximum number of budget items reached.\n");
        return;
    }

    strcpy(items[count].name, name);
    strcpy(items[count].amount, amount);

    count++;
}

void display_budget_items(budget_item_t *items, int count) {
    printf("Budget Items:\n");

    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", items[i].name);
        printf("Amount: %s\n\n", items[i].amount);
    }
}

int main() {
    budget_item_t budget_items[MAX_BUDGET_ITEMS];
    int budget_count = 0;

    char name[MAX_BUDGET_NAME_LENGTH];
    char amount[MAX_BUDGET_AMOUNT_LENGTH];

    printf("Enter budget item name (blank to finish): ");
    scanf("%s", name);

    while (strcmp(name, "")!= 0) {
        printf("Enter budget item amount: ");
        scanf("%s", amount);

        add_budget_item(budget_items, budget_count, name, amount);

        printf("Enter budget item name (blank to finish): ");
        scanf("%s", name);
    }

    display_budget_items(budget_items, budget_count);

    return 0;
}