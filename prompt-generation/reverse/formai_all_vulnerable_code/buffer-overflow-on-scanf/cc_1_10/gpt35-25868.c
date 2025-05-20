//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declare struct for Warehouse Item
struct WarehouseItem {
    char name[50];
    int quantity;
    float price;
};

//Function prototypes
void displayMenu();
int addItem(struct WarehouseItem inventory[], int itemCount);
void displayInventory(struct WarehouseItem inventory[], int itemCount);
void removeItem(struct WarehouseItem inventory[], int *itemCount);
void updateQuantity(struct WarehouseItem inventory[], int itemCount);

int main() {
    //Initialize variables
    int itemCount = 0;
    struct WarehouseItem inventory[50];

    //Loop through menu until user quits
    int choice = 0;
    while(choice != 5) {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                itemCount = addItem(inventory, itemCount);
                break;
            case 2:
                displayInventory(inventory, itemCount);
                break;
            case 3:
                removeItem(inventory, &itemCount);
                break;
            case 4:
                updateQuantity(inventory, itemCount);
                break;
            case 5:
                printf("\nThank you for using our Warehouse Management System!\n");
                break;
            default:
                printf("\nInvalid choice, please try again.\n");
                break;
        }
    }

    return 0;
}

//Function to display menu options
void displayMenu() {
    printf("\n\nWarehouse Management System\n");
    printf("------------------------------\n");
    printf("1. Add Item\n");
    printf("2. Display Inventory\n");
    printf("3. Remove Item\n");
    printf("4. Update Quantity of an Item\n");
    printf("5. Quit\n");
}

//Function to add item to inventory
int addItem(struct WarehouseItem inventory[], int itemCount) {
    printf("\nAdd Item Menu\n");
    printf("------------------------------\n");

    //Prompt user for item details
    printf("\nEnter name of item: ");
    scanf("%s", inventory[itemCount].name);
    printf("Enter quantity of item: ");
    scanf("%d", &inventory[itemCount].quantity);
    printf("Enter price of item: ");
    scanf("%f", &inventory[itemCount].price);

    //Increment item count and return new item count
    itemCount++;
    printf("\nItem added successfully!\n");
    return itemCount;
}

//Function to display inventory
void displayInventory(struct WarehouseItem inventory[], int itemCount) {
    printf("\nInventory List\n");
    printf("------------------------------\n");
    printf("Name\tQuantity\tPrice\n");

    //Loop through inventory array and print details of each item
    for(int i = 0; i < itemCount; i++) {
        printf("%s\t%d\t\t%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

//Function to remove an item from inventory
void removeItem(struct WarehouseItem inventory[], int *itemCount) {
    printf("\nRemove Item Menu\n");
    printf("------------------------------\n");

    //Prompt user for name of item to remove
    char name[50];
    printf("\nEnter name of item to remove: ");
    scanf("%s", name);

    //Loop through inventory array to find item to remove
    int index = -1;
    for(int i = 0; i < *itemCount; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    //If item is found, remove it and shift remaining items left
    if(index != -1) {
        for(int i = index; i < *itemCount - 1; i++) {
            inventory[i] = inventory[i+1];
        }
        (*itemCount)--;
        printf("\nItem removed successfully!\n");
    } else {
        printf("\nItem not found in inventory.\n");
    }
}

//Function to update quantity of an item in inventory
void updateQuantity(struct WarehouseItem inventory[], int itemCount) {
    printf("\nUpdate Quantity Menu\n");
    printf("------------------------------\n");

    //Prompt user for name of item to update
    char name[50];
    printf("\nEnter name of item to update: ");
    scanf("%s", name);

    //Loop through inventory array to find item to update
    int index = -1;
    for(int i = 0; i < itemCount; i++) {
        if(strcmp(inventory[i].name, name) == 0) {
            index = i;
            break;
        }
    }

    //If item is found, prompt user for new quantity and update item
    if(index != -1) {
        int newQuantity;
        printf("\nEnter new quantity for item: ");
        scanf("%d", &newQuantity);
        inventory[index].quantity = newQuantity;
        printf("\nQuantity updated successfully!\n");
    } else {
        printf("\nItem not found in inventory.\n");
    }
}