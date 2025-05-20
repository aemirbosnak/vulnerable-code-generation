//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100
#define NAME_LENGTH 50

typedef struct {
    char name[NAME_LENGTH];
    int quantity;
    float price;
} Item;

typedef struct {
    Item items[MAX_ITEMS];
    int count;
} Warehouse;

void initializeWarehouse(Warehouse *warehouse) {
    warehouse->count = 0;
}

void addItem(Warehouse *warehouse) {
    if (warehouse->count >= MAX_ITEMS) {
        printf("Warehouse is full! Can't add more items.\n");
        return;
    }
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter price: ");
    scanf("%f", &newItem.price);
    
    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully!\n");
}

void removeItem(Warehouse *warehouse) {
    char name[NAME_LENGTH];
    printf("Enter the item name to remove: ");
    scanf("%s", name);
    
    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item '%s' removed successfully!\n", name);
            return;
        }
    }
    printf("Item '%s' not found!\n", name);
}

void viewItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in warehouse.\n");
        return;
    }
    printf("\nWarehouse Inventory:\n");
    printf("-------------------------------------------------\n");
    printf("%-20s %-10s %-10s\n", "Item Name", "Quantity", "Price");
    printf("-------------------------------------------------\n");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%-20s %-10d $%-9.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
    printf("-------------------------------------------------\n");
}

void menu() {
    printf("\nWelcome to the Warehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Items\n");
    printf("4. Exit\n");
}

int main() {
    Warehouse warehouse;
    initializeWarehouse(&warehouse);
    int choice;

    while (1) {
        menu();
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
                printf("Exiting... Have a great day!\n");
                return 0;
            default:
                printf("Invalid choice! Please select again.\n");
        }
    }
    return 0;
}