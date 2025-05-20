//Gemma-7B DATASET v1.0 Category: Medical Store Management System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store medical store items
struct Item
{
    char name[50];
    int quantity;
    float price;
};

// Define a function to add an item to the store
void addItem(struct Item *item)
{
    printf("Enter the name of the item: ");
    scanf("%s", item->name);

    printf("Enter the quantity of the item: ");
    scanf("%d", &item->quantity);

    printf("Enter the price of the item: ");
    scanf("%f", &item->price);
}

// Define a function to display all items in the store
void displayItems(struct Item *items, int numItems)
{
    for (int i = 0; i < numItems; i++)
    {
        printf("%s - %d - %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }
}

// Define a function to find an item in the store
struct Item *findItem(struct Item *items, int numItems, char *itemName)
{
    for (int i = 0; i < numItems; i++)
    {
        if (strcmp(items[i].name, itemName) == 0)
        {
            return &items[i];
        }
    }

    return NULL;
}

// Define a function to update the quantity of an item
void updateQuantity(struct Item *item, int newQuantity)
{
    item->quantity = newQuantity;
}

// Define a function to update the price of an item
void updatePrice(struct Item *item, float newPrice)
{
    item->price = newPrice;
}

// Main function
int main()
{
    // Create an array of items
    struct Item items[10];

    // Initialize the number of items to 0
    int numItems = 0;

    // Add some items to the store
    addItem(&items[numItems++]);
    addItem(&items[numItems++]);
    addItem(&items[numItems++]);

    // Display all items in the store
    displayItems(items, numItems);

    // Find an item in the store
    struct Item *item = findItem(items, numItems, "Item 2");

    // If the item was found, update its quantity and price
    if (item)
    {
        updateQuantity(item, 10);
        updatePrice(item, 10.0);
    }

    // Display all items in the store again
    displayItems(items, numItems);

    return 0;
}