//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int item_no;
    float item_price;
    char item_name[20];
    int quantity;
    float total_amount = 0.0;

    // Display menu
    printf("----------------------------------------\n");
    printf("Welcome to the Coffee Cafe!\n");
    printf("----------------------------------------\n");
    printf("Items:\n");
    printf("1. Coffee - $5.00\n");
    printf("2. Tea - $3.00\n");
    printf("3. Juice - $4.00\n");
    printf("4. Milk - $2.00\n");
    printf("5. Water - $1.00\n");

    // Get item number
    printf("Enter item number: ");
    scanf("%d", &item_no);

    // Get item price
    switch (item_no)
    {
        case 1:
            item_price = 5.00;
            break;
        case 2:
            item_price = 3.00;
            break;
        case 3:
            item_price = 4.00;
            break;
        case 4:
            item_price = 2.00;
            break;
        case 5:
            item_price = 1.00;
            break;
        default:
            printf("Invalid item number.\n");
            exit(1);
    }

    // Get item name
    switch (item_no)
    {
        case 1:
            strcpy(item_name, "Coffee");
            break;
        case 2:
            strcpy(item_name, "Tea");
            break;
        case 3:
            strcpy(item_name, "Juice");
            break;
        case 4:
            strcpy(item_name, "Milk");
            break;
        case 5:
            strcpy(item_name, "Water");
            break;
        default:
            printf("Invalid item number.\n");
            exit(1);
    }

    // Get quantity
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Calculate total amount
    total_amount = item_price * quantity;

    // Display receipt
    printf("----------------------------------------\n");
    printf("Order Receipt\n");
    printf("Item: %s\n", item_name);
    printf("Quantity: %d\n", quantity);
    printf("Price: $%.2f\n", item_price);
    printf("Total Amount: $%.2f\n", total_amount);
    printf("----------------------------------------\n");

    // Calculate change
    float change = total_amount;
    int coins = 0;
    while (change >= 25)
    {
        coins++;
        change -= 25.00;
    }
    while (change >= 10)
    {
        coins++;
        change -= 10.00;
    }
    while (change >= 5)
    {
        coins++;
        change -= 5.00;
    }
    while (change >= 1)
    {
        coins++;
        change -= 1.00;
    }

    // Display change
    printf("Number of coins: %d\n", coins);
    printf("Total change: $%.2f\n", change);
    printf("----------------------------------------\n");
}