//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store warehouse item information
typedef struct item {
    char name[50];
    int quantity;
    double price;
} item_t;

// Define a function to add an item to the warehouse
void add_item(item_t *item) {
    printf("Enter item name: ");
    scanf("%s", item->name);

    printf("Enter item quantity: ");
    scanf("%d", &item->quantity);

    printf("Enter item price: ");
    scanf("%lf", &item->price);
}

// Define a function to list all items in the warehouse
void list_items(item_t *item) {
    printf("List of items:\n");

    for (int i = 0; item[i].name[0] != '\0'; i++) {
        printf("%s - %d - %.2lf\n", item[i].name, item[i].quantity, item[i].price);
    }
}

// Define a function to search for an item in the warehouse
void search_item(item_t *item) {
    char item_name[50];

    printf("Enter item name: ");
    scanf("%s", item_name);

    for (int i = 0; item[i].name[0] != '\0'; i++) {
        if (strcmp(item[i].name, item_name) == 0) {
            printf("Item name: %s\n", item[i].name);
            printf("Item quantity: %d\n", item[i].quantity);
            printf("Item price: %.2lf\n", item[i].price);
        }
    }
}

int main() {
    item_t item;

    // Add an item to the warehouse
    add_item(&item);

    // List all items in the warehouse
    list_items(&item);

    // Search for an item in the warehouse
    search_item(&item);

    return 0;
}