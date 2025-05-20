//Falcon-180B DATASET v1.0 Category: Data mining ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define MAX_CATEGORIES 10
#define MAX_ITEMS_PER_CATEGORY 10

typedef struct {
    char name[100];
    int quantity;
} Item;

typedef struct {
    char name[100];
    int num_items;
    Item items[MAX_ITEMS_PER_CATEGORY];
} Category;

typedef struct {
    char name[100];
    int num_categories;
    Category categories[MAX_CATEGORIES];
} Store;

void read_items(Item items[], int num_items) {
    printf("Enter %d items:\n", num_items);
    for (int i = 0; i < num_items; i++) {
        printf("Item %d: ", i+1);
        scanf("%s %d", items[i].name, &items[i].quantity);
    }
}

void read_categories(Category categories[], int num_categories) {
    printf("Enter %d categories:\n", num_categories);
    for (int i = 0; i < num_categories; i++) {
        printf("Category %d: ", i+1);
        scanf("%s", categories[i].name);
        categories[i].num_items = 0;
    }
}

void add_item_to_category(Category* category, Item item) {
    if (category->num_items >= MAX_ITEMS_PER_CATEGORY) {
        printf("Category is full!\n");
        return;
    }
    strcpy(category->items[category->num_items].name, item.name);
    category->items[category->num_items].quantity = item.quantity;
    category->num_items++;
}

void read_store(Store* store) {
    printf("Enter store name:\n");
    scanf("%s", store->name);
    printf("Enter number of categories:\n");
    scanf("%d", &store->num_categories);
    printf("Enter categories:\n");
    read_categories(store->categories, store->num_categories);
}

void print_store(Store store) {
    printf("Store: %s\n", store.name);
    printf("Categories:\n");
    for (int i = 0; i < store.num_categories; i++) {
        printf("Category %s:\n", store.categories[i].name);
        for (int j = 0; j < store.categories[i].num_items; j++) {
            printf("- %s (%d)\n", store.categories[i].items[j].name, store.categories[i].items[j].quantity);
        }
    }
}

int main() {
    Store store;
    read_store(&store);
    print_store(store);
    return 0;
}