//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int item_no, quantity, total_items = 0, total_amount = 0;
    char item_name[20];

    // Create a loop to allow the customer to enter items until they are finished
    while (1)
    {
        // Get the item name, number, and quantity
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate the total cost of the item
        int item_cost = quantity * 10;

        // Add the item to the total items and amount
        total_items++;
        total_amount += item_cost;

        // Check if the customer is finished entering items
        printf("Are you finished entering items? (Y/N): ");
        char finished;
        scanf("%c", &finished);

        if (finished == 'Y')
        {
            break;
        }
    }

    // Print the total items and amount
    printf("Total items: %d\n", total_items);
    printf("Total amount: $%d\n", total_amount);

    // Calculate the tax and total cost
    int tax = total_amount * 0.08;
    int total_cost = total_amount + tax;

    // Print the tax and total cost
    printf("Tax: $%d\n", tax);
    printf("Total cost: $%d\n", total_cost);

    // Prompt the customer to pay
    printf("Please pay the total amount: $%d\n", total_cost);

    return 0;
}