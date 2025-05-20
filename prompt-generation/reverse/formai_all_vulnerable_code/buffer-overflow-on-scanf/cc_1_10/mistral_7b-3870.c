//MISTRAL-7B DATASET v1.0 Category: Warehouse Management System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INVENTORY 100
#define INVENTORY_SIZE sizeof(struct InventoryItem)
typedef struct InventoryItem {
    char name[50];
    int stock;
    float price;
} InventoryItem;
InventoryItem inventory[MAX_INVENTORY];
int inventoryCount = 0;
void addItem(char *name, int stock, float price) {
    if (inventoryCount < MAX_INVENTORY) {
        strcpy(inventory[inventoryCount].name, name);
        inventory[inventoryCount].stock = stock;
        inventory[inventoryCount].price = price;
        inventoryCount++;
    } else {
        printf("Inventory is full.\n");
    }
}
void removeItem(char *name) {
    int i;
    for (i = 0; i < inventoryCount; i++) {
        if (strcmp(inventory[i].name, name) == 0) {
            memmove(&inventory[i], &inventory[i + 1], (inventoryCount - i - 1) * INVENTORY_SIZE);
            inventoryCount--;
            break;
        }
    }
}
void displayInventory() {
    int i;
    for (i = 0; i < inventoryCount; i++) {
        printf("%s - Stock: %d, Price: %.2f\n", inventory[i].name, inventory[i].stock, inventory[i].price);
    }
}
int main() {
    char command[20];
    char name[50];
    int stock, choice;
    float price;
    while (1) {
        printf("\nWarehouse Management System\n1. Add Item\n2. Remove Item\n3. Display Inventory\n4. Quit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter item name: ");
                scanf("%s", name);
                printf("Enter stock: ");
                scanf("%d", &stock);
                printf("Enter price: ");
                scanf("%f", &price);
                addItem(name, stock, price);
                break;
            case 2:
                printf("Enter item name: ");
                scanf("%s", name);
                removeItem(name);
                break;
            case 3:
                displayInventory();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}