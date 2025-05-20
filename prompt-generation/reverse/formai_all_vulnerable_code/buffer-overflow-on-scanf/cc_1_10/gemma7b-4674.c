//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("clear");
    system("color 2");

    // Coffee Menu
    printf("\n\tWelcome to Caffeinated Dreams!\n");
    printf("\t1. Black Coffee\t\t$2.00\n");
    printf("\t2. Espresso\t\t$3.00\n");
    printf("\t3. Cappuccino\t\t$4.00\n");
    printf("\t4. Latte\t\t$5.00\n");

    // Get Customer Order
    printf("\nEnter your order number:");
    int orderNum = 0;
    scanf("%d", &orderNum);

    // Calculate Total Cost
    int cost = 0;
    switch (orderNum)
    {
        case 1:
            cost = 2;
            break;
        case 2:
            cost = 3;
            break;
        case 3:
            cost = 4;
            break;
        case 4:
            cost = 5;
            break;
        default:
            printf("Invalid order number!");
            return 1;
    }

    // Print Receipt
    printf("\n\tOrder Summary:");
    printf("\tOrder Number: %d", orderNum);
    printf("\tItem: Coffee (%s)", "Black Coffee" + (orderNum - 1) * 2);
    printf("\tCost: $%d", cost);
    printf("\n\tTotal Cost: $%d", cost);
    printf("\n\tThank you for your order at Caffeinated Dreams!");

    return 0;
}