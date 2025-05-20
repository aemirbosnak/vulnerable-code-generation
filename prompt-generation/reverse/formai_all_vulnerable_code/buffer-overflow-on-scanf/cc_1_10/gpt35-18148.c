//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printInventory(int inventory[]);
void addToInventory(int inventory[], int item);
void removeFromInventory(int inventory[], int item);

int main()
{
    int inventory[10] = {0}; // Initialize inventory with 0 items
    int choice;
    srand(time(NULL));
    printf("Welcome to the Warehouse Management System!\n");

    while(1)
    {
        printf("\nSelect an option (1-3):\n");
        printf("1. Add item to inventory\n");
        printf("2. Remove item from inventory\n");
        printf("3. View inventory\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addToInventory(inventory, rand() % 10 + 1); // Add a random item to inventory
                break;

            case 2:
                removeFromInventory(inventory, rand() % 10 + 1); // Remove a random item from inventory
                break;

            case 3:
                printInventory(inventory); // View inventory
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

void printInventory(int inventory[])
{
    printf("\nInventory:\n");

    for(int i = 0; i < 10; i++)
    {
        printf("%d: %d\n", i+1, inventory[i]);
    }
}

void addToInventory(int inventory[], int item)
{
    for(int i = 0; i < 10; i++)
    {
        if(inventory[i] == 0) // If slot is empty, add item
        {
            inventory[i] = item;
            printf("\nAdded item %d to inventory!\n", item);
            return;
        }
    }
    printf("\nInventory is full!\n");
}

void removeFromInventory(int inventory[], int item)
{
    for(int i = 0; i < 10; i++)
    {
        if(inventory[i] == item) // If item is found, remove it
        {
            inventory[i] = 0;
            printf("\nRemoved item %d from inventory!\n", item);
            return;
        }
    }
    printf("\nItem %d not found in inventory!\n", item);
}