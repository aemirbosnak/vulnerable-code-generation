//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int item_no, quantity, total_items = 0, total_amount = 0;
    char item_name[20];
    float item_price;

    // Create a loop to get items
    while (1)
    {
        printf("Enter item number: ");
        scanf("%d", &item_no);

        if (item_no == 0)
            break;

        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item price: ");
        scanf("%f", &item_price);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate item total
        int item_total = quantity * item_price;

        // Add item to total items and total amount
        total_items++;
        total_amount += item_total;

        // Print confirmation message
        printf("Item added successfully!\n");
    }

    // Calculate total amount
    float total_tax = total_amount * 0.1;
    int grand_total = total_amount + total_tax;

    // Print bill
    printf("--------------------------------------------------------\n");
    printf("C Cafe Bill\n");
    printf("--------------------------------------------------------\n");
    printf("Total Items: %d\n", total_items);
    printf("Total Amount: $%.2f\n", total_amount);
    printf("Tax: $%.2f\n", total_tax);
    printf("Grand Total: $%d\n", grand_total);
    printf("--------------------------------------------------------\n");

    return 0;
}