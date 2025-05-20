//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: satisfied
#include <stdio.h>
#define TAX_RATE 0.06
#define MAX_ITEMS 100

int main()
{
    int item_count = 0;
    float item_price[MAX_ITEMS];
    float total_price = 0.0;
    float tax_amount = 0.0;

    printf("*** C Cafe Billing System ***\n");
    printf("*****************************\n");

    while (1)
    {
        printf("\nEnter the price of the item (Enter 0 to stop): ");
        scanf("%f", &item_price[item_count]);

        if (item_price[item_count] == 0)
        {
            break;
        }

        if (++item_count == MAX_ITEMS)
        {
            printf("Maximum number of items reached.\n");
            break;
        }
    }

    printf("\n\n");
    printf("*****************************\n");
    printf("**** C Cafe Bill Receipt ****\n");
    printf("*****************************\n");

    printf("item id \t| price\n");
    printf("------------------------------\n");

    for (int i = 0; i < item_count; i++)
    {
        printf("item %d \t| %.2f\n", i + 1, item_price[i]);
        total_price += item_price[i];
    }

    tax_amount = total_price * TAX_RATE;
    printf("------------------------------\n");
    printf("Total Amount (excluding tax) : %.2f\n", total_price);
    printf("Tax : %.2f\n", tax_amount);
    printf("Total Amount (including tax) : %.2f\n", total_price + tax_amount);

    printf("------------------------------\n");
    printf("Thank you for dining with us!\n");

    return 0;
}