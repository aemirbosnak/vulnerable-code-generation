//GPT-4o-mini DATASET v1.0 Category: Warehouse Management System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITEMS 100

typedef struct {
    char name[30];
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
        printf("Warehouse is full. Cannot add more items.\n");
        return;
    }
    
    Item newItem;
    printf("Enter item name: ");
    scanf("%s", newItem.name);
    printf("Enter item quantity: ");
    scanf("%d", &newItem.quantity);
    printf("Enter item price: ");
    scanf("%f", &newItem.price);

    warehouse->items[warehouse->count] = newItem;
    warehouse->count++;
    printf("Item added successfully!\n");
}

void removeItem(Warehouse *warehouse) {
    char name[30];
    printf("Enter item name to remove: ");
    scanf("%s", name);

    for (int i = 0; i < warehouse->count; i++) {
        if (strcmp(warehouse->items[i].name, name) == 0) {
            for (int j = i; j < warehouse->count - 1; j++) {
                warehouse->items[j] = warehouse->items[j + 1];
            }
            warehouse->count--;
            printf("Item removed successfully!\n");
            return;
        }
    }
    printf("Item not found.\n");
}

void viewItems(const Warehouse *warehouse) {
    if (warehouse->count == 0) {
        printf("No items in the warehouse.\n");
        return;
    }

    printf("Current Items in Warehouse:\n");
    printf("%-15s %-10s %-10s\n", "Name", "Quantity", "Price");
    for (int i = 0; i < warehouse->count; i++) {
        printf("%-15s %-10d %-10.2f\n", warehouse->items[i].name, warehouse->items[i].quantity, warehouse->items[i].price);
    }
}

void displayMenu() {
    printf("\nWarehouse Management System\n");
    printf("1. Add Item\n");
    printf("2. Remove Item\n");
    printf("3. View Items\n");
    printf("4. Exit\n");
    printf("Choose an option: ");
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
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please select again.\n");
        }
    }

    return 0;
}