//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no, quantity, total_items = 0, total_amount = 0;
    char item_name[20];
    float item_price, total_price = 0.0f;

    // Create a loop to add items to the bill
    while (1)
    {
        // Get the item name, number, and price
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item quantity: ");
        scanf("%d", &quantity);

        printf("Enter item price: ");
        scanf("%f", &item_price);

        // Calculate the item total price
        total_price = quantity * item_price;

        // Add the item to the bill
        total_items++;
        total_amount += total_price;

        // Check if the user wants to add more items
        printf("Do you want to add more items? (Y/N): ");
        char answer;
        scanf("%c", &answer);

        // Break out of the loop if the user does not want to add more items
        if (answer == 'N')
            break;
    }

    // Calculate the total bill amount
    total_amount += total_items * 10.0f;

    // Print the bill
    printf("\nBill:");
    printf("\nItem No. | Item Name | Quantity | Price | Total Price |");
    printf("\n--- | --- | --- | --- | --- |");

    for (int i = 0; i < total_items; i++)
    {
        printf("%d | %s | %d | %.2f | %.2f |", i + 1, item_name, quantity, item_price, total_price);
        printf("\n");
    }

    printf("\nTotal Items: %d", total_items);
    printf("\nTotal Amount: $%.2f", total_amount);

    // Prompt the customer to pay
    printf("\nPlease pay the total amount: $");
    float payment;
    scanf("%f", &payment);

    // Check if the payment is sufficient
    if (payment < total_amount)
    {
        printf("Insufficient payment. Please pay the remaining amount: $%.2f", total_amount - payment);
    }
    else
    {
        printf("Thank you for your payment. Your change is $%.2f", payment - total_amount);
    }
}