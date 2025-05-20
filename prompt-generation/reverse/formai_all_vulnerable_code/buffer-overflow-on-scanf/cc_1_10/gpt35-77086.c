//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: realistic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int choice,quantity,price,continue_order,total_bill=0,order_count=0;
    printf("Welcome to Unique C Cafe!\n");
    printf("\nMenu:\n");
    printf("1. Cappuccino: $5\n");
    printf("2. Latte: $4\n");
    printf("3. Espresso: $6\n");
    printf("4. Americano: $3\n");
    printf("5. Mocha: $7\n");
    printf("6. Quit\n");

    while(choice!=6)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the quantity: ");
                scanf("%d",&quantity);
                price=5;
                total_bill+=price*quantity;
                order_count+=quantity;
                printf("\nCappuccino added to order! Total Bill: $%d\n",total_bill);
                break;

            case 2:
                printf("\nEnter the quantity: ");
                scanf("%d",&quantity);
                price=4;
                total_bill+=price*quantity;
                order_count+=quantity;
                printf("\nLatte added to order! Total Bill: $%d\n",total_bill);
                break;

            case 3:
                printf("\nEnter the quantity: ");
                scanf("%d",&quantity);
                price=6;
                total_bill+=price*quantity;
                order_count+=quantity;
                printf("\nEspresso added to order! Total Bill: $%d\n",total_bill);
                break;

            case 4:
                printf("\nEnter the quantity: ");
                scanf("%d",&quantity);
                price=3;
                total_bill+=price*quantity;
                order_count+=quantity;
                printf("\nAmericano added to order! Total Bill: $%d\n",total_bill);
                break;

            case 5:
                printf("\nEnter the quantity: ");
                scanf("%d",&quantity);
                price=7;
                total_bill+=price*quantity;
                order_count+=quantity;
                printf("\nMocha added to order! Total Bill: $%d\n",total_bill);
                break;

            case 6:
                printf("\nThank you for ordering! Total Bill: $%d for %d orders.\n",total_bill,order_count);
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
                continue;
        }

        printf("\nWould you like to continue with the order: (1 for yes / 0 for no): ");
        scanf("%d",&continue_order);

        if(continue_order == 1)
        {
            continue;
        }
        else
        {
            printf("\nThank you for ordering! Total Bill: $%d for %d orders.\n",total_bill,order_count);
            break;
        }

    }

    return 0;
}