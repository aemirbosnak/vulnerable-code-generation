//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: active
#include<stdio.h>
#include<stdlib.h>

struct Medicine{
    char name[20];
    int quantity;
    float price;
};

void add_medicine(struct Medicine med[], int n);
void sell_medicine(struct Medicine med[], int n);
void display(struct Medicine med[], int n);

int main()
{
    struct Medicine med[10];
    int choice, n = 0;

    while(1)
    {
        printf("\n\n1.Add a medicine");
        printf("\n2.Sell a medicine");
        printf("\n3.Display the stock");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                add_medicine(med, n);
                n++;
                break;

            case 2:
                sell_medicine(med, n);
                break;

            case 3:
                display(med, n);
                break;

            case 4:
                exit(0);
                break;

            default:
                printf("\nInvalid choice!");
                break;
        }
    }

    return 0;
}

void add_medicine(struct Medicine med[], int n)
{
    printf("\nEnter the name of the medicine:");
    scanf("%s",med[n].name);

    printf("Enter the quantity of the medicine:");
    scanf("%d",&med[n].quantity);

    printf("Enter the price of the medicine:");
    scanf("%f",&med[n].price);

    printf("\nMedicine added successfully!");
}

void sell_medicine(struct Medicine med[], int n)
{
    char name[20];
    int i, quantity;

    printf("\nEnter the name of the medicine:");
    scanf("%s",name);

    for(i=0;i<n;i++)
    {
        if(strcmp(med[i].name,name) == 0)
        {
            printf("Available quantity: %d\n",med[i].quantity);

            printf("Enter the quantity you want to sell:");
            scanf("%d",&quantity);

            if(quantity > med[i].quantity)
            {
                printf("\nQuantity not available!");
            }
            else
            {
                med[i].quantity -= quantity;
                printf("\nSold successfully!");
                break;
            }
        }
    }

    if(i == n)
    {
        printf("\nMedicine not found in stock!");
    }
}

void display(struct Medicine med[], int n)
{
    int i;

    printf("\n\nName\tQuantity\tPrice\n");

    for(i=0;i<n;i++)
    {
        printf("%s\t%d\t\t%.2f\n",med[i].name,med[i].quantity,med[i].price);
    }
}