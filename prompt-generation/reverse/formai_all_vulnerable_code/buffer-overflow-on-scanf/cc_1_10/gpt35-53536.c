//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char menu[10][50]={"Coffee","Tea","Sandwich","Burger","Pizza","Pasta","Hot Dog","French Fries","Soft Drink","Juice"};

    float price[10]={1.5,1.2,2.5,3.0,8.0,6.5,5.0,2.5,1.0,1.5};

    int choice, quantity, i, j;

    float total=0.0;

    printf("\n\nWelcome to the Cafe Billing System!\n\n");

    do
    {
        printf("Please select a menu item (1-10)\n");
        printf("1. Coffee - $1.5\n");
        printf("2. Tea - $1.2\n");
        printf("3. Sandwich - $2.5\n");
        printf("4. Burger - $3.0\n");
        printf("5. Pizza - $8.0\n");
        printf("6. Pasta - $6.5\n");
        printf("7. Hot Dog - $5.0\n");
        printf("8. French Fries - $2.5\n");
        printf("9. Soft Drink - $1.0\n");
        printf("10. Juice - $1.5\n");

        printf("Enter choice: ");
        scanf("%d",&choice);

        if(choice<1 || choice>10)
        {
            printf("\nInvalid choice! Please enter choice between 1-10.\n\n");
            continue;
        }

        printf("Enter quantity: ");
        scanf("%d",&quantity);

        total += price[choice-1] * quantity;

        printf("\nItem added to the bill: %s\n",menu[choice-1]);
        printf("Price per item: $%.2f\n",price[choice-1]);
        printf("Quantity: %d\n\n",quantity);

    }while(choice!=0);

    printf("Total bill amount: $%.2f\n",total);

    printf("\nThank you for visiting us. Have a nice day!\n\n");

    return 0;
}