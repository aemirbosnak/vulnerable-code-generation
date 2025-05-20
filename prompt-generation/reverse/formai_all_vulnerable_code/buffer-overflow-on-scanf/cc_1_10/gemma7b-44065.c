//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: careful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int item_no, quantity, total_items = 0;
    float price, total_amount = 0.0;
    char item_name[20];

    // Loop to get item details
    while (1)
    {
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate item price
        price = quantity * 10;

        // Add item to the total items
        total_items++;

        // Add item cost to the total amount
        total_amount += price;

        // Check if the user wants to continue
        char continue_or_not;
        printf("Do you want to continue? (Y/N): ");
        scanf("%c", &continue_or_not);

        if (continue_or_not == 'N')
            break;
    }

    // Calculate the total amount due
    float tax = total_amount * 0.1;
    float grand_total = total_amount + tax;

    // Print the bill
    printf("--------------------------------------------------------\n");
    printf("C Cafe Bill\n");
    printf("--------------------------------------------------------\n");
    printf("Item No. | Item Name | Quantity | Price | Total Cost |\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < total_items; i++)
    {
        printf("%d | %s | %d | %f | %f |\n", item_no, item_name, quantity, price, total_amount);
    }

    printf("--------------------------------------------------------\n");
    printf("Total Items: %d\n", total_items);
    printf("Total Amount: %.2f\n", total_amount);
    printf("Tax: %.2f\n", tax);
    printf("Grand Total: %.2f\n", grand_total);
    printf("--------------------------------------------------------\n");

    return 0;
}