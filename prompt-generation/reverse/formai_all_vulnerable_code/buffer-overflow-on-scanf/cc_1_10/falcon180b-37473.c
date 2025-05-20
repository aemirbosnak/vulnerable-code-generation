//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_BUDGET_CATEGORIES 50
#define MAX_BUDGET_ITEMS 100

typedef struct {
    char name[50];
    double amount;
} budget_item_t;

typedef struct {
    char name[50];
    int num_items;
    budget_item_t items[MAX_BUDGET_ITEMS];
} budget_category_t;

int main() {
    int num_categories;
    budget_category_t categories[MAX_BUDGET_CATEGORIES];
    int i, j;

    printf("Enter number of budget categories: ");
    scanf("%d", &num_categories);

    for (i = 0; i < num_categories; i++) {
        printf("Enter name of budget category %d: ", i+1);
        scanf("%s", categories[i].name);
        categories[i].num_items = 0;
    }

    int total_items = 0;

    while (total_items < MAX_BUDGET_ITEMS) {
        printf("Enter budget item (enter 'done' when finished): ");
        scanf("%s", categories[0].items[total_items].name);

        if (strcmp(categories[0].items[total_items].name, "done") == 0) {
            break;
        }

        printf("Enter amount for %s: ", categories[0].items[total_items].name);
        scanf("%lf", &categories[0].items[total_items].amount);

        total_items++;
    }

    for (i = 0; i < num_categories; i++) {
        printf("Category: %s\n", categories[i].name);
        for (j = 0; j < categories[i].num_items; j++) {
            printf("\t%s: $%.2f\n", categories[i].items[j].name, categories[i].items[j].amount);
        }
        printf("\n");
    }

    return 0;
}