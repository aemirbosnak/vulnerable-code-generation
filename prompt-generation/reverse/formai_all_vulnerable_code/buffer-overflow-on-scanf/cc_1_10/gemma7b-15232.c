//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store warehouse item information
typedef struct item {
    char item_name[50];
    int quantity;
    float price;
} item_t;

// Define a function to add an item to the warehouse
void add_item(item_t *items, int *items_count) {
    items = (item_t *)realloc(items, (*items_count + 1) * sizeof(item_t));
    items_count++;

    printf("Enter item name: ");
    scanf("%s", items[*items_count - 1].item_name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*items_count - 1].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*items_count - 1].price);
}

// Define a function to search for an item in the warehouse
item_t *search_item(item_t *items, int items_count, char *item_name) {
    for (int i = 0; i < items_count; i++) {
        if (strcmp(items[i].item_name, item_name) == 0) {
            return &items[i];
        }
    }

    return NULL;
}

// Define a function to update item quantity in the warehouse
void update_item_quantity(item_t *items, int items_count, char *item_name, int new_quantity) {
    item_t *item = search_item(items, items_count, item_name);

    if (item) {
        item->quantity = new_quantity;
    }
}

// Define a function to delete an item from the warehouse
void delete_item(item_t *items, int *items_count, char *item_name) {
    item_t *item = search_item(items, items_count, item_name);

    if (item) {
        for (int i = item - items; i < items_count - 1; i++) {
            items[i] = items[i + 1];
        }

        (*items_count)--;
    }
}

// Main function
int main() {
    item_t *items = NULL;
    int items_count = 0;

    // Add some items to the warehouse
    add_item(items, &items_count);
    add_item(items, &items_count);
    add_item(items, &items_count);

    // Search for an item in the warehouse
    item_t *item = search_item(items, items_count, "Item 2");
    if (item) {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    // Update item quantity in the warehouse
    update_item_quantity(items, items_count, "Item 2", 10);
    item = search_item(items, items_count, "Item 2");
    if (item) {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->quantity);
    }

    // Delete an item from the warehouse
    delete_item(items, &items_count, "Item 2");
    item = search_item(items, items_count, "Item 2");
    if (item) {
        printf("Item name: %s\n", item->item_name);
        printf("Item quantity: %d\n", item->quantity);
    }

    return 0;
}