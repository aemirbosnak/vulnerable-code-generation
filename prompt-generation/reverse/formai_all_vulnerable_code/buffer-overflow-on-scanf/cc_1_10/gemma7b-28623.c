//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct Item
{
    char name[20];
    int price;
    int quantity;
} Item;

// Define a function to calculate total cost
int calculateTotalCost(Item item, int quantity)
{
    return item.price * quantity;
}

// Define a function to print receipt
void printReceipt(Item item, int quantity, int totalCost)
{
    printf("----------------------------------------\n");
    printf("Item: %s\n", item.name);
    printf("Quantity: %d\n", quantity);
    printf("Price: %d\n", item.price);
    printf("Total Cost: %d\n", totalCost);
    printf("----------------------------------------\n");
}

int main()
{
    // Create an array of items
    Item items[] = {
        {"Coffee", 50, 10},
        {"Tea", 40, 8},
        {"Juice", 30, 6}
    };

    // Get the item name, quantity, and print receipt
    char itemName[20];
    int itemQuantity;
    printf("Enter item name: ");
    scanf("%s", itemName);

    printf("Enter quantity: ");
    scanf("%d", &itemQuantity);

    int itemIndex = 0;
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(itemName, items[i].name) == 0)
        {
            itemIndex = i;
            break;
        }
    }

    int totalCost = calculateTotalCost(items[itemIndex], itemQuantity);
    printReceipt(items[itemIndex], itemQuantity, totalCost);

    return 0;
}