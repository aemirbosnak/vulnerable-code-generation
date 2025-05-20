//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 20
#define MAX_ITEMS 100
#define MAX_CATEGORY_NAME 20
#define MAX_ITEM_NAME 50

typedef struct {
    char name[MAX_CATEGORY_NAME];
    int count;
} category;

typedef struct {
    char name[MAX_ITEM_NAME];
    float price;
    int category_index;
} item;

int main() {
    int num_categories, num_items, i, j;
    category categories[MAX_CATEGORIES];
    item items[MAX_ITEMS];

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i + 1);
        scanf("%s", categories[i].name);
        categories[i].count = 0;
    }

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (i = 0; i < num_items; i++) {
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);
        printf("Enter the price of item %d: ", i + 1);
        scanf("%f", &items[i].price);
        printf("Enter the category index of item %d (1-%d): ", i + 1, num_categories);
        scanf("%d", &items[i].category_index);
        categories[items[i].category_index - 1].count++;
    }

    for (i = 0; i < num_categories; i++) {
        printf("Category %d has %d item(s)\n", i + 1, categories[i].count);
    }

    return 0;
}