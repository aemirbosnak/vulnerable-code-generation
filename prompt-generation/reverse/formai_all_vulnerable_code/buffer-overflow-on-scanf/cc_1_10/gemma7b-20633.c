//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int item_no;
    char item_name[20];
    float item_price;
    int quantity;
    float total_amount = 0.0;

    printf("Welcome to Coffee Haven! Please select an item:");
    scanf("%d", &item_no);

    switch (item_no)
    {
        case 1:
            strcpy(item_name, "Cappuccino");
            item_price = 50.0;
            break;
        case 2:
            strcpy(item_name, "Latte");
            item_price = 40.0;
            break;
        case 3:
            strcpy(item_name, "Americano");
            item_price = 30.0;
            break;
        case 4:
            strcpy(item_name, "Macchiato");
            item_price = 60.0;
            break;
        default:
            printf("Invalid item number!");
            return 1;
    }

    printf("Enter the quantity:");
    scanf("%d", &quantity);

    item_price *= quantity;
    total_amount += item_price;

    printf("Item name: %s\n", item_name);
    printf("Quantity: %d\n", quantity);
    printf("Item price: %.2f\n", item_price);
    printf("Total amount: %.2f\n", total_amount);

    system("pause");
    return 0;
}