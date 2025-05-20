//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct for storing inventory items */
typedef struct {
    char name[20];   // name of item
    int quantity;    // amount in stock
    float price;     // price per unit
} InventoryItem;

/* Function prototypes */
void addInventory(InventoryItem *inventory, int *numItems);
void sellItem(InventoryItem *inventory, int *numItems);
void printInventory(InventoryItem *inventory, int numItems);

/* Main program */
int main() {
    InventoryItem inventory[50];
    int numItems = 0;
    char choice;

    printf("Welcome to the Retro Warehouse Management System!\n\n");

    while(1) {
        printf("Please choose from the following options: \n");
        printf("      1) Add an item to inventory\n");
        printf("      2) Sell an item from inventory\n");
        printf("      3) Print inventory list\n");
        printf("      4) Exit program\n");

        scanf(" %c", &choice);
        printf("\n");

        switch(choice) {
            case '1':
                addInventory(inventory, &numItems);
                break;
            case '2':
                sellItem(inventory, &numItems);
                break;
            case '3':
                printInventory(inventory, numItems);
                break;
            case '4':
                printf("Thank you for using the Retro Warehouse Management System!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        printf("\n");
    }
}

/* Function for adding inventory items */
void addInventory(InventoryItem *inventory, int *numItems) {
    InventoryItem newItem;

    printf("Enter the name of the new item: ");
    scanf("%s", newItem.name);

    printf("Enter the quantity of the new item: ");
    scanf("%d", &newItem.quantity);

    printf("Enter the price of the new item: ");
    scanf("%f", &newItem.price);

    inventory[*numItems] = newItem;
    (*numItems)++;

    printf("\n");
    printf("New item added to inventory.\n");
}

/* Function for selling inventory items */
void sellItem(InventoryItem *inventory, int *numItems) {
    char itemName[20];
    int sellQuantity;
    int i;

    printf("Enter the name of the item to sell: ");
    scanf("%s", itemName);

    for(i = 0; i < *numItems; i++) {
        if(strcmp(inventory[i].name, itemName) == 0) {
            printf("Enter the quantity to sell: ");
            scanf("%d", &sellQuantity);

            if(sellQuantity <= inventory[i].quantity) {
                inventory[i].quantity -= sellQuantity;
                printf("Sold %d %s for $%.2f each.\n", sellQuantity, inventory[i].name, inventory[i].price);
            }
            else {
                printf("Not enough %s in stock.\n", inventory[i].name);
            }

            return;
        }
    }

    printf("Item not found in inventory.\n");
}

/* Function for printing inventory items */
void printInventory(InventoryItem *inventory, int numItems) {
    int i;

    printf("Current inventory:\n");

    for(i = 0; i < numItems; i++) {
        printf("  %s: %d in stock at $%.2f each\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}