//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: standalone
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice,quantity;
    float price=0,total_price=0;
    char cont;
    
    do
    {
        printf("***Welcome to C Cafe Billing System***\n");

        printf("\nMenu:\n");

        printf("1. Cappuccino \tRs. 120\n");
        printf("2. Espresso \tRs. 100\n");
        printf("3. Latte \tRs. 130\n");
        printf("4. Iced Coffee \tRs. 150\n");

        printf("\nEnter your choice (1/2/3/4): ");
        scanf("%d",&choice);

        printf("\nEnter the quantity: ");
        scanf("%d",&quantity);

        switch(choice)
        {
            case 1: price = 120;
                    break;

            case 2: price = 100;
                    break;

            case 3: price = 130;
                    break;

            case 4: price = 150;
                    break;

            default: printf("\nInvalid choice");
                     exit(0);
        }

        total_price += price * quantity;

        printf("\nDo you want to continue (Y/N): ");
        scanf(" %c",&cont);

    }while(cont=='Y' || cont=='y');

    printf("\nTotal amount to be paid: Rs. %.2f",total_price);

    return 0;
}