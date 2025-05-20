//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: active
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store item information
typedef struct item {
    char name[50];
    int quantity;
    float price;
} item_t;

// Define a function to add an item to the store
void add_item(item_t *items, int *items_count) {
    // Allocate memory for a new item
    items = (item_t *)realloc(items, (*items_count + 1) * sizeof(item_t));

    // Get item information from the user
    printf("Enter item name: ");
    scanf("%s", items[*items_count].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*items_count].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*items_count].price);

    // Increment the items count
    (*items_count)++;
}

// Define a function to search for an item
item_t *search_item(item_t *items, int items_count, char *name) {
    for (int i = 0; i < items_count; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return &items[i];
        }
    }

    return NULL;
}

// Define a function to update item quantity
void update_item_quantity(item_t *items, int items_count, char *name, int new_quantity) {
    item_t *item = search_item(items, items_count, name);

    if (item) {
        item->quantity = new_quantity;
    }
}

// Define a function to delete an item
void delete_item(item_t *items, int *items_count, char *name) {
    item_t *item = search_item(items, items_count, name);

    if (item) {
        for (int i = item - items; i < items_count - 1; i++) {
            items[i] = items[i + 1];
        }

        (*items_count)--;
    }
}

int main() {
    // Create an array of items
    item_t *items = NULL;

    // Initialize the items count
    int items_count = 0;

    // Add some items to the store
    add_item(items, &items_count);
    add_item(items, &items_count);
    add_item(items, &items_count);

    // Search for an item
    item_t *item = search_item(items, items_count, "Item 2");

    // Update item quantity
    update_item_quantity(items, items_count, "Item 2", 10);

    // Delete an item
    delete_item(items, &items_count, "Item 1");

    // Print the items
    for (int i = 0; i < items_count; i++) {
        printf("%s, %d, %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    return 0;
}