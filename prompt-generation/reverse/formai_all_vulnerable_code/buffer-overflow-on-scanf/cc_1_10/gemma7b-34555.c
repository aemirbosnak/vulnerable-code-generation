//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store items
typedef struct Item {
    char name[20];
    int quantity;
    float price;
} Item;

// Define a function to add an item to the store
void addItem(Item **items, int *numItems) {
    Item *newItem = malloc(sizeof(Item));
    printf("Enter item name: ");
    scanf("%s", newItem->name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem->quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem->price);

    (*items) = realloc((*items), (*numItems) * sizeof(Item) + sizeof(Item));
    (*numItems)++;
    items = (*items) + (*numItems) - 1;
    *items = newItem;
}

// Define a function to search for an item
Item *searchItem(Item *items, int numItems, char *name) {
    for (int i = 0; i < numItems; i++) {
        if (strcmp(items[i].name, name) == 0) {
            return &items[i];
        }
    }

    return NULL;
}

// Define a function to update item quantity
void updateItemQuantity(Item *item, int quantity) {
    item->quantity = quantity;
}

// Define a function to delete an item
void deleteItem(Item *items, int *numItems, char *name) {
    Item *item = searchItem(items, *numItems, name);

    if (item) {
        free(item);
        (*numItems)--;
    }
}

int main() {
    Item *items = NULL;
    int numItems = 0;

    // Add some items to the store
    addItem(&items, &numItems);
    addItem(&items, &numItems);
    addItem(&items, &numItems);

    // Search for an item
    Item *item = searchItem(items, numItems, "Item 2");

    // Update item quantity
    if (item) {
        updateItemQuantity(item, 10);
    }

    // Delete an item
    deleteItem(items, &numItems, "Item 1");

    // Print the items in the store
    for (int i = 0; i < numItems; i++) {
        printf("%s, %d, %f\n", items[i].name, items[i].quantity, items[i].price);
    }

    return 0;
}