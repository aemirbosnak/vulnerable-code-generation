//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: brave
#include <stdio.h>
#include <stdlib.h>

//Function to display the menu for the system
void displayMenu()
{
    printf("=== WAREHOUSE MANAGEMENT SYSTEM ===\n");
    printf("1. Add an item to the warehouse\n");
    printf("2. Remove an item from the warehouse\n");
    printf("3. Check inventory of an item\n");
    printf("4. Display all items in the warehouse\n");
    printf("5. Exit\n");
}

//Structure to store item information
struct Item
{
    char itemName[50];
    int itemID;
    int quantity;
};

int main()
{
    int choice, n=0, i, itemToRemove, itemToCheck;
    struct Item items[100];

    do
    {
        displayMenu();
        printf("Select an option: ");
        scanf("%d", &choice);

        switch(choice)
        {
            //Case to add item to the warehouse
            case 1:
                printf("Enter Item Name: ");
                scanf("%s", items[n].itemName);
                printf("Enter Item ID: ");
                scanf("%d", &items[n].itemID);
                printf("Enter Quantity: ");
                scanf("%d", &items[n].quantity);
                printf("\nItem added successfully\n");
                n++;
                break;

            //Case to remove an item from the warehouse
            case 2:
                printf("Enter Item ID to remove: ");
                scanf("%d", &itemToRemove);
                for(i=0; i<n; i++)
                {
                    if(items[i].itemID==itemToRemove)
                    {
                        //Shift all elements to remove the selected item
                        for(int j=i; j<n-1; j++)
                        {
                            items[j] = items[j+1];
                        }
                        n--;
                        printf("\nItem removed successfully\n");
                        break;
                    }
                }
                if(i==n)
                    printf("\nItem not found\n");
                break;

            //Case to check inventory of an item
            case 3:
                printf("Enter Item ID to check inventory: ");
                scanf("%d", &itemToCheck);
                for(i=0; i<n; i++)
                {
                    if(items[i].itemID==itemToCheck)
                    {
                        printf("\nItem Name: %s", items[i].itemName);
                        printf("\nItem ID: %d", items[i].itemID);
                        printf("\nQuantity: %d\n", items[i].quantity);
                        break;
                    }
                }
                if(i==n)
                    printf("\nItem not found\n");
                break;

            //Case to display all items in the warehouse
            case 4:
                printf("\n=== ALL ITEMS IN WAREHOUSE ===\n");
                printf("+-------+------------------------------+----------+\n");
                printf("| ItemID|           Item Name           | Quantity |\n");
                printf("+-------+------------------------------+----------+\n");
                for(i=0; i<n; i++)
                {
                    printf("| %5d | %28s | %8d |\n", items[i].itemID, items[i].itemName, items[i].quantity);
                }
                printf("+-------+------------------------------+----------+\n");
                break;

            //Case to exit the program
            case 5:
                printf("\nExiting program...");
                break;

            //Invalid input case
            default:
                printf("\nInvalid input, please enter a valid option\n");
        }
    }while(choice!=5);

    return 0;
}