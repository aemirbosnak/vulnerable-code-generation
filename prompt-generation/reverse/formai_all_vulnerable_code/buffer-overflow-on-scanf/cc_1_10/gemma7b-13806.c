//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store warehouse item information
typedef struct item {
    char name[20];
    int quantity;
    float price;
} item_t;

// Define a function to add an item to the warehouse
void add_item(item_t *items, int *num_items) {
    // Allocate memory for a new item
    items = (item_t *)realloc(items, (*num_items + 1) * sizeof(item_t));

    // Get the item name, quantity, and price from the user
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);

    // Increment the number of items
    *num_items++;
}

// Define a function to search for an item in the warehouse
item_t *search_item(item_t *items, int num_items, char *name) {
    // Iterate over the items in the warehouse
    for (int i = 0; i < num_items; i++) {
        // Check if the item name matches the search term
        if (strcmp(items[i].name, name) == 0) {
            // Return the item
            return &items[i];
        }
    }

    // Return NULL if the item is not found
    return NULL;
}

// Define a function to update the quantity of an item in the warehouse
void update_item_quantity(item_t *items, int num_items, char *name, int new_quantity) {
    // Search for the item in the warehouse
    item_t *item = search_item(items, num_items, name);

    // If the item is found, update its quantity
    if (item) {
        item->quantity = new_quantity;
    }
}

// Define a function to delete an item from the warehouse
void delete_item(item_t *items, int *num_items, char *name) {
    // Search for the item in the warehouse
    item_t *item = search_item(items, num_items, name);

    // If the item is found, delete it from the warehouse
    if (item) {
        // Subtract the item from the number of items
        *num_items--;

        // Free the memory occupied by the item
        free(item);
    }
}

int main() {
    // Create an array of items in the warehouse
    item_t *items = NULL;

    // Initialize the number of items to 0
    int num_items = 0;

    // Add some items to the warehouse
    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    // Search for an item in the warehouse
    item_t *item = search_item(items, num_items, "Item 2");

    // If the item is found, print its information
    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %f\n", item->price);
    }

    // Update the quantity of an item in the warehouse
    update_item_quantity(items, num_items, "Item 2", 10);

    // Search for the item again and print its updated information
    item = search_item(items, num_items, "Item 2");

    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %f\n", item->price);
    }

    // Delete an item from the warehouse
    delete_item(items, &num_items, "Item 2");

    // Search for the item again and print whether it has been deleted
    item = search_item(items, num_items, "Item 2");

    if (item) {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %f\n", item->price);
    } else {
        printf("Item not found.\n");
    }

    return 0;
}