//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: random
#include <stdio.h>
#include <stdlib.h>

void main()
{
    system("color 0f");
    int item_no;
    char item_name[20];
    float item_price;
    int quantity;
    float total_amount = 0.0f;

    // Display menu
    printf("\nWelcome to Coffee Cafe!\n\n");
    printf("Menu:\n");
    printf("1. Espresso\t\t$2.00\n");
    printf("2. Cappuccino\t\t$2.50\n");
    printf("3. Latte\t\t$3.00\n");
    printf("4. Macchiato\t\t$3.50\n");
    printf("5. Mocha\t\t$4.00\n");
    printf("Please select an item number:");

    // Get item number
    scanf("%d", &item_no);

    // Get item name and price
    switch (item_no)
    {
        case 1:
            strcpy(item_name, "Espresso");
            item_price = 2.00f;
            break;
        case 2:
            strcpy(item_name, "Cappuccino");
            item_price = 2.50f;
            break;
        case 3:
            strcpy(item_name, "Latte");
            item_price = 3.00f;
            break;
        case 4:
            strcpy(item_name, "Macchiato");
            item_price = 3.50f;
            break;
        case 5:
            strcpy(item_name, "Mocha");
            item_price = 4.00f;
            break;
        default:
            printf("Invalid item number.\n");
            return;
    }

    // Get quantity
    printf("Enter quantity:");
    scanf("%d", &quantity);

    // Calculate total amount
    total_amount = item_price * quantity;

    // Display order summary
    printf("\nOrder Summary:");
    printf("\nItem name: %s", item_name);
    printf("\nQuantity: %d", quantity);
    printf("\nItem price: $%.2f", item_price);
    printf("\nTotal amount: $%.2f", total_amount);

    // Calculate tax and total cost
    float tax = total_amount * 0.10f;
    float total_cost = total_amount + tax;

    // Display tax and total cost
    printf("\nTax: $%.2f", tax);
    printf("\nTotal cost: $%.2f", total_cost);

    // Thank you and goodbye
    printf("\nThank you for your order. Come again soon!\n");

    return;
}