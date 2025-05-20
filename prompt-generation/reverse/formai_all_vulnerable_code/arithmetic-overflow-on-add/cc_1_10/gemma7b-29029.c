//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int item_no, quantity, total_items = 0, total_amount = 0;
    char item_name[20];

    // Menu items
    struct item_list
    {
        int item_no;
        char item_name[20];
        int price;
    } items[] =
    {
        {1, "Coffee", 50},
        {2, "Tea", 40},
        {3, "Juice", 30},
        {4, "Smoothie", 60}
    };

    // Loop to get item information
    while (1)
    {
        printf("Enter item number: ");
        scanf("%d", &item_no);

        // Check if item number is valid
        if (item_no < 1 || item_no > 4)
        {
            printf("Invalid item number.\n");
            continue;
        }

        printf("Enter item quantity: ");
        scanf("%d", &quantity);

        // Calculate item cost
        int item_cost = items[item_no - 1].price * quantity;

        // Add item to total items and amount
        total_items++;
        total_amount += item_cost;

        // Break out of loop
        break;
    }

    // Calculate total bill
    int tax = 10;
    int total_bill = total_amount + tax;

    // Print bill
    printf("\nBill\n");
    printf("---------------------------\n");
    printf("Total items: %d\n", total_items);
    printf("Total amount: $%d\n", total_amount);
    printf("Tax: $%d\n", tax);
    printf("Total bill: $%d\n", total_bill);
    printf("---------------------------\n");

    return 0;
}