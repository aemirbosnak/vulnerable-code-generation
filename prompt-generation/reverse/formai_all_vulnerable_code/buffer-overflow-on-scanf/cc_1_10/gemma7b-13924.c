//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice, item_num, quantity, total_cost = 0;
    char item_name[20];

    // Display menu
    printf("Welcome to the Coffee Shop!\n");
    printf("Please select an item:\n");
    printf("1. Coffee\n");
    printf("2. Tea\n");
    printf("3. Juice\n");
    printf("4. Snack\n");

    // Get user input
    scanf("Enter your choice: ", &choice);

    // Calculate item cost based on user choice
    switch (choice)
    {
        case 1:
            strcpy(item_name, "Coffee");
            item_num = 1;
            quantity = 0;
            total_cost = 50;
            break;
        case 2:
            strcpy(item_name, "Tea");
            item_num = 2;
            quantity = 0;
            total_cost = 30;
            break;
        case 3:
            strcpy(item_name, "Juice");
            item_num = 3;
            quantity = 0;
            total_cost = 20;
            break;
        case 4:
            strcpy(item_name, "Snack");
            item_num = 4;
            quantity = 0;
            total_cost = 10;
            break;
        default:
            printf("Invalid choice.\n");
            return 1;
    }

    // Get item quantity
    printf("Enter the quantity of items: ");
    scanf("%d", &quantity);

    // Calculate total cost
    total_cost = total_cost * quantity;

    // Display bill
    printf("Item: %s\n", item_name);
    printf("Quantity: %d\n", quantity);
    printf("Total cost: $%d\n", total_cost);

    // Prompt for payment
    printf("Please pay the total cost: $");
    int payment;
    scanf("%d", &payment);

    // Calculate change
    int change = payment - total_cost;

    // Display change
    printf("Change: $%d\n", change);

    return 0;
}