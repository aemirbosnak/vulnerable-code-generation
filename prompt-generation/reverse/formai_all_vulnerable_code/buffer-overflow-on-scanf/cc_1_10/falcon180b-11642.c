//Falcon-180B DATASET v1.0 Category: Data mining ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 100
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    int count;
} Category;

typedef struct {
    char name[MAX_CATEGORY_LENGTH];
    int index;
} Item;

int main() {
    int num_items, num_categories;
    char input[100];
    Item items[MAX_ITEMS];
    Category categories[MAX_CATEGORIES];

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    printf("Enter number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter category %d: ", i+1);
        scanf("%s", categories[i].category);
        categories[i].count = 0;
    }

    for (int i = 0; i < num_items; i++) {
        printf("Enter item %d: ", i+1);
        scanf("%s", items[i].name);
        items[i].index = i;
    }

    for (int i = 0; i < num_items; i++) {
        printf("Enter category for item %s: ", items[i].name);
        scanf("%s", input);
        int category_index = -1;
        for (int j = 0; j < num_categories; j++) {
            if (strcmp(categories[j].category, input) == 0) {
                category_index = j;
                break;
            }
        }
        if (category_index == -1) {
            printf("Category not found.\n");
            continue;
        }
        categories[category_index].count++;
    }

    for (int i = 0; i < num_categories; i++) {
        printf("Category %s: %d items\n", categories[i].category, categories[i].count);
    }

    return 0;
}