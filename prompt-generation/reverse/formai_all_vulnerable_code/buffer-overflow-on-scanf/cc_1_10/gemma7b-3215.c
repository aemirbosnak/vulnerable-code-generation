//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

// Define a structure to store item information
typedef struct Item
{
    char name[50];
    int quantity;
    float price;
} Item;

// Define a function to calculate the total cost of an item
float calculateTotalCost(Item item)
{
    return item.quantity * item.price;
}

// Define a function to print the bill
void printBill(Item items[], int numItems)
{
    printf("----------------------------------------------------------------\n");
    printf("C Cafe Billing System\n");
    printf("----------------------------------------------------------------\n");

    for (int i = 0; i < numItems; i++)
    {
        printf("Item: %s, Quantity: %d, Price: %.2f\n", items[i].name, items[i].quantity, items[i].price);
    }

    printf("Total Cost: %.2f\n", calculateTotalCost(items[0]) + calculateTotalCost(items[1]));

    printf("Payment: $");
    float payment = 0;
    scanf("%f", &payment);

    printf("Change: $%.2f\n", payment - calculateTotalCost(items[0]) - calculateTotalCost(items[1]));
}

int main()
{
    // Create two items
    Item items[2] =
    {
        {"Coffee", 2, 3.50},
        {"Tea", 1, 2.00}
    };

    // Print the bill
    printBill(items, 2);

    return 0;
}