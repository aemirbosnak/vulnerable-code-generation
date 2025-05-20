//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to store item information
    typedef struct Item
    {
        char name[20];
        int price;
        int quantity;
    } Item;

    // Create an array of items
    Item items[] = {
        {"Coffee", 50, 10},
        {"Tea", 30, 5},
        {"Juice", 20, 7},
        {"Smoothie", 40, 2}
    };

    // Initialize the total cost
    int totalCost = 0;

    // Get the customer's order
    char order[20];
    printf("What would you like to order? ");
    scanf("%s", order);

    // Iterate over the items and check if the customer's order matches
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(order, items[i].name) == 0)
        {
            // Add the item's cost to the total cost
            totalCost += items[i].price * items[i].quantity;
        }
    }

    // Print the total cost
    printf("Total cost: $%d", totalCost);

    // Calculate the tax
    int tax = totalCost * 0.08;

    // Print the tax
    printf("Tax: $%d", tax);

    // Calculate the total amount due
    int totalAmountDue = totalCost + tax;

    // Print the total amount due
    printf("Total amount due: $%d", totalAmountDue);

    return 0;
}