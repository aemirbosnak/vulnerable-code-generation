//Falcon-180B DATASET v1.0 Category: Personal Finance Planner ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10
#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} item;

typedef struct {
    char name[MAX_NAME_LENGTH];
    int id;
} category;

void add_item(item *items, int *num_items, category *categories, int *num_categories) {
    char input[MAX_NAME_LENGTH];
    int id;
    printf("Enter item name: ");
    scanf("%s", input);
    strcpy(items[*num_items].name, input);
    printf("Enter item ID: ");
    scanf("%d", &id);
    items[*num_items].id = id;
    (*num_items)++;
}

void add_category(category *categories, int *num_categories) {
    char input[MAX_NAME_LENGTH];
    int id;
    printf("Enter category name: ");
    scanf("%s", input);
    strcpy(categories[*num_categories].name, input);
    printf("Enter category ID: ");
    scanf("%d", &id);
    categories[*num_categories].id = id;
    (*num_categories)++;
}

void print_items(item *items, int num_items, category *categories, int num_categories) {
    for (int i = 0; i < num_items; i++) {
        printf("Item: %s (%d)\n", items[i].name, items[i].id);
    }
}

void print_categories(category *categories, int num_categories) {
    for (int i = 0; i < num_categories; i++) {
        printf("Category: %s (%d)\n", categories[i].name, categories[i].id);
    }
}

int main() {
    item items[MAX_ITEMS];
    int num_items = 0;
    category categories[MAX_CATEGORIES];
    int num_categories = 0;

    add_category(categories, &num_categories);
    add_item(items, &num_items, categories, &num_categories);
    print_items(items, num_items, categories, num_categories);
    print_categories(categories, num_categories);

    return 0;
}