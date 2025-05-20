//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical store items
typedef struct item
{
    char name[50];
    int quantity;
    float price;
} item;

// Define a function to add an item to the store
void add_item(item *items, int *num_items)
{
    // Allocate memory for a new item
    items = (item *)realloc(items, (*num_items + 1) * sizeof(item));

    // Get the item name, quantity, and price from the user
    printf("Enter item name: ");
    scanf("%s", items[*num_items].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*num_items].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*num_items].price);

    // Increment the number of items
    (*num_items)++;
}

// Define a function to search for an item
void search_item(item *items, int num_items)
{
    // Get the item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item
    int found = 0;
    for (int i = 0; i < num_items; i++)
    {
        if (strcmp(items[i].name, item_name) == 0)
        {
            // Print the item details
            printf("Item name: %s\n", items[i].name);
            printf("Item quantity: %d\n", items[i].quantity);
            printf("Item price: %.2f\n", items[i].price);
            found = 1;
        }
    }

    // If the item was not found, print an error message
    if (!found)
    {
        printf("Item not found.\n");
    }
}

// Define a function to update an item
void update_item(item *items, int num_items)
{
    // Get the item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item
    int found = 0;
    for (int i = 0; i < num_items; i++)
    {
        if (strcmp(items[i].name, item_name) == 0)
        {
            // Get the new item name, quantity, and price from the user
            printf("Enter new item name: ");
            scanf("%s", items[i].name);

            printf("Enter new item quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new item price: ");
            scanf("%f", &items[i].price);

            found = 1;
        }
    }

    // If the item was not found, print an error message
    if (!found)
    {
        printf("Item not found.\n");
    }
}

// Define a function to delete an item
void delete_item(item *items, int num_items)
{
    // Get the item name from the user
    char item_name[50];
    printf("Enter item name: ");
    scanf("%s", item_name);

    // Search for the item
    int found = 0;
    for (int i = 0; i < num_items; i++)
    {
        if (strcmp(items[i].name, item_name) == 0)
        {
            // Delete the item
            items = (item *)realloc(items, (num_items - 1) * sizeof(item));

            // Decrement the number of items
            num_items--;

            found = 1;
        }
    }

    // If the item was not found, print an error message
    if (!found)
    {
        printf("Item not found.\n");
    }
}

int main()
{
    // Create an array of items
    item *items = NULL;
    int num_items = 0;

    // Add some items to the store
    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    // Search for an item
    search_item(items, num_items);

    // Update an item
    update_item(items, num_items);

    // Delete an item
    delete_item(items, num_items);

    return 0;
}