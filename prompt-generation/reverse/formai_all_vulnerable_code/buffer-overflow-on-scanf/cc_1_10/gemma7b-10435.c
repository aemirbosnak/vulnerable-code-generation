//Gemma-7B DATASET v1.0 Category: Cafe Billing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("CLS");
    printf("********************************************************\n");
    printf("WELCOME TO THE CAFFE-BILLING SYSTEM!\n");
    printf("********************************************************\n");

    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);

    int menu_choice;
    printf("Please select an item: \n");
    printf("1. Coffee \n");
    printf("2. Tea \n");
    printf("3. Juice \n");
    printf("4. Milkshake \n");
    scanf("%d", &menu_choice);

    float price = 0.0f;
    switch (menu_choice)
    {
        case 1:
            price = 50.0f;
            break;
        case 2:
            price = 40.0f;
            break;
        case 3:
            price = 30.0f;
            break;
        case 4:
            price = 20.0f;
            break;
        default:
            printf("Invalid item selection.\n");
            break;
    }

    int quantity;
    printf("Enter the quantity: ");
    scanf("%d", &quantity);

    float total_price = price * quantity;

    printf("--------------------------------------------------------\n");
    printf("NAME: %s\n", name);
    printf("ITEM: %s\n", menu_choice);
    printf("QUANTITY: %d\n", quantity);
    printf("TOTAL PRICE: %.2f\n", total_price);
    printf("THANK YOU FOR VISITING THE CAFFE-BILLING SYSTEM!\n");
    printf("********************************************************\n");

    return 0;
}