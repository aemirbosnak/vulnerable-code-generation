//Falcon-180B DATASET v1.0 Category: Medical Store Management System ; Style: Romeo and Juliet
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 1000

struct medicine
{
    char name[50];
    int price;
    int quantity;
};

struct medicine med[MAX];

int main()
{
    int i,j,n,ch;

    printf("Enter the number of medicines: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the name of medicine %d: ",i+1);
        scanf("%s",med[i].name);

        printf("Enter the price of medicine %d: ",i+1);
        scanf("%d",&med[i].price);

        printf("Enter the quantity of medicine %d: ",i+1);
        scanf("%d",&med[i].quantity);
    }

    while(1)
    {
        printf("\n1.Display\n2.Purchase\n3.Exit");
        printf("\nEnter your choice: ");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                for(i=0;i<n;i++)
                {
                    printf("\n%s\t%d\t%d",med[i].name,med[i].price,med[i].quantity);
                }
                break;

            case 2:
                printf("\nEnter the name of medicine to purchase: ");
                scanf("%s",med[0].name);

                for(i=0;i<n;i++)
                {
                    if(strcmp(med[i].name,med[0].name)==0)
                    {
                        printf("\nEnter the quantity of %s to purchase: ",med[i].name);
                        scanf("%d",&j);

                        if(j>med[i].quantity)
                        {
                            printf("\nInsufficient stock!");
                        }
                        else
                        {
                            printf("\nTotal cost: Rs. %d",j*med[i].price);
                            med[i].quantity -= j;
                        }

                        break;
                    }
                }

                break;

            case 3:
                exit(0);

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}