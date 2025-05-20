//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for items in warehouse
typedef struct {
    char itemName[20];
    int itemID;
    int quantity;
    float cost;
} Item;

// Define global variables
Item warehouseItems[50];
int numItems = 0;

// Define function to add a new item to the warehouse
void addItem() {
    printf("Enter item name: ");
    scanf("%s", warehouseItems[numItems].itemName);

    printf("Enter item ID: ");
    scanf("%d", &(warehouseItems[numItems].itemID));

    printf("Enter quantity: ");
    scanf("%d", &(warehouseItems[numItems].quantity));

    printf("Enter cost per unit: ");
    scanf("%f", &(warehouseItems[numItems].cost));

    numItems++;
}

// Define function to print all items in the warehouse
void printInventory() {
    printf("Warehouse Inventory:\n");
    printf("=====================\n");
    for (int i = 0; i < numItems; i++) {
        printf("Item Name: %s\n", warehouseItems[i].itemName);
        printf("Item ID: %d\n", warehouseItems[i].itemID);
        printf("Quantity: %d\n", warehouseItems[i].quantity);
        printf("Cost per Unit: %.2f\n", warehouseItems[i].cost);
        printf("\n");
    }
}

// Define function to calculate total cost of all items in the warehouse
float getTotalCost() {
    float totalCost = 0;
    for (int i = 0; i < numItems; i++) {
        totalCost += warehouseItems[i].quantity * warehouseItems[i].cost;
    }
    return totalCost;
}

int main() {
    int choice;
    do {
        // print menu
        printf("Warehouse Management System\n");
        printf("===========================\n");
        printf("1. Add Item\n");
        printf("2. Print Inventory\n");
        printf("3. Print Total Cost\n");
        printf("4. Exit\n");
        printf("Enter choice: ");

        // get user choice
        scanf("%d", &choice);

        // perform chosen action
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                printInventory();
                break;
            case 3:
                printf("Total Warehouse Cost: %.2f\n", getTotalCost());
                break;
            case 4:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
                break;
        }

    } while (choice != 4);

    return 0;
}