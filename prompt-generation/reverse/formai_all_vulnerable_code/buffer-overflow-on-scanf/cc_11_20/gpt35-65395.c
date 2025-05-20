//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: protected
#include<stdio.h> 

void main()
{
    char name[50], menu[5], option;
    int bill_no, qty[5], price[5], total = 0;
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Enter bill number: ");
    scanf("%d", &bill_no);
    printf("\n----------------");
    printf("\n WELCOME TO C CAFE");
    printf("\n----------------");
    do
    {
        printf("\n\nEnter the menu you want to order:\n");
        printf("A - Coffee 10/-\n");
        printf("B - Tea 5/-\n");
        printf("C - Sandwich 20/-\n");
        printf("D - Burger 25/-\n");
        scanf("%s", menu);

        if(menu[0] == 'A')
        {
            printf("Enter quantity: ");
            scanf("%d", &qty[0]);
            price[0] = qty[0] * 10;
            printf("\n%d Coffee ordered for %d/-", qty[0], price[0]);
        }
        else if(menu[0] == 'B')
        {
            printf("Enter quantity: ");
            scanf("%d", &qty[1]);
            price[1] = qty[1] * 5;
            printf("\n%d Tea ordered for %d/-", qty[1], price[1]);
        }
        else if(menu[0] == 'C')
        {
            printf("Enter quantity: ");
            scanf("%d", &qty[2]);
            price[2] = qty[2] * 20;
            printf("\n%d Sandwich ordered for %d/-", qty[2], price[2]);
        }
        else if(menu[0] == 'D')
        {
            printf("Enter quantity: ");
            scanf("%d", &qty[3]);
            price[3] = qty[3] * 25;
            printf("\n%d Burger ordered for %d/-", qty[3], price[3]);
        }
        else
        {
            printf("\nInvalid option!");
        }

        printf("\nDo you want to order anything else? (Y/N)");
        scanf(" %c", &option);
    }while(option == 'y' || option == 'Y');

    printf("\n\nFinal Order:\n");
    printf("Name:\t%s\n", name);
    printf("Bill No:\t%d\n", bill_no);
    printf("Items\tQuantity\tPrice\n");
    printf("---------------------------------\n");
    if(price[0] != 0)
    {
        printf("Coffee:\t%d\t\t%d\n", qty[0], price[0]);
        total += price[0];
    }
    if(price[1] != 0)
    {
        printf("Tea:\t%d\t\t%d\n", qty[1], price[1]);
        total += price[1];
    }
    if(price[2] != 0)
    {
        printf("Sandwich:\t%d\t\t%d\n", qty[2], price[2]);
        total += price[2];
    }
    if(price[3] != 0)
    {
        printf("Burger:\t%d\t\t%d\n", qty[3], price[3]);
        total += price[3];
    }

    printf("---------------------------------\n");
    printf("Total:\t\t\t%d\n", total);
    printf("---------------------------------\n");
    printf("Thank you for visiting C Cafe!\n");
}