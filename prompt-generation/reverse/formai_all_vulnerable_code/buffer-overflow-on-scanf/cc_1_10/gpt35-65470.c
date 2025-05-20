//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: complete
#include <stdio.h>
#include <stdbool.h>

//Defining Item structure to hold item details
typedef struct Item
{
    int id;
    char name[20];
    int quantity;
    float cost;
} Item;

//Defining a dynamic array of Items
Item *inventory = NULL;
int itemCount = 0;

//Function to add an item to the inventory
void addItem() 
{
    Item item;
    printf("\nEnter the id of the Item: ");
    scanf("%d", &item.id);
    printf("\nEnter the name of the Item: ");
    scanf("%s", item.name);
    printf("\nEnter the quantity of the Item: ");
    scanf("%d", &item.quantity);
    printf("\nEnter the cost of the Item: ");
    scanf("%f", &item.cost);
    inventory = (Item *)realloc(inventory, (itemCount + 1) * sizeof(Item));
    inventory[itemCount++] = item;
}

//Function to display all the items in the inventory
void displayInventory() 
{
    printf("\n---------------------------------------------");
    printf("\n| %-10s | %-20s | %-10s | %-10s |","ID","Name","Quantity", "Cost");
    printf("\n---------------------------------------------");
    for(int i = 0; i < itemCount; i++) 
    {
        printf("\n| %-10d | %-20s | %-10d | $%-10.2f |", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].cost);
    }
    printf("\n---------------------------------------------");
}

//Function to search for an item in the inventory
void searchItem() 
{
    int id;
    printf("\nEnter the ID of the Item you want to search: ");
    scanf("%d", &id);
    for(int i = 0; i < itemCount; i++)
    {
        if(inventory[i].id == id) 
        {
            printf("\n---------------------------------------------");
            printf("\n| %-10s | %-20s | %-10s | %-10s |","ID","Name","Quantity", "Cost");
            printf("\n---------------------------------------------");
            printf("\n| %-10d | %-20s | %-10d | $%-10.2f |", inventory[i].id, inventory[i].name, inventory[i].quantity, inventory[i].cost);
            printf("\n---------------------------------------------");
            return;
        }
    }
    printf("\nItem not found!");
}

//Function to update an existing item
void updateItem() 
{
    int id, choice;
    bool found = false;
    printf("\nEnter the ID of the Item you want to update: ");
    scanf("%d", &id);
    for(int i = 0; i < itemCount; i++)
    {
        if(inventory[i].id == id) 
        {
            found = true;
            printf("\nWhat do you want to update?\n1. Name\n2. Quantity\n3. Cost\nEnter your choice: ");
            scanf("%d", &choice);
            switch(choice) {
                case 1:
                    printf("\nEnter new name: ");
                    scanf("%s", inventory[i].name);
                    break;
                case 2:
                    printf("\nEnter new quantity: ");
                    scanf("%d", &inventory[i].quantity);
                    break;
                case 3:
                    printf("\nEnter new cost: ");
                    scanf("%f", &inventory[i].cost);
                    break;
                default:
                    printf("\nInvalid choice!");
            }
            printf("\nItem updated Successfully!\n");
            displayInventory();
            break;
        }
    }
    if(!found)
        printf("\nItem not found!");
}

//Function to delete an existing item
void deleteItem() 
{
    int id, index = -1;
    printf("\nEnter the ID of the Item you want to delete: ");
    scanf("%d", &id);
    for(int i = 0; i < itemCount; i++)
    {
        if(inventory[i].id == id) 
        {
            index = i;
            break;
        }
    }
    if(index == -1)
    {
        printf("\nItem not found!");
        return;
    }
    for(int i = index; i < itemCount - 1; i++)
    {
        inventory[i] = inventory[i+1];
    }
    itemCount--;
    inventory = (Item *)realloc(inventory, itemCount * sizeof(Item));
    printf("\nItem deleted Successfully!\n");
    displayInventory();
}

int main()
{
    int choice;
    do 
    {
        printf("\n-----------------------------");
        printf("\nWarehouse Management System");
        printf("\n-----------------------------");
        printf("\n1. Add item to inventory");
        printf("\n2. Display inventory");
        printf("\n3. Search for an item");
        printf("\n4. Update an item");
        printf("\n5. Delete an item");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) 
        {
            case 1:
                addItem();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                searchItem();
                break;
            case 4:
                updateItem();
                break;
            case 5:
                deleteItem();
                break;
            case 6:
                printf("\nThank you for using Warehouse Management System!");
                break;
            default:
                printf("\nInvalid choice!");
        }    
    } while(choice != 6);
    return 0;
}