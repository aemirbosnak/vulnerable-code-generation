//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: unmistakable
#include <stdio.h>
#include <string.h>

void main()
{
    int item_no, quantity;
    char item_name[20];
    float price, total_amount = 0.0f;

    // Loop to get customer details
    printf("Enter item number: ");
    scanf("%d", &item_no);

    printf("Enter item name: ");
    scanf("%s", item_name);

    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Calculate item price
    switch (item_no)
    {
        case 1:
            price = 100.0f;
            break;
        case 2:
            price = 200.0f;
            break;
        case 3:
            price = 300.0f;
            break;
        default:
            printf("Invalid item number.");
            return;
    }

    // Calculate total amount
    total_amount = quantity * price;

    // Print invoice
    printf("---------------------------------------\n");
    printf("Item No: %d\n", item_no);
    printf("Item Name: %s\n", item_name);
    printf("Quantity: %d\n", quantity);
    printf("Price: %.2f\n", price);
    printf("Total Amount: %.2f\n", total_amount);
    printf("---------------------------------------\n");

    // Calculate tax and other charges
    float tax = total_amount * 0.1f;
    float other_charges = total_amount * 0.05f;

    // Print total charges
    printf("Tax: %.2f\n", tax);
    printf("Other Charges: %.2f\n", other_charges);

    // Calculate grand total
    float grand_total = total_amount + tax + other_charges;

    // Print grand total
    printf("Grand Total: %.2f\n", grand_total);

    // Print receipt
    printf("Thank you for your purchase! Come again soon.\n");

    return;
}