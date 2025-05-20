//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 20

typedef struct {
    char name[50];
    int item_count;
    double total_cost;
} Category;

typedef struct {
    char name[50];
    int category_id;
    double cost;
    int quantity;
} Item;

int main() {
    int num_categories, num_items;
    Category categories[MAX_CATEGORIES];
    Item items[MAX_ITEMS];

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", categories[i].name);
        categories[i].item_count = 0;
        categories[i].total_cost = 0.0;
    }

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter the category ID: ");
        scanf("%d", &items[i].category_id);
        printf("Enter the cost per unit: ");
        scanf("%lf", &items[i].cost);
        printf("Enter the quantity: ");
        scanf("%d", &items[i].quantity);
    }

    double total_cost = 0.0;

    for (int i = 0; i < num_categories; i++) {
        printf("Category %s:\n", categories[i].name);
        for (int j = 0; j < num_items; j++) {
            if (categories[i].item_count == 0 || items[j].category_id!= i + 1)
                continue;
            printf("  %s - %.2lf x %.2lf = %.2lf\n", items[j].name, items[j].quantity, items[j].cost, items[j].quantity * items[j].cost);
            total_cost += items[j].quantity * items[j].cost;
            categories[i].item_count++;
        }
        printf("Total cost for this category: %.2lf\n\n", total_cost);
        total_cost = 0.0;
    }

    return 0;
}