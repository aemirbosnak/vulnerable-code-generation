//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int item_id, quantity, total_items = 0, total_cost = 0;
    float item_price;

    // Create an array of items
    struct item
    {
        int id;
        char name[20];
        float price;
    } items[] =
    {
        {1, "Coffee", 50.0},
        {2, "Tea", 30.0},
        {3, "Juice", 20.0},
        {4, "Smoothie", 40.0}
    };

    // Loop to get the items and quantities
    while (1)
    {
        printf("Enter item ID: ");
        scanf("%d", &item_id);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Check if the item ID is valid
        if (item_id < 1 || item_id > 4)
        {
            printf("Invalid item ID.\n");
            continue;
        }

        // Calculate the total cost of the item
        item_price = items[item_id - 1].price * quantity;

        // Add the item to the total items and cost
        total_items++;
        total_cost += item_price;

        // Break out of the loop
        if (quantity == 0)
            break;
    }

    // Print the total items and cost
    printf("Total items: %d\n", total_items);
    printf("Total cost: $%.2f\n", total_cost);

    return 0;
}