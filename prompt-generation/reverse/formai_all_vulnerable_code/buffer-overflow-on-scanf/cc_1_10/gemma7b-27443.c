//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of items that can be ordered
#define MAX_ITEMS 10

// Define the structure of an item
typedef struct Item
{
    char name[20];
    float price;
    int quantity;
} Item;

// Define the function to add an item to the order
void add_item(Item items[], int *num_items)
{
    // Allocate memory for the new item
    items = (Item *)realloc(items, (*num_items + 1) * sizeof(Item));

    // Get the item name, price, and quantity
    printf("Enter the item name:");
    scanf("%s", items[*num_items].name);

    printf("Enter the item price:");
    scanf("%f", &items[*num_items].price);

    printf("Enter the item quantity:");
    scanf("%d", &items[*num_items].quantity);

    // Increment the number of items in the order
    (*num_items)++;
}

// Define the function to calculate the total cost of the order
float calculate_total_cost(Item items[], int num_items)
{
    float total_cost = 0;

    // Iterate over the items in the order
    for (int i = 0; i < num_items; i++)
    {
        total_cost += items[i].price * items[i].quantity;
    }

    return total_cost;
}

// Define the function to print the order
void print_order(Item items[], int num_items)
{
    // Print the items in the order
    printf("Order:");

    for (int i = 0; i < num_items; i++)
    {
        printf("\n%s - %d @ %.2f", items[i].name, items[i].quantity, items[i].price);
    }

    printf("\nTotal cost: %.2f", calculate_total_cost(items, num_items));
}

int main()
{
    // Create an array of items
    Item items[MAX_ITEMS];

    // Initialize the number of items in the order
    int num_items = 0;

    // Add items to the order
    add_item(items, &num_items);
    add_item(items, &num_items);
    add_item(items, &num_items);

    // Print the order
    print_order(items, num_items);

    return 0;
}