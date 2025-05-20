//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#define ITEM_NUM 5

int main()
{
    float price[ITEM_NUM] = {1.50, 2.00, 2.50, 3.50, 4.50};
    char *items[ITEM_NUM] = {"Coffee", "Tea", "Muffin", "Donut", "Sandwich"};

    float total_price = 0, paid_price, change;

    printf("------ Welcome to Cafe Billing System ------\n");
    printf("Item - Price\n");

    for(int i=0; i<ITEM_NUM; i++)
    {
        printf("%s - $%.2f\n", items[i], price[i]);
    }

    printf("-------------------------------------------\n");

    int item_num, item_qty;
    char ans;

    do
    {
        printf("Enter item number (1-5): ");
        scanf("%d", &item_num);
        printf("Enter quantity: ");
        scanf("%d", &item_qty);

        // Calculate price of selected item
        float item_price = price[item_num-1] * item_qty;
        total_price += item_price;

        printf("%d %s added to the bill. Cost: $%.2f\n", item_qty, items[item_num-1], item_price);

        // Prompt to continue ordering
        printf("Would you like to add another item? (y/n)\n");
        scanf(" %c", &ans);
    } while(ans == 'y' || ans == 'Y');

    // Print receipt
    printf("\n ------------------ Bill ----------------- \n");
    for(int i=0; i<ITEM_NUM; i++)
    {
        if(price[i] != 0)
        {
            printf("%s - $%.2f\n", items[i], price[i]);
        }
    }
    printf("Total - $%.2f\n", total_price);

    // Accept payment and calculate change
    printf("Enter amount paid: $");
    scanf("%f", &paid_price);

    if(paid_price < total_price)
    {
        printf("Insufficient payment!\n");
        exit(1);
    }

    change = paid_price - total_price;
    printf("Change - $%.2f\n", change);

    printf("Thank you for patronizing Cafe Billing System!\n");

    return 0;
}