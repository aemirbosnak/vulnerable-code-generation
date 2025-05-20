//Falcon-180B DATASET v1.0 Category: Cafe Billing System ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

#define MAX 100

struct item
{
    char name[50];
    float price;
};

struct bill
{
    char name[50];
    int quantity;
    float amount;
};

int main()
{
    int choice,i,j,k;
    char ch;
    float total=0.0;
    struct item menu[MAX];
    struct bill bill[MAX];
    int n=0,m=0;

    printf("\nWelcome to Cafe Billing System\n");

    for(i=0;i<MAX;i++)
    {
        printf("\nEnter item name: ");
        scanf("%s",&menu[i].name);
        printf("Enter item price: ");
        scanf("%f",&menu[i].price);
    }

    while(1)
    {
        printf("\nEnter your choice:\n1.Add item\n2.Remove item\n3.View bill\n4.Exit");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                if(n>=MAX)
                    printf("\nBill is full!!");
                else
                {
                    printf("\nEnter item name: ");
                    scanf("%s",&bill[n].name);
                    printf("Enter quantity: ");
                    scanf("%d",&bill[n].quantity);
                    m=0;
                    for(i=0;i<MAX;i++)
                    {
                        if(strcmp(menu[i].name,bill[n].name)==0)
                        {
                            bill[n].amount=bill[n].quantity*menu[i].price;
                            m=1;
                            break;
                        }
                    }
                    if(m==0)
                        printf("\nItem not found!!");
                    n++;
                    total+=bill[n-1].amount;
                }
                break;

            case 2:
                if(n==0)
                    printf("\nBill is empty!!");
                else
                {
                    printf("\nEnter item name to remove: ");
                    scanf("%s",&ch);
                    for(i=0;i<n;i++)
                    {
                        if(strcmp(bill[i].name,ch)==0)
                        {
                            total-=bill[i].amount;
                            for(j=i;j<n-1;j++)
                            {
                                bill[j]=bill[j+1];
                            }
                            n--;
                            break;
                        }
                    }
                    if(i==n)
                        printf("\nItem not found!!");
                }
                break;

            case 3:
                if(n==0)
                    printf("\nBill is empty!!");
                else
                {
                    printf("\nBill:\n");
                    for(i=0;i<n;i++)
                    {
                        printf("\nName: %s\nQuantity: %d\nPrice: %.2f\nAmount: %.2f\n",bill[i].name,bill[i].quantity,menu[k].price,bill[i].amount);
                    }
                    printf("\nTotal amount: %.2f",total);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("\nInvalid choice!!");
        }
    }

    return 0;
}