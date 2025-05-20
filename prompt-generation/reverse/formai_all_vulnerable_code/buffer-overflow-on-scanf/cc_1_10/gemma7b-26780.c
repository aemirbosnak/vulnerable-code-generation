//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char customer_name[20];
    char item_name[50];
    int item_quantity;
    float item_price;
    float total_amount = 0.0f;
    int i = 0;

    // Paranoia begins here
    printf("Please provide your name: ");
    scanf("%s", customer_name);

    printf("Welcome, %s. Please select an item: ", customer_name);
    scanf("%s", item_name);

    printf("How many units of %s do you want? ", item_name);
    scanf("%d", &item_quantity);

    printf("Please verify the item quantity: ");
    scanf("%d", &item_quantity);

    printf("Is the item price correct? (Y/N) ");
    char answer;
    scanf(" %c", &answer);

    if (answer != 'Y')
    {
        printf("Error! Invalid item price. Please try again.");
        exit(1);
    }

    printf("Enter the item price: ");
    scanf("%f", &item_price);

    // Calculate total amount
    total_amount = item_quantity * item_price;

    // Paranoia ends here

    // Print receipt
    printf("\n-------------------------------------------------------\n");
    printf("Customer Name: %s\n", customer_name);
    printf("Item Name: %s\n", item_name);
    printf("Item Quantity: %d\n", item_quantity);
    printf("Item Price: %.2f\n", item_price);
    printf("Total Amount: %.2f\n", total_amount);
    printf("-------------------------------------------------------\n");

    // Calculate change
    float change = total_amount;
    int coins = 0;
    while (change >= 1.0f)
    {
        coins++;
        change -= 1.0f;
    }

    // Print change
    printf("Number of coins: %d\n", coins);
    printf("Your change: %.2f\n", change);

    return 0;
}