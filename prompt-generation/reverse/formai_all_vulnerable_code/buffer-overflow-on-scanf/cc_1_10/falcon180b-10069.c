//Falcon-180B DATASET v1.0 Category: Stock market tracker ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 10

struct stock
{
    char name[20];
    int price;
    int quantity;
};

void addstock(struct stock *s, int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nEnter the name of the stock: ");
        scanf("%s",s[i].name);
        printf("\nEnter the price of the stock: ");
        scanf("%d",&s[i].price);
        printf("\nEnter the quantity of the stock: ");
        scanf("%d",&s[i].quantity);
    }
}

void display(struct stock s[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("\nName: %s",s[i].name);
        printf("\nPrice: %d",s[i].price);
        printf("\nQuantity: %d",s[i].quantity);
        printf("\n");
    }
}

void modify(struct stock s[], int n)
{
    int i,j,k;
    char ch;
    printf("\nEnter the name of the stock to be modified: ");
    scanf("%s",ch);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].name,ch)==0)
        {
            printf("\nEnter the new name of the stock: ");
            scanf("%s",s[i].name);
            printf("\nEnter the new price of the stock: ");
            scanf("%d",&s[i].price);
            printf("\nEnter the new quantity of the stock: ");
            scanf("%d",&s[i].quantity);
            break;
        }
    }
}

void delete(struct stock s[], int n)
{
    int i,j;
    char ch;
    printf("\nEnter the name of the stock to be deleted: ");
    scanf("%s",ch);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].name,ch)==0)
        {
            for(j=i;j<n-1;j++)
            {
                s[j]=s[j+1];
            }
            n--;
            break;
        }
    }
}

void search(struct stock s[], int n)
{
    int i;
    char ch;
    printf("\nEnter the name of the stock to be searched: ");
    scanf("%s",ch);
    for(i=0;i<n;i++)
    {
        if(strcmp(s[i].name,ch)==0)
        {
            printf("\nStock found!");
            break;
        }
        else
        {
            printf("\nStock not found!");
        }
    }
}

int main()
{
    int n,i;
    struct stock s[MAX];
    printf("\nEnter the number of stocks: ");
    scanf("%d",&n);
    addstock(s,n);
    printf("\nThe stocks added are:\n");
    display(s,n);
    printf("\nEnter 1 to modify a stock\nEnter 2 to delete a stock\nEnter 3 to search for a stock\nEnter 0 to exit");
    while(1)
    {
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                modify(s,n);
                break;
            case 2:
                delete(s,n);
                break;
            case 3:
                search(s,n);
                break;
            case 0:
                exit(0);
            default:
                printf("\nInvalid choice!");
        }
    }
    return 0;
}