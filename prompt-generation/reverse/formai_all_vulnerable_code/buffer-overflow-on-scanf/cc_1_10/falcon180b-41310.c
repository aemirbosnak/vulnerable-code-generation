//Falcon-180B DATASET v1.0 Category: Expense Tracker ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CATEGORIES 100
#define MAX_ITEMS 1000
#define MAX_NAME_LENGTH 50
#define MAX_PRICE_LENGTH 10

typedef struct {
    char name[MAX_NAME_LENGTH];
    char category[MAX_NAME_LENGTH];
    char price[MAX_PRICE_LENGTH];
} Item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int count;
} Category;

int main() {
    int num_categories, num_items;
    Category categories[MAX_CATEGORIES];
    Item items[MAX_ITEMS];

    printf("Enter number of categories: ");
    scanf("%d", &num_categories);

    printf("Enter categories:\n");
    for (int i = 0; i < num_categories; i++) {
        scanf("%s", categories[i].name);
        categories[i].count = 0;
    }

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    printf("Enter items:\n");
    for (int i = 0; i < num_items; i++) {
        scanf("%s %s %s", items[i].name, items[i].category, items[i].price);
        int category_index = -1;
        for (int j = 0; j < num_categories; j++) {
            if (strcmp(items[i].category, categories[j].name) == 0) {
                category_index = j;
                break;
            }
        }
        if (category_index == -1) {
            printf("Invalid category: %s\n", items[i].category);
            exit(1);
        }
        categories[category_index].count++;
    }

    printf("Expense tracker:\n");
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d items, $%.2f total\n", categories[i].name, categories[i].count, 0.0);
    }

    return 0;
}