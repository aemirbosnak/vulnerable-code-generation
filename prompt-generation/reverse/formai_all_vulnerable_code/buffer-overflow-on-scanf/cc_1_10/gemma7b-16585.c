//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define a structure for a medical store item
typedef struct item {
    char name[20];
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

// Define a function to list all items in the store
void list_items(item_t *items, int num_items) {
    for (int i = 0; i < num_items; i++) {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Define a function to search for an item in the store
void search_item(item_t *items, int num_items) {
    char item_name[20];

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].name, item_name) == 0) {
            printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
        }
    }
}

int main() {
    item_t *items = NULL;
    int num_items = 0;

    // Add some items to the store
    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    // List all items in the store
    list_items(items, num_items);

    // Search for an item in the store
    search_item(items, num_items);

    return 0;
}