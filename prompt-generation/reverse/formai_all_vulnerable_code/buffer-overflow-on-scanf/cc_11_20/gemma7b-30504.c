//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shape shifting
#include <stdio.h>
#include <string.h>

void main()
{
    int menu_choice, quantity;
    float total_price = 0.0f;
    char customer_name[20];

    // Menu options
    int coffee_menu[] = {10, 12, 15, 20, 25};
    int tea_menu[] = {8, 10, 12, 15, 20};
    int juice_menu[] = {7, 9, 11, 13, 15};

    // Display menu options
    printf("**Coffee:**\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s - $%d\n", coffee_menu[i], coffee_menu[i], coffee_menu[i]);
    }

    printf("\n**Tea:**\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s - $%d\n", tea_menu[i], tea_menu[i], tea_menu[i]);
    }

    printf("\n**Juice:**\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d. %s - $%d\n", juice_menu[i], juice_menu[i], juice_menu[i]);
    }

    // Get customer name and menu choice
    printf("Enter your name: ");
    scanf("%s", customer_name);

    printf("Enter your menu choice: ");
    scanf("%d", &menu_choice);

    // Calculate total price
    switch (menu_choice)
    {
        case 1:
            quantity = 1;
            total_price = coffee_menu[0] * quantity;
            break;
        case 2:
            quantity = 1;
            total_price = coffee_menu[1] * quantity;
            break;
        case 3:
            quantity = 1;
            total_price = coffee_menu[2] * quantity;
            break;
        case 4:
            quantity = 1;
            total_price = coffee_menu[3] * quantity;
            break;
        case 5:
            quantity = 1;
            total_price = coffee_menu[4] * quantity;
            break;
        case 6:
            quantity = 1;
            total_price = tea_menu[0] * quantity;
            break;
        case 7:
            quantity = 1;
            total_price = tea_menu[1] * quantity;
            break;
        case 8:
            quantity = 1;
            total_price = tea_menu[2] * quantity;
            break;
        case 9:
            quantity = 1;
            total_price = tea_menu[3] * quantity;
            break;
        case 10:
            quantity = 1;
            total_price = tea_menu[4] * quantity;
            break;
        case 11:
            quantity = 1;
            total_price = juice_menu[0] * quantity;
            break;
        case 12:
            quantity = 1;
            total_price = juice_menu[1] * quantity;
            break;
        case 13:
            quantity = 1;
            total_price = juice_menu[2] * quantity;
            break;
        case 14:
            quantity = 1;
            total_price = juice_menu[3] * quantity;
            break;
        case 15:
            quantity = 1;
            total_price = juice_menu[4] * quantity;
            break;
    }

    // Print receipt
    printf("\n**Receipt:**\n");
    printf("Customer Name: %s\n", customer_name);
    printf("Menu Choice: %d\n", menu_choice);
    printf("Quantity: %d\n", quantity);
    printf("Total Price: $%.2f\n", total_price);

    // Thank you message
    printf("Thank you for your order, %s!\n", customer_name);
}