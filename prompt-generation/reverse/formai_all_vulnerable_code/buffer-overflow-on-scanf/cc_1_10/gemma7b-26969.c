//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct Item
{
    char name[20];
    int price;
    int quantity;
} Item;

// Create an array of items
Item items[] =
{
    {"Coffee", 50, 10},
    {"Tea", 40, 8},
    {"Juice", 30, 6},
    {"Soda", 20, 4},
    {"Water", 10, 2}
};

// Define a function to calculate the total cost of an order
int calculateTotalCost(int numItems, Item items[])
{
    int totalCost = 0;
    for (int i = 0; i < numItems; i++)
    {
        totalCost += items[i].price * items[i].quantity;
    }
    return totalCost;
}

// Define a function to print the bill
void printBill(int totalCost, int numItems, Item items[])
{
    printf("------------------------------------------------\n");
    printf("Bill\n");
    printf("------------------------------------------------\n");
    printf("Number of items: %d\n", numItems);
    for (int i = 0; i < numItems; i++)
    {
        printf("%s: %d x %d = %d\n", items[i].name, items[i].quantity, items[i].price, items[i].price * items[i].quantity);
    }
    printf("Total cost: $%d\n", totalCost);
    printf("------------------------------------------------\n");
}

int main()
{
    int numItems = 0;
    Item items[100];

    // Get the number of items in the order
    printf("How many items do you want to order? ");
    scanf("%d", &numItems);

    // Create the order
    for (int i = 0; i < numItems; i++)
    {
        items[i].name[0] = '\0';
        printf("Enter the name of item %d: ", i + 1);
        scanf("%s", items[i].name);

        printf("Enter the price of item %d: ", i + 1);
        scanf("%d", &items[i].price);

        printf("Enter the quantity of item %d: ", i + 1);
        scanf("%d", &items[i].quantity);
    }

    // Calculate the total cost of the order
    int totalCost = calculateTotalCost(numItems, items);

    // Print the bill
    printBill(totalCost, numItems, items);

    return 0;
}