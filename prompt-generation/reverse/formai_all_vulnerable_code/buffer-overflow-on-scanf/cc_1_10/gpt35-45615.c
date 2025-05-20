//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 10

typedef struct 
{
    char name[20];
    int quantity;
    float price;
} Item;

Item warehouse[MAX_ITEMS]; 
int itemCount = 0;

void addItem(char name[], int quantity, float price)
{
    if(itemCount >= MAX_ITEMS)
    {
        printf("Warehouse is full!\n");
        return;
    }

    Item newItem;
    strcpy(newItem.name, name);
    newItem.quantity = quantity;
    newItem.price = price;

    warehouse[itemCount++] = newItem;

    printf("Item added successfully. New item count: %d\n", itemCount);
}

void displayItems()
{
    printf("Warehouse Inventory:\n");
    printf("--------------------\n");

    if(itemCount == 0)
    {
        printf("No items found.\n");
        return;
    }

    for(int i=0; i<itemCount; i++)
    {
        printf("Name: %s\n", warehouse[i].name);
        printf("Quantity: %d\n", warehouse[i].quantity);
        printf("Price: $%.2f\n", warehouse[i].price);
        printf("--------------------\n");
    }

}

int main()
{
    printf("Welcome to Neon Warehouse Management System!\n");
    printf("--------------------------------------------\n");

    int choice;
    do
    {
        printf("Enter your choice:\n");
        printf("1. Add Item\n");
        printf("2. Display Items\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter item name:\n");
                char name[20];
                scanf("%s", name);

                printf("Enter item quantity:\n");
                int quantity;
                scanf("%d", &quantity);

                printf("Enter item price:\n");
                float price;
                scanf("%f", &price);

                addItem(name, quantity, price);
                break;

            case 2:
                displayItems();
                break;

            case 3:
                printf("Exiting Neon Warehouse Management System. Goodbye!\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    return 0;
}