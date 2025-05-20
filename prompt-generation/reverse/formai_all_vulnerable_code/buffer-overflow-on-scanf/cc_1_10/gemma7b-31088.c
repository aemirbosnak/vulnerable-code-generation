//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define a structure to store item information
    typedef struct item
    {
        char name[20];
        int price;
        int quantity;
    } item;

    // Create an array of items
    item items[] = {
        {"Coffee", 50, 10},
        {"Tea", 40, 8},
        {"Juice", 30, 12},
        {"Smoothie", 60, 9},
        {"Biscuits", 20, 15}
    };

    // Define the total cost of the order
    int total_cost = 0;

    // Get the customer's order
    printf("Enter your order: ");
    char order[20];
    scanf("%s", order);

    // Iterate over the items to find the ones in the order
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(items[i].name, order) == 0)
        {
            // Add the item's cost to the total cost
            total_cost += items[i].price * items[i].quantity;
        }
    }

    // Calculate the total cost
    total_cost = total_cost * 1.1;

    // Print the total cost
    printf("Total cost: $%d", total_cost);

    // Print the receipt
    printf("\nYour receipt:\n");
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(items[i].name, order) == 0)
        {
            printf("%s: %d x %d = $%d\n", items[i].name, items[i].quantity, items[i].price, items[i].price * items[i].quantity);
        }
    }

    printf("Thank you for your order!\n");

    return 0;
}