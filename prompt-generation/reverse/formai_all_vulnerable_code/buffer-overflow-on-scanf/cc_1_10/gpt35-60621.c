//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include<stdio.h>
#include<string.h>

int main()
{
    char name[20];
    int quantity;
    float price;

    //Display the menu
    printf("\n----------------------------");
    printf("\n HOT COFFEE CAFE MENU");
    printf("\n----------------------------");
    printf("\n 1. Cappuccino - Rs. 80");
    printf("\n 2. Latte - Rs. 100");
    printf("\n 3. Espresso - Rs. 90");
    printf("\n----------------------------");

    //Get order details
    printf("\nEnter your name: ");
    scanf("%s", name);
    printf("\nEnter the item number: ");
    int choice;
    scanf("%d", &choice);

    //Calculate price based on item selected
    switch(choice)
    {
        case 1:
            price = 80.00;
            printf("\nEnter quantity: ");
            scanf("%d", &quantity);
            price *= quantity;
            break;
        case 2:
            price = 100.00;
            printf("\nEnter quantity: ");
            scanf("%d", &quantity);
            price *= quantity;
            break;
        case 3:
            price = 90.00;
            printf("\nEnter quantity: ");
            scanf("%d", &quantity);
            price *= quantity;
            break;
        default:
            printf("\nInvalid choice.");
            return 0;
    }

    //Display the bill
    printf("\n----------------------------");
    printf("\n HOT COFFEE CAFE BILL");
    printf("\n----------------------------");
    printf("\n Customer Name: %s", name);
    printf("\n Item Ordered: ");

    switch(choice)
    {
        case 1:
            printf("Cappuccino");
            break;
        case 2:
            printf("Latte");
            break;
        case 3:
            printf("Espresso");
            break;
    }

    printf("\n Quantity: %d", quantity);
    printf("\n Total Price: Rs. %.2f", price);
    printf("\n----------------------------");

    return 0;
}