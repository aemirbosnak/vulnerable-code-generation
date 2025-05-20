//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 100

struct item
{
    char name[50];
    int quantity;
};

struct warehouses
{
    char location[50];
    struct item stored_items[MAX];
    int num_items;
};

struct company
{
    char name[50];
    struct warehouses warehouse[10];
    int num_warehouses;
};

void add_warehouse(struct company *c)
{
    if(c->num_warehouses==10)
    {
        printf("Sorry, you cannot add more than 10 warehouses.\n");
        return;
    }

    printf("Warehouse Location: ");
    scanf("%s",c->warehouse[c->num_warehouses].location);

    c->warehouse[c->num_warehouses].num_items=0;

    printf("New Warehouse added successfully.\n");
    c->num_warehouses++;
}

void add_item(struct company *c)
{
    char location[50];
    int i, found=0;
    printf("Enter Warehouse Location: ");
    scanf("%s",location);

    for(i=0;i<c->num_warehouses;i++)
    {
        if(strcmp(c->warehouse[i].location,location)==0)
        {
            found=1;
            if(c->warehouse[i].num_items==MAX)
            {
                printf("Sorry, the warehouse is already full.\n");
                return;
            }

            printf("Item Name: ");
            scanf("%s",c->warehouse[i].stored_items[c->warehouse[i].num_items].name);

            printf("Item Quantity: ");
            scanf("%d",&c->warehouse[i].stored_items[c->warehouse[i].num_items].quantity);

            printf("Item added successfully.\n");

            c->warehouse[i].num_items++;
            break;
        }
    }

    if(found==0)
    {
        printf("Warehouse not found.\n");
    }
}

void print_all(struct company c)
{
    int i,j;

    for(i=0;i<c.num_warehouses;i++)
    {
        printf("Warehouse Location: %s\n",c.warehouse[i].location);

        if(c.warehouse[i].num_items==0)
        {
            printf("No items in the warehouse.\n");
        }

        else
        {
            printf("Stored Items:\n");
            for(j=0;j<c.warehouse[i].num_items;j++)
            {
                printf("%d. %s - %d\n",j+1,c.warehouse[i].stored_items[j].name,c.warehouse[i].stored_items[j].quantity);
            }
        }
        printf("\n");
    }
}

int main()
{
    struct company c;
    c.num_warehouses=0;
    int choice;

    while(1)
    {
        printf("-----Warehouse Management System-----\n");
        printf("1. Add Warehouse\n");
        printf("2. Add Item\n");
        printf("3. Print all warehouses and items\n");
        printf("4. Exit\n");
        printf("------------------------------------\n");

        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1: add_warehouse(&c);
                    break;

            case 2: add_item(&c);
                    break;

            case 3: print_all(c);
                    break;

            case 4: exit(0);

            default: printf("Invalid choice entered, try again.\n");
        }

        printf("\n");
    }
    return 0;
}