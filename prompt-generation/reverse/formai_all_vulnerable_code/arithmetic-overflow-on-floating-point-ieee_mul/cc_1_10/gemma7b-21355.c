//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int item_no, quantity, total_items = 0, total_amount = 0;
    char item_name[20];
    float item_price;

    // Display menu
    printf("Welcome to the C Cafe Billing System!\n");
    printf("------------------------\n");
    printf("Please select an item: \n");

    // Loop to get item details
    while (1)
    {
        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter item name: ");
        scanf("%s", item_name);

        printf("Enter item price: ");
        scanf("%f", &item_price);

        printf("Enter quantity: ");
        scanf("%d", &quantity);

        // Calculate total items and amount
        total_items++;
        total_amount += quantity * item_price;

        // Check if user wants to continue
        printf("Do you want to continue? (Y/N): ");
        char answer;
        scanf(" %c", &answer);

        // If user does not want to continue, break out of the loop
        if (answer != 'Y')
            break;
    }

    // Display total items and amount
    printf("------------------------\n");
    printf("Total items: %d\n", total_items);
    printf("Total amount: $%.2f\n", total_amount);

    // Calculate tax and total cost
    float tax = total_amount * 0.08;
    int total_cost = (int) (total_amount + tax);

    // Display tax and total cost
    printf("Tax: $%.2f\n", tax);
    printf("Total cost: $%d\n", total_cost);

    // Thank you message
    printf("Thank you for your visit to the C Cafe!\n");

    return 0;
}