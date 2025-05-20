//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[50];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int itemCount;
} Warehouse;

void addItem(Warehouse *warehouse) {
    if (warehouse->itemCount >= MAX_ITEMS) {
        printf("Warehouse is full, cannot add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse->items[warehouse->itemCount++] = newItem;
    printf("Item added successfully.\n");
}

void removeItem(Warehouse *warehouse) {
    char itemName[50];
    printf("Enter item name to remove: ");
    scanf("%s", itemName);
    for (int i = 0; i < warehouse->itemCount; ++i) {
        if (strcmp(warehouse->items[i].name, itemName) == 0) {
            warehouse->items[i] = warehouse->items[--warehouse->itemCount];
            printf("Item removed successfully.\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void viewItems(Warehouse *warehouse) {
    printf("\nWarehouse Inventory:\n");
    float totalValue = 0;
    for (int i = 0; i < warehouse->itemCount; ++i) {
        printf("Item Name: %s, Quantity: %d, Price: %.2f\n",
               warehouse->items[i].name, 
               warehouse->items[i].quantity, 
               warehouse->items[i].price);
        totalValue += warehouse->items[i].quantity * warehouse->items[i].price;
    }
    printf("Total Value of Inventory: %.2f\n", totalValue);
}

int main() {
    Warehouse warehouse;
    warehouse.itemCount = 0;
    
    int choice;
    do {
        printf("\nWarehouse Management System\n");
        printf("1. Add Item\n");
        printf("2. Remove Item\n");
        printf("3. View Items\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
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
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}