//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no;
    float price, total_price = 0, quantity;

    // Display welcome message
    printf("Welcome to Caffeinated Dreams!\n");

    // Loop to get item number, price, and quantity
    while (1)
    {
        printf("Enter item number: ");
        scanf("%d", &item_no);

        if (item_no == 0)
            break;

        printf("Enter item price: ");
        scanf("%f", &price);

        printf("Enter quantity: ");
        scanf("%f", &quantity);

        // Calculate item total price
        float item_total_price = price * quantity;

        // Add item total price to total price
        total_price += item_total_price;

        // Display item details
        printf("Item No: %d\n", item_no);
        printf("Item Price: %.2f\n", price);
        printf("Quantity: %.2f\n", quantity);
        printf("Item Total Price: %.2f\n", item_total_price);
    }

    // Display total price
    printf("Total Price: %.2f\n", total_price);

    // Calculate tax
    float tax = total_price * 0.1;

    // Display tax
    printf("Tax: %.2f\n", tax);

    // Calculate grand total
    float grand_total = total_price + tax;

    // Display grand total
    printf("Grand Total: %.2f\n", grand_total);

    // Thank you message
    printf("Thank you for your visit to Caffeinated Dreams!\n");

    // Exit
    exit(0);
}