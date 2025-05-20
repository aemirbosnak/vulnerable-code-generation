//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: automated
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct item
{
    char name[20];
    int price;
};

struct item menu[] =
{
    {"Coffee", 30},
    {"Tea", 20},
    {"Coca-Cola", 40},
    {"Pepsi", 35},
    {"Sprite", 30},
    {"Water", 10}
};

int main()
{
    int choice, i, j, total = 0;
    char ch;
    struct item cart[100];
    int n = 0;

    printf("Welcome to Cafe Billing System\n");

    do
    {
        system("clear");
        printf("1.Menu\n2.Cart\n3.Checkout\n4.Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Menu:\n");
                for(i = 0; i < 6; i++)
                {
                    printf("%d. %s - %d\n", i+1, menu[i].name, menu[i].price);
                }
                break;

            case 2:
                printf("Cart:\n");
                for(i = 0; i < n; i++)
                {
                    printf("%d. %s - %d\n", i+1, cart[i].name, cart[i].price);
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("Your cart is empty.\n");
                }
                else
                {
                    total = 0;
                    for(i = 0; i < n; i++)
                    {
                        total += cart[i].price;
                    }
                    printf("Total amount: %d\n", total);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice.\n");
        }

    }while(choice!= 4);

    return 0;
}