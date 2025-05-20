//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct item
{
   char name[50];
   int quantity;
   float price;
   int rackNo;
};
struct item stock[100];

int n=0;

void addItem()
{
    printf("\nEnter Item Name: ");
    scanf("%s",stock[n].name);
    printf("\nEnter Item Quantity: ");
    scanf("%d",&stock[n].quantity);
    printf("\nEnter Item Price: ");
    scanf("%f",&stock[n].price);
    printf("\nEnter Rack Number: ");
    scanf("%d",&stock[n].rackNo);
    n++;
    printf("\nItem Added Successfully!\n\n");
}

void displayAllItems()
{
    printf("\n*********************************************************\n");
    printf("Name\t\tQuantity\tPrice\t\tRack Number\n");
    printf("*********************************************************\n\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t\t%d\t\t%.2f\t\t%d\n",stock[i].name,stock[i].quantity,stock[i].price,stock[i].rackNo);
    }
    printf("\n");
}

void searchItem()
{
    char itemName[50];
    printf("Enter Item Name: ");
    scanf("%s",itemName);
    int index = -1;
    for(int i=0;i<n;i++)
    {
        if(strcmp(itemName,stock[i].name) == 0)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        printf("Item not found!\n");
    }
    else
    {
        printf("Name\t\tQuantity\tPrice\t\tRack Number\n");
        printf("%s\t\t%d\t\t%.2f\t\t%d\n\n",stock[index].name,stock[index].quantity,stock[index].price,stock[index].rackNo);
    }
}

void deleteItem()
{
    char itemName[50];
    printf("Enter Item Name: ");
    scanf("%s",itemName);
    int index = -1;
    for(int i=0;i<n;i++)
    {
        if(strcmp(itemName,stock[i].name) == 0)
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        printf("Item not found!\n");
    }
    else
    {
        for(int i=index;i<n-1;i++)
        {
            stock[i] = stock[i+1];
        }
        n--;
        printf("Item Deleted Successfully\n\n");
    }
}

int main()
{
    int choice;
    printf("\n\t\tWarehouse Management System\n");
    do
    {
        printf("1. Add Item\n2. Display All Items\n3. Search Item\n4. Delete Item\n5. Exit\n\n");
        printf("Enter your choice(1-5): ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: addItem();
                    break;
            case 2: displayAllItems();
                    break;
            case 3: searchItem();
                    break;
            case 4: deleteItem();
                    break;
            case 5: printf("\nThank you for using the system!\n");
                    break;
            default: printf("\nInvalid choice! Please enter a valid choice(1-5)\n\n");
        }
    }while(choice != 5);

    return 0;
}