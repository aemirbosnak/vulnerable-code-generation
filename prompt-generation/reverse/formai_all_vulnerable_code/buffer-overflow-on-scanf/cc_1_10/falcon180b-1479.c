//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 50
#define MAX_CATEGORY_NAME_LENGTH 50
#define MAX_ITEM_NAME_LENGTH 100
#define MAX_ITEM_QUANTITY_LENGTH 10
#define MAX_ITEM_PRICE_LENGTH 10

typedef struct {
    char name[MAX_ITEM_NAME_LENGTH];
    char category[MAX_CATEGORY_NAME_LENGTH];
    char quantity[MAX_ITEM_QUANTITY_LENGTH];
    char price[MAX_ITEM_PRICE_LENGTH];
    float total_cost;
} item;

typedef struct {
    char name[MAX_CATEGORY_NAME_LENGTH];
    int num_items;
    float total_cost;
} category;

int main() {
    int num_categories, num_items;
    category categories[MAX_CATEGORIES];
    item items[MAX_ITEMS];
    char input[MAX_ITEM_NAME_LENGTH];
    int i, j, k;

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i+1);
        scanf("%s", categories[i].name);
        categories[i].num_items = 0;
        categories[i].total_cost = 0.0;
    }

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter the category of item %d: ", i+1);
        scanf("%s", items[i].category);
        printf("Enter the quantity of item %d: ", i+1);
        scanf("%s", items[i].quantity);
        printf("Enter the price of item %d: ", i+1);
        scanf("%s", items[i].price);
        items[i].total_cost = atof(items[i].price) * atoi(items[i].quantity);
        for (j = 0; j < num_categories; j++) {
            if (strcmp(items[i].category, categories[j].name) == 0) {
                categories[j].num_items++;
                categories[j].total_cost += items[i].total_cost;
                break;
            }
        }
    }

    printf("\n");
    for (i = 0; i < num_categories; i++) {
        printf("Category %s:\n", categories[i].name);
        printf("Number of items: %d\n", categories[i].num_items);
        printf("Total cost: $%.2f\n\n", categories[i].total_cost);
        for (j = 0; j < num_items; j++) {
            if (strcmp(items[j].category, categories[i].name) == 0) {
                printf("Item %s: $%.2f\n", items[j].name, items[j].total_cost);
            }
        }
    }

    return 0;
}