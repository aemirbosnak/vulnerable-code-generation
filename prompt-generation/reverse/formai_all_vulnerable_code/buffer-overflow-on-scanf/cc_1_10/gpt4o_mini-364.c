//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define ITEM_NAME_LENGTH 50

typedef struct {
    char name[ITEM_NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void initializeWarehouse(Warehouse* warehouse) {
    warehouse->itemCount = 0;
}

void addItem(Warehouse* warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full!\n");
        return;
    }
    
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    
    warehouse->items[warehouse->itemCount] = newItem;
    warehouse->itemCount++;
    printf("Item added successfully.\n");
}

void removeItem(Warehouse* warehouse) {
    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->itemCount - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->itemCount--;
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found!\n");
}

void viewItems(const Warehouse* warehouse) {
    if (warehouse->itemCount == 0) {
        printf("No items in warehouse.\n");
        return;
    }

    printf("Items in Warehouse:\n");
    for (int i = 0; i < warehouse->itemCount; i++) {
        printf("Name: %s, Quantity: %d, Price: %.2f\n", 
               warehouse->items[i].name, 
               warehouse->items[i].quantity, 
               warehouse->items[i].price);
    }
}

void searchItem(const Warehouse* warehouse) {
    char name[ITEM_NAME_LENGTH];
    printf("Enter item name to search: ");
    scanf("%s", name);
    
    for (int i = 0; i < warehouse->itemCount; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            printf("Item found: Name: %s, Quantity: %d, Price: %.2f\n", 
                   warehouse->items[i].name, 
                   warehouse->items[i].quantity, 
                   warehouse->items[i].price);
            return;
        }
    }
    printf("Item not found!\n");
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Items\n");
    printf("4. Search Item\n");
    printf("5. Exit\n");
    printf("Select an option: ");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;
    
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                addItem(&warehouse);
                break;
            case 2:
                removeItem(&warehouse);
                break;
            case 3:
                viewItems(&warehouse);
                break;
            case 4:
                searchItem(&warehouse);
                break;
            case 5:
                printf("Exiting the system.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}