//Falcon-180B DATASET v1.0 Category: Data mining ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 1000
#define MAX_CATEGORIES 10
#define MAX_NAME_LENGTH 100
#define MAX_CATEGORY_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int category;
} item;

typedef struct {
    char name[MAX_CATEGORY_LENGTH];
    int count;
} category;

void read_items(item *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("Enter item %d name: ", i+1);
        scanf("%s", items[i].name);
        printf("Enter item %d category (0-9): ", i+1);
        scanf("%d", &items[i].category);
    }
}

void read_categories(category *categories, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        printf("Enter category %d name: ", i+1);
        scanf("%s", categories[i].name);
    }
}

void count_categories(item *items, category *categories, int num_categories, int num_items) {
    for (int i = 0; i < num_items; i++) {
        int category_index = items[i].category % num_categories;
        categories[category_index].count++;
    }
}

void print_categories(category *categories, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        printf("%s: %d\n", categories[i].name, categories[i].count);
    }
}

int main() {
    item items[MAX_ITEMS];
    category categories[MAX_CATEGORIES];

    int num_items, num_categories;

    printf("Enter number of items: ");
    scanf("%d", &num_items);

    printf("Enter number of categories: ");
    scanf("%d", &num_categories);

    read_items(items, num_items);
    read_categories(categories, num_categories);

    count_categories(items, categories, num_categories, num_items);

    printf("\nData Mining Results:\n");
    printf("=====================\n");
    print_categories(categories, num_categories);

    return 0;
}