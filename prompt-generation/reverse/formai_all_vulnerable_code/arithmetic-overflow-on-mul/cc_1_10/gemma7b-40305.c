//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no, quantity, total_items = 0, total_amount = 0;
    char item_name[50];

    system("cls");

    // Loop to get items
    while (1)
    {
        printf("Enter item number: ");
        scanf("%d", &item_no);

        if (item_no == 0)
            break;

        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate item total
        int item_total = quantity * 10;

        // Add item to total items and amount
        total_items++;
        total_amount += item_total;

        // Print item details
        printf("Item No: %d\n", item_no);
        printf("Item Name: %s\n", item_name);
        printf("Quantity: %d\n", quantity);
        printf("Item Total: $%d\n", item_total);

        printf("\n");
    }

    // Calculate total bill
    int tax = total_amount * 10 / 100;
    int total_bill = total_amount + tax;

    // Print bill details
    printf("Total Items: %d\n", total_items);
    printf("Total Amount: $%d\n", total_amount);
    printf("Tax: $%d\n", tax);
    printf("Total Bill: $%d\n", total_bill);

    // Prompt for payment
    printf("Please pay the total bill: $%d", total_bill);

    return;
}