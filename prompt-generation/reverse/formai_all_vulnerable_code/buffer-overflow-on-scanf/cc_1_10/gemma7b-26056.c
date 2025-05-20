//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: synchronous
#include <stdio.h>
#include <string.h>

int main()
{
    char itemName[20];
    int itemQuantity;
    float itemPrice;
    float totalAmount = 0.0f;

    printf("Welcome to the C Cafe Billing System!\n");

    // Loop until the user enters "q"
    while (1)
    {
        printf("Enter item name: ");
        scanf("%s", itemName);

        if (strcmp(itemName, "q") == 0)
        {
            break;
        }

        printf("Enter item quantity: ");
        scanf("%d", &itemQuantity);

        printf("Enter item price: ");
        scanf("%f", &itemPrice);

        // Calculate item total cost
        float itemTotalCost = itemQuantity * itemPrice;

        // Add item total cost to the total amount
        totalAmount += itemTotalCost;

        // Print item details
        printf("Item name: %s\n", itemName);
        printf("Item quantity: %d\n", itemQuantity);
        printf("Item price: %.2f\n", itemPrice);
        printf("Item total cost: %.2f\n", itemTotalCost);
        printf("\n");
    }

    // Calculate the total amount due
    float totalAmountDue = totalAmount * 1.1f;

    // Print the total amount due
    printf("Total amount: %.2f\n", totalAmount);
    printf("Total amount due: %.2f\n", totalAmountDue);

    // Prompt for payment
    printf("Please pay the total amount due: ");
    float paymentReceived = 0.0f;

    // Loop until the payment received is equal to the total amount due
    while (paymentReceived < totalAmountDue)
    {
        printf("Enter payment received: ");
        scanf("%f", &paymentReceived);

        // Update the total amount received
        paymentReceived += paymentReceived;

        // Check if the payment received is enough
        if (paymentReceived >= totalAmountDue)
        {
            printf("Payment received: %.2f\n", paymentReceived);
            printf("Change: %.2f\n", paymentReceived - totalAmountDue);
        }
        else
        {
            printf("Insufficient payment. Please try again.\n");
        }
    }

    return 0;
}