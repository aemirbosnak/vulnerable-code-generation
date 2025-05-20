//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    int id;
    char name[NAME_LENGTH];
    int quantity;
} Item;

Item warehouse[MAX_ITEMS];
int itemCount = 0;

void addItem() {
    if (itemCount >= MAX_ITEMS) {
        printf("Warehouse is full! Cannot add more items.\n");
        return;
    }
    Item newItem;
    newItem.id = itemCount + 1; // Assign a new ID
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
  
    warehouse[itemCount] = newItem;
    itemCount++;
    printf("Item added successfully! ID: %d\n", newItem.id);
}

void removeItem() {
    int id;
    printf("Enter the item ID to remove: ");
    scanf("%d", &id);
    if (id < 1 || id > itemCount) {
        printf("Invalid ID. Item not found.\n");
        return;
    }
    for (int i = id - 1; i < itemCount - 1; i++) {
        warehouse[i] = warehouse[i + 1]; // Shift items to the left
    }
    itemCount--;
    printf("Item with ID %d removed successfully!\n", id);
}

void displayItems() {
    if (itemCount == 0) {
        printf("Warehouse is empty.\n");
        return;
    }
    printf("\nItems in the Warehouse:\n");
    printf("--------------------------------------------------------\n");
    printf("ID\tName\t\tQuantity\n");
    printf("--------------------------------------------------------\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t\t%d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
    printf("--------------------------------------------------------\n");
}

void warehouseMenu() {
    int choice;
    while (1) {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. Display Items\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                removeItem();
                break;
            case 3:
                displayItems();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    printf("Welcome to the Warehouse Management System!\n");
    warehouseMenu();
    return 0;
}