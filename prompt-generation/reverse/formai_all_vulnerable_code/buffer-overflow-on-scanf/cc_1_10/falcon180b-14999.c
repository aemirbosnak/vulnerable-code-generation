//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

typedef struct
{
    int id;
    char name[20];
    char category[20];
    int quantity;
    int price;
}Product;

Product p[MAX];
int n=0;

void addProduct()
{
    printf("\nEnter Product ID:");
    scanf("%d",&p[n].id);

    printf("\nEnter Product Name:");
    scanf("%s",p[n].name);

    printf("\nEnter Product Category:");
    scanf("%s",p[n].category);

    printf("\nEnter Product Quantity:");
    scanf("%d",&p[n].quantity);

    printf("\nEnter Product Price:");
    scanf("%d",&p[n].price);

    n++;
}

void displayProducts()
{
    printf("\n\nProduct ID\tProduct Name\tCategory\tQuantity\tPrice");
    for(int i=0;i<n;i++)
    {
        printf("\n%d\t\t%s\t\t%s\t\t%d\t\t%d",p[i].id,p[i].name,p[i].category,p[i].quantity,p[i].price);
    }
}

void searchProduct()
{
    int id;
    printf("\nEnter Product ID to search:");
    scanf("%d",&id);

    for(int i=0;i<n;i++)
    {
        if(p[i].id==id)
        {
            printf("\n\nProduct Details:");
            printf("\nProduct ID:%d",p[i].id);
            printf("\nProduct Name:%s",p[i].name);
            printf("\nProduct Category:%s",p[i].category);
            printf("\nProduct Quantity:%d",p[i].quantity);
            printf("\nProduct Price:%d",p[i].price);
        }
    }
}

void main()
{
    int choice;

    do
    {
        printf("\n\n1.Add Product");
        printf("\n2.Display Products");
        printf("\n3.Search Product");
        printf("\n4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                addProduct();
                break;

            case 2:
                displayProducts();
                break;

            case 3:
                searchProduct();
                break;

            case 4:
                printf("\nExiting....");
                break;

            default:
                printf("\nInvalid choice!");
        }
    }while(choice!=4);
}