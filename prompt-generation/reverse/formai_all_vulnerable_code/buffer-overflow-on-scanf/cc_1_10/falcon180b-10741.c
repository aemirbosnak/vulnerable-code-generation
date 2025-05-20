//Falcon-180B DATASET v1.0 Category: Data mining ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 10

typedef struct {
    char name[50];
    int quantity;
} item;

typedef struct {
    char name[50];
    int num_items;
} category;

int main() {
    int num_items, num_categories;
    category categories[MAX_CATEGORIES];
    item items[MAX_ITEMS];

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        printf("Enter the name and quantity of item %d: ", i+1);
        scanf("%s %d", items[i].name, &items[i].quantity);
    }

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter the name of category %d: ", i+1);
        scanf("%s", categories[i].name);
    }

    printf("Enter the category for each item:\n");
    for (int i = 0; i < num_items; i++) {
        int category_index;
        printf("Item %s: ", items[i].name);
        scanf("%d", &category_index);
        categories[category_index-1].num_items++;
    }

    printf("Category summary:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d items\n", categories[i].name, categories[i].num_items);
    }

    return 0;
}