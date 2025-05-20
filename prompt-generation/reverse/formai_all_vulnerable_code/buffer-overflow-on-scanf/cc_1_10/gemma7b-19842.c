//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int menu_choice, quantity;
    float total_price = 0.0f;
    char customer_name[50];

    printf("Welcome to Coffee Bean Cafe!\n");
    printf("Please enter your name: ");
    scanf("%s", customer_name);

    printf("Please select a menu item:\n");
    printf("1. Espresso\t$5.00\n");
    printf("2. Latte\t$6.00\n");
    printf("3. Cappuccino\t$7.00\n");
    printf("4. Mocha\t$8.00\n");

    printf("Enter your choice: ");
    scanf("%d", &menu_choice);

    switch (menu_choice)
    {
        case 1:
            total_price += 5.00f;
            break;
        case 2:
            total_price += 6.00f;
            break;
        case 3:
            total_price += 7.00f;
            break;
        case 4:
            total_price += 8.00f;
            break;
        default:
            printf("Invalid menu choice.\n");
            break;
    }

    printf("Please enter the quantity of your order: ");
    scanf("%d", &quantity);

    total_price *= quantity;

    printf("Your order total is $%.2f.", total_price);

    printf("\nThank you, %s, for visiting Coffee Bean Cafe!\n", customer_name);

    return;
}