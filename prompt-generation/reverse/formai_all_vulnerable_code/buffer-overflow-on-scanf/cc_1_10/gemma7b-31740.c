//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("cls");
    int item_no, quantity, total_items = 0, total_amount = 0;
    char item_name[20];
    float item_price;

    // Loop to get items
    while (1)
    {
        printf("Enter item name: ");
        scanf("%s", item_name);

        if (strcmp(item_name, "q") == 0)
            break;

        printf("Enter item number: ");
        scanf("%d", &item_no);

        printf("Enter item quantity: ");
        scanf("%d", &quantity);

        // Calculate item price
        item_price = quantity * 2;

        // Add item to total items and amount
        total_items++;
        total_amount += item_price;

        // Print confirmation
        printf("Item added.\n");
    }

    // Calculate total cost
    float total_cost = total_amount + 10;

    // Print bill
    printf("------------------------------------------------------------------------\n");
    printf("C Cafe Billing System\n");
    printf("------------------------------------------------------------------------\n");
    printf("Total Items: %d\n", total_items);
    printf("Total Amount: $%.2f\n", total_amount);
    printf("Total Cost: $%.2f\n", total_cost);
    printf("------------------------------------------------------------------------\n");

    return 0;
}