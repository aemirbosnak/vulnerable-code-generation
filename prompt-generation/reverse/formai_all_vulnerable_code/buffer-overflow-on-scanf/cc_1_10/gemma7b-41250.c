//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store medical item information
typedef struct Item
{
    char name[50];
    int quantity;
    float price;
} Item;

// Define a function to add a new item to the inventory
void addItem(Item *items, int *numItems)
{
    // Allocate memory for a new item
    items = (Item *)realloc(items, (*numItems + 1) * sizeof(Item));

    // Get the item name, quantity, and price
    printf("Enter item name: ");
    scanf("%s", items[*numItems].name);

    printf("Enter item quantity: ");
    scanf("%d", &items[*numItems].quantity);

    printf("Enter item price: ");
    scanf("%f", &items[*numItems].price);

    // Increment the number of items
    (*numItems)++;
}

// Define a function to display the inventory
void displayInventory(Item *items, int numItems)
{
    // Print the inventory items
    for (int i = 0; i < numItems; i++)
    {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Define a function to search for an item
Item *searchItem(Item *items, int numItems, char *name)
{
    // Search for the item by name
    for (int i = 0; i < numItems; i++)
    {
        if (strcmp(items[i].name, name) == 0)
        {
            return &items[i];
        }
    }

    // Item not found
    return NULL;
}

// Main function
int main()
{
    // Create an array of items
    Item *items = NULL;

    // Initialize the number of items to 0
    int numItems = 0;

    // Add some items to the inventory
    addItem(items, &numItems);
    addItem(items, &numItems);
    addItem(items, &numItems);

    // Display the inventory
    displayInventory(items, numItems);

    // Search for an item
    Item *item = searchItem(items, numItems, "Item 2");

    // If the item was found, display its information
    if (item)
    {
        printf("Item name: %s\n", item->name);
        printf("Item quantity: %d\n", item->quantity);
        printf("Item price: %.2f\n", item->price);
    }

    // Free the memory allocated for the items
    free(items);

    return 0;
}