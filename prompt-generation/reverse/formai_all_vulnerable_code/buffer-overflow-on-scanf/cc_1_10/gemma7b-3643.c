//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10

typedef struct Item
{
    char name[20];
    int quantity;
    float price;
} Item;

Item items[MAX_ITEMS] = {
    {"Coffee", 10, 50.0},
    {"Tea", 5, 30.0},
    {"Juice", 7, 20.0},
    {"Smoothie", 2, 40.0},
    {"Soda", 8, 15.0},
    {"Water", 9, 10.0},
    {"Ice Cream", 3, 25.0},
    {"Cake", 4, 35.0},
    {"Cookies", 6, 20.0},
    {"Brownies", 1, 45.0}
};

int main()
{
    int i, order_num = 1, item_num, total_price = 0;
    char customer_name[20];

    printf("Welcome to Caffeinated Dreams!\n");
    printf("Please enter your name: ");
    scanf("%s", customer_name);

    printf("Please select an item: ");
    for (i = 0; i < MAX_ITEMS; i++)
    {
        printf("%d. %s (%d) - $%.2f\n", i + 1, items[i].name, items[i].quantity, items[i].price);
    }
    scanf("%d", &item_num);

    if (item_num > MAX_ITEMS || item_num <= 0)
    {
        printf("Invalid item number.\n");
    }
    else
    {
        items[item_num - 1].quantity--;
        total_price += items[item_num - 1].price;
        order_num++;
    }

    printf("Thank you, %s. Your order number is %d.\n", customer_name, order_num);
    printf("Total price: $%.2f\n", total_price);

    return 0;
}