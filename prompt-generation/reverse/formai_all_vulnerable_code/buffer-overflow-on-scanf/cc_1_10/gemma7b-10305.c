//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int item_no;
    char item_name[20];
    int quantity;
    float price;
    float total_amount = 0.0;

    // Display welcome message
    printf("Welcome to the Coffee Cafe!\n");

    // Loop until the customer enters 0 for item number
    while (1)
    {
        printf("Enter item number (0 to quit): ");
        scanf("%d", &item_no);

        if (item_no == 0)
        {
            break;
        }

        // Get item name, quantity, and price
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        printf("Enter price: ");
        scanf("%f", &price);

        // Calculate total amount
        float item_total = quantity * price;
        total_amount += item_total;

        // Print item details
        printf("Item: %s, Quantity: %d, Price: %.2f, Total Amount: %.2f\n", item_name, quantity, price, item_total);
    }

    // Calculate total amount
    float tax = total_amount * 0.1;
    float grand_total = total_amount + tax;

    // Print total amount and grand total
    printf("Total Amount: %.2f\n", total_amount);
    printf("Tax: %.2f\n", tax);
    printf("Grand Total: %.2f\n", grand_total);

    // Thank you message
    printf("Thank you for your visit to the Coffee Cafe! Come again soon.\n");

    return 0;
}