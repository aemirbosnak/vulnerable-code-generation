//FormAI DATASET v1.0 Category: Cafe Billing System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char name[20], menu[20], again = 'y';
    int qty, rate, total = 0, count = 0, i = 0, j = 0, flag;
    
    printf("Welcome to Cafe Billing System\n\n");
    printf("Enter your name: ");
    scanf("%s", name);
    
    while(again == 'y')
    {
        printf("\nEnter item name: ");
        scanf("%s", menu);
        printf("Enter item quantity: ");
        scanf("%d", &qty);
        
        //Finding the rate of the item
        if(strcmp(menu, "Coffee") == 0)
        {
            rate = 10;
        }
        else if(strcmp(menu, "Tea") == 0)
        {
            rate = 8;
        }
        else if(strcmp(menu, "Sandwich") == 0)
        {
            rate = 20;
        }
        else if(strcmp(menu, "Burger") == 0)
        {
            rate = 30;
        }
        else
        {
            printf("\nSorry, the item is not available\n");
            rate = 0;
            flag = 1;
        }
        
        //Calculating the total cost of each item
        if(!flag)
        {
            total += rate*qty;
            printf("Cost of %s = %d\n", menu, rate*qty);
            
            count++; //To calculate the number of items ordered
        }
        
        //Asking the user if he wants to order again
        printf("\nDo you want to order again? (y/n) ");
        scanf(" %c", &again);
        
        flag = 0;
    }
    
    //Printing the final bill
    printf("\n\nCUSTOMER DETAILS\n");
    printf("Name: %s\n", name);
    printf("Number of items purchased: %d\n", count);
    printf("Total cost: Rs. %d\n", total);
    printf("Thank you for visiting us. Visit again!\n");

    return 0;
}