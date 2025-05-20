//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: shape shifting
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to generate random integer
int generateRandomInt(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

//structure for item
struct Item
{
    int itemID;
    char itemName[50];
    int itemQty;
};

//function to display item details
void displayItemDetails(struct Item *item)
{
    printf("Item ID: %d\n", item->itemID);
    printf("Item Name: %s\n", item->itemName);
    printf("Item Quantity: %d\n", item->itemQty);
    printf("========================\n");
}

//function to add items to warehouse
void addItem(struct Item warehouse[], int size)
{
    int id = generateRandomInt(1000, 9999);
    char name[50];
    int qty;

    printf("Enter Item Name: ");
    scanf("%s", name);
    printf("Enter Item Quantity: ");
    scanf("%d", &qty);

    for(int i=0;i<size;i++)
    {
        if(warehouse[i].itemID == 0)
        {
            warehouse[i].itemID = id;
            strcpy(warehouse[i].itemName, name);
            warehouse[i].itemQty = qty;
            printf("Item added successfully!\n");
            return;
        }
    }
    printf("Warehouse is full. Item cannot be added.\n");
}

//function to remove items from warehouse
void removeItem(struct Item warehouse[], int size)
{
    int id;

    printf("Enter Item ID: ");
    scanf("%d", &id);

    for(int i=0;i<size;i++)
    {
        if(warehouse[i].itemID == id)
        {
            warehouse[i].itemID = 0;
            warehouse[i].itemName[0] = '\0';
            warehouse[i].itemQty = 0;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found.\n");
}

//main function
int main()
{
    srand(time(0)); //seed for generating random number

    struct Item warehouse[10]; //array of items

    int choice;

    do
    {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Item Details\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addItem(warehouse, 10);
                break;

            case 2:
                removeItem(warehouse, 10);
                break;

            case 3:
                for(int i=0;i<10;i++)
                {
                    if(warehouse[i].itemID != 0)
                    {
                        displayItemDetails(&warehouse[i]);
                    }
                }
                break;

            case 4:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
                break;
        }
    }
    while(choice != 4);

    return 0;
}