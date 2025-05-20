//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    system("color 0c");
    printf("----------------------------------------\n");
    printf("   C Cafe Billing System\n");
    printf("----------------------------------------\n");

    char name[20];
    int quantity, item_no;
    float price, total = 0;

    printf("Enter your name: ");
    scanf("%s", name);

    printf("Enter the item number: ");
    scanf("%d", &item_no);

    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    switch (item_no)
    {
        case 1:
            price = 50.00;
            break;
        case 2:
            price = 75.00;
            break;
        case 3:
            price = 100.00;
            break;
        default:
            printf("Invalid item number.\n");
            return 1;
    }

    total = quantity * price;

    printf("Your name: %s\n", name);
    printf("Item number: %d\n", item_no);
    printf("Quantity: %d\n", quantity);
    printf("Price: %.2f\n", price);
    printf("Total: %.2f\n", total);

    system("pause");
    return 0;
}