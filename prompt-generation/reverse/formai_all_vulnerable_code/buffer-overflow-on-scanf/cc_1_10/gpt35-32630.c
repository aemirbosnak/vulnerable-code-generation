//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_ITEMS 1000

typedef struct Item 
{
    char itemName[50];
    int itemID;
    float itemPrice;
    int itemQuantity;
} Item;

Item stock[MAX_ITEMS];
int numItems = 0;

void addItem()
{
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.itemName);
    printf("Enter item ID: ");
    scanf("%d", &newItem.itemID);
    printf("Enter item price: ");
    scanf("%f", &newItem.itemPrice);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.itemQuantity);

    stock[numItems] = newItem;
    numItems++;

    printf("%s has been added to the warehouse!\n", newItem.itemName);
}

void removeItem()
{
    int idToRemove;
    printf("Enter ID of item to remove: ");
    scanf("%d", &idToRemove);

    for (int i = 0; i < numItems; i++)
    {
        if (stock[i].itemID == idToRemove)
        {
            printf("%s has been removed from the warehouse!\n", stock[i].itemName);
            for (int j = i + 1; j < numItems; j++)
            {
                stock[j-1] = stock[j];
            }
            numItems--;
            return;
        }
    }
    printf("Item not found in warehouse!\n");
}

void printStock()
{
    printf("Warehouse Stock:\n");
    printf("ID \tName \t\tPrice \tQuantity\n");
    for (int i = 0; i < numItems; i++)
    {
        printf("%d \t%-12s \t%.2f \t%3d\n", stock[i].itemID, stock[i].itemName, stock[i].itemPrice, stock[i].itemQuantity);
    }
}

int main()
{
    printf("Welcome to the Surprised Warehouse Management System!\n\n");
    while (1)
    {
        printf("Enter 1 to add new item to the warehouse.\n");
        printf("Enter 2 to remove an item from the warehouse.\n");
        printf("Enter 3 to print current stock.\n");
        printf("Enter any other number to exit.\n");

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                printStock();
                break;
            default:
                printf("Goodbye!\n");
                exit(0);
        }

        printf("\n");
    }

    return 0;
}