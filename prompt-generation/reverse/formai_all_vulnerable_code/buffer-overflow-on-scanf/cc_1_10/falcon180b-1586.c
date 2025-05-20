//Falcon-180B DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item item;
    int reorderLevel;
    int reorderQuantity;
} Inventory;

void initializeInventory(Inventory* inv) {
    strcpy(inv->item.name, "");
    inv->item.quantity = 0;
    inv->item.price = 0.0;

    inv->reorderLevel = 0;
    inv->reorderQuantity = 0;
}

void displayInventory(Inventory inv) {
    printf("Item Name: %s\n", inv.item.name);
    printf("Quantity: %d\n", inv.item.quantity);
    printf("Price: $%.2f\n", inv.item.price);

    printf("Reorder Level: %d\n", inv.reorderLevel);
    printf("Reorder Quantity: %d\n", inv.reorderQuantity);
}

int main() {
    Inventory inv;
    initializeInventory(&inv);

    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Delete Item\n");
        printf("4. Display Inventory\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", inv.item.name);
                printf("Enter item quantity: ");
                scanf("%d", &inv.item.quantity);
                printf("Enter item price: $");
                scanf("%f", &inv.item.price);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", inv.item.name);
                printf("Enter new item quantity: ");
                scanf("%d", &inv.item.quantity);
                printf("Enter new item price: $");
                scanf("%f", &inv.item.price);
                break;
            case 3:
                printf("Enter item name: ");
                scanf("%s", inv.item.name);
                break;
            case 4:
                displayInventory(inv);
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while(choice!= 5);

    return 0;
}