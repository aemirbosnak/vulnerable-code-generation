//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store items
typedef struct item {
    char name[50];
    int quantity;
    float price;
} item_t;

// Define a function to add an item to the store
void add_item(item_t *items, int *num_items) {
    items = (item_t *)realloc(items, (*num_items + 1) * sizeof(item_t));
    (*num_items)++;

    printf("Enter item name: ");
    scanf("%s", items[*num_items - 1].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items - 1].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*num_items - 1].price);
}

// Define a function to display all items in the store
void display_items(item_t *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Define a function to search for an item in the store
item_t *search_item(item_t *items, int num_items, char *name) {
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return &items[i];
        }
    }

    return NULL;
}

// Define a function to update the quantity of an item
void update_quantity(item_t *items, int num_items, char *name, int new_quantity) {
    item_t *item = search_item(items, num_items, name);

    if (item) {
        item->quantity = new_quantity;
    }
}

// Define a function to delete an item from the store
void delete_item(item_t *items, int *num_items, char *name) {
    item_t *item = search_item(items, num_items, name);

    if (item) {
        for (int i = item - items; i < num_items - 1; i++) {
            items[i] = items[i + 1];
        }

        (*num_items)--;
    }
}

int main() {
    // Define an array of items
    item_t *items = NULL;
    int num_items = 0;

    // Add some items to the store
    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    // Display all items in the store
    display_items(items, num_items);

    // Search for an item in the store
    item_t *item = search_item(items, num_items, "Item 2");

    // If the item is found, update its quantity
    if (item) {
        update_quantity(items, num_items, "Item 2", 10);
    }

    // Display all items in the store after updating the quantity
    display_items(items, num_items);

    // Delete an item from the store
    delete_item(items, &num_items, "Item 1");

    // Display all items in the store after deleting an item
    display_items(items, num_items);

    return 0;
}