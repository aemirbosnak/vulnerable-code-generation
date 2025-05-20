//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PI 3.14159

typedef struct Coffee
{
    char name[20];
    float price;
    int quantity;
} Coffee;

Coffee coffee_list[] = {
    {"Latte", 5.0, 0},
    {"Cappuccino", 4.0, 0},
    {"Americano", 3.0, 0},
    {"Macchiato", 4.5, 0},
    {"Mocha", 4.2, 0}
};

int main()
{
    int i, order_num = 1, total_price = 0;
    char customer_name[20];

    printf("Welcome to Caffeinated Dreams!\n");
    printf("Please enter your name: ");
    scanf("%s", customer_name);

    printf("What would you like to order? (1-5): ");
    scanf("%d", &i);

    switch (i)
    {
        case 1:
            coffee_list[0].quantity++;
            total_price += coffee_list[0].price;
            break;
        case 2:
            coffee_list[1].quantity++;
            total_price += coffee_list[1].price;
            break;
        case 3:
            coffee_list[2].quantity++;
            total_price += coffee_list[2].price;
            break;
        case 4:
            coffee_list[3].quantity++;
            total_price += coffee_list[3].price;
            break;
        case 5:
            coffee_list[4].quantity++;
            total_price += coffee_list[4].price;
            break;
        default:
            printf("Invalid order number.\n");
            break;
    }

    printf("Here is your order:\n");
    for (i = 0; i < 5; i++)
    {
        printf("%s: %d cups at $%.2f each = $%.2f\n", coffee_list[i].name, coffee_list[i].quantity, coffee_list[i].price, coffee_list[i].quantity * coffee_list[i].price);
    }

    printf("Total price: $%.2f\n", total_price);
    printf("Thank you for your order, %s! Enjoy your Caffeinated Dreams!\n", customer_name);

    return 0;
}