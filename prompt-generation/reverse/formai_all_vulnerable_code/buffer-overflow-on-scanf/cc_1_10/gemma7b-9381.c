//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void inv_bill_system()
{
    system("clear");
    printf("Welcome to the Invasive Coffee Cafe!\n");
    printf("Please select an item from the menu:**\n");
    printf("1. Black Coffee\n");
    printf("2. Cappuccino\n");
    printf("3. Latte\n");
    printf("4. Mocha\n");
    printf("5. Espresso\n");

    int item_choice;
    scanf("%d", &item_choice);

    switch (item_choice)
    {
        case 1:
            printf("Your order: Black Coffee\n");
            break;
        case 2:
            printf("Your order: Cappuccino\n");
            break;
        case 3:
            printf("Your order: Latte\n");
            break;
        case 4:
            printf("Your order: Mocha\n");
            break;
        case 5:
            printf("Your order: Espresso\n");
            break;
        default:
            printf("Invalid item choice\n");
    }

    printf("Please enter the quantity of your order:**");
    int quantity;
    scanf("%d", &quantity);

    int total_price = quantity * 2;

    printf("Your total price: $%d\n", total_price);

    printf("Thank you for your order at the Invasive Coffee Cafe!\n");
    system("pause");
}

int main()
{
    inv_bill_system();
    return 0;
}