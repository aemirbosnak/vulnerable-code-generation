//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for items in warehouse
typedef struct Item
{
    int id;
    char name[50];
    int quantity;
} Item;

// Function declarations
void displayMenu();
void displayItems(Item items[], int numItems);
void addItem(Item items[], int *numItems);
void removeItem(Item items[], int *numItems);

int main()
{
    Item items[100];
    int numItems = 0;
    int choice;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                displayItems(items, numItems);
                break;
            case 2:
                addItem(items, &numItems);
                break;
            case 3:
                removeItem(items, &numItems);
                break;
            case 4:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }
    }
    while (choice != 4);

    return 0;
}

// Function to display menu options
void displayMenu()
{
    printf("\nWarehouse management system\n");
    printf("1. View items in warehouse\n");
    printf("2. Add item to warehouse\n");
    printf("3. Remove item from warehouse\n");
    printf("4. Exit program\n");
    printf("Enter choice: ");
}

// Function to display items in warehouse
void displayItems(Item items[], int numItems)
{
    if (numItems == 0)
    {
        printf("\nNo items in warehouse.\n");
    }
    else
    {
        printf("\nItems in warehouse:\n");
        printf("ID\tName\tQuantity\n");
        printf("------------------------\n");
        for (int i = 0; i < numItems; i++)
        {
            printf("%d\t%s\t%d\n", items[i].id, items[i].name, items[i].quantity);
        }
    }
}

// Function to add item to warehouse
void addItem(Item items[], int *numItems)
{
    Item newItem;

    printf("\nEnter item ID: ");
    scanf("%d", &newItem.id);

    printf("Enter item name: ");
    scanf("%s", newItem.name);

    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);

    items[*numItems] = newItem;
    *numItems += 1;

    printf("Item added to warehouse.\n");
}

// Function to remove item from warehouse
void removeItem(Item items[], int *numItems)
{
    int idToRemove;

    printf("\nEnter ID of item to remove: ");
    scanf("%d", &idToRemove);

    int found = 0;
    for (int i = 0; i < *numItems; i++)
    {
        if (items[i].id == idToRemove)
        {
            found = 1;
            *numItems -= 1;
            items[i] = items[*numItems];
            printf("Item removed from warehouse.\n");
            break;
        }
    }

    if (!found)
    {
        printf("Item with ID %d not found.\n", idToRemove);
    }
}