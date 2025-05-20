//Gemma-7B DATASET v1.0 Category: Warehouse Management System ; Style: portable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define a structure to store warehouse item information
typedef struct item {
    char item_name[50];
    int item_quantity;
    float item_price;
} item_t;

// Define a function to add an item to the warehouse
void add_item(item_t *items, int *num_items) {
    // Allocate memory for a new item
    items = (item_t *)realloc(items, (*num_items + 1) * sizeof(item_t));

    // Get item name, quantity, and price from the user
    printf("Enter item name: ");
    scanf("%s", items[*num_items].item_name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].item_quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*num_items].item_price);

    // Increment the number of items
    *num_items++;
}

// Define a function to search for an item in the warehouse
void search_item(item_t *items, int num_items) {
    // Get item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item
    int found = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].item_name, item_name) == 0) {
            // Item found
            found = 1;
            printf("Item name: %s\n", items[i].item_name);
            printf("Item quantity: %d\n", items[i].item_quantity);
            printf("Item price: %f\n", items[i].item_price);
        }
    }

    // If item not found
    if (!found) {
        printf("Item not found.\n");
    }
}

// Define a function to update item quantity in the warehouse
void update_item_quantity(item_t *items, int num_items) {
    // Get item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item
    int found = 0;
    for (int i = 0; i < num_items; i++) {
        if (strcmp(items[i].item_name, item_name) == 0) {
            // Item found
            found = 1;
            printf("Enter new item quantity: ");
            scanf("%d", &items[i].item_quantity);
        }
    }

    // If item not found
    if (!found) {
        printf("Item not found.\n");
    }
}

// Define a function to delete an item from the warehouse
void delete_item(item_t *items, int *num_items) {
    // Get item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item
    int found = 0;
    for (int i = 0; i < *num_items; i++) {
        if (strcmp(items[i].item_name, item_name) == 0) {
            // Item found
            found = 1;
            // Delete the item
            items = (item_t *)realloc(items, (*num_items - 1) * sizeof(item_t));
            *num_items--;
        }
    }

    // If item not found
    if (!found) {
        printf("Item not found.\n");
    }
}

int main() {
    // Define an array of items
    item_t *items = NULL;
    int num_items = 0;

    // Loop until the user chooses to quit
    char choice;
    while (1) {
        // Display menu options
        printf("Enter 'a' to add an item, 's' to search for an item, 'u' to update item quantity, 'd' to delete an item, or 'q' to quit: ");
        scanf(" %c", &choice);

        // Switch case to handle user input
        switch (choice) {
            case 'a':
                add_item(items, &num_items);
                break;
            case 's':
                search_item(items, num_items);
                break;
            case 'u':
                update_item_quantity(items, num_items);
                break;
            case 'd':
                delete_item(items, &num_items);
                break;
            case 'q':
                printf("Goodbye.\n");
                exit(0);
            default:
                printf("Invalid input.\n");
        }
    }

    return 0;
}