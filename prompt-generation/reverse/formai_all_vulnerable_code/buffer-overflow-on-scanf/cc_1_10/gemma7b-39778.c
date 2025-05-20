//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item
{
    char name[20];
    float price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 50.0, 10},
    {"Tea", 40.0, 8},
    {"Juice", 30.0, 6},
    {"Smoothie", 20.0, 4},
    {"Ice Cream", 10.0, 2}
};

int main()
{
    int item_num = 0;
    char order[20];
    float total_price = 0.0;

    printf("Welcome to Caffeinated Dreams!\n");

    // Get the customer's order
    printf("Please enter your order: ");
    scanf("%s", order);

    // Iterate over the items and find the match
    for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++)
    {
        if (strcmp(order, items[item_num].name) == 0)
        {
            // Calculate the item's total cost
            float item_price = items[item_num].price * items[item_num].quantity;
            total_price += item_price;
            break;
        }
    }

    // If the item is not found, display an error message
    if (item_num == MAX_ITEM_NUM)
    {
        printf("Error: item not found.\n");
    }

    // Calculate the total cost
    total_price += total_price * 0.1; // 10% tax

    // Print the order confirmation
    printf("Your order: %s\n", order);
    printf("Total price: %.2f\n", total_price);

    return 0;
}