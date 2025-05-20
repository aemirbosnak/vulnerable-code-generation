//FormAI DATASET v1.0 Category: Medical Store Management System ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct medicine
{
    int id;
    char name[20];
    int quantity;
    float price;
};

struct medicine inventory[100];
int count = 0;

void addMedicine()
{
    struct medicine med;
    printf("Enter ID of the medicine: ");
    scanf("%d",&med.id);
    printf("Enter name of the medicine: ");
    scanf("%s",med.name);
    printf("Enter quantity of the medicine: ");
    scanf("%d",&med.quantity);
    printf("Enter price of the medicine: ");
    scanf("%f",&med.price);
    inventory[count++] = med;
    printf("Medicine added successfully!\n\n");
}

void removeMedicine()
{
    int id,i;
    printf("Enter ID of the medicine to be removed: ");
    scanf("%d",&id);
    for(i=0; i<count; i++)
    {
        if(inventory[i].id == id)
        {
            printf("%s removed successfully!\n\n",inventory[i].name);
            break;
        }
    }
    if(i==count)
    {
        printf("Medicine with ID %d not found!\n\n",id);
    }
    else
    {
        for(;i<count-1;i++)
        {
            inventory[i] = inventory[i+1];
        }
        count--;
    }
}

void searchMedicine()
{
    int id,i;
    printf("Enter ID of the medicine to be searched: ");
    scanf("%d",&id);
    for(i=0; i<count; i++)
    {
        if(inventory[i].id == id)
        {
            printf("ID: %d\nName: %s\nQuantity: %d\nPrice: %.2f\n\n",inventory[i].id,inventory[i].name,inventory[i].quantity,inventory[i].price);
            break;
        }
    }
    if(i==count)
    {
        printf("Medicine with ID %d not found!\n\n",id);
    }
}

void displayInventory()
{
    int i;
    printf("ID  Name  Quantity Price\n");
    for(i=0; i<count; i++)
    {
        printf("%2d  %4s  %8d %.2f\n",inventory[i].id,inventory[i].name,inventory[i].quantity,inventory[i].price);
    }
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("************ Medical Store Management System *************\n");
        printf("1. Add Medicine\n");
        printf("2. Remove Medicine\n");
        printf("3. Search Medicine\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                addMedicine();
                break;
            case 2:
                removeMedicine();
                break;
            case 3:
                searchMedicine();
                break;
            case 4:
                displayInventory();
                break;
            case 5:
                printf("Thank you!\n");
                break;
            default:
                printf("Invalid choice!\n\n");
        }
    }while(choice!=5);
    return 0;
}