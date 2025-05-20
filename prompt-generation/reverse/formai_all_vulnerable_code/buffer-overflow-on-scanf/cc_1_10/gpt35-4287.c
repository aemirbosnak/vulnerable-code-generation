//FormAI DATASET v1.0 Category: Product Inventory System ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 50
#define MAX_NAME_LENGTH 20

int totalItems = 0;

struct Item{
    char name[MAX_NAME_LENGTH];
    int quantity;
    float price;
};

struct Item inventory[MAX_ITEMS];

void addItem(char itemName[], int itemQuantity, float itemPrice)
{
    if(totalItems == MAX_ITEMS)
    {
        printf("Inventory is full, cannot add more items.\n");
        return;
    }

    strcpy(inventory[totalItems].name, itemName);
    inventory[totalItems].quantity = itemQuantity;
    inventory[totalItems].price = itemPrice;
    totalItems++;

    printf("Item added to inventory.\n");
}

void removeItem(char itemName[])
{
    for(int i=0; i<totalItems; i++)
    {
        if(strcmp(inventory[i].name, itemName) == 0)
        {
            for(int j=i; j<totalItems-1; j++)
            {
                strcpy(inventory[j].name, inventory[j+1].name);
                inventory[j].quantity = inventory[j+1].quantity;
                inventory[j].price = inventory[j+1].price;
            }
            totalItems--;

            printf("Item removed from inventory.\n");

            return;
        }
    }

    printf("Item not found in inventory.\n");
}

void displayInventory()
{
    printf("Name\tQuantity\tPrice\n");

    for(int i=0; i<totalItems; i++)
    {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

void clearInventory()
{
    totalItems = 0;

    printf("Inventory cleared.\n");
}

int main()
{
    printf("Welcome to the Multiplayer Product Inventory System!\n");

    while(1)
    {
        printf("\n1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. Display inventory\n");
        printf("4. Clear inventory\n");
        printf("5. Exit\n");

        int choice;
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
            {
                char itemName[MAX_NAME_LENGTH];
                int itemQuantity;
                float itemPrice;

                printf("Enter item name: ");
                scanf("%s", itemName);

                printf("Enter item quantity: ");
                scanf("%d", &itemQuantity);

                printf("Enter item price: ");
                scanf("%f", &itemPrice);

                addItem(itemName, itemQuantity, itemPrice);
                break;
            }

            case 2:
            {
                char itemName[MAX_NAME_LENGTH];
                printf("Enter item name to remove: ");
                scanf("%s", itemName);

                removeItem(itemName);
                break;
            }

            case 3:
            {
                displayInventory();
                break;
            }

            case 4:
            {
                clearInventory();
                break;
            }

            case 5:
            {
                printf("Exiting inventory system...\n");
                exit(0);
            }

            default:
            {
                printf("Invalid choice, please enter a value from 1 to 5.\n");
                break;
            }
        }
    }

    return 0;
}