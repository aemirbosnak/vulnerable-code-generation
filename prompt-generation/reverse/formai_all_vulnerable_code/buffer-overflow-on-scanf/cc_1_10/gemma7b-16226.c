//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEM_NUM 10

typedef struct Item
{
    char name[20];
    int price;
    int quantity;
} Item;

Item items[MAX_ITEM_NUM] = {
    {"Coffee", 50, 10},
    {"Tea", 40, 5},
    {"Juice", 30, 7},
    {"Soda", 20, 3},
    {"Water", 10, 2},
    {"Smoothie", 60, 4},
    {"Ice Cream", 70, 6},
    {"Cake", 80, 3},
    {"Cookies", 90, 2},
    {"Brownies", 100, 1}
};

int main()
{
    int item_num = 0;
    char item_name[20];
    int item_quantity;
    int total_price = 0;

    printf("Welcome to the C Cafe Billing System!\n");

    // Loop to get the item name and quantity
    while (1)
    {
        printf("Enter item name: ");
        scanf("%s", item_name);

        // Check if the item name is valid
        for (item_num = 0; item_num < MAX_ITEM_NUM; item_num++)
        {
            if (strcmp(item_name, items[item_num].name) == 0)
            {
                break;
            }
        }

        if (item_num == MAX_ITEM_NUM)
        {
            printf("Invalid item name.\n");
        }
        else
        {
            printf("Enter item quantity: ");
            scanf("%d", &item_quantity);

            // Calculate the total price
            total_price += items[item_num].price * item_quantity;

            // Break out of the loop
            break;
        }
    }

    // Calculate the total tax
    int total_tax = total_price * 10 / 100;

    // Calculate the total amount
    int total_amount = total_price + total_tax;

    // Print the invoice
    printf("Invoice:\n");
    printf("Item name: %s\n", items[item_num].name);
    printf("Quantity: %d\n", item_quantity);
    printf("Price: %d\n", items[item_num].price);
    printf("Total price: %d\n", total_price);
    printf("Tax: %d\n", total_tax);
    printf("Total amount: %d\n", total_amount);

    return 0;
}