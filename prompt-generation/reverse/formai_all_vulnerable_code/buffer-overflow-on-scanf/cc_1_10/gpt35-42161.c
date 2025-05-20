//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct menu
{
    char item_name[20];
    float item_price;
};

void print_header(int count)
{
    printf("\n ******** C Cafe Billing System ********* \n");
    printf("\n *************************************** \n");
    printf("\n Your Order Details: ");
    printf("\n *************************************** \n");
    printf("\n SI No.\t Item\t\t Price \n");
    printf("\n *************************************** \n");
    printf("\n");
}

int main()
{
    int order_size = 0;
    struct menu items[20];
    float order_price = 0;

    printf("\n Welcome to C Cafe! \n");

    int choice = 0;

    do {
        printf("\n 1. Add Item to Menu");
        printf("\n 2. Place Order");
        printf("\n 3. Exit");
        printf("\n Enter your choice : ");

        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("\n Enter the item name : ");
                scanf("%s", items[order_size].item_name);

                printf("\n Enter the item price : ");
                scanf("%f", &items[order_size].item_price);

                order_size++;
                break;

            case 2:
                if(order_size > 0)
                {
                    print_header(order_size + 1);
                    for(int i = 0; i < order_size; i++)
                    {
                        printf("\n %d. %s\t%.2f", i+1, items[i].item_name, items[i].item_price);
                        order_price += items[i].item_price;
                    }

                    printf("\n *************************************** \n");
                    printf("\n Total bill : %.2f", order_price);
                    printf("\n *************************************** \n");

                    // Reset order
                    order_size = 0;
                    order_price = 0;
                    memset(items, 0, sizeof(struct menu) * 20);
                }
                else
                {
                    printf("\n No items in the menu. Please add items first.");
                }

                break;

            case 3: 
                printf("\n Thank you for visiting C Cafe! \n");
                break;

            default:
                printf("\n Invalid option. Please try again.");
                break;
        }
    } while(choice != 3);

    return 0;
}