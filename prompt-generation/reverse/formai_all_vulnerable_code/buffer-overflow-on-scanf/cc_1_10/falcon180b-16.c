//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: artistic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORIES 20
#define MAX_ITEMS 100
#define MAX_CATEGORY_LENGTH 20
#define MAX_ITEM_LENGTH 50

typedef struct {
    char category[MAX_CATEGORY_LENGTH];
    int num_items;
    float total_cost;
} category_t;

typedef struct {
    char name[MAX_ITEM_LENGTH];
    int category_index;
    float cost;
} item_t;

int main() {
    int num_categories, num_items;
    category_t categories[MAX_CATEGORIES];
    item_t items[MAX_ITEMS];

    printf("Enter the number of categories: ");
    scanf("%d", &num_categories);

    for (int i = 0; i < num_categories; i++) {
        printf("Enter category %d: ", i+1);
        scanf("%s", categories[i].category);
        categories[i].num_items = 0;
        categories[i].total_cost = 0;
    }

    printf("Enter the number of items: ");
    scanf("%d", &num_items);

    for (int i = 0; i < num_items; i++) {
        printf("Enter item %d: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter category: ");
        char category_name[MAX_CATEGORY_LENGTH];
        scanf("%s", category_name);
        int category_index = -1;
        for (int j = 0; j < num_categories; j++) {
            if (strcmp(category_name, categories[j].category) == 0) {
                category_index = j;
                break;
            }
        }
        if (category_index == -1) {
            printf("Category not found\n");
            i--;
            continue;
        }
        items[i].category_index = category_index;
        printf("Enter cost: ");
        scanf("%f", &items[i].cost);
        categories[category_index].num_items++;
        categories[category_index].total_cost += items[i].cost;
    }

    printf("Expense Tracker\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: $%.2f (%d items)\n", categories[i].category, categories[i].total_cost, categories[i].num_items);
    }

    return 0;
}