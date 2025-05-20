//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no;
    char item_name[20];
    float item_price;
    int qty;
    float total_bill = 0.0f;

    // Display menu
    printf("Welcome to the C Cafe!\n");
    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Soda\n");

    // Get item number
    scanf("%d", &item_no);

    // Switch case to get item name and price
    switch (item_no)
    {
        case 1:
            strcpy(item_name, "Coffee");
            item_price = 5.0f;
            break;
        case 2:
            strcpy(item_name, "Tea");
            item_price = 3.0f;
            break;
        case 3:
            strcpy(item_name, "Juice");
            item_price = 4.0f;
            break;
        case 4:
            strcpy(item_name, "Soda");
            item_price = 2.0f;
            break;
        default:
            printf("Invalid item number.\n");
            return;
    }

    // Get item quantity
    printf("Enter the quantity of items: ");
    scanf("%d", &qty);

    // Calculate total bill
    total_bill = item_price * qty;

    // Display bill
    printf("Your order:\n");
    printf("%s - %d units @ %.2f per unit = %.2f\n", item_name, qty, item_price, total_bill);
    printf("Total bill: %.2f\n", total_bill);

    // Prompt for payment
    printf("Please pay the bill: ");
    float payment;
    scanf("%f", &payment);

    // Calculate change
    float change = payment - total_bill;

    // Display change
    printf("Change: %.2f\n", change);

    // Thank you message
    printf("Thank you for your visit to the C Cafe!\n");

    return;
}