//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no;
    float price;
    char item_name[20];
    int quantity;
    float total_amount = 0.0f;

    // Display welcome message
    printf("Welcome to the Coffee Cafe!\n");

    // Loop until the customer enters "q"
    while (1)
    {
        // Get the item name, number, and quantity
        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate the price of the item
        price = 0.0f;
        switch (item_no)
        {
            case 1:
                price = 50.0f;
                break;
            case 2:
                price = 75.0f;
                break;
            case 3:
                price = 90.0f;
                break;
            default:
                printf("Invalid item number.\n");
                continue;
        }

        // Calculate the total amount
        total_amount += quantity * price;

        // Display the item information
        printf("Item name: %s\n", item_name);
        printf("Item number: %d\n", item_no);
        printf("Quantity: %d\n", quantity);
        printf("Price: %.2f\n", price);

        // Ask the customer if they want to continue
        printf("Do you want to continue? (y/n): ");
        char continue_char;
        scanf("%c", &continue_char);

        // Break out of the loop if the customer enters "q"
        if (continue_char == 'q')
        {
            break;
        }
    }

    // Calculate the total amount
    total_amount = total_amount * 1.1f;

    // Display the total amount
    printf("Total amount: %.2f\n", total_amount);

    // Thank the customer
    printf("Thank you for your visit to the Coffee Cafe!\n");

    // Exit the program
    exit(0);
}