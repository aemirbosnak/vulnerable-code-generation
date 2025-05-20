//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int choice, item_num, quantity, total_price = 0, item_price;

    // Display menu options
    printf("Welcome to the Coffee Cafe!\n");
    printf("Please select an option:\n");
    printf("1. View Menu\n");
    printf("2. Place Order\n");
    printf("3. Check Out\n");

    // Get user input
    scanf("%d", &choice);

    // Process user selection
    switch (choice)
    {
        case 1:
            // Display menu items
            printf("Here is our menu:\n");
            printf("1. Coffee - $5\n");
            printf("2. Tea - $3\n");
            printf("3. Juice - $4\n");
            printf("4. Soda - $2\n");
            break;

        case 2:
            // Get item number and quantity
            printf("Please enter the item number: ");
            scanf("%d", &item_num);

            printf("Please enter the quantity: ");
            scanf("%d", &quantity);

            // Calculate item price
            switch (item_num)
            {
                case 1:
                    item_price = 5 * quantity;
                    break;

                case 2:
                    item_price = 3 * quantity;
                    break;

                case 3:
                    item_price = 4 * quantity;
                    break;

                case 4:
                    item_price = 2 * quantity;
                    break;
            }

            // Add item price to total price
            total_price += item_price;

            break;

        case 3:
            // Calculate total cost
            total_price = total_price * 1.1;

            // Print receipt
            printf("Your order:\n");
            printf("Item: %s\n", "Coffee");
            printf("Quantity: %d\n", quantity);
            printf("Price: $%d\n", item_price);

            printf("Total Cost: $%d\n", total_price);

            break;
    }

    // Display farewell message
    printf("Thank you for visiting the Coffee Cafe!\n");

    // Exit program
    exit(0);
}