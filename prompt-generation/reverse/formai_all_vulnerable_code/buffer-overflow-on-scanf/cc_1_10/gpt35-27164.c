//FormAI DATASET v1.0 Category: Warehouse Management System ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct for storing information about inventory items
typedef struct {
    char name[50];
    int quantity;
    float price;
} InventoryItem;

// Function for adding a new item to inventory
void addInventoryItem(InventoryItem *inventory, int *inventoryCount) {
    printf("Enter item name: ");
    scanf("%s", inventory[*inventoryCount].name);
    printf("Enter item quantity: ");
    scanf("%d", &inventory[*inventoryCount].quantity);
    printf("Enter item price: ");
    scanf("%f", &inventory[*inventoryCount].price);
    (*inventoryCount)++;
    printf("Item added to inventory!\n");
}

// Function for printing out current inventory
void printInventory(InventoryItem *inventory, int inventoryCount) {
    printf("INVENTORY:\n");
    printf("Name\tQuantity\tPrice\n");
    for (int i = 0; i < inventoryCount; i++) {
        printf("%s\t%d\t\t$%.2f\n", inventory[i].name, inventory[i].quantity, inventory[i].price);
    }
}

int main() {
    int inventoryCount = 0;
    InventoryItem inventory[100];

    // Menu loop
    while (1) {
        printf("Enter an option:\n");
        printf("1. Add an item to inventory\n");
        printf("2. Print current inventory\n");
        printf("3. Exit\n");

        int option;
        scanf("%d", &option);

        switch (option) {
            case 1:
                addInventoryItem(inventory, &inventoryCount);
                break;
            case 2:
                printInventory(inventory, inventoryCount);
                break;
            case 3:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid option.\n");
                break;
        }
    }

    return 0;
}