//Falcon2-11B DATASET v1.0 Category: Medical Store Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10
#define MAX_NAME_LENGTH 20
#define MAX_QUANTITY 100

struct item
{
    char name[MAX_NAME_LENGTH];
    int quantity;
};

struct item items[MAX_ITEMS];

int main()
{
    int choice, item_id;
    char name[MAX_NAME_LENGTH];
    int quantity;

    printf("Welcome to Medical Store Inventory Management System!\n");
    printf("1. Add Item\n");
    printf("2. View Inventory\n");
    printf("3. Update Item Quantity\n");
    printf("4. Delete Item\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    while(choice!= 5)
    {
        switch(choice)
        {
            case 1:
                printf("Enter the item name: ");
                scanf("%s", name);
                printf("Enter the item quantity: ");
                scanf("%d", &quantity);

                item_id = 0;
                while(item_id < MAX_ITEMS && strcmp(items[item_id].name, name)!= 0)
                {
                    item_id++;
                }

                if(item_id >= MAX_ITEMS)
                {
                    printf("Item not found!\n");
                }
                else
                {
                    strcpy(items[item_id].name, name);
                    items[item_id].quantity = quantity;
                }

                break;
            case 2:
                printf("Current Inventory:\n");
                for(int i = 0; i < MAX_ITEMS; i++)
                {
                    if(items[i].quantity > 0)
                    {
                        printf("Name: %s, Quantity: %d\n", items[i].name, items[i].quantity);
                    }
                }
                break;
            case 3:
                printf("Enter the item name: ");
                scanf("%s", name);
                printf("Enter the new quantity: ");
                scanf("%d", &quantity);

                item_id = 0;
                while(item_id < MAX_ITEMS && strcmp(items[item_id].name, name)!= 0)
                {
                    item_id++;
                }

                if(item_id >= MAX_ITEMS)
                {
                    printf("Item not found!\n");
                }
                else
                {
                    items[item_id].quantity = quantity;
                }
                break;
            case 4:
                printf("Enter the item name: ");
                scanf("%s", name);
                printf("Enter the confirmation: ");
                scanf("%s", name);

                item_id = 0;
                while(item_id < MAX_ITEMS && strcmp(items[item_id].name, name)!= 0)
                {
                    item_id++;
                }

                if(item_id >= MAX_ITEMS)
                {
                    printf("Item not found!\n");
                }
                else
                {
                    strcpy(items[item_id].name, name);
                    items[item_id].quantity = 0;
                }
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
    }

    return 0;
}