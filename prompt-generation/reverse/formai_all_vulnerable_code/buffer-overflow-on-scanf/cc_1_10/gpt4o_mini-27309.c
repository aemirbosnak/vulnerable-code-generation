//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    int id;
    char name[50];
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
    printf("Enter item ID: ");
    scanf("%d", &newItem.id);
    printf("Enter item name: ");
    getchar(); // consume newline
    fgets(newItem.name, sizeof(newItem.name), stdin);
    newItem.name[strcspn(newItem.name, "\n")] = 0; // remove newline
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    warehouse[itemCount++] = newItem;
    printf("Item added successfully.\n");
}

void updateStock() {
    int id, newQuantity;
    printf("Enter item ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            printf("Current quantity of %s: %d\n", warehouse[i].name, warehouse[i].quantity);
            printf("Enter new quantity: ");
            scanf("%d", &newQuantity);
            warehouse[i].quantity = newQuantity;
            printf("Stock updated successfully.\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void viewInventory() {
    if (itemCount == 0) {
        printf("Inventory is empty!\n");
        return;
    }
    printf("Current Inventory:\n");
    printf("ID\tName\t\tQuantity\n");
    for (int i = 0; i < itemCount; i++) {
        printf("%d\t%s\t%d\n", warehouse[i].id, warehouse[i].name, warehouse[i].quantity);
    }
}

void removeItem() {
    int id;
    printf("Enter item ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < itemCount; i++) {
        if (warehouse[i].id == id) {
            for (int j = i; j < itemCount - 1; j++) {
                warehouse[j] = warehouse[j + 1];
            }
            itemCount--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Update Stock\n");
    printf("3. View Inventory\n");
    printf("4. Remove Item\n");
    printf("5. Exit\n");
}

int main() {
    int choice = 0;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addItem();
                break;
            case 2:
                updateStock();
                break;
            case 3:
                viewInventory();
                break;
            case 4:
                removeItem();
                break;
            case 5:
                printf("Exiting the system. Thank you!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}